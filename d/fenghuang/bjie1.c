inherit ROOM;
void create()
{
	set("short", "�ڸ����");
	set("long", @LONG
����һ���ð����̳ɵĴ�����ɼ����������ݳޣ��������վ��
ʿ��������ɭ�ϣ�һ�����ǲ�������������ģ�����������ɱ
���⣬������Ƿ�˳ǵ�ƽ����֮ɫ���������ۡ�ˣ���
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
		"north" : __DIR__"bjie2",
		"south" : __DIR__"zhongxin",
	]));
	set("objects", ([
		__DIR__"npc/weishi" : 4,
	]));
//      set("no_clean_up", 0);
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}

