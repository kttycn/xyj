// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
	set ("short", "���Ĺ㳡");
	set ("long", @LONG

�������ϙ�ǵ����ģ���ɫʯ���̳ɵĴ�����ķ����ӡ��㳡�����Σ�һ
ȦΧ�Ķ���С�������ˣ��Ϳ����ֵ��ˡ�������������Ⱥ��Ҳ�ٲ��˼���
�ܽ���֮�ˣ��ܶ�����������ڴ���������δ�ŵġ�
LONG);

	set("objects", ([ /* sizeof() == 1 */

	]));
	set("outdoors", 1);

	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"lukou",
		"north" : __DIR__"yujie",
		"east" : __DIR__"jiedao4",
		"west" : __DIR__"jiedao1",
	]));

	setup();
}


