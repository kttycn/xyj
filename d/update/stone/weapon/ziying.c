#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;
inherit F_UNIQUE;

int do_wear(string arg);
int do_remove(string arg);
int do_amalgamation();
object offensive_target(object me);

void create()
{
	set_name(MAG "��۫��" NOR, ({"ziying sword", "sword"}) );
	set_weight(14000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�ѿ��ĳ������������������Ϲ⣬�������ˡ�\n");
		set("no_sell", "��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
		set("no_put", 1);
		set("no_drop", "��ô����Ķ��������˶��ϧѽ��\n");
		set("no_give", "�����������а������������ˣ�\n");
		set("no_get", "�㱻�����ϵ�����һ����һ�����£�����һ�ɣ����������л��䣡\n");
		set("value", 30000);
		set("replace_file", "/d/obj/weapon/sword/xijian");
		set("material", "crimsonsteel");
		set("wield_msg", "ֻ������쬡���һ����$N�������Ѿ�����һ�Ѻ�������ı�������$n��\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
		set("weapon_prop/int", 3);		
		
/*		set("unit", "��");
		set("material", "crystal");
		set("no_steal",1);
		set("value",0);
		set("no_put","��������װ����������ȥ��\n");
		set("no_drop", "��˱���ı����������󰡡�\n");
		set("no_sell", "������˭�������");
		set("replace_file", "/d/sea/obj/pearl");
		set("long","��˵�е����б���֮һ����֮�ɱ�ʯ�ң����ɷ�����ϵ������\nΪ����������֮�");
		set("armor_prop/armor", 1);
		set("spells/earth", 1);*/
	}
	set("is_monitored",1);
	setup();
}

int init()
{
	add_action("do_wear","wear");
	add_action("do_remove", "remove");
	add_action("do_amalgamation", "hesword");
	return 1;
}

object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

int do_wear (string arg)
{
	object me = this_player();
	object zhu = this_object();
	string name = zhu->query("name");
	string msg;

	if(arg!="all" && arg != "tuzhu" &&	arg != "tu lingzhu" )
		return notify_fail("��Ҫ���ʲô��\n");
	msg = "$N����һ��"+name+"����ɫ�ı�������ǰһ��һ���ġ�\n"; 
	if(zhu->query("unequip_msg"))
		zhu->delete("unequip_msg");
	zhu->set("wear_msg",msg);
	remove_call_out("tuzhuconditions");
	call_out("tuzhuconditions",7,me,zhu);
	return 0;
}

int do_remove (string arg)
{
	object me = this_player();
	object zhu = this_object();
	string name = zhu->query("name");
	string msg;

	if (arg != "all" && arg != "tuzhu" && arg != "tu lingzhu")
		return notify_fail("��Ҫժ��ʲô��\n");

	msg = "$N��"+name+"�����ժ��������\n"; 
	zhu->delete("wear_msg");
	zhu->set("unequip_msg",msg);
	remove_call_out("tuzhuconditions");
	return 0;
}

void tuzhuconditions(object who,object ob)
{
	object target;
	int ap,dp,damage;
	string msg;
	string type;
	type = ob->query("armor_type");
	if( !who || !ob )
		return;
	if( who->query_temp("armor/" + type) && ob->query("equipped")!="worn")
		return;
	if( who->is_fighting())
	{
		if( ! target = offensive_target(who) ) return ;
		if( ! present( target,environment(who)) ) return ;		
		msg = HIY"������ȽȽ����$n��ͷ�ϳ���һ���޴��ʯɽ��ֻ��������һ����\n
ʯɽ�������䣡\n"NOR;

		ap = 2000000;
		dp = target->query("combat_exp");
			
			
		if( random(ap + dp) > dp )
		{
			damage = 500+random(300);
			damage -= (int)target->query("max_mana") / 10 + random((int)target->query("eff_sen") / 5);
			damage -= random((int)target->query("mana_factor"));

			if( damage > 0 ) 
			{
				msg += HIC "���$n��ܲ�������ʯɽ�Ҹ����ţ�ͷ��Ѫ����\n" NOR;

				target->receive_damage("sen", damage*4/5);
				target->receive_wound("sen", damage/3);
				target->receive_damage("kee", damage*4/5);
				target->receive_wound("kee", damage/4);
			} 
			else
//here, cast failed and the target's mana_factor will be added to the previous
//damage to hurt yourself:(...note damage<0.
		msg += HIC "\n˭֪$n���޷�Ӧ��\n" NOR;	 
		}
		else
			msg += "���Ǳ�$n�㿪�ˡ�\n";

		message_vision(msg, who, target); 
	}
	call_out("tuzhuconditions",7,who,ob);
}
int do_amalgamation()
{
	//������
	object qingsuo
	object who = this_player();
	object ziqingjian;
	string ziqing_given;
	shengzhu_given = "/d/ourhome/honglou/dreamland/obj/ziqing-sword.c";

	if(who->is_fighting())
		 return notify_fail("������ս���أ���������\n");
	if(who->is_busy())
		 return notify_fail("����æ����!\n");
	if(!qingsuo = present("qingsuojian",who))
		 return notify_fail("�㻹ȱ��"+HIC "������" NOR +"��!��ô����ϱ���?\n");
/*	if(!thunder = present("leizhu",who))
		 return notify_fail("�㻹ȱ��"+HIB "������" NOR +"��!��ô����ϱ���?\n");
	if(!earth = present("huozhu",who))
		 return notify_fail("�㻹ȱ��"+HIR "������" NOR +"��!��ô����ϱ���?\n");
	if(!water = present("shuizhu",who))
		 return notify_fail("�㻹ȱ��"+HIW "ˮ����" NOR +"��!��ô����ϱ���?\n");*/
	if ((water->query("equipped")!="worn") && (wind->query("equipped")!="worn") && (thunder->query("equipped")!="worn") && (earth->query("equipped")!="worn") && (this_object()->query("equipped")!="worn"))
	{	
		ziqing = new("/d/ourhome/honglou/dreamland/obj/ziqing-sword.c");
		ziqingjian->move(who);
		if ( !(ziqingjian_given->in_mud()) ) {
			message_vision("$N���Ὣ˫������,�������� !\n
ͻȻ,һ����������,"+MAG "����" NOR+"�Զ�����,����������\n 
�������һ��,һ����������,"+CYN "����" NOR+"�������,����������\n
������һ��������������������.�ҽ����ں� !!\n
һ����Х,�����ж��һ��MAG"��"CYN"��"NOR"˫��"NOR���㲻�ɵĵ����һЦ��\n",who);
					
/*			$N����ű������һ��ֻ����ű���ȽȽ����һʱ�����ʢ��ֱ��������\n
���꣬"+HIG "������" NOR+"���������ų�����̹⣻"+HIR "������" NOR +"�����Ϸ�������Ŀ��⣻"+HIB "������" NOR +"������������������\n
�����������⣻"+HIW "ˮ����" NOR +"ȴͨ��Ө�ף�����������"+HIY "������" NOR +"ֱ����񷣬к������ƹ⡣\n
�ִ�Ƭ�̣��������һ����$N����ȴ����һ��˶���͸�����飬��ʱ������ʺ��⡣\n",who);*/
			MONITOR_D->report_rumor_object_msg(who, "�õ�[����˫��]�ˣ�");
		} else {
			message_vision("$N���Ὣ˫������,�������� !\n
ͻȻ,һ����������"+MAG "����" NOR+"�Զ�����������������\n 
�������һ��,һ����������"+CYN "����" NOR+"�������������������\n
������һ�������������������֣��ҽ����ں� !!\n
һ����Х��˫�����ķ���һ��ѣĿ�Ĺ�â��һ�ж���ʧ�ˡ�\n",who);
			
			
/*			message_vision("$N����ű������һ��ֻ����ű���ȽȽ����һʱ�����ʢ��ֱ��������\n
���꣬"+HIG "������" NOR+"���������ų�����̹⣻"+HIR "������" NOR +"�����Ϸ�������Ŀ��⣻"+HIB "������" NOR +"������������������\n
�����������⣻"+HIW "ˮ����" NOR +"ȴͨ��Ө�ף�����������"+HIY "������" NOR +"ֱ����񷣬к������ƹ⡣\n
�ִ�Ƭ�̣��������һ����һ�ж���ʧ�ˡ�\n",who);*/
			destruct(ziqingjian);
		}
		destruct(qingsuojian);
/*		destruct(earth);
		destruct(thunder);*/
		destruct(this_object());
		return 1;
	}
	return notify_fail("����������²��ܺ�赣�\n");
}
