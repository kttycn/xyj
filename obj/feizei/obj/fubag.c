//package ����
// stone 20020415 

#include <ansi.h>
inherit ITEM;
int do_open(string arg);
     
string *package_object=({
	"/obj/feizei/obj/shendan.c",
	"/obj/feizei/obj/xuelianzhi.c",
	"/obj/feizei/obj/putiguo.c",
	"/obj/feizei/obj/lingzhi.c",
	"/obj/feizei/obj/honey.c",
	"/obj/feizei/obj/deergao.c",

});
              
void create()
{
	set_name(WHT"����"NOR, ({"bao guo", "bao", "package"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����ɫ��ֽ������ͮͮ�Ĵ�����һ���������֡���֪��������ʲô�ö�����"+HIR"����"NOR+"�ƺ�������һ����(mo)��\n");
		set("unit", "��");
	}
	set("is_monitored",1);
	setup();
}


void init()
{
//	if(query("teared"))return;
	set("no_give","��������в�֪����ʲô���㲻��֪��������ʲô�ö�����\n");
	set("no_drop","�ȴ�������������Ҳ���ٰ���\n");
	set("no_sell","��֪��������ʲô��������ֵ�������Ӱ���\n");
	set("no_put","�뱣�ֻ����������𵽴��ҷ�ѽ��Υ�߷��\n");
	set("no_get","���ΰɣ��ٺٺ٣���\n");
	add_action("do_open","mo");
}

int do_open(string arg)
{ 
	object me=this_player(),ob;
	object package=this_object();
	int rand;

//	if(query("teared")) return 0;
//	set("teared",1);
    	set("value", "0");
    	set("no_give",0);
    	set("no_drop",1);
    	set("no_sell",1);
    	set("no_put",0);
	set("no_get",0);
	set("long", "һ���ûҲ����ŵĸ�����"+WHT"������"NOR+"�Ѿ���˺���ˡ�\n");
	if(me->query("gender")=="����")
		tell_object(me,"�����ſ�ˮ��һ�½�"+WHT+"����"NOR+"������\n");
	else
    	tell_object(me,"��С�ĵؽ�"+WHT+"����"NOR+"�򿪣�\n");


	rand=random(sizeof(package_object));
//	set_name(names[random(sizeof(names))], ({"pi pa"}));

	if (!ob=new(package_object[rand]))
	{
		tell_object(me,"���ʲôҲû�С�\n"NOR);
		return 1;
	}
	tell_object(me,"�㷢����һ"+ob->query("unit")+ob->query("name")+"��\n"NOR);
	if(ob->query("id")=="haba gou")
	{
		ob->set("boss_id",me->query("id"));
		ob->set("name",me->name(1)+"�Ĺ��͹�");
		ob->set("mud_age",200000);
		ob->set("gender","����");
		ob->set_leader(me);
		ob->move(environment(me));
	}
	else ob->move(me);
	destruct(package);
	return 1;
}  
