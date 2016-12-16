#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
	set_name("������", ({ "le zhuren", "le" }));
	set("title", "��˾�У�Ӵ�Ա");
	set("long", "
���Ƿ�˾�У�����Σ�ר�ŽӴ������ģ�����������ѧ�����顣\n");
	set("gender", "����");

	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "����");
	set("per", 24);
	set("str", 22);
	set("int", 28);
	set("con", 30);

	set("max_kee", 800);
	set("max_gin", 300);
	set("max_sen", 800);
	set("force", 1000);
	set("max_force", 500);
	set("force_factor", 25);
	set("combat_exp", 420000);
	set("score", 6000);

	set("inquiry", ([
		"��ѧ" : (: ask_me :),
	]));

	set("book_count", 1);

	setup();
	carry_object("/d/obj/weapon/blade/blade")->wield();
	carry_object("/d/obj/cloth/cloth")->wear();
}
init()
{
	add_action("do_decide", "decide");
}

string ask_me()
{
	object me = this_player();
	if(me->query("str") < 21 || me->query("con") < 28 || me->query("cor") < 20)
		return "��λ"+RANK_D->query_respect(me)+"������ı�߾Ͱɡ�\n";
	me->set_temp("xuexiao/decide",1);
	return "��ѧ�Ժ�Ҫ�ϸ�����ѧУ�涨�����"+RANK_D->query_respect(me)+"����(decide)�������ϸ�������ѧ������\n";
}

int do_decide()
{
	object ob, me;
	me = this_player();
	if (!me->query_temp("xuexiao/decide"))
	{
		message_vision("$N��$n��ֵ�˵������Ҫ�������\n", this_object(), me);
		return 1;
	}
	me->delete_temp("xuexiao/decide");
	ob = new("/d/fenghuang/obj/zhengshu");
	ob->move(me);
	me->set("xmark/ѧԱ", 1);
	me->set("title", HIM "��˾�УѧԱ"NOR);
       message_vision("$N˵�����ã�\n", this_object());
	message_vision("$N��$nһ��ѧ��֤��\n", this_object(), me);
	message_vision("$N˵������λ"+RANK_D->query_respect(me) + "�Ժ����ѧԱ�ˣ�Ҫ��ѧ����ѽ��\n", this_object());
	return 1;
}
