inherit ROOM;
int do_break(string arg);
void create ()
{
	set ("short", "��");
	set ("long", @LONG
�����������Ѿ������ˣ���Ϊû�˴�ɨ����һ����һ�ѵ�ȫ����
�˹�ͷ��������һ��ʯ��(men)�������кܶ���ʯ�ӣ���������ʲ
ô�����������
LONG);

	set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"ro5",
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


		message_vision(
		"$N�ߵ�ʯ��ǰ���ڳ��������ʽ������һ������˫��ͬʱ�ĳ���\n", this_player());
				
		if (n>=300) {
				message_vision(
				"$Nֻ��һ�����죬$N��ʯ�����ˣ�\n", this_player());
				set("exits/north", __DIR__"sl");
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
		room->delete("exits/north");
}
																																															
