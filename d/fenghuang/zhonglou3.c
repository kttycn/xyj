// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	set("short", "��¥����");
	set("long", @LONG
�����������������ת����Ϊ����ǽ��֮�϶����˸�СС��������ǰ
�������ͬ��ǽ�ϱڻ��������䣬���������������»��ƣ���������
�������֡�
LONG
	);
	set("exits", ([ 
		"up" : __DIR__"zhonglou4",
		"down" : __DIR__"zhonglou2",
	]));
	setup();
	replace_program(ROOM);
}
