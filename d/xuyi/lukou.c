// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
	set ("short", "ʮ��·��");
	set ("long", @LONG

����ϙ���ڵ���Ҫ��ó����������ɫɫ�Ľ������ڶ��ߴ���˷������಻
����·�ϳ�ˮ��������ɫ����Ħ����࣬���ַǷ�������ƫ���Ϸ�һ�磬
���ױ�֮�����쳯���в�ͬ��Ȼ������紾�ӣ����й�֮��
LONG);

	set("objects", ([ /* sizeof() == 1 */
	]));
	set("outdoors", __DIR__);

	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"jiedao0",
		"north" : __DIR__"center",
		"west" : __DIR__"jiedao5",
		"east" : __DIR__"jiedao7",
	]));

	setup();
}
