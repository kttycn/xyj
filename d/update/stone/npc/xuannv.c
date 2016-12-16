// zong guan vikee.c
// created by vikee 2000.11

#include <ansi.h>

inherit NPC;

void create()
{
         set_name(HIG"������Ů"NOR, ({"jiutian xuannv", "xuannv"}));
	set("long", "����רΪ��ʦ���͸��ֲ�Ʒ��ƷҩƷ���ܹ�"HIG"������Ů"NOR",�����(list)�鿴��Ҫ(yao xxx)�Ķ�����\n");
	set("nickname", CYN"�������"CYN);
	set("gender", "Ů��");
	set("age", 20);
	set("per", 50);
	set("title",""MAG"��Ʒ����Ʒ�ܹ�"NOR);
	set("chat_chance",20);
    set("chat_msg", ({
        HIG"������Ů"NOR"���������㣺�������"HIG"list"NOR"ָ���г���Ҫ�Ķ�����\n",
        HIG"������Ů"NOR"���������㣺�������"HIG"yao xxx"NOR"ָ��������ȡ��Ʒ����Ʒ��\n",
        HIG"������Ů"NOR"��������˵���Ҿ��������ʯͷ��ʦ���ܹܣ��ܹܾ����ң�\n",         
        }));
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
	message("vision",""HIY"\n��������������������������������������������������������������������������
          \n"HIY"��Ʒ��"HIG"
          1.������(gan)             2.�������(zhuguo)     3.�˲ι�(guo)
          4.����(li)                5.����(zao)            6.��֥��(lingzhi)
          7.��ź(ou)                8.⨺���(tao)          9.�ɾ�(jiu)
         10.������(lengxiang)      11.����(xiantao)       12.�±�(yuebing)
          \n"HIY"��Ʒ��"HIG"
          1.������(wan)             2.ϴ�赤(dan)          3.������֥(zhi)
          4.�ɵ�(xiandan)           5.���Ǻ�«(hulu)       6.������(huanyang)
          7.�󻹵�(huandan)         8.������(ling)         9.�ָ�(shougao)
         10.����(yuyi)             11.�����ڵ�(neidan)    12.����(nang)
         13.����(gaozhi)           14.���͹�(dog)         15.С����(xiaodan)
          \n"HIY"ҩƷ��"HIG" 
          1.���Ǿ�(hugu)            2.������¶(hua)        3.�߱����׵�(meirandan)
          4.����ͨ����(tongmai)     5.�����Ѫ��(huojin)   6.�޳���(wuchangdan)
          7.����������(baoming)     8.������(liushen)      9.���ŷ��赤(sancai)
         10.�˲�������(zaizao)     11.���������(duomei)  12.���Ľⶾ��(qingxin)
         13.�������Ӹ�(sanhua)       
"HIY"\n��������������������������������������������������������������������������\n"NOR"",who,me);

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
		return notify_fail("����Ҫʲô����Ʒ����Ʒ��ҩƷ��(����:yao gan)\n");
	else 
	{
		sscanf(arg,"%s",type);
			switch(type)
			{
			//��Ʒ
			case "gan":
				ob=new("/d/fenghuang/obj/huolonggan.c");
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
			case "yuebing":
				ob=new("/d/city/obj/yuebing.c");
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
			case "ling":
				ob=new("/d/city/liwu/obj/ling.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "shougao":
				ob=new("/d/city/liwu/obj/shougao.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "yuyi":
				ob=new("/d/city/liwu/obj/yuyi.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "neidan":
				ob=new("/d/city/liwu/obj/neidan.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "xiandan":
				ob=new("/d/obj/story/xiandan.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "huanyang":
				ob=new("/d/update/stone/obj/huanyang.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "hulu":
				ob=new("/d/obj/story/bingtang.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "huandan":
				ob=new("/d/city/liwu/obj/dhhd.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "nang":
				ob=new("/d/city/liwu/obj/jinnang.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "gaozhi":
				ob=new("/d/city/liwu/obj/gaozhi.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;	
			case "dog":
				ob=new("/d/city/liwu/obj/luckdog.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;	
			case "xiaodan":
				ob=new("/d/city/liwu/obj/xhhd.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;	
/*			case "arrow":
				ob1=new("/d/obj/weapon/archery/qiankun-bow.c");
				ob2=new("/d/obj/weapon/archery/zhentian-arrow.c");
				ob1->move(who);
				ob2->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob1->query("name")+"��"+
				ob2->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;*/
			//ҩƷ
			case "hugu":
				ob=new("/d/obj/medicine/hugu.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "hua":
				ob=new("/d/obj/medicine/jyhua.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "meirandan":
				ob=new("/d/obj/medicine/qibao.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "tongmai":
				ob=new("/d/obj/medicine/tongmai.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "huojin":
				ob=new("/d/obj/medicine/huojin.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "wuchangdan":
				ob=new("/d/obj/medicine/wuchang.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "baoming":
				ob=new("/d/obj/medicine/baoming.c.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "liushen":
				ob=new("/d/obj/medicine/liushen.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "sancai":
				ob=new("/d/obj/medicine/sancai.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "zaizao":
				ob=new("/d/obj/medicine/zaizao.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "duomei":
				ob=new("/d/obj/medicine/hpdm.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "qingxin":
				ob=new("/d/obj/medicine/qingxin.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "sanhua":
				ob=new("/d/obj/medicine/sanhua.c");
				ob->move(who);
				tell_object(who,HIG"������Ů"NOR"��"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			default:
				tell_object(who,HIG"������Ů"NOR"˵��������û��"+type+",����Ҫ���������ˣ����Ҿ����ˡ�\n");
				break;
			}
	}
	return 1;
}
