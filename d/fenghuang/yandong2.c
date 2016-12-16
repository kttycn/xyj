inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIY"地下二号岩洞"NOR);
	set("long", @LONG
这里就是凤凰星的地下二号岩洞，这里经常有
很多怪兽出没，不过据闻怪兽身上可有好多好
东东。(dig yandong)
LONG
	);
	set("exits", ([
		"down"  : __DIR__"yandong3",
		"up"     : __DIR__"yandong1",
	]));
	setup();
	
}
void init()
{
	add_action("do_dig", "dig");
}
int do_dig(string arg)
{
	object me,obj;
	int exp;
	me = this_player();
	obj=new("/d/fenghuang/npc/guaishou");
	if (!arg || arg!="yandong") return notify_fail("你要挖什么？\n");
	if (me->query_temp("digdong2")!=1) return notify_fail("你还是先去领任务吧！\n");
	if ( me->query("kee") < 10 ) return notify_fail("你的气血不足，休息一下再来吧！\n");
	if ( me->query("combat_exp") > 500000)
		return notify_fail("你已经不需要通过杀怪兽来提高自己的战斗力了！\n");
	if ( me->is_busy()) return notify_fail("你正忙着呢！\n");
	me->add("kee", -10);
	if ( random(2)==1 )
	{
		message_vision(HIR"$N心不在焉地挖着，结果挖到自己脚上去了！\n"NOR, me);
		me->start_busy(1);
	}

	else
	{
		message_vision(HIW"$N挖开好大一块土。\n"NOR, me);
		me->add_temp("dig",1);
		if (me->query_temp("dig")>8)
		{
			me->set_temp("digdong2",0);
		    me->set_temp("dig",0);
			write("你挖开一个大洞，突然从下面钻出一头怪兽来！\n");  
			obj->move(environment(me));
			remove_call_out("destrory");
			call_out("destrory",300,obj);
			return 1;
		}
		me->start_busy(1);
	}
	return 1;
}

void destrory(object ob)
{    object me=this_player();
     me->set_temp("digdong2",0);
     me->set_temp("dig",0);       
     destruct(ob);
     return;
}
