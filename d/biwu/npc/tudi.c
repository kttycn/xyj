// rewritten by snowcat on 4.12.1997

inherit NPC;

int give_fajian();

void create()
{
  set_name("土地公公", ({"tu di", "tu", "di"}));
  set("gender", "男性");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 250000);
  set("daoxing", 300000);

  set("per", 25);
  set_skill("dodge", 60);
  set("max_sen",600);
  set("max_gee",600);
  set("max_gin",600);
  set("force",800);
  set("max_force",800);
  set("max_mana",800);
  set("force_factor",25);
  set_skill("spells",60);
  set_skill("stick",60);
  setup();

  set("inquiry", ([
       "here": "这儿是风雨楼，盟主就在上面。\n",
       "name": "本处土地也，老夫别无他物，只有一些饭菜啦。\n",
      ]));
  carry_object("/d/obj/cloth/choupao")->wear();

}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_yao","want");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	tell_object(ob,"土地公公笑咪咪向你说道：
    从现在开始，你将要接受最大的考验。首先你要通过一个迷宫，然后你会到达风
雨楼，在一刻钟内击败里面的十一大高手，最后向盟主挑战。在风雨楼内没有回头的
路，你只有等待一刻钟后自动送会长安十字街头。
    顺便问一下，您想要(want)馒头和水袋吗？\n\n");
        ob->set_temp("comehere",1);
}

int do_yao()
{
	object ob,kele,hbb;
	ob = this_player();

	if (ob || interactive(ob))
		if ( ob->query_temp("comehere") )
		{
			tell_object(ob, "土地公公看了你一眼，馒头和水袋飞了过来，“您老慢吃吧。”\n");
			kele = new("/d/biwu/obj/kele");
			hbb = new("/d/biwu/obj/hbb");
			kele->move(ob);
			hbb->move(ob);
        	ob->delete_temp("comehere");
        	return 1;
        }
	return 0;
}
