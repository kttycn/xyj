//Cracked by Roath
//anshi.c
//#include <room.h>
//STONE
inherit ROOM;

int can_enter=1;

void create ()
{
	set ("short", "ѩɽ֮��");
	set ("long", @LONG

ֻ��ɽҰ��˪��أ���������ѩ�����ؾ�������ʹ����Ϣ����
ѩ�׵�������ƺ�����������������޷ֱ��ҡ���������У�
���͵��䣬Ⱥɽ�����������Ŀ��̤��֮������������İ�ѩ
�������죬ͷ����ѩ��Ʈ�裬�ֺ�ѩԭ�������������ǡ�����
������ԼԼ�����������˱ǣ���֪�Ӻζ����� 
LONG);

	set("no_clean_up", 1);
	set("exits", 
	([ //sizeof() == 4
		"west" : __DIR__"xueshan5",
	]));
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/snake1" : 1,
	]));

//	can_enter=1;

	setup();
}


void init()
{
	add_action("do_dig", "dig");
	add_action("do_dig", "wa");

	if( query("started") != 1 )
	{
		set("started", 1);
		call_out("generate", 259200+random(1080) );//75Сʱ
//		call_out("generate", 180+random(60) );//75Сʱ
	}
}

void generate()
{
	remove_call_out("generate");
	set("available", 1);
}

void reset_enter()
{
	can_enter=1;
}

int do_dig(string arg)
{
	object shen, weapon;
	object me = this_player();
	int kee;
	   if( (!arg) || (arg != "xue shen" && arg != "xueshen" && arg != "snowshen" && arg !="ѩ��") )
     	return notify_fail("��Ҫ��ʲô��\n");
	        if (objectp(present("xue she", environment(me))))
        return notify_fail("ǧ��ѩ�ߡ�ಡ���һ�������˹���������ŭĿ���ӣ����ų��£��ò��׶�\n");
		if(!objectp(weapon = me->query_temp("weapon")))
	return notify_fail("���������ô�ڣ�\n");
		if((weapon->query("skill_type") != "sword") 
	&& (weapon->query("skill_type") != "blade"))
		return notify_fail("����Ҹ�����֮��Ĳ�����ѽ��\n");
	if(me->query("kee") < 50)
		return notify_fail("�������ֽ�����ʲôҲ�����ˣ�\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
	notify_fail("�����"+weapon->query("name")+"������ѩ����������������ʲôҲû���š�\n");
		me->start_busy(3);
/*	message_vision("$N����"+weapon->query("name")+"��ѩ��������������\n",me);
	me->start_busy(3);
	me->receive_damage("kee",50);
	call_out("finish",3,me);
	return 1;*/
	
	kee=me->query("kee");
	if(kee<110) return 0;
	kee-=100;
	me->set("kee",kee);

	kee=(me->query("combat_exp")+me->query("daoxing"))/2;
	if(kee<50000) return 0;

	if( query("available") == 1 )
	{
		set("available", 0);
		if(random(2))
			shen = new(__DIR__"obj/snowginseng");
		else
			shen = new(__DIR__"obj/snowginseng");
		shen -> move(this_object());
		message_vision("ͻȻ�㿴��ѩѨ��һ��ѩ��˶��ĲΣ����������������ʱһ��Ũ���Ĳ���Ʈɢ�ڿ��С�
�㲻�����������һ������\n", me);

		remove_call_out("generate");
		call_out("generate", 144000+random(1080) );//40Сʱ
//		call_out("generate", 180+random(60) );//75Сʱ

		return 1;
	}
	return 0;
}

	
int clean_up()
{
	return 0;
}
