#include <ansi.h>
inherit NPC;
int rank_me();

void create()
{
	set_name("������", ({ "hu qiuniang", "hu" }));
	set("long", "һλ�����ޱȵ�Ů�ӣ���֪վ�Ÿ���\n");
	set("gender", "Ů��");
	set("age", 17);
	set("attitude", "heroism");
	set("per", 30);
	set("max_kee", 700);
	set("max_gin", 700);
	set("max_sen", 700);
	set("force", 700);
	set("max_force", 700);
	set("force_factor", 60);
	set("max_mana", 700);
	set("mana", 400);
	set("mana_factor", 60);
	set("combat_exp", 410000);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("force", 50);
	set_skill("spells", 50);
	set_skill("unarmed", 50);
	set_skill("staff", 50);
	set_skill("gouhunshu", 50);
	set_skill("tonsillit", 50);
	set_skill("ghost-steps", 50);
	set_skill("jienan-zhi", 50);
	set_skill("lunhui-zhang", 50);
	map_skill("unarmed", "jienan-zhi");
	map_skill("force", "tonsillit");
	map_skill("spells", "gouhunshu");
	map_skill("staff", "lunhui-zhang");

	set("inquiry", ([
		"ְλ": (: rank_me :),
	]) );

	setup();
	carry_object("/d/obj/cloth/gongpao")->wear();
	carry_object("/d/qujing/biqiu/obj/ring")->wear();
	carry_object("/d/qujing/biqiu/obj/neck")->wear();
	carry_object("/d/qujing/biqiu/obj/wrists")->wear();
}


void die ()
{
	object me = this_object();
	object ob;
         ob=new("/d/qujing/xuanyuan/obj/pipa");
	message_vision ("\n$N���ڵ�������ԭ��ԭ��һֻ���þ���\n",me);
          ob->move(environment());//ԭ��ob->move(environment(this_object()));
//          call_out("destory",1,me); 
          destruct(me);
}

void destory(object me)
{
	destruct(me);
}

void unconcious ()
{
	die ();
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "���ĺ���")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
	if( (string)me->query("family/family_name") == "��ԯ��Ĺ"){
		if( exp <= 500000 ) {
			return notify_fail("��������ѧ̫�ͣ���������Ҫʲôְλ��\n");
		} else if(exp <= 1000000 ){
			me->set("nick", WHT"��ԯ��Ĺ"NOR+RED"��"BLU"͵������"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", WHT"��ԯ��Ĺ"NOR+RED"��"YEL"�������"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", WHT"��ԯ��Ĺ"NOR+RED"��"RED"�������"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", WHT"��ԯ��Ĺ"NOR+RED"��"MAG"���ǹ��"NOR);
		} else {
			me->set("nick", WHT"��ԯ��Ĺ"NOR+RED"��"CYN"��ԯ��ħ"NOR);
		}

		tell_object(me, "���������˵���������"+me->query("nick")+"��\n");
		tell_room(environment(me),
"�������"+me->query("name")+"˵���������"+me->query("nick")+"��\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","�����豾�ŵ���"+me->query("name")+""+me->query("nick")+HIC"һְ�������λ�ɳ����������");
		me->save();	
	}
	return 1;
}
