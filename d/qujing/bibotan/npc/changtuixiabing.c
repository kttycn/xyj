inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("长腿虾兵", ({"changtui xiabing","xiabing"}));
  set("gender", "男性");
  set("age", 25);
  set("title", "碧波潭九头驸马侍卫");
  set("long","碧波潭与龙宫和火云洞都有交情,他是来龙宫做客的,顺便也收些徒弟。\n");
  set("combat_exp", 100000+random(3000));
  set("daoxing", 100000);
  set("per", 15);
  set_skill("dodge", 70);
  set_skill("parry", 70);
  set_skill("unarmed", 70);
  set_skill("force", 70);
  set_skill("spells", 70);
  set_skill("fork", 70);
  set_skill("huaxue-dafa", 70);
  set_skill("huaxue-force", 70);
  set_skill("moyun-shou", 70);
  set_skill("moshenbu", 70);
  map_skill("force", "huaxue-force");
  map_skill("spells", "huaxue-dafa");
  map_skill("unarmed", "moyun-shou");
  map_skill("dodge", "moshenbu");
  map_skill("fork", "yueya-chan");
  set("max_sen",800);
  set("max_kee",800);
  set("force", 400);
  set("max_force", 400);
  set("force_factor", 20);
  set("mana", 400);
  set("max_mana", 400);
  set("mana_factor", 20);

  create_family("碧波潭", 3, "蓝");

  setup();

  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
  carry_object("d/obj/weapon/stick/mugun")->wield();


}

void attempt_apprentice(object ob)
{       ob=this_player();

        if( (string)ob->query("family/family_name") == "碧波潭") {
		command("say 大家同门中人，不敢当，不敢当！\n");
		return;
	}
                command("grin");
                command("recruit " + ob->query("id"));
                return ;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "yaomo");
                ob->set("title", "乱石山碧波潭小妖");
        }
}
