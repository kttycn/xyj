// zong guan vikee.c
// created by vikee 2000.11

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIG"����"NOR, ({"zong guan", "vikee"}));
	set("long", "����רΪ��ʦ����װ�����ܹ�"HIG"����"NOR",�����(list)�鿴��Ҫ(yao xxx)�Ķ�����\n");
	set("gender", "Ů��");
	set("age", 20);
	set("per", 40);
	set("title",""MAG"װ���ܹ�"NOR);
	set_skill("literate", 141);
	setup();
	carry_object("/d/obj/cloth/female-cloth")->wear();
}

void init()
{
	::init();
	add_action("do_fight", "fight");
	add_action("do_kill", "kill");
	add_action("do_steal", "steal");
	add_action("do_cast", "cast");
	add_action("do_ji","ji");
	add_action("do_throw","throw");
	add_action("do_list","list");
	add_action("do_yao","yao");
}

int do_fight(string arg)
{
	object who = this_player();
	object me = this_object();

	if (arg && present(arg,environment(who))==me)
	{
		message_vision("$N���������ܣ���"HIG"����"NOR"���к���,����$N���֡�\n",who,me);
		return 1;
	}
	return 0;
}

int do_kill(string arg)
{
	object who = this_player();
	object me = this_object();

	if (arg && present(arg,environment(who))==me)
	{
		message_vision("$N��������ɱ��"HIG"����"NOR"����"HIG"����"NOR"���Ļ���,û��$Nһ���ʶ��\n",who,me);
		return 1;
	}
	return 0;
}

int do_cast(string arg)
{
	object who = this_player();
	object me = this_object();

	message_vision("$N����"HIG"����"NOR"���Ͱ͵����˼�������Լ����о��������ˡ�\n",who,me);
	return 1;
}

int do_steal(string arg)
{
	object who = this_player();
	object me = this_object();

	message_vision("$N��͵������������������û������\n",who,me);
	return 1;
}


int do_ji(string arg)
{
	object who = this_player();
	object me = this_object();

	message_vision("$N���"HIG"����"NOR"��������ǰ˼���룬����û�ҡ�\n",who,me);
	return 1;
}

int do_throw(string arg)
{
	object who = this_player();
	object me = this_object();

	message_vision("$N�ͳ����������˿�"HIG"����"NOR"�����Ĳ��㣬�ְѰ�������������\n",who,me);
	return 1;
}

int do_list(string arg)
{
	object who = this_player();
	object me = this_object();
	message("vision",""HIG"\n��������������������������������������������������������������������������
          \n"HIY"���ף�"HIC"
          1.��⬼�(armor)   2. ��������(pifeng) 3.����(shield)
          4.����(head)      5. �����(cloth)   6.��Ӱ��ѥ(shoes)
          7.ָ��(belt)      8. ����(dress)     9.�����ָ(ring)
          \n"HIY"������"HIC" 
          1.��ħ��(stick)   2. ���콣(sword)  3.������(whip)
          4.������(blade)   5. ����צ(zhua)   6.�����(staff)
          7.������(axe)     8. ������(fork)   9.÷����(hammer)
          10.��Ȫǹ(spear)  11.�����(qin)    12.����(archery)
          13.��װ�(mace)   14.�����(halberd)
"HIG"\n��������������������������������������������������������������������������\n"NOR"",who,me);

	return 1;
}

int do_yao(string arg)
{
	string type;
	object ob, ob1, ob2;
	object who=this_player();
	//object me=this_object();

	if (!wizardp(who))
		return notify_fail("�㲻����ʦ�������Լ�ȥ��װ����! :P\n");

    if (!arg)
		return notify_fail("����Ҫʲô�����������ǿ��ף�(����:yao sword)\n");
	else 
	{
		sscanf(arg,"%s",type);
			switch(type)
			{
			//����
			case "armor":
				ob=new("/d/obj/weapon/wizard/ruanwei.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "pifeng":
				ob=new("/d/obj/weapon/wizard/jinyipifeng.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "shield":
				ob=new("/d/obj/weapon/wizard/shield.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "shoes":
				ob=new("/d/obj/weapon/wizard/meiying_boots.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "cloth":
				ob=new("/d/obj/weapon/wizard/cloth.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "head":
				ob=new("/d/obj/weapon/wizard/cuiyu.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "belt":
				ob=new("/d/obj/weapon/wizard/seven_belt.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "dress":
				ob=new("/d/obj/weapon/wizard/green_dress.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "ring":
				ob=new("/d/obj/weapon/wizard/ring.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
				//����
			case "sword":
				ob=new("/d/obj/weapon/wizard/yitian-jian.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "whip":
				ob=new("/d/obj/weapon/wizard/whip.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "blade":
				ob=new("/d/obj/weapon/wizard/tulong-dao.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "stick":
				ob=new("/d/obj/weapon/wizard/stick.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "spear":
				ob=new("/d/obj/weapon/wizard/spear.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "fork":
				ob=new("/d/obj/weapon/wizard/fork.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "hammer":
				ob=new("/d/obj/weapon/wizard/hammer.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "qin":
				ob=new("/d/obj/weapon/wizard/qin.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "axe":
				ob=new("/d/obj/weapon/wizard/axe.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "staff":
				ob=new("/d/obj/weapon/wizard/staff.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "zhua":
				ob=new("/d/obj/weapon/wizard/zhua.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "mace":
				ob=new("/d/obj/weapon/wizard/goldjian.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "halberd":
				ob=new("/d/obj/weapon/wizard/tianlong.c");
				ob->move(who);
				tell_object(who,HIG"����"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "arrow":
				ob1=new("/d/obj/weapon/archery/qiankun-bow.c");
				ob2=new("/d/obj/weapon/archery/zhentian-arrow.c");
				ob1->move(who);
				ob2->move(who);
				tell_object(who,HIG"����"NOR"��"+ob1->query("name")+"��"+
				ob2->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			default:
				tell_object(who,HIG"����"NOR"˵��������û��"+type+",����Ҫ���������ˣ����Ҿ����ˡ�\n");
				break;
			}
	}
	return 1;
}
