// laozhe.c

#include <ansi.h>

inherit NPC;
int rank_me();

void create()
{
	set_name(HIG"老者"NOR, ({"lao zhe", "laozhe"}));
	set("long", "一个悠闲的老人家，坐在树下乘凉。\n");
	set("title", HIC"武帝门"NOR);
	set("gender", "男性");
	set("age", 1000);
	set("class", "wusheng");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "护法");
	set("looking", "英俊潇洒，玉树临风，风流倜傥。");
	set("max_kee", 1000);
	set("max_gin", 100);
	set("max_sen", 1000);
	set("force", 1000);
	set("max_force", 500);
	set("force_factor", 10);
	set("max_mana", 500);
	set("mana", 1000);
	set("mana_factor", 10);
	set("combat_exp", 500000);
	set("daoxing", 1100000);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("spells", 100);  
	set_skill("feisheng-spells", 100);
	set_skill("literate", 100);
	set_skill("sword", 100);  
	set_skill("wuying-sword", 100);
	set_skill("fumobashi", 100);  
	set_skill("mizong-steps", 100);
	set_skill("dodge", 100);  
	set_skill("force", 100);   
	set_skill("xiantian-force", 100);

	map_skill("spells", "feisheng-spells");
	map_skill("unarmed", "fumobashi");
	map_skill("force", "xiantian-force");
	map_skill("sword", "wuying-sword");
	map_skill("parry", "wuying-sword");
	map_skill("dodge", "mizong-steps");
	set("inquiry", ([
		"职位": (: rank_me :),
	]));

	setup();
	carry_object("/d/obj/armor/jinjia")->wear();
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "乾坤尊者")
		return notify_fail("你已经是掌门人了，还来要什么职位．\n");
	if( (string)me->query("family/family_name") == "武圣门"){
		if( exp <= 500000 ) {
			return notify_fail("你现在武学太低，还不能来要什么职位．\n");
		} else if(exp <= 1000000 ){
			me->set("nick", WHT"终南武圣"NOR+RED"◆"BLU"修武行者"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", WHT"终南武圣"NOR+RED"◆"YEL"神力罗汉"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", WHT"终南武圣"NOR+RED"◆"RED"护派金刚"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", WHT"终南武圣"NOR+RED"◆"MAG"神武天尊"NOR);
		} else {
			me->set("nick", WHT"终南武圣"NOR+RED"◆"CYN"傲剑天皇"NOR);
		}

		tell_object(me, "老者对你说：你可以做"+me->query("nick")+"。\n");
		tell_room(environment(me),
"老者对"+me->query("name")+"说：你可以做"+me->query("nick")+"。\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","现授予本门弟子"+me->query("name")+""+me->query("nick")+HIC"一职。恭请各位仙长多加捧场！");
		me->save();  
	}
	return 1;
}
