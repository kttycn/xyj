// Room: /d/welcome/newbie3
inherit ROOM;

void create ()
{
	set ("short", "����֮·");
	set ("long", @LONG
�뿪����֮·����ᵽ����Ϸ�еĵ�һվ��Ҳ���ǳ����ǣ��ڳ�
�������Ҳ����������Ŀ�ջ����������ЩǮ��Ҳ���Ե��������ѧ
��������似���ˣ����ǻ�Ϊ����׼����һЩװ���ˣ����˿�ջ��
west,north,down��Ȼ��list���Ϳ����г����п��Ը����װ������
Ҫ��ס����Щ�����ɲ�����Ӵ��������ף����̤������֮·�ɣ�
LONG);

	set("exits", ([ /* sizeof() == 1 */
		"down" : "/d/city/kezhan",
	]));
	set("no_magic", 1);
	set("no_beg",1);
	set("pingan",1);
	set("no_fight", 1);

	setup();
}
int valid_leave(object me, string dir)
{
	if (dir =="down")
	{
		me->set("startroom","/d/city/kezhan");
		me->save();
	}
	return ::valid_leave(me, dir);
}
