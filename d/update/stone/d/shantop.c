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

������һ���޼ʵ�ѩԭ��Ρ����ΰ�ı�ɽ��ͻȻ��̲����꣬��
�׳����ˮ��չ������ǰ�����ʱ����һ����������ӿ����ͷ��
ɽ�������ݣ��񣬷·��ǵ�����һ�����硣�����ŵ���������
(wa)�� 
LONG);

	set("no_clean_up", 1);
	can_enter=1;

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
	object me, shen, weapon;
	int sen;
	if(!objectp(weapon = me->query_temp("weapon")))
		return notify_fail("���������ô�ڣ�\n");
	if((weapon->query("skill_type") != "sword") 
	&& (weapon->query("skill_type") != "blade"))
		return notify_fail("����Ҹ�����֮��Ĳ�����ѽ��\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
	notify_fail("��ʲôҲû���š�\n");
//	if(query("num") <= 0)
//		return notify_fail("������Ķ����Ѿ��������ڹ��ˣ�\n");
	if(me->query("kee") < 50)
		return notify_fail("�������ֽ�����ʲôҲ�����ˣ�\n");
	
	sen=me->query("sen");
	if(sen<110) return 0;
	sen-=100;
	me->set("sen",sen);

	sen=(me->query("combat_exp")+me->query("daoxing"))/2;
	if(sen<50000) return 0;

	if( query("available") == 1 )
	{
		set("available", 0);
		if(random(2))
			guo = new(__DIR__"obj/snowginseng");
		else
			guo = new(__DIR__"obj/snowginseng");
		shen -> move(this_object());
		message_vision("ͻȻ�㿴��ѩѨ��һ��˶�������˲Σ���ʱһ��Ũ���Ĳ���Ʈɢ�ڿ��С�
		����������һ������\n", me);

		remove_call_out("generate");
		call_out("generate", 259200+random(1080) );

		return 1;
	}
	return 0;
}

/*	message_vision("$N����"+weapon->query("name")+"��ѩ��������������\n",me);
	me->start_busy(3);
	me->receive_damage("kee",50);
	call_out("finish",3,me);
	return 1;*/

	
int clean_up()
{
	return 0;
}
