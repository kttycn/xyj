// Room: /d/nanhai/zhaifang
#include <room.h>
inherit ROOM;
void init ();
int do_dinner();

void create ()
{
	set ("short", "ի��");
	set ("long", @LONG

����������ɽ���˵����ǳԷ���ի�ĳ����������ϰ���һЩ
�߲�ˮ�������������ߴ����ɮ�ˣ����ի��ֻ�ṩ��ϯ��
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
		return notify_fail("�����ǳ���,��������Ϲ����ʲô?\n");
	if (who->query("family/family_name")!="�Ϻ�����ɽ")
		return notify_fail("��������������ô�ҵ��أ�\n");
	if(who->is_busy())
		return notify_fail ("����æ���أ�\n");
//        if(environment(who)->query("have_dinner"))
  //         return notify_fail("ի���ո����������������ˣ�\n");
	if((int)who->query("kee") <80)
		return notify_fail("��̫���ˣ�ЪЪ�ɣ�\n");
	message_vision("ֻ��$N���еĲ˵����·��ɡ�\n", who);
	message_vision("$N��һ����к��˲ˣ�������ի����\n", who);
	who->start_busy(7);
	message_vision("$NĨ��һ�Ѻ��������Ц��Ц�������������ŷ��˵�������\n",who);
	who->receive_damage("kee", 60);
	who->delete("make_dinner");
	tell_object(who,"�����������֮��Ҳ�����ջ�\n");
	tell_object(who,"��ľ���ͻ����ڹ�����ˡ�\n");
	who->improve_skill("force",random(who->query("int")),1);
	who->add("faith",1);
	who->add("combat_exp",10);
	who->add("potential",5);
	return 1;
}
