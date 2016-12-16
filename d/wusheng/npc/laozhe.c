// laozhe.c

#include <ansi.h>

inherit NPC;
int rank_me();

void create()
{
	set_name(HIG"����"NOR, ({"lao zhe", "laozhe"}));
	set("long", "һ�����е����˼ң��������³�����\n");
	set("title", HIC"�����"NOR);
	set("gender", "����");
	set("age", 1000);
	set("class", "wusheng");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "����");
	set("looking", "Ӣ�������������ٷ磬�������Ρ�");
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
		"ְλ": (: rank_me :),
	]));

	setup();
	carry_object("/d/obj/armor/jinjia")->wear();
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "Ǭ������")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
	if( (string)me->query("family/family_name") == "��ʥ��"){
		if( exp <= 500000 ) {
			return notify_fail("��������ѧ̫�ͣ���������Ҫʲôְλ��\n");
		} else if(exp <= 1000000 ){
			me->set("nick", WHT"������ʥ"NOR+RED"��"BLU"��������"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", WHT"������ʥ"NOR+RED"��"YEL"�����޺�"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", WHT"������ʥ"NOR+RED"��"RED"���ɽ��"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", WHT"������ʥ"NOR+RED"��"MAG"��������"NOR);
		} else {
			me->set("nick", WHT"������ʥ"NOR+RED"��"CYN"�������"NOR);
		}

		tell_object(me, "���߶���˵���������"+me->query("nick")+"��\n");
		tell_room(environment(me),
"���߶�"+me->query("name")+"˵���������"+me->query("nick")+"��\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","�����豾�ŵ���"+me->query("name")+""+me->query("nick")+HIC"һְ�������λ�ɳ����������");
		me->save();  
	}
	return 1;
}
