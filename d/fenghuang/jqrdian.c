inherit ROOM;
void create()
{
	set("short", "���Ź�˾");
	set("long", @LONG
����һ��˽�˾�Ӫ�ĵ��Ź�˾��������Ŀ��ͨѶ�豸�����ۻ����ң�
��������������Ŷ���������������Ա�ɣ�ǽ����һ������(zhaopai)��
LONG);
	set("item_desc", ([
		"zhaopai": "���� \"list\" �г������\"buy\" ���Ա���\n",
	]));
	set("exits", ([
		"south" : __DIR__"shangjie2",
//		"up" : __DIR__"youju",
	]));
	set("objects", ([
		__DIR__"npc/dianyuan": 1,
	]));
	setup();
}


