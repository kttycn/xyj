inherit ROOM;

void create()
{
	set("short", "��¥һ��");
	set("long", @LONG
����һ��שľ�ṹ�ı����������߲㣬�������˽��Σ�����
���ᣬ�ܽ��Ϲ�����һ����Сͭ�壬��綣�����졣����ǽ����
�յ����������˳������ǵ��¼���һ������̬άФ����������
����֮�֡�
LONG );
	set("exits", ([
		"west" : __DIR__"xiaoxue",
		"up" : __DIR__"zhonglou2",
	]));
	set("objects",([
		__DIR__"npc/bing" : 2,
	]));
//      set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

