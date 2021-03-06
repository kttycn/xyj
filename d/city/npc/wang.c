inherit NPC;
#include <ansi.h>
void do_drink();
 
void create()
{
	seteuid(getuid());
	set_name("王扒皮", ({"wang bapi", "wang"}));
	set("long", "大白脸王扒皮，刻苦钻营，媚术通天。\n");
	set("gender","男性");
	set("title", "倒霉蛋");
	set("age",44);
	set("con",20);
	set("per",12);
	set("str",15);
	set("int",15);
	set("daoxing",100000);
	set("attitude","heroism");
	set("chat_chance",20);
	set("chat_msg", ({
        "王扒皮恶狠狠地看了你一眼，说道：还不上缴利润，我撤你职！\n",
        "王扒皮摇摇头说：我只要总理宝座，你们嘛就只好过过当炮灰的瘾了。\n",
        "王扒皮得意地唱道：我是王扒皮，鼎鼎大名的半夜鸡叫！\n",
		"王扒皮嘿嘿地奸笑一声道：今年就这样了，看来中国人的忍耐力就是值得称道。\n",
        (: do_drink :),
        "王扒皮低吟道：明天给这些小不点们就发40%吧。后年嘛……\n",
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
        command("say 钱．．．给我钱．．．");
    }
    return;
}

void die()
{
  if (environment())
    message("sound", HIR"\n你再打我，我让你们行长踢了你！\n"NOR, environment());

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
