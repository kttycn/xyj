// zong guan vikee.c
// created by vikee 2000.11

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIG"������Ů"NOR, ({"zong guan", "vikee"}));
	set("long", "����רΪ��ʦ���͸��ֲ�Ʒ����Ʒ���ܹ�"HIG"������Ů"NOR",�����(list)�鿴��Ҫ(yao xxx)�Ķ�����\n");
	set("gender", "Ů��");
	set("age", 20);
	set("per", 40);
	set("title",""MAG"��Ʒ����Ʒ�ܹ�"NOR);
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
		message_vision("$N���������ܣ���"HIG"������Ů"NOR"���к���,����$N���֡�\n",who,me);
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
		message_vision("$N��������ɱ��"HIG"������Ů"NOR"����"HIG"������Ů"NOR"���Ļ���,û��$Nһ���ʶ��\n",who,me);
		return 1;
	}
	return 0;
}

int do_cast(string arg)
{
	object who = this_player();
	object me = this_object();

	message_vision("$N����"HIG"������Ů"NOR"���Ͱ͵����˼�������Լ����о��������ˡ�\n",who,me);
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

	message_vision("$N���"HIG"������Ů"NOR"��������ǰ˼���룬����û�ҡ�\n",who,me);
	return 1;
}

int do_throw(string arg)
{
	object who = this_player();
	object me = this_object();

	message_vision("$N�ͳ����������˿�"HIG"������Ů"NOR"�����Ĳ��㣬�ְѰ�������������\n",who,me);
	return 1;
}

int do_list(string arg)
{
	object who = this_player();
	object me = this_object();
	message("vision",""HIG"\n��������������������������������������������������������������������������
          \n"HIY"��Ʒ��"HIC"
          1.������(gan)         2.�������(zhuguo)     3.�˲ι�(guo)
          4.����(li)            5.����(zao)            6.��֥��(lingzhi)
          7.��ź(ou)            8.⨺���(tao)          9.�ɾ�(jiu)
         10.������(lengxiang)  11.����(xiantao)
          \n"HIY"��Ʒ��"HIC" 
          1.������(wan)         2. ϴ�赤(dan)         3.������֥(zhi)
          4.�ɵ�(xiandan)       5. ���Ǻ�«(hulu)      6.�����(staff)
          7.������(axe)         8. ������(fork)        9.÷����(hammer)
         10.��Ȫǹ(spear)      11.�����(qin)         12.����(archery)
         13.��װ�(mace)       14.�����(halberd)
"HIG"\n��������������������������������������������������������������������������\n"NOR"",who,me);

	return 1;
}

int do_yao(string arg)
{
	string type;
	object ob, ob1, ob2;
	object who=this_player();
	object me=this_object();

	if (!wizardp(who))
		return notify_fail("�㲻����ʦ�������Լ�ȥ��취��! :P\n");

    if (!arg)
		return notify_fail("����Ҫʲô����Ʒ����Ʒ��(����:yao gan)\n");
	else 
	{
		sscanf(arg,"%s",type);
			switch(type)
			{
			//��Ʒ
			case "gan":
				ob=new("/d/fenghuang/obj/huologgan.c.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "zhuguo":
				ob=new("/d/fenghuang/obj/xiandan.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "guo":
				ob=new("/d/obj/drug/renshen-guo.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "lingzhi":
				ob=new("/d/xuyi/obj/lingzhi.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "zao":
				ob=new("/d/obj/drug/huozao.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "li":
				ob=new("/d/obj/drug/jiaoli.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "ou":
				ob=new("/d/obj/drug/biou.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "tao":
				ob=new("/d/obj/drug/mihoutao.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "jiu":
				ob=new("/d/obj/drug/xianjiu.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "lengxiang":
				ob=new("/d/obj/drug/lengxiangwan.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;	
			case "jiu":
				ob=new("/d/obj/drug/xianjiu.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "xiantao":
				ob=new("/d/obj/drug/xiantao.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;		
				//��Ʒ
			case "dan":
				ob=new("/d/obj/story/xisuidan.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "zhi":
				ob=new("/d/obj/story/lingzhi.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "xiandan":
				ob=new("/d/obj/story/xiandan.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "wan":
				ob=new("/d/obj/story/shenliwan.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "spear":
				ob=new("/d/obj/weapon/wizard/spear.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "fork":
				ob=new("/d/obj/weapon/wizard/fork.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "hammer":
				ob=new("/d/obj/weapon/wizard/hammer.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "qin":
				ob=new("/d/obj/weapon/wizard/qin.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "xiandan":
				ob=new("/d/obj/story/xiandan.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "staff":
				ob=new("/d/obj/weapon/wizard/staff.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "hulu":
				ob=new("/d/obj/story/bingtang.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "mace":
				ob=new("/d/obj/weapon/wizard/goldjian.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "halberd":
				ob=new("/d/obj/weapon/wizard/tianlong.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "arrow":
				ob1=new("/d/obj/weapon/archery/qiankun-bow.c");
				ob2=new("/d/obj/weapon/archery/zhentian-arrow.c");
				ob1->move(who);
				ob2->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob1->query("name")+"��"+
				ob2->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			default:
				tell_object(who,HIG"������Ů"NOR"˵��������û��"+type+",����Ҫ���������ˣ����Ҿ����ˡ�\n");
				break;
			}
	}
	return 1;
}
