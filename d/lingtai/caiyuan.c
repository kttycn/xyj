// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: some place in ��ţ����
// houyuan.c

inherit ROOM;

void create()
{
	set("short", "��԰");
	set ("long", @LONG

����ɽ������ࡣΪ�˸�������������������ں�԰������һ��Ƭ
�˵أ���ֲ���ָ������߲˺�ˮ����
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"southwest": __DIR__"houyuan",
	]));
	set("no_clean_up", 0);
	set("outdoors", 1);
	setup();
}

