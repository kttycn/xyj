// fuhu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIY"·ü»¢ÂÞºº"NOR, ({"xianglong luohan", "luohan"}));
       set("long", "Óë½µÁúÂÞººÒ»Ñù£¬ÊÇÌìÉÏÉñ±øÖ®Ò»¡£\n");
       set("title", HIC"ÎäµÛÃÅ"NOR);
       set("gender", "ÄÐÐÔ");
       set("age", 50);
       set("class", "wusheng");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "ÂÞºº");
       set("looking", "ÓñÃæ¶à¹âÈó£¬²Ô÷×ò¢ÏÂÆ®£¬½ð¾¦·É»ðÑæ£¬³¤Ä¿¹ýÃ¼ÉÒ¡£");
       set("max_kee", 3000);
       set("max_gin", 500);
       set("max_sen", 3000);
       set("force", 3000);
       set("max_force", 1500);
       set("force_factor", 50);
       set("max_mana", 1500);
       set("mana", 2000);
       set("mana_factor", 50);
       set("combat_exp", 1400000);
       set("daoxing", 2100000);

        set_skill("unarmed", 90);
        set_skill("dodge", 90);
        set_skill("parry", 90);
        set_skill("spells", 90);  
        set_skill("feisheng-spells", 50);
        set_skill("literate", 90);
        set_skill("sword", 90);  
        set_skill("wuying-sword", 90);
        set_skill("fumobashi", 90);  
        set_skill("mizong-steps", 90);
        set_skill("force", 100);   
        set_skill("xiantian-force", 100);

        map_skill("spells", "feisheng-spells");
        map_skill("unarmed", "fumobashi");
        map_skill("force", "xiantian-force");
        map_skill("sword", "wuying-sword");
        map_skill("parry", "wuying-sword");
        map_skill("dodge", "mizong-steps");

create_family("ÎäÊ¥ÃÅ", 2, "ÂÞºº");
   setup();
   carry_object("/d/obj/weapon/sword/qinghong")->wield();
   carry_object("/d/obj/armor/jinjia")->wear();
}
void attempt_apprentice(object ob, object me)
{
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) +
"¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓÐ³É¡£\n");
        command("recruit " + ob->query("id") );
	return;
}		

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wusheng");
}

ÿ
