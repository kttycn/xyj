inherit NPC;

void create()
{
	set_name("��Ů", ({ "shi nv", "shi" }));
	set("age", 18);
	set("gender", "Ů��");
	set("long", "����������������Ů�������������ɡ�\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("cor", 16);
	set("per", 36);
	set("combat_exp", 18000);
	set("shen_type", 0);

	set("chat_chance_combat", 4);
	set("chat_msg_combat", ({
		"��ŮЦӯӯ�Ŀ����㣬��������������˽�������̸��ʲô\n",
		"��Ů̧ͷ������һ�£��ֵ���ͷȥ�ˡ\n",
	}));
	setup();
	carry_object("/d/fenghuang/obj/shoes")->wear();
	carry_object("/d/fenghuang/obj/dress")->wear();
}

