// ��Ʒ��

#include <ansi.h>
inherit ITEM;
int do_open(string arg);
     
string *red_object=({
	"/d/city/liwu/obj/xhhd",
	"/d/city/liwu/obj/neidan",
	"/d/city/liwu/obj/gaozhi",
	"/d/city/liwu/obj/luckdog",
});

void create()
{
	set_name(HIR"��Ʒ��"NOR, ({"happy box", "box"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����µ�"+HIR"��Ʒ�У�"NOR+"�ƺ����Դ�(tearoff)��\n");
		set("unit", "��");
		set("value", "10000");
	}
	set("is_monitored",1);
}


void init()
{
	if(query("teared"))return;
	set("no_give","ÿ����ֻ��һ�����㶼��ô�󷽣�\n");
	set("no_get","ÿ����ֻ��һ������Ҫ��ô̰�ģ�\n");
	set("no_sell","��ô�õĶ����������������\n");
	set("no_drop","��ô���Ķ�����Ҳ�ӣ���\n");
	add_action("do_open","tearoff");
}

int do_open(string arg)
{ 
	object me=this_player(),ob;
	object box=this_object();
	int rand;

    if(query("teared"))              
         return 0;
    set("teared",1);
    set("value", "100");

    set("no_give",0);
    set("no_drop",1);
    set("no_sell",1);
    set("no_put",0);

    set("long", "һ�����µ�"+HIR"��Ʒ�У�"NOR+"�Ѿ������ˡ�\n");
	if(me->query("gender")=="����")
		tell_object(me,"���Ȳ������ؽ�"+HIR+"��Ʒ��"NOR+"�򿪣�\n");
	else
		tell_object(me,"��С������ؽ�"+HIR+"��Ʒ��"NOR+"�򿪣�\n");

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
	destruct(box);
	return 1;
}
