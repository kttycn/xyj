//stone 20020614
// /d/guzhanchang/obj/jiaosword1.c

#include <weapon.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit SWORD;
int close(object me, object ob);

void create()
{
        set_name(HIR"����Ѫ��"NOR, ({ "xuesword", "xue sword","sword" }));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIR"һ��ɭɭ���⣬��������Ľ��������ֳ�����ɫ
�⻪��������Ѫ����󣬺����ƣ������ֳ�һ
�����ԣ�����Ѫ���â�������²�������â��¶��"NOR);
		set("no_sell", "��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
		set("no_put", 1);
		set("no_drop", "��ôϡ���ı������㲻����ϧ��\n");
		set("no_give", "�����ǧ��һ����������а������������ˣ�\n");
		set("no_get", "�㱻���ϵ�ɱ��һ�ƣ�����һ����æ�����ض��³���Ѫ����\n");
		set("value", 30000);
		set("replace_file", "/d/obj/weapon/sword/xijian");
		set("material", "steel");		
		set("wield_msg", HIR"$N�����ֱ���һ�Σ���Ǻ����һ���γ�$n"+HIR"����ʱ����һ��ҫĿ�ĳ��֮�⡣\n����â�����������ڣ�ֱ��������
$N���϶�ʱ����һ��ɭ����ɱ���� \n"NOR);
		set("unwield_msg", "��$Nһ�����ε�̾Ϣ����⼲����$N��$n��ر���\n");
		set("weapon_prop/courage", 8);
	}
	init_sword(135);
	set("is_monitored",1);
	setup();
}

void init()
{
    add_action("do_wield","wield");
}
int do_wield(string arg)
{
    	object me,ob;
	me = this_player();
	ob = this_object();
//if( !arg ) return 0;
	if(arg == "xuesword" || arg == "sword") {    
	if((int)me->query("max_force", 1) < 2500 ||
    	(int)me->query("force", 1) < 1000  ){
 	tell_object(me,"��о�ȫ����Ϣ���ڣ�ԭ���������������᲻����ѳ�Ѫ�����\n");
  	return 1;
  	}
	if((int)me->query_str() < 20){
   	tell_object(me,"���������ѳ�Ѫ�������������������ֻ�����ա�\n");
  	return 1;
	}
	ob->wield();
	message_vision(HIY"$Nһ����Х����Ǻ����һ���ӱ���γ�����Ѫ������ʱ����һ��ҫĿ�ĳ��֮�⡣
����â�����������ڣ�ֱ��������
$N���϶�ʱ����һ��ɭ����ɱ����\n"NOR, me);
	me->add("force", -100);
	remove_call_out("close");
	call_out("close",900, me,ob);
  	return 1;
  	}
}

int close(object me, object ob)
{
	object jiaosword;
	tell_room(environment(me), ob->query("name")+"�ĺ�⽥����ȥ���ָֻ��ɳ��Խ�......\n");
	jiaosword= new("/d/guzhanchang/obj/jiaosword");
	jiaosword->move(me);
        destruct(ob);
	return 1;
}