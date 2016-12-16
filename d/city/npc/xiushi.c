// whitexiu.c
// stone amend 20020315
inherit NPC;

void create()
{
        set_name("白衣秀士", ({"xiu shi","xiushi","xiu","shi"}));
        set("gender", "男性" );
        set("age", 25);
        set("long", "一位风流书生．不过他面色看起来怪怪的，好像有满腹心事。\n");
        set("combat_exp", 10000);
        set("attitude", "peaceful");
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_skill("literate", 30);
        set_skill("force", 30);   
        set("per", 25);
        set("max_kee", 500);
        set("max_sen", 300);
        set("force", 150);
        set("max_force", 300);
        set("force_factor", 0);
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 20);
        set("chat_msg", ({
		"白衣秀士不屑地瞥了你一眼，又低头看手中的书。。\n",       
		"白衣秀士低声自语道：“书中自有黄金屋，书中自有颜如玉”。\n",
		"白衣秀士眉头紧锁，低头沉思。\n",
		"白衣秀士自言自语说道：“听说有〖万言集〗，文法精妙，可惜无缘一见。”唉。。。。！\n",
		(: random_move :)
	}) );
        set("inquiry", ([
                "name" : "关你屁事！\n",
                "here" : "长着眼睛你不会看啊。\n",
	    "袁守诚" : "江湖骗子。只有你们这帮傻瓜才信他。\n",
	    "算命先生" : "江湖骗子。只有你们这帮傻瓜才信他。\n",
	    "book" : "你有〖万言集〗吗？可否借小生一阅，在下感激涕零。\n",
	    "万言集" : "你有〖万言集〗吗？可否借小生一阅，在下感激涕零。\n",	    
	 ]) );
}

	
int accept_object(object me, object ob)
{
	object plan;

	if(userp(ob)) return 0;

	if( (string)ob->query("name")=="〖万言集〗" )
	{
		command("jump");
		command("thank" + me->query("id"));
		command("say 这位" + RANK_D->query_respect(me) + "真是小生的挚友。\n这里我也有一册书，乃各代壮元的妙文汇聚。\n可惜小生天资愚笨，尚不能领悟精义，不如送与"+ RANK_D->query_respect(me) +"吧 。\n");
		carry_object("/d/obj/book/plan");
		command("give plan to " + me->query("id"));
		return 1;
	}
/*	else if( (string)ob->query("id")=="book" )
	{
		message_vision("白衣秀士忙低头细看。。。\n");
		command("sigh");
		message_vision("白衣秀士对$N道：多谢"+RANK_D->query_respect(me)+"赠书。\n可惜不是〖万言集〗，小生久闻该书文法精妙，但无缘一读。\n", me);
		command("give book to " + me->query("id"));
		return 1;
	}*/
}