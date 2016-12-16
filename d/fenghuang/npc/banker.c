// originally coded by xiang
#include <ansi.h>
#include <dbase.h>
inherit NPC;

void create()
{
	set_name("¶����", ({"banker", "zhiyuan"}));
	set("title", HIR "��˴�����ְԱ" NOR);
	set("nickname", HIM "���֮��" NOR);
	set("gender", "Ů��");
	set("age", 24);
	set("str", 20);
	set("int", 24);
	set("dex", 40);
	set("per", 40);
	set("con", 18);
	set("kee", 1000);
	set("max_kee", 1000);
	set("sen", 1000);
	set("max_sen", 1000);
	set("shen", 0);

	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 2);
	set("chat_msg", ({
		"¶���϶�����ȻһЦ������������ǧ���ϵ꣬�ڷ���ǿ���˵�ǵ�һ�ҡ�\n",
		"¶����Ц��˵�����ڱ����Ǯ����Ϣ������������������(apply)�������ÿ���\n"
	}));
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);
	setup();
	add_money("gold", 5);
	setup();
}

void init()
{
	add_action("do_zhuanzhang", "zhuanzhang");
}

int do_zhuanzhang(string arg)
{     
	object ob,me;
	string str;
	int num, num0;
	me=this_player();
	if (!arg) return notify_fail("��Ҫ��ʲô��\n");
	if(sscanf(arg, "%s %d", str, num)==2 );
	else return notify_fail("��Ҫת��˭��\n");
	ob = find_player(str);
	num0 = num / 10000;
	if (num<0) return notify_fail("����Щ����а����ƭǮ��\n");
	if (num0>me->query("money")) return notify_fail("��û����ô��ƽ��ˣ�\n");
	if (!ob) return notify_fail("����û�����.\n");

	me->add("balance",-num0);
	ob->add("balance",num0);
	tell_object(me,sprintf(HIC"��ת��%d�ƽ��%s��\n"NOR,num,ob->query("name")));
	tell_object(ob,sprintf(HIC"%sת��%d�ƽ���㣡\n"NOR,me->query("name"),num));

	return 1;                                                               
}
