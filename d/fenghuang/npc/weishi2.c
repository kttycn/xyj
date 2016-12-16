inherit NPC;

void create()
{
	set_name("��ǰ����", ({ "shi wei", "shi" }));
	set("age", 22);
	set("gender", "����");
	set("long", "��������������ǰ��������������������ѡ�ģ���һ��һ�ĸ��֡�\n");
	set("attitude", "peaceful");

	set("kee", 1000);
	set("max_kee", 1000);
	set("sen", 1000);
	set("max_sen", 1000);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 50);
	set("str", 32);
	set("cor", 28);
	set("combat_exp", 50000);
	set("shen_type", 1);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("blade", 80);
	set_skill("force", 80);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"��ǰ�������������������������£��书�ھ����ڣ��㻹��Ͷ��������\n",
    	"��ǰ�����ȵ�����Ҫ�ǲ�ͶЧ�Ļ����Ͽ�������ٲ������ҿ�Ҫ�����ˣ�\n",
	}));
	setup();

	carry_object("/d/fenghuang/obj/blade")->wield();
	carry_object("/d/fenghuang/obj/pixue")->wear();
	carry_object("/d/fenghuang/obj/junfu")->wear();
}

