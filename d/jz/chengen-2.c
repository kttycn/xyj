//Cracked by Roath
inherit ROOM;
void create()
{
	set ("short", "�ж���");
	set ("long", @LONG

        ���С��Ҳ����һ����ʷ�ˣ�����λ��ƫԶ�������ؾ���Ҳ
���Ǻܶ࣬�����ճ���С�ǵ�ĩ�䡣����ȻԶ�Ȳ��˳����ķ�������
��ȴ�������񾲵ķ�Χ��

LONG);
	set("exits", ([
		"east" : __DIR__"chengen-1",
		"west" : __DIR__"wgate",
	]));
	set("outdoors", "jiangzhou");
	setup();
}