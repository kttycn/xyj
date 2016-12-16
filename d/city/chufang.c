// Room: /d/city/chufang

#include <ansi.h>
inherit ROOM;
int do_xi(string arg);

void create ()
{
	set ("short", "����");
	set ("long", @LONG
������ϳǿ�ջ�ĳ������ɾ����룬ǽ�ߵĹ����������������Ĳ;ߡ�
������һ����һ��СС��ˮ�أ������������ˮ������������ϴ��xi��
Щʲô��
LONG);

	set("no_dazuo",1);
	set("no_kill",1);
	set("no_fight",1);
	set("kezhan",1);
	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"kezhan",
	]));
	set("resource", ([ /* sizeof() == 1 */
		"water" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_xi","xi");
	add_action("do_mo", "mo");
}

int do_xi(string arg)
{
	object me=this_player(); 
	object ob,ob1;
	if (!me->query_temp("gongzuo/xipanzi"))
		return notify_fail("�㻹����ȥ����С������к��ɡ�\n");

	if (!arg || (arg != "������" && arg != "zangpanzi") )
		return notify_fail("��Ҫϴʲô��\n");

	if (!(ob = present("zangpanzi", this_player())))
		return notify_fail("������û�������ӣ���ô��ϴ�أ���\n");

	if ( (int)me->query("sen")<20)
		return notify_fail("��̫���ˣ�ЪϢ�°ɡ�\n");

	if (me->query_temp("gongzuo/xipanzi")==6)
		return notify_fail("����ϴ���ˣ��ͻص�С���Ƕ��ɡ�\n");

	message_vision("$N�ӳ���������ˮ����ʼ������ϴ���ӡ�\n",me);
	me->add("sen",-(10+random(10)));
	me->add_temp("gongzuo/xipanzi",1);
	if ( (int)me->query_temp("gongzuo/xipanzi")==6)
	{
		message_vision(CYN"$Nϴ�����ã����ڽ�����ȫ��ϴ���ˡ�\n"NOR,me);
		ob->set_name( "����" , ({"panzi"}));
		ob->set("long","һ����ϴ�õ����ӡ�\n");
	}
	return 1;
} 

int do_mo(string arg)
{
	object me, key;
	int sen;

	me = this_player();
	notify_fail("��ʲôҲû���š�\n");
	
	if(me->is_busy()) return 0;

	sen=me->query("sen");
	if(sen<110) return 0;
	me->add("sen",-100);

	sen=(me->query("combat_exp")+me->query("daoxing"))/2;
	if(sen<10000) return 0;

	key = new(__DIR__"obj/candle");
	key -> move(me);
	message_vision("������һ֧��������\n", me);

	return 1;
}
