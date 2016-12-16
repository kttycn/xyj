// Room: /d/wiz/wizroom.c

inherit ROOM;

int block_cmd();

void create ()
{
	set ("short", "��ʦ������");
	set ("long", @LONG

��������ʦ�������۵ĵط��������ʦ��Ҫ����Ļ���Ҳ����ѡ����
����С�
LONG);

	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"system",
		"north" : __DIR__"jobroom",
		"sleeve": __DIR__"sleeveroom",
		"work": __DIR__"workroom",
		"guest": __DIR__"guest",
		"jail":__DIR__"punish",
		"kz": "/d/city/kezhan",
		"east" : "/d/wiz/newsroom",
	]));

	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/vikee" : 1,
	]));

	set("no_time", 1);
	set("valid_startroom", 1);
	set("wiz_board",1);

	setup();
//        call_other("/obj/board/wizard_b", "???");
}

void init()
{   
        if (!wizardp(this_player()))
          add_action("block_cmd","",1);   
}

int block_cmd()
{
       string verb = query_verb();

       if (verb=="say") return 0; //allow say
       if (verb=="chat") return 0;
       if (verb=="quit") return 0;
       if (verb=="look") return 0;
       return 1;
}

