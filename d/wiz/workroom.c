//By waiwai@mszj  2000/11/17

#include <ansi.h>

inherit ROOM;

void create ()
{
	set ("short", "����Ա������");
	set ("long", @LONG

������ϵͳ����Ա������Ϊ��������Ա����ѧϰ���޽��Ĺ����ҡ�
��Ŀ�����µĻ��ݳ����������ķ��䡣

LONG);
	set("exits", 
	([ //sizeof() == 3
		"kz" : "/d/city/kezhan",
		"north" : __DIR__"wizroom",
                 "up" : "/d/update/stone/d/stoneroom",
	]));

	set("no_death", 1);
	set("no_fight", 1);
	set("no_kill", 1);
	set("no_magic", 1);
	set("no_time", 1);

	set("no_clean_up", 0);
	set("valid_startroom", 1);
	call_other( "/obj/board/work_bbs", "???" );

	setup();
}

void init()
{
	string str;
	object me = this_player();
	switch(me->query("gender")) 
	{
		case "Ů��":
			switch( wizhood(me) ) {
				case "(admin)":
					str = "Ů��";
					break;
				case "(arch)":
					str = "����";
					break;
				case "(wizard)":
					str = "��ħŮ";
					break;
				case "(apprentice)":
					str = "ħŮ";
					break;
				case "(immortal)":
					str = "СħŮ";
					break;
				case "(elder)":
					str = "С����";
					break;
            }
            break;
		case "����":
			switch( wizhood(me) ) {
				case "(admin)":
					str = "����";
					break;
				case "(arch)":
					str = "����";
					break;
				case "(wizard)":
					str = "����";
					break;
				case "(apprentice)":
					str = "��ʦ";
					break;
				case "(immortal)":
					str = "ħ��ʦ";
					break;
				case "(elder)":
					str = "С����";
					break;
			}
			break;
	}
	tell_room( environment(me), CYN"���ص���˵������ע�⣬��"+str+"��" + me->query("title") 
	+ " " + me->query("name") + "(" + capitalize(me->query("id")) + ")" + " �����˹����ң�����\n"NOR);
}


