// /d/guzhanchang/npc/shigui.c 食尸鬼
// stone 20020621

/************************************************************/
#include <ansi.h>
inherit NPC;

int accept_object(object me, object ob);
/************************************************************/

void create()
{
  set_name("食尸鬼", ({"shi gui", "yao", "gui", "monster"}));
  set("long","这是一副全身沾满了黄土的骸骨，竟然还有一些腐肉挂在骨架上。\n");
  set("gender", "男性");
  set("age", 40+random(15));
  set("attitude", "peaceful");
  set("combat_exp", 200000);
  set("daoxing", 100000);

  set_skill("unarmed", 200);
  set_skill("parry", 200);
  set_skill("dodge", 200);
  set_skill("blade", 200);
  set_skill("kugu-blade", 200);
  map_skill("blade", "kugu-blade");
  map_skill("parry", "kugu-blade");
  map_skill("dodge", "kugu-blade");
  set("chat_chance", 20);
  set("chat_msg", ({
	"食尸鬼道：唉，也不知在这里躺了多久了，好久没吃上人尸了。\n",
	"食尸鬼道：在这呆长了，都忘了尸体是什么味儿了！\n",
	"食尸鬼道：真想出去大吃一顿啊！\n",
	}) );
  set("inquiry", ([
	"name":		"名字？什么名字？我早就不记得了。",
	"here":		"这里？这里是个破地方。要不是那个混帐恶鬼王叫我看着，我早出去吃人尸，享清福了！",
	"rumors":	"嘿嘿，我都在这里躺好些年了，还能知道点什么？",
	"人尸":		"唉......能吃上点新鲜的人尸就好了。",
	"尸体":		"尸体，真是美味啊，好久没尝上了，真谗啊！你有吗？",
	]));

  setup();
  carry_object("/d/obj/weapon/blade/blade")->wield();
}

/************************************************************/

void init()
{
    object ob;
    ::init();

    if (interactive(ob=this_player()) && !is_fighting())
    {
	remove_call_out("greeting");
	call_out("greeting", 1, ob);
    }
}

void greeting(object me)
{
    string myrude=RANK_D->query_rude(me);
    command("hehe "+me->query("id"));
    command("say 你这"+myrude+"来这里干什么？有没有带好东西孝敬我来着？");
    return;
}
/************************************************************/
int accept_object(object me, object ob)
{
        if( (string)ob->query("id")=="corpse" )
    {
	command("say 不错不错，你小子果然还没忘了我！");
	message_vision(CYN"食尸鬼一接到尸体，立即张口大嚼了起来......\n\n\n嘴里嘟嘟囔囔地说道：“好吃，好吃，真是美味！”\n"NOR, me);
	me->add_temp("guzhanchang/gave_guard_corpse", 1);
	return 1;
    }
    command("say 什么破玩意？");
    return 0;

}

/************************************************************/

void die()
{
    string msg;

    msg="食尸鬼散作一堆枯骨，化作一堆黄土。\n";
    msg+=CYN"四面八方传来阵阵惨笑：想杀死一堆骸骨，你真是痴心妄想！我会回来的！\n"NOR;
    if(environment())
	message("vision", msg, environment());
    destruct(this_object());
}
�