//seal.c
//stone amend

#include <ansi.h>
 
inherit ITEM;
 
void create()
{
        set_name(YEL"抓鬼符"NOR, ({"ghost seal", "seal", "paper"}));
        set_weight(100);
        if(clonep())
                set_default_object(__FILE__);
        else {

        set("long","一张画上了符咒的桃符黄纸。\n");
        set("unit", "张");
        set("value", 0);
        set("no_put",1);
        set("no_sell",1);
        }
        setup();
}

string long()
{
        if(query("finished"))
                return "一张由钟馗写了几道符咒的桃符黄纸。\n"+
                "已经有一只鬼被符咒给制住了。\n";
        if(stringp(query("desc")))
                return "一张由钟馗写了几道符咒的桃符黄纸。可以(burn)来抓鬼。\n"+
                "只见上面画着：\n"+
                query("desc");
}

void init()
{
        add_action("do_burn", "burn");
        	if( (int)this_object()->query("created") != 1 )
	{
		this_object()->set("created", 1);
		remove_call_out ("destroy_seal");
		call_out ("destroy_seal", 900);//15 mins

	}
}

int do_burn(string arg)
{
        object room, me;
        string name;
        
        if(!arg||!id(arg))
                return notify_fail("你要烧什么？\n");
        me=this_player();
        
        if(query("finished"))
                return notify_fail("上面已经有一只鬼了，快回去交给钟馗吧。\n");
        if(!query("master")||query("master")!=me)
        {
                message_vision(RED"$N大喊一声“妖魔鬼怪快现身”，手一挥，祭出了一张抓鬼灵符。。。\n\n"NOR, me);
                message_vision("结果什么都没有发生。\n", me);
                destruct(this_object());
                return 1;
        }
        
        room=environment(me);
        message_vision(RED"$N大喊一声“妖魔鬼怪快现身”，手一挥，祭出了一张抓鬼灵符。。。\n\n"NOR, me);
        if(file_name(room)+".c"!=query("file_name"))
        {
                message_vision("结果什么都没有发生。\n", me);
                destruct(this_object());
                return 1;
        }
        name=({ "大头", "青面", "独角", "赤发"})[random(4)];

        message_vision(HIB"只见一道亮光闪过，"+name+"鬼已经被抓鬼灵符给制住。\n"NOR, me);
        set("finished", 1);
        return 1;
}

void destroy_seal()
{
	object seal1 = this_object();
  	object who = environment(seal1);
  	object sealpaper;
	message_vision("一阵风吹来，" + (string)this_object()->query("name") + "的符咒渐渐隐去，只留下一张黄纸留在$N手中。\n", environment(this_object()));
	sealpaper = new (__DIR__"sealpaper");
        sealpaper->move(who);
        destruct(seal1);
}

