// /d/jz/dadian.c

inherit ROOM;

void create ()
{
	set ("short", "���");
	set("long", @LONG

���ǽ�ɽ�µĴ���Ȼ���ʧ�ޣ�����������Ժ���Եú����࣬
���պ��и߸����ϣ�Ц����ÿһ���ˡ���ǰ����һ�������䣬��
���������˵ľ�����
LONG);
	set("exits",([
		"eastdown": __DIR__"shanmen",
		"south": __DIR__"fzroom",
	]));
	set("objects",([
		__DIR__"obj/xiang" : 1,
	]));
	setup();
	replace_program(ROOM);
}
