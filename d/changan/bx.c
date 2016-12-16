//By waiwai@mszj 2000/10/26

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "野郎中医馆手术间");
	set("long", 

HIB"\n你现在正站在野郎中医馆的手术间里，全靠一把刀蒙古大夫\n"+
"正拿着一把贼亮的小刀对着你嘿嘿地阴笑着......墙上挂着\n"+
"一个小木牌子 "+HIR"(paizi)\n\n"NOR);
	set("item_desc", ([
		"paizi": HIC"请用 "+HIR"\"bianxing id\""+HIC" 来开始手术！！！ \n\n"NOR,
	]));

	set("objects", ([
		__DIR__"npc/menggu" : 1,
	]));
 
	setup();
}
void init()
{
	add_action("do_bianxing","bianxing");
}

int do_bianxing(string arg)
{
	object me,ob;
	string msg;

	me=this_player();
	ob = present(arg, environment(me));

	if (arg) {
		message_vision(HIR"$N没来得及反应,只见"+HIG"蒙古大夫"+HIR"手起刀落,"+HIW"嚓.... "+HIR"$N忍不住剧痛，惊叫了一声就晕了过去......\n\n"NOR,this_player());
		if(random(20))
		{
			if(ob->query("gender")=="女性") ob->set( "gender", "男性" );
			else ob->set( "gender", "女性" );
			msg = HIM "【谣言四起】某人：据说 "HIW+me->query("name")+"("+capitalize(ob->query("id"))+")"+
			HIM" 不惜巨资，在蒙古大夫医馆成功地做了一次比较变态的变性手术！！！\n"NOR;
		}
		else
		{
			ob->set("gender", "无性" );
			msg = HIM "【谣言四起】某人：据说 "HIW+me->query("name")+"("+capitalize(ob->query("id"))+")"+
			HIM" 在蒙古大夫医馆里做变性手术失败了！！！\n"NOR;
		}
		message("shout", msg, users());
		me->save();
		me->unconcious();
		me->move("/d/changan/bx1");

		return 1;
	}
}
