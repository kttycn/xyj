
#include <ansi.h>

inherit NPC;

int ask_ziying(object me);

void create()
{
	set_name("Ì«ÉÏÀÏ¾ı",({"taishang laojun","laojun","dao"}));
	set("gender", "ÄĞĞÔ");
	set("age", 55);
	set("long", "		\nÌ«ÉÏÀÏ¾ı¡£\n");

	set("attitude", "peaceful");
	set("class", "taoist");
	set("combat_exp", 2000000);
	set("daoxing", 4000000);
	set("kee", 400);
	set("max_kee", 400);
	set("sen", 400);
	set("max_sen", 400);
	set("force", 400);
	set("max_force", 400);
	set("mana", 400);
	set("max_mana", 400);
	set("force_factor", 5);
	set("mana_factor", 10);

	set_skill("spells", 30);
	set_skill("dao", 30);
	set_skill("dodge", 60);
	set_skill("parry", 40);
	set_skill("unarmed", 30);

	set("inquiry", ([
		"ziying-sword"	:(: ask_ziying :),
		"×ÏÛ«½£"	:(: ask_ziying :),
		"here"	 : "ÕâÀï¾ÍÊÇ¶µÂÊ¹¬£¬ÄãÀ´ÕâÀï¸ÉÊ²Ã´£¿",
	]));

	setup();
	carry_object("/d/lingtai/obj/cloth")->wear();
}


void init()
{
	object who;

	::init();
	if( interactive(who = this_player()) && !is_fighting() ) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, who);
	}
}


void greeting(object who)
{
	object me = this_object();
	if (who->query("dntg/laojunlu")=="allow")
	{
		me->command("kick");
	who->set("dntg/laojunlu","allow");
		me->command("chat ´óÊÂ²»ºÃ£¡"HIR+who->query("name")+HIC" ´Ó°ËØÔÂ¯ÖĞÌÓ³öÀ´ÁË¡«¡«¡«¡«");
		remove_call_out("leave_laojunlu");
		call_out("leave_laojunlu", 1, who);	
	} 
}

int leave_laojunlu(object who)
{
	who = this_player();
	message("channel:rumor", HIC"¡¾Ò¥ÑÔËÄÆğ¡¿"HIR+who->query("name")+"Ò»½ÅÌß·­ÀÏ¾ıÂ¯,Å­»ğÖ±³å¾ÅÏö¡«¡«¡«¡« \n"NOR, users());
	who->command("chat [1;31mÓñµÛÀÏ¶ùÄãµÈ×Å£¬´ıÎÒÕâ¾ÍÉ±ÉÏÁéÏöµî£¬¶áÁËÄãÄÇ»è¾ıµÄ±¦×ù£¡£¡£¡[0m");
	who->move("/d/dntg/sky/tongmingdian");
}

int ask_ziying(object me)	
{
	me=this_player();
	if( me->query_temp("ask_ziying") == "tang1" ) 
	{
		command("consider");
		command("say Äã¸©¶ú¹ıÀ´¡£");
		command("say ¾İËµ£¬ÔÚÎå×¯¹Ûºó»¨Ô°ÀïÓĞÏ¬Å£¾«£¬Ìú¹ÕÀï±È½ÏÇå³ş£¬ÄãËÙÈ¥½µ·ü£¡");
		command("say ÀÏµÀÒ»ĞÄÎªÈË£¬Éá¼º·î¹«£¬°ÑĞ¡ÑòÈÃ¸ø±ğÈË£¬°Ñ·ÊÖíÁô¸ø×Ô¼º¡£");
		me->set_temp("ask_ziying","laojun1");
		return 1;
	}
	else if( me->query_temp("ask_ziying") == "tieguaili" ) 
	{
		command("say ÓĞÕâµÈ´óÊÂ£¿£¡");
		message_vision("$NÆşÖ¸Ò»Ëã.....\n", this_object());
		message_vision("$NàèÁ¨Å¾À²É¿ÁË×Ô¼ºÎŞÊı¸ö°ÍÕÆ£¬ÖÕÓÚÃ÷°×ÁË»¨¶ùÎªÊ²Ã´ÕâÑùºìµÄµÀÀí!\n", this_object());
		message_vision("¶Ô$NËµµÀ£º¿Ï¶¨ÊÇÔÚ»Ê¹¬!\n", me);
		me->set_temp("ask_ziying","laojun2");
		return 1;
	}
	command("say ÕâÊÇÕæµÄÂğ£¿");
	message_vision ("ÌÆÌ«×ÚÓĞĞ©»ÅÕÅÆğÀ´.\n",me);
	command("say ÉÏÏÉ»¹ÇëºóÌÃ");
	me->set("enter", 1);
	return ("Õâ´Î¾Í¶à¶à¸ĞĞ»ÉÏÏÉÁË¡£¡£¡£\n");
}
