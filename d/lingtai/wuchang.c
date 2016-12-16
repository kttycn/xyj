// Room: /d/lingtai/wuchang.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是方寸山三星洞的练武场。由无数块巨大的花岗岩石板铺就。
上千年的踩踏已使得这些石板如同镜子般平整光滑。西边角上还
有两个大沙坑，十来个道士正在练习武艺。东西两面各是一间静
室。
LONG );
	set("exits", ([
		"down" : __DIR__"jingtang",
		"east" : __DIR__"xiuwu",
		"west" : __DIR__"yangxin",
	]));

	setup();
}

