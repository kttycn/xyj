// xianglong.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIY"降龙罗汉"NOR, ({"xianglong luohan", "luohan"}));
       set("long", "与伏虎罗汉一样，是天上神兵之一。\n");
       set("title", HIC"武帝门"NOR);
       set("gender", "男性");
       set("age", 50);
       set("class", "wusheng");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "罗汉");
       set("looking", "玉面多光润，苍髯颌下飘，金睛飞火焰，长目过眉梢。");
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
        set_skill("dodge", 100);
        set_skill("parry", 90);
        set_skill("spells", 90);  
        set_skill("feisheng-spells", 90);
        set_skill("literate", 60);
        set_skill("sword", 90);  
        set_skill("wuying-sword", 90);
        set_skill("fumobashi", 90);  
        set_skill("mizong-steps", 100);
        set_skill("force", 90);   
        set_skill("xiantian-force", 90);

        map_skill("spells", "feisheng-spells");
        map_skill("unarmed", "fumobashi");
        map_skill("force", "xiantian-force");
        map_skill("sword", "wuying-sword");
        map_skill("parry", "wuying-sword");
        map_skill("dodge", "mizong-steps");

create_family("武圣门", 2, "罗汉");
   setup();
   carry_object("/d/obj/weapon/sword/qinghong")->wield();
   carry_object("/d/obj/armor/jinjia")->wear();
}
void attempt_apprentice(object ob, object me)
{
        command("say 很好，" + RANK_D->query_respect(ob) +
"多加努力，他日必定有成。\n");
        command("recruit " + ob->query("id") );
	return;
}		

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wusheng");
}

�
