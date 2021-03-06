// changan wusheng
// room1.c

inherit ROOM;
#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create()
{
	set ("short", "武圣大殿");
	set ("long", @LONG

孔武大帝之圣殿，四处飘渺着从八个盘龙大鼎中升出的紫烟。仔
细看看该八个大鼎，乃远古之物，鼎中溢出的丝丝紫烟，烟中带
香，整个大殿各种香气飘逸，无不令人心旷神怡。八个鼎中还泛
着八种幽光，使整个大殿不用任何火光也日夜通明。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"northwest": __DIR__"room4",
		"north": __DIR__"shijie5",
		"northeast": __DIR__"room5",
		"west": __DIR__"room3",
		"east": __DIR__"room2",
		"south": __DIR__"guangchang",
	]));
	set("objects", ([
		"/d/wusheng/obj/danlu": 1,
		"/d/wusheng/npc/zhangmen": 1,]));
	set("no_clean_up", 0);
	set("outdoors", "wusheng");
	setup();
}
void init()
{
	object who=this_player();
	object where=this_object();
	if( (string)who->query("family/family_name")=="武圣门" ) {
		call_out("heal_up", 9, who);
	}
	remove_call_out("sounding");
	call_out("sounding", random(10), this_object());
	remove_call_out("check_time");
	check_time(where);
	add_action("do_hear","hear");
}
int sounding(object where)
{
    string *msgs=({
    "八个大鼎中同时飘出一阵紫烟。\n",
    "八个大鼎中的灵光同时闪了几闪。\n",
    "紫烟灵光混合后在大殿中轻舞飞扬。\n",
    "飞舞的光烟化做一条神龙。\n",
  });
  tell_room (where,msgs[random(sizeof(msgs))]);
}

int heal_up(object who)
{
        if( !who || environment(who) != this_object() ){
		 return 1;
	}
/*
	if( (int)who->query("max_sen")==(int)who->query("eff_sen")
	&& 	(int)who->query("max_kee")==(int)who->query("max_kee") ){
		return 1;
	}
	
*/
        who->set("eff_gin", (int)who->query("max_gin"));
        who->set("eff_kee", (int)who->query("max_kee"));
        who->set("eff_sen", (int)who->query("max_sen"));

        message_vision("阵阵紫烟飘向$N，$N深深吸了几口气。\n", who);
        write("你觉得自己的精神气血一下子都恢复了。\n");

	if( (int)who->query("food") < (int)who->max_food_capacity() )
		who->set("food", (int)who->max_food_capacity());
	if( (int)who->query("water")< (int)who->max_water_capacity())
		who->set("water", (int)who->max_water_capacity());


        return 1;
}
void check_time(object where)
{
	mixed *local = localtime(time()-900000000);
	int t = local[2] * 60 + local[1];

	int phase=((int)(t%120));
	if(phase==31&&(!query("wusheng/start_jiangjing"))) jiang_jing(where);
	if(phase==34&&query("wusheng/start_jiangjing")) finish_jing(where);
	call_out("check_time",40,where);
}

void jiang_jing(object where)
{
	message("channel:es",HIY+"【圣火洞武圣门】孔武大帝(Master dadi)：现在开讲天下武技，各位弟子到大殿听讲。\n"+NOR,users());
	tell_object(where,"你听到孔武大帝的声音：道生之，德畜之，物形之，势成之。\n");
	tell_object(where,"你听到孔武大帝的声音：是以万物莫不尊道而贵德。\n");
	tell_object(where,"你听到孔武大帝的声音：道之尊，德之贵，夫莫之命而常自然。\n");
	tell_object(where,"你听到孔武大帝的声音：故道生之，德畜之；长之育之；成之熟之；养之覆之。生而不有，为而不恃，长而不宰。是谓玄德。\n");
	tell_object(where,"........................................\n");
	set("wusheng/start_jiangjing",1);
}
void finish_jing(object where)
{
	tell_object(where,"孔武大帝说道：大家休息吧。\n");
	set("wusheng/start_jiangjing",0);
}
int do_hear()
{
	object yao;
	object me=this_player();

	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if(!query("wusheng/start_jiangjing"))
		return notify_fail("孔武大帝还没有开始传授先天乾坤功。\n");

	if((string)me->query("family/family_name")!="武圣门")
		return notify_fail("外派弟子不得来听讲。\n");
	if(me->query("faith")>800)
		return notify_fail("孔武大帝对你说道：你可以去找些其它的事情做了。\n");
	tell_object(me,"你不禁被孔武大帝的武技修为深深吸引了。\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("xiantian-force",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"你觉得你的先天乾坤功进步了！\n");
	return 1;
}
