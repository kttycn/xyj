inherit ROOM;
void create()
{
	set("short", "�ڸ����");
	set("long", @LONG
����һ���ð����̳ɵĴ�����ɼ����������ݳޣ��������վ��
ʿ��������ɭ�ϣ�һ�����ǲ�������������ģ�����������ɱ
���⣬������Ƿ�˳ǵ�ƽ����֮ɫ���������ۡ�ˣ���Խ��Խ
�ĺ��ˣ����ɵ����ȥ�������������Ŀ����书����������ǰ�߬�
�Ѿ������Ŀ����������Ĵ����ˡ�
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
	    "north" : __DIR__"gate",
	    "south" : __DIR__"bjie2",
	]));
	set("objects", ([
		__DIR__"npc/weishi" : 4,
		__DIR__"npc/weishi1" : 2,
	]));
//      set("no_clean_up", 0);
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}


