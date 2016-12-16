//change.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int rank_me();

void create()
{
	set_name("��ū", ({"yue nu", "yuenu", "yue","master"}));
	set("long",
"�����ǹ��������֮�������ɣ�����϶�Ϊʦ��\n");
	set("title", "����");
	set("gender", "Ů��");
	set("age", 20);
	set("class", "xian");
	set("attitude", "friendly");
	set("rank_info/respect", "�ɹ�");
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
		"ְλ": (: rank_me :),
	]) );

	create_family("�¹�", 3, "����");
	setup();

	carry_object("/d/moon/obj/luoyi")->wear();
//  carry_object("/d/moon/obj/guihuajian")->wield();
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "�㺮������")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
	if( (string)me->query("family/family_name") == "�¹�"){
		if( exp <= 500000 ) {
			return notify_fail("��������ѧ̫�ͣ���������Ҫʲôְλ��\n");
		} else if(exp <= 1000000 ){
			me->set("nick", HIM"�����¹�"NOR+RED"��"BLU"������Ů"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", HIM"�����¹�"NOR+RED"��"YEL"�����輧"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", HIM"�����¹�"NOR+RED"��"RED"Ʈ������"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", HIM"�����¹�"NOR+RED"��"MAG"��ңʥŮ"NOR);
		} else {
			me->set("nick", HIM"�����¹�"NOR+RED"��"CYN"����ʥĸ"NOR);
		}

		tell_object(me, "��ū����˵���������"+me->query("nick")+"��\n");
		tell_room(environment(me),
"��ū��"+me->query("name")+"˵���������"+me->query("nick")+"��\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","�����豾�ŵ���"+me->query("name")+""+me->query("nick")+HIC"һְ�������λ�ɳ����������");
		me->save();  
	}
	return 1;
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="Ů��")){
           command("shake");
           command("say �����¹�ֻ��Ůͽ����λ" +
RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
           return;
        }

        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ�����������¹�������\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}
�
