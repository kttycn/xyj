// ���

#include <ansi.h>
inherit ITEM;
int do_open(string arg);
     
string *red_object=({
	"/d/city/liwu/obj/dhhd",
	"/d/city/liwu/obj/yuyi",
	"/d/city/liwu/obj/shougao",
	"/d/city/liwu/obj/ling",
	"/d/city/liwu/obj/luckdog",
});
              
void create()
{
	set_name(HIR"���"NOR, ({"hong bao", "bao", "hong"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ú�ֽ�������ɵ�"+HIR"�����"NOR+"�ƺ�����˺��(tearoff)��\n");
		set("unit", "��");
	}
	set("is_monitored",1);
	setup();
}


void init()
{
	if(query("teared"))return;
//	set("no_give","ÿ����ֻ��һ�����㶼��ô�󷽣�\n");
	set("no_drop","��ô���Ķ�����Ҳ�ӣ���\n");
	set("no_sell","��ô�õĶ����������������\n");
	set("no_put","�뱣�ֻ����������𵽴��ҷ�ѽ��\n");
	add_action("do_open","tearoff");
}

int do_open(string arg)
{ 
	object me=this_player(),ob;
	object red=this_object();
	int rand;

	if(query("teared")) return 0;
    set("teared",1);
    set("value", "0");

    set("no_give",0);
    set("no_drop",1);
    set("no_sell",1);
    set("no_put",0);

	set("long", "һ���ú�ֽ�������ɵ�"+HIR"�����"NOR+"�Ѿ���˺���ˡ�\n");
	if(me->query("gender")=="����")
		tell_object(me,"���Ȳ������ؽ�"+HIR+"���"NOR+"˺����\n");
	else
    	tell_object(me,"��С������ؽ�"+HIR+"���"NOR+"�򿪣�\n");

	rand=random(sizeof(red_object));

	if (!ob=new(red_object[rand]))
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
	destruct(red);
	return 1;
}  
