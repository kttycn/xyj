// �����硤���μ�֮�����ͣ�
 
// create by jing 2000.7.13
 
inherit ROOM;

void create ()
{
	set ("short", "����");
	set ("long", @LONG

������һ�������˱ǣ���Լ�����������̺����Ǹ��޴�Ļ��ԣ���������
�Ÿ��ָ������ʻ����������������ʻ��������������õ�ѡ���ڻ���
�ſڣ���������վ��һ��С���
LONG);

	set("exits", ([
		"south"   : __DIR__"jiedao1",
	]));
	set("objects", ([
		__DIR__"npc/maihuanv" : 1,
	]));

	setup();
}
 

