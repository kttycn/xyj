// Room: /changan/nanchengkou.c
//cglaem...12/12/96.
//fei modify 2001.3

inherit ROOM;

void create ()
{
	set ("short", "�ϳǿ�");
	set ("long", @LONG

�����ǳ������ϳǿڡ�������ȥ�ѿɿ����ϳ������ﲻ������������
�������Ĺٱ�����ȥһ�Ÿ߿���ˮ������ʴ�����ɽ´�����غ����
����Ұ�������˲���̾�ⳤ���ǵش��������֮��壬����������֮
����
LONG);

	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"jiaowai2",
		"south" : __DIR__"nbridge",
		"north" : "/d/city/zhuque-s4",
		"east" : __DIR__"jiaowai1",
]));
        set("objects", 
        ([ //sizeof() == 1
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
        ]));


  set("outdoors", "changan-south");

  setup();
}






