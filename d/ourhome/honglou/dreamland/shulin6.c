
inherit ROOM;
string *names=({
	__DIR__"shulin5",
	__DIR__"shulin1",
	__DIR__"shulin6",
	__DIR__"shulin7",
} );
void create()
{
	set("short", "����");
	set("long", @LONG
����һƬï�ܵ����֣��������䣬�����������һ��������������֮����
����һ�㣬���շ��������й�֮��һ�߽�������·���ʧ�˷���
LONG
	);
	set("coor/x",2100);
	set("coor/y",-230);
	set("coor/z",-10);
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
