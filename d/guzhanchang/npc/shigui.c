// /d/guzhanchang/npc/shigui.c Ê³Ê¬¹í
// stone 20020621

/************************************************************/
#include <ansi.h>
inherit NPC;

int accept_object(object me, object ob);
/************************************************************/

void create()
{
  set_name("Ê³Ê¬¹í", ({"shi gui", "yao", "gui", "monster"}));
  set("long","ÕâÊÇÒ»¸±È«ÉíÕ´ÂúÁË»ÆÍÁµÄº¡¹Ç£¬¾¹È»»¹ÓĞÒ»Ğ©¸¯Èâ¹ÒÔÚ¹Ç¼ÜÉÏ¡£\n");
  set("gender", "ÄĞĞÔ");
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
	"Ê³Ê¬¹íµÀ£º°¦£¬Ò²²»ÖªÔÚÕâÀïÌÉÁË¶à¾ÃÁË£¬ºÃ¾ÃÃ»³ÔÉÏÈËÊ¬ÁË¡£\n",
	"Ê³Ê¬¹íµÀ£ºÔÚÕâ´ô³¤ÁË£¬¶¼ÍüÁËÊ¬ÌåÊÇÊ²Ã´Î¶¶ùÁË£¡\n",
	"Ê³Ê¬¹íµÀ£ºÕæÏë³öÈ¥´ó³ÔÒ»¶Ù°¡£¡\n",
	}) );
  set("inquiry", ([
	"name":		"Ãû×Ö£¿Ê²Ã´Ãû×Ö£¿ÎÒÔç¾Í²»¼ÇµÃÁË¡£",
	"here":		"ÕâÀï£¿ÕâÀïÊÇ¸öÆÆµØ·½¡£Òª²»ÊÇÄÇ¸ö»ìÕÊ¶ñ¹íÍõ½ĞÎÒ¿´×Å£¬ÎÒÔç³öÈ¥³ÔÈËÊ¬£¬ÏíÇå¸£ÁË£¡",
	"rumors":	"ºÙºÙ£¬ÎÒ¶¼ÔÚÕâÀïÌÉºÃĞ©ÄêÁË£¬»¹ÄÜÖªµÀµãÊ²Ã´£¿",
	"ÈËÊ¬":		"°¦......ÄÜ³ÔÉÏµãĞÂÏÊµÄÈËÊ¬¾ÍºÃÁË¡£",
	"Ê¬Ìå":		"Ê¬Ìå£¬ÕæÊÇÃÀÎ¶°¡£¬ºÃ¾ÃÃ»³¢ÉÏÁË£¬Õæ²÷°¡£¡ÄãÓĞÂğ£¿",
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
    command("say ÄãÕâ"+myrude+"À´ÕâÀï¸ÉÊ²Ã´£¿ÓĞÃ»ÓĞ´øºÃ¶«Î÷Ğ¢¾´ÎÒÀ´×Å£¿");
    return;
}
/************************************************************/
int accept_object(object me, object ob)
{
        if( (string)ob->query("id")=="corpse" )
    {
	command("say ²»´í²»´í£¬ÄãĞ¡×Ó¹ûÈ»»¹Ã»ÍüÁËÎÒ£¡");
	message_vision(CYN"Ê³Ê¬¹íÒ»½Óµ½Ê¬Ìå£¬Á¢¼´ÕÅ¿Ú´ó½ÀÁËÆğÀ´......\n\n\n×ìÀïà½à½àìàìµØËµµÀ£º¡°ºÃ³Ô£¬ºÃ³Ô£¬ÕæÊÇÃÀÎ¶£¡¡±\n"NOR, me);
	me->add_temp("guzhanchang/gave_guard_corpse", 1);
	return 1;
    }
    command("say Ê²Ã´ÆÆÍæÒâ£¿");
    return 0;

}

/************************************************************/

void die()
{
    string msg;

    msg="Ê³Ê¬¹íÉ¢×÷Ò»¶Ñ¿İ¹Ç£¬»¯×÷Ò»¶Ñ»ÆÍÁ¡£\n";
    msg+=CYN"ËÄÃæ°Ë·½´«À´ÕóÕó²ÒĞ¦£ºÏëÉ±ËÀÒ»¶Ñº¡¹Ç£¬ÄãÕæÊÇ³ÕĞÄÍıÏë£¡ÎÒ»á»ØÀ´µÄ£¡\n"NOR;
    if(environment())
	message("vision", msg, environment());
    destruct(this_object());
}
ÿ