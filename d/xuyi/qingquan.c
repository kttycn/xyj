// �����硤���μ�֮�����ͣ�
 
// create by night 2000.7.25

inherit ROOM;

void create ()
{
	set ("short", "���");
	set ("long", @LONG

�������������ܵ��������е��徻���������Ȼ����Ȫ����԰�ֹ�������
���£������˲ʡ�������Ϻ��浹Ҳ���˲��٣������ļ��紺�������£�
�ɻ�˯���ޱ���次�
LONG);

	set("exits", ([
		"west"   : __DIR__"jiedao8",     
	]));
	set("objects", ([
		__DIR__"npc/girl"   : 2,
	]));
	set("outdoors", __DIR__);

	setup();
}

