// By canoe 2001.03.25
#include <ansi.h>
inherit ROOM;
void create ()
{
	set ("short", "��̨");
	set ("long", @LONG

��̨ʮ���徲����ǰһ����ԫ����ǧ�ٴ�����ӳ��ǽ�º���һ϶����Ȫһ
�ɣ���������������ǽ�ڣ��ƽ�Ե����ǰԺ���������¶������м���һ
��ľ������ֻСľ�ʣ����ϰ���һ����¯(xianglu)��
LONG);

	set("item_desc", ([ /* sizeof() == 1 */
		"xianglu" : "�����ͨ��fen xiang����������ĸ���֡�
	",
	]));
	set("exits", ([ /* sizeof() == 1 */
		"down" : "/d/moon/nroom",
	]));

	setup();
}

void init() {
	add_action("do_start",({"fen"}));
}
int do_start(string arg) {
	object me=this_player();
	object wangmu;

	if (!arg || arg!="xiang") return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("( ����һ��������û����ɡ�)\n");
//	if (me->query("weiwang")<200)
//		return notify_fail("�������������û�˻����㣡\n");
	if(!me->query_temp("ask_niulang")) return notify_fail("��û��������ĸ���ָ�ʲô��\n");  
	if (me->query("obstacle/niulang")=="done")
		return notify_fail("���Ѿ��������ĸ�˰ɡ�\n");
	message_vision(CYN"$N���ĳ���ط��㵻�棬��������ĸ�ĳ��� !\n"NOR,me);
	me->start_busy(3);
	me->add_temp("xwm_fx",1);
	if (me->query_temp("xwm_fx")==3) {
		message_vision(HIY"һ�����Ϯ��������ĸ������$N����ǰ!\n"NOR,me);
		wangmu=new("/d/niulang/npc/xiwangmu");
		wangmu->move(environment(me));
		wangmu->set("target",me);
		me->delete_temp("xwm_fx");
		return 1;
	}
	else message_vision(CYN"��ϧûʲô����������$N�ĳ��ⲻ����������\n"NOR,me);
	return 1;
}
