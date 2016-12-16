
inherit ROOM;
string *names=({
	__DIR__"shulin5",
	__DIR__"shulin7",
	__DIR__"shulin6",
	__DIR__"shulin5",
} );
void create()
{
	set("short", "树林");
	set("long", @LONG
这是一片茂密的树林，曲折深邃，好象被人设计了一种阵，有如诸葛武侯之八卦
迷阵一般，幽谜繁复处尤有过之。一走进来，你仿佛迷失了方向。
LONG
	);
	set("coor/x",2020);
	set("coor/y",-210);
	set("coor/z",0);
	setup();
}
void reset()
{
	int i,j;
	string temp;
	::reset();
	for (i=0;i<=3;i++)
	{
		j=random(4);
		temp=names[j];
		names[j]=names[i];
		names[i]=names[j];
		names[i]=temp;
	}
	set("exits", ([
		"north" : names[0],
		"south" : names[1],
		"east" : names[2],
		"west" : names[3],
	]));
}
