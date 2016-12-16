// created 4/5/1997 by snowcat
#include <ansi.h>
#define NAME "Î÷ÁºÅûËªÏÉºó"

inherit NPC;

void create()
{
  set_name(NAME, ({"xiliang xianhou", "queen"}));
  set("title", "³¿êØÅ®Éñ");
  set("gender", "Å®ĞÔ");
  set("age", 23);
  set("long", "Î÷ÁºÅûËªÏÉºó³¿êØÅ®Éñ¡£\n");
  set("combat_exp", 1000000);
  set("daoxing", 1000000);

  set_skill("snowsword", 100);
  set_skill("sword", 100);
  set_skill("unarmed", 100);
  set_skill("dodge", 120);
  set_skill("parry", 120);
  set_skill("dragon-steps", 120);
  map_skill("dodge", "dragon-steps");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("force", 900);
  set("max_force", 900);
  set("force_factor", 10);

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/obj/weapon/sword/feijian")->wield();
}

void init()
{
  ::init();
}

void announce_success(object who, string reason)
{//disabled announce and reward...
	int i;

	i = random(500);
	if (who->query("obstacle/nverguo") == "done")
		return;
	who->add("obstacle/number",1);
	who->set("obstacle/nverguo","done");
	who->add("daoxing",i+4000);
	who->add("score", 10);
	command("chat "+who->query("name")+"Ñ°»ØÎ÷Áº¹ú±¦£¬Î÷ÁºÉÏÏÂ±¼×ßÏà¸æ£¡");
	message("channel:chat",HIW"¡¾¹ı¹ØÕ¶½«¡¿Î÷ÁºÅûËªÏÉºó(Xiliang xianhou)£º"+who->query("name")+"´³¹ıÎ÷ĞĞÈ¡¾­µÚÊ®¾Å¹Ø£¡\n"NOR,users());
	tell_object(who,"ÄãÓ®µÃÁË"+COMBAT_D->chinese_daoxing(i+4000)+"µÄµÀĞĞ£¡");
	who->save();
	message_vision (HIY NAME+"ÔÚÒ»Õó°×ÎíÖĞĞìĞìÏûÊ§¡£\n" NOR,who);
}

void refuse_player(object who)
{
  string name;
  name = who->name();
  message_vision (HIY NAME+"Í»È»´Ó°×ÎíÖĞÉÁ³öÏò$NÒ¡Ò¡Í·£º"+
                  "ÄúÒÑ´³¹ıÎ÷ÁºÕâÒ»¹ØÁË¡£¿ìÈ¥Î÷ÌìÈ¡¾­°É¡£\n" NOR,who);
  message_vision (HIY "Ëµ°Õ"+NAME+"ÔÚÒ»Õó°×ÎíÖĞĞìĞìÏûÊ§¡£\n" NOR,who);
}

void stop_access(object who)
{
  string name;
  name = who->name();

  message_vision (HIY NAME+"´ÓÒ»ÍÅ°×ÎíÖĞÏÔ³ö£¬¸æËß$N£º"+
                  "ÄúÉĞÎ´´³¹ıÎ÷ÁºÕâÒ»¹Ø£¬¶Ô²»Æğ¡£\n" NOR,who);
  message_vision (HIY "Ëµ°Õ°×ÎíÓµ×Å"+NAME+"ÔÚ¿ÕÖĞÂıÂıµØÏûÊ§¡£\n" NOR,who);
}
ÿ
