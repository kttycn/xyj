
inherit ROOM;
int do_break(string arg);
void create()
{
	set("short", "ʯ�ֱ�Ե");
	set("long", @LONG
������һƬ������ʯͷ�ѡ����ƺ������ĸо���ʯ�ֵ�͸������
ɱ������������ȴ�ָе�һ��Ī���Ŀ־塭���㲻�����˿�������
(men)��
LONG);

	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"sl1",
	]));	
	set("objects", ([
	]));
	set("item_desc", ([
		"men" : "����ʯ���ѱ����һ����Ϳ�����ǲ������ˣ����������(break)����\n",
	]) );
	setup();
}		 


void init()
{
	add_action("do_break", "break");
}	 

int do_break(string arg)
{
	int n;
	n = this_player()->query("force");
	if( !arg || arg!="men" ) {
		write("�򣡴򣡴����ʲô��\n");
		return 1;
	}

	message_vision("$N�ߵ�ʯ��ǰ���ڳ��������ʽ������һ������˫��ͬʱ�ĳ���\n", this_player());
				
	if (n>=300) {
		message_vision("$Nֻ��һ�����죬$N��ʯ�����ˣ�\n", this_player());
		set("exits/south", __DIR__"yongdao1");
		this_player()->set("force",n-300);
		remove_call_out("close");
		call_out("close", 5, this_object());
	}
	else {
		message_vision(
		"$N���һ���������������ʲôҲû����������$N����������ǿ��\n", this_player());
		this_player()->set("force",0);
	}
	return 1;
}

void close(object room)
{
	message("vision","ʯ�Ż������Σ�ϡ�ﻩ��̮����������\n", room);
	room->delete("exits/south");
}
																										
