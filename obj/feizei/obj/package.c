//package 包裹
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
	set_name(WHT"包裹"NOR, ({"bao guo", "bao", "package"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个小包裹，用整块灰布包得严严实实，不知道里面是什么好东西？"+WHT"包裹"NOR+"似乎可以撕开(ripoff)。\n");
		set("unit", "个");
	}
	set("is_monitored",1);
	setup();
}


void init()
{
//	if(query("teared"))return;
	set("no_give","这个灰布包裹中不知道是什么，你不想知道里面是什么好东西吗？\n");
	set("no_drop","先打开来看看，再扔也不迟啊！\n");
	set("no_sell","不知道里面是什么东西，能值多少银子啊？\n");
	set("no_put","请保持环境卫生，别到处乱放呀，违者罚款！\n");
	add_action("do_open","ripoff");
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

	set("long", "一个用灰布包着的包裹，"+WHT"包裹，"NOR+"已经被撕开了。\n");
	if(me->query("gender")=="男性")
		tell_object(me,"你急不可耐，一下将"+WHT+"包裹"NOR+"扯开。\n");
	else
    	tell_object(me,"你小心翼翼地将"+WHT+"包裹"NOR+"打开，\n");


	rand=random(sizeof(package_object));
//	set_name(names[random(sizeof(names))], ({"pi pa"}));

	if (!ob=new(package_object[rand]))
	{
		tell_object(me,"结果什么也没有。\n"NOR);
		return 1;
	}
	tell_object(me,"你发现有一"+ob->query("unit")+ob->query("name")+"。\n"NOR);
	if(ob->query("id")=="haba gou")
	{
		ob->set("boss_id",me->query("id"));
		ob->set("name",me->name(1)+"的哈巴狗");
		ob->set("mud_age",200000);
		ob->set("gender","雄性");
		ob->set_leader(me);
		ob->move(environment(me));
	}
	else ob->move(me);
	destruct(package);
	return 1;
}  
