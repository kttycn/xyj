//2001.5.22
//by yxm
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�����Ƿ�", ({ "ayi nafa", "ayinafa", "nafa" }));
	set("long", "���������µ�һ�񵶣��ƹܰ����޽�Ĵ�����������Ĵ���Ӱ����Ƿ���
��˵����ͨ�����ڵ��κλ��أ�����,���Ŷݼ�֮�����Ƿ���ﲻ�ɶ�õ��˲š�
��ϧ���������������Ա��������������࿴��\n");
	set("title", HIW"����"HIR"��һ"HIW"��"NOR);
	set("gender", "����");
	set("age", 800);
	set("str",40);
	set("per",40);
	set("max_kee", 5000);
	set("max_gin", 5000);
	set("max_sen", 5000);
	set("force", 5000);
	set("max_force", 5000);
	set("force_factor", 300);
	set("max_mana", 5000);
	set("mana", 5000);
	set("mana_factor", 300);
	set("combat_exp", 3900000);
	set("daoxing", 28000000);
	set_skill("buddhism", 300);
	set_skill("dodge", 300);
	set_skill("force", 300);
	set_skill("jienan-zhi", 300);
	set_skill("literate", 300);
	set_skill("lotusforce", 300);
	set_skill("lotusmove", 300);
	set_skill("bingpo-blade", 300);
	set_skill("parry", 300);
	set_skill("spells", 300);
	set_skill("blade", 300);
	set_skill("unarmed", 300);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("blade", "bingpo-blade");
	map_skill("parry", "bingpo-blade");
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
		(: perform_action, "blade", "yaowu" :),
	}) );
	set("inquiry", ([
		"��ȸ����": "�ٺ٣�������ƽ����޵��ˣ�������ܰ���ɱ�������Ҿʹ���ȥһ���õط���",
		"��ȸ": "�ٺ٣�������ƽ����޵��ˣ�������ܰ���ɱ�������Ҿʹ���ȥһ���õط���",
		"��ĸ": "�ٺ٣�������ƽ����޵��ˣ�������ܰ���ɱ�������Ҿʹ���ȥһ���õط���",
	]));
	setup();
	carry_object("/d/obj/cloth/jia_sha")->wear();
	carry_object("/d/qujing/xiuluo/obj/shixieshendao")->wield();
}

int accept_object(object me, object ob)
{
	me=this_player();

	if( (string)ob->query("id")=="ziying-sword" )
	{
		if ( me->query("xiuluo/lingjiu_ok") != 1)
			return notify_fail("������ô�õ���ѽ���?!�ߣ�\n");
		else
		{
			command("u&me " + me->query("id"));
			command("say ��λ" + RANK_D->query_respect(me) + "�����������⣡\n���Ȼ���ҳ����˴����Ҳ����ʳ�ԡ�\n���ҵĿ����㴵������һ������ȥ�ɡ�\n........\n");
			tell_object(me,"\nһ�������㴵��...\n\n�������۾����Ѿ���������һ�����硣\n\n");
			command("rumor ��˵"HIR""+me->query("name")+""HIM"��"HIR"�����Ƿ�"HIM"������"WHT"�����޽�"NOR"��");
			me->set("xiuluo/lingjiu_ok",0);  
			me->move("/d/qujing/xiuluo/jiemen");
			return 1;
		}
	}
}