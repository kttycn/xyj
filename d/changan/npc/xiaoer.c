//By waiwai@mszj 2000/10/26

inherit NPC;
#include <ansi.h>

void create()
{
       set_name(HIW "С��" NOR, ({"xiao er","er"}));
       set("title",HIM"Ұ����ҽ��"NOR);
       set("gender", "����");
       set("combat_exp", 50000);
       set("age", 25);
       set("per", 24);
       set("str", 100);
       set("force", 400);
       set("max_force", 200);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 200);
       set_skill("dodge", 200);
       set_skill("force", 200);

       setup();

       carry_object("/d/obj/cloth/linen")->wear();
}
void init()
{
    ::init();

}

int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 10000000) 
	{
		tell_object(who, HIB"С����������һЦ��Ȼ�������������һ��.....\n
��ֻ����һ�������......\n\n"NOR);
		who->set_temp("rent_paid",1);
		who->move("/d/changan/bx");

		return 1;
	}
	return 0;
}
