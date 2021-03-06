// Room: /d/nanhai/zhaifang
#include <room.h>
inherit ROOM;
void init ();
int do_dinner();

void create ()
{
	set ("short", "斋房");
	set ("long", @LONG

这里是普陀山门人弟子们吃饭用斋的场所，桌子上摆着一些
蔬菜水果。由于来此者大多是僧人，因此斋房只提供素席。
LONG);

	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"zoulang2",
	]));
	set("objects", ([ /* sizeof() == 4 */
		"/d/ourhome/obj/dhg" : 1,
		"/d/ourhome/obj/hulu" : 1,
		"/d/ourhome/obj/xbc" : 1,
		"/d/ourhome/obj/xqc" : 1,
	]));
	set("light_up", 1);
	set("no_fight", 1);
	set("no_magic", 1);
	set("resource", ([ /* sizeof() == 1 */
		"water" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_dinner","zuofan");
}

int do_dinner()
{
	object who = this_player();
	object where = environment(who);
	if (!who->query("make_dinner"))
		return notify_fail("这里是厨房,你在这里瞎搅和什么?\n");
	if (who->query("family/family_name")!="南海普陀山")
		return notify_fail("您来作饭，这怎么敢当呢？\n");
	if(who->is_busy())
		return notify_fail ("你正忙着呢！\n");
//        if(environment(who)->query("have_dinner"))
  //         return notify_fail("斋饭刚刚做过，不用再做了！\n");
	if((int)who->query("kee") <80)
		return notify_fail("你太累了，歇歇吧！\n");
	message_vision("只见$N手中的菜刀上下翻飞。\n", who);
	message_vision("$N不一会就切好了菜，作好了斋饭。\n", who);
	who->start_busy(7);
	message_vision("$N抹了一把汗，得意的笑了笑。厨房里四溢着饭菜的香气。\n",who);
	who->receive_damage("kee", 60);
	who->delete("make_dinner");
	tell_object(who,"你觉得在劳累之余也有所收获。\n");
	tell_object(who,"你的经验和基本内功提高了。\n");
	who->improve_skill("force",random(who->query("int")),1);
	who->add("faith",1);
	who->add("combat_exp",10);
	who->add("potential",5);
	return 1;
}
