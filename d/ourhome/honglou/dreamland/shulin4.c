
inherit ROOM;
string *names=({
	__DIR__"shulin6",
	__DIR__"shulin2",
	__DIR__"shulin",
	__DIR__"shulin1",
} );
void create()
{
	set("short", "����");
	set("long", @LONG
����һƬï�ܵ����֣��������䣬�����������һ��������������֮����
����һ�㣬���շ��������й�֮��һ�߽�������·���ʧ�˷���
LONG
	);
	setup();
}

int valid_leave(object me,string dir)
{
	if (userp(me) && query("exits/"+dir)==__DIR__"shulin")
		me->set_temp("shulin",1); 
    return 1;
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
 
