// �����硤���μ�֮�����ͣ�
 
// create by jing 2000.7.13
 
inherit ROOM;

void create ()
{
	set ("short", "�ֵ�");
	set ("long", @LONG

һ��ƽֱ��ʯ·��·����Ȼ���Ǻܿ���������������Ҳ��һƬ���ٵľ�
��������ˮĸ����ĸ�ۡ�����߲�Զ�Ϳ��Ե�ϙ�ǵ������ģ�������
���ǵı�Ӫ��Ӫ����Լ������ս��˻����
LONG);

	set("exits", ([
		"east"   : __DIR__"jiedao1",
		"south"   : __DIR__"jiedao6",
		"west"   : __DIR__"jiedao3",
	]));
	set("objects", ([
//        __DIR__"npc/people"   : 1,
	]));
	set("outdoors", __DIR__);

	setup();
}
