inherit NPC;
#include <ansi.h>
void do_drink();
 
void create()
{
	seteuid(getuid());
	set_name("����Ƥ", ({"wang bapi", "wang"}));
	set("long", "���������Ƥ���̿���Ӫ������ͨ�졣\n");
	set("gender","����");
	set("title", "��ù��");
	set("age",44);
	set("con",20);
	set("per",12);
	set("str",15);
	set("int",15);
	set("daoxing",100000);
	set("attitude","heroism");
	set("chat_chance",20);
	set("chat_msg", ({
        "����Ƥ��ݺݵؿ�����һ�ۣ�˵���������Ͻ������ҳ���ְ��\n",
        "����Ƥҡҡͷ˵����ֻҪ���������������ֻ�ù������ڻҵ���ˡ�\n",
        "����Ƥ����س�������������Ƥ�����������İ�ҹ���У�\n",
		"����Ƥ�ٺٵؼ�Цһ����������������ˣ������й��˵�����������ֵ�óƵ���\n",
        (: do_drink :),
        "����Ƥ���������������ЩС�����Ǿͷ�40%�ɡ��������\n",
		(: random_move :)
	}));

	set("chat_chance", 10);

	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("unarmed", 80);
	set_skill("sword", 120);
	set_skill("literate", 120);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 10);
	set("eff_gin", 2000);
	set("eff_kee", 2000);
	set("eff_sen", 2000);
	set("kee", 2000);
	set("gin", 2000);
	set("sen", 2000);

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/d/moon/obj/jiudai");
	add_money("silver", 40);
}
 
void do_drink()
{
    object *list, ob;
    int i, can_drink;
    if ((int)this_object()->query("water") >= 380) return;
    list = all_inventory(this_object());
    i = sizeof(list);
    can_drink = 0;
    while (i--) {
        if ((string)list[i]->query("liquid/type") == "alcohol") {
            ob = list[i];
            can_drink = 1;
        }
    }
    if (can_drink) {
        command("drink "+(string)ob->query("id"));
        if ((int)ob->query("liquid/remaining") == 0)
            command("drop "+(string)ob->query("id"));
    }
    else {
        command("heihei");
        command("say Ǯ����������Ǯ������");
    }
    return;
}

void die()
{
  if (environment())
    message("sound", HIR"\n���ٴ��ң����������г������㣡\n"NOR, environment());

	set("eff_gin", 2000);
	set("eff_kee", 2000);
	set("eff_sen", 2000);
	set("force", 3600);
	set("mana", 3600);
	set("kee", 2000);
	set("gin", 2000);
	set("sen", 2000);
	
}

void unconcious()
{
  die ();
}
