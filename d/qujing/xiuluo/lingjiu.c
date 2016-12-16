#include <ansi.h>
inherit ROOM;
string *msgs = ({
	"���ߣ���Ե���ա�",
	"�����ߣ���Կա�",
	"�������У�売��ڲ���֮�ڡ�",
	"���ĬĬ����ң�ڼ���֮�С�",
	"����ն��ٶ��Σ���������ǧ���",
	"���˼��֪�����뵱ʶ�ġ�",
	"�ľ���������գ��Ĵ����򾳽��塣",
	"������Ƿ�����࣬��ǰ�ɼ���",
	"�����������л����������",
	"�й���������Ϊ�붨֮ԭ��",
	"����ʩ������������֮����",
	"������׾����֪������Ϊ��",
	"�ƼƷǳ����ͷͷ���¡�",
	"��ʹһ�Ĳ�����������ȫ��",
	"���Ʋ�����������Ϊ����������٣�ʵ����ʡ�",
	"ֻҪ����Ե����������ɫ�Կա�",
	"���ش����Ѱ�������Ȼ���������",
});

void create ()
{
	set ("short", "��ѩɽ��������");
	set ("long", @LONG
[1;33m������ǵ�����������õ��ɷ�ĵط���ѩɽ���ն�����,[2;37;0m
[1;33m�����Ƿ�ĸ-[2;37;0m-[1;33m��ȸ�����������ĵ�����[2;37;0m
[1;33m�����������磬����Ϊ�����޷������������ʥ�ء�[2;37;0m
LONG);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/kongque" : 1,
	]));
	set("no_magic", 1);
	setup();
}

void init ()
{
	add_action ("do_canwu", "canchan");
	add_action("do_out","out");
	add_action("do_action", ({"ji","cast"}));  
}
int do_action(string arg)
{
	write("û�в����������?\n");
	return 1;
}
int do_canwu ()
{
	object m;

	object who = this_player();
	int size = sizeof(msgs);
	int i = who->query_temp("xiuluo/lingjiu_canwu");
	int j;

	if( who->query("xiuluo/lingjiu_ok") == 1 ) 
		return notify_fail ("���Ѿ��������ˣ��㻹��Ҫ������\n");

	if (who->is_busy())
		return notify_fail ("����æ���أ�\n");

	message_vision ("$N��ϥ��������ʼ�������ն��еİ��\n",who);
	if (i >= size)
	{      
		message_vision ("\n$N��˼���꣬�����Ѿ����������ն��е����ܡ�\n",who); 
		message_vision("$Nվ���������򶴶�������ȥ����ʱ��̨һƬ����(out dong)��\n", who);
		who->set("xiuluo/lingjiu_ok",1);  
	}  
	else
	{
		j = i*18+10;
		who->start_busy (j,j);
		call_out ("start_canwu",5,who,i);
		call_out ("finish_canwu",j,who);
	}
	return 1;
}
void start_canwu (object who, int i)
{
	message_vision ("\n$N�����"+msgs[i]+"\n",who); 
	message_vision ("\nƬ�̣�$N��ʼ�������ն��е����ܡ�\n",who); 
	who->set_temp("xiuluo/lingjiu_canwu",i+1);
}

void finish_canwu (object who)
{
	object where = environment(who);

	who->interrupt_me ();
	message_vision ("\n$N������ϣ�վ���������ƺ���û���������ն��е����ܡ�\n",who); 
  // much slower than normal speed, just a symbolic reward
	where->add("times",1);
	if (where->query("times") < 1)
	{
		who->add("potential",random(3)+1);
		tell_object(who,"�㷢���Լ�����õ���ʲô����һ����\n");
	}
}
int do_out(string arg)
{
	object me;
	me = this_player();
	if (!arg||arg!="dong") return 0;
	write("������˫�ۣ�˫�ַ���һ����ʯ�����һ������������\n");
	if( me->query("xiuluo/lingjiu_ok") != 1 ) 
	{
		write("��û�в�������еİ��أ���������ǳ���ȥ�ġ�\n");
		return 1;
	};
	write("������ʼ����ת����ɲʱ����ص�����ɽ���¡�\n");
	me->move("/d/qujing/lingshan/shanjiao");
	return 1;
}
