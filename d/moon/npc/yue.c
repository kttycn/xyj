//change.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int rank_me();

void create()
{
	set_name("ÔÂÅ«", ({"yue nu", "yuenu", "yue","master"}));
	set("long",
"ËıÄËÊÇ¹ğÊ÷²ÉÌìµØÖ®¾«»ª»¯³É£¬ºó°İæÏ¶ğÎªÊ¦£®\n");
	set("title", "¹ğ»¨ÏÉ");
	set("gender", "Å®ĞÔ");
	set("age", 20);
	set("class", "xian");
	set("attitude", "friendly");
	set("rank_info/respect", "ÏÉ¹Ã");
	set("per", 30);
	set("int", 30);
	set("max_kee", 500);
	set("max_gin", 500);
	set("max_sen", 500);
	set("force", 500);
	set("max_force", 500);
	set("force_factor", 20);
	set("max_mana", 300);
	set("mana", 300);
	set("mana_factor", 20);
	set("combat_exp", 200000);
	set("daoxing", 100000);

	set("eff_dx", 70000);
	set("nkgain", 260);

	set_skill("literate", 20);
	set_skill("unarmed", 50);
	set_skill("dodge", 80);
	set_skill("force", 50);
	set_skill("parry", 50);
	set_skill("sword", 50);
	set_skill("spells", 50);
	set_skill("moonshentong", 60);
	set_skill("baihua-zhang", 60);
	set_skill("moonforce", 60);
	set_skill("snowsword", 60);
	set_skill("moondance", 60);
	set_skill("whip", 50);
	map_skill("spells", "moonshentong");
	map_skill("unarmed", "baihua-zhang");
	map_skill("force", "moonforce");
	map_skill("sword", "snowsword");
	map_skill("parry", "snowsword");
	map_skill("dodge", "moondance");

	set("inquiry", ([
		"Ö°Î»": (: rank_me :),
	]) );

	create_family("ÔÂ¹¬", 3, "µÜ×Ó");
	setup();

	carry_object("/d/moon/obj/luoyi")->wear();
//  carry_object("/d/moon/obj/guihuajian")->wield();
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "¹ãº®¹¬´«ÈË")
		return notify_fail("ÄãÒÑ¾­ÊÇÕÆÃÅÈËÁË£¬»¹À´ÒªÊ²Ã´Ö°Î»£®\n");
	if( (string)me->query("family/family_name") == "ÔÂ¹¬"){
		if( exp <= 500000 ) {
			return notify_fail("ÄãÏÖÔÚÎäÑ§Ì«µÍ£¬»¹²»ÄÜÀ´ÒªÊ²Ã´Ö°Î»£®\n");
		} else if(exp <= 1000000 ){
			me->set("nick", HIM"À¥ÂØÔÂ¹¬"NOR+RED"¡ô"BLU"°éÎèËÅÅ®"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", HIM"À¥ÂØÔÂ¹¬"NOR+RED"¡ô"YEL"¾ªºçÎè¼§"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", HIM"À¥ÂØÔÂ¹¬"NOR+RED"¡ô"RED"Æ®ÃìÎèÏÉ"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", HIM"À¥ÂØÔÂ¹¬"NOR+RED"¡ô"MAG"åĞÒ£Ê¥Å®"NOR);
		} else {
			me->set("nick", HIM"À¥ÂØÔÂ¹¬"NOR+RED"¡ô"CYN"²¹ÌìÊ¥Ä¸"NOR);
		}

		tell_object(me, "ÔÂÅ«¶ÔÄãËµ£ºÄã¿ÉÒÔ×ö"+me->query("nick")+"¡£\n");
		tell_room(environment(me),
"ÔÂÅ«¶Ô"+me->query("name")+"Ëµ£ºÄã¿ÉÒÔ×ö"+me->query("nick")+"¡£\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","ÏÖÊÚÓè±¾ÃÅµÜ×Ó"+me->query("name")+""+me->query("nick")+HIC"Ò»Ö°¡£¹§Çë¸÷Î»ÏÉ³¤¶à¼ÓÅõ³¡£¡");
		me->save();  
	}
	return 1;
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="Å®ĞÔ")){
           command("shake");
           command("say ÎÒÃÇÔÂ¹¬Ö»ÊÕÅ®Í½£¬ÕâÎ»" +
RANK_D->query_respect(ob) + "»¹ÊÇÁíÇë¸ß¾Í°É¡£\n");
           return;
        }

        command("pat "+ob->query("id"));
        command("say ºÃ£¬Ï£Íû" + RANK_D->query_respect(ob) +
"¶à¼ÓÅ¬Á¦£¬°ÑÎÒÃÇÔÂ¹¬·¢Ñï¹â´ó¡£\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}
ÿ
