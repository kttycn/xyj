// whitexiu.c
// stone amend 20020315
inherit NPC;

void create()
{
        set_name("������ʿ", ({"xiu shi","xiushi","xiu","shi"}));
        set("gender", "����" );
        set("age", 25);
        set("long", "һλ������������������ɫ�������ֵֹģ��������������¡�\n");
        set("combat_exp", 10000);
        set("attitude", "peaceful");
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_skill("literate", 30);
        set_skill("force", 30);   
        set("per", 25);
        set("max_kee", 500);
        set("max_sen", 300);
        set("force", 150);
        set("max_force", 300);
        set("force_factor", 0);
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 20);
        set("chat_msg", ({
		"������ʿ��м��Ƴ����һ�ۣ��ֵ�ͷ�����е��顣��\n",       
		"������ʿ��������������������лƽ��ݣ��������������񡱡�\n",
		"������ʿüͷ��������ͷ��˼��\n",
		"������ʿ��������˵��������˵�С����Լ������ķ������ϧ��Եһ������������������\n",
		(: random_move :)
	}) );
        set("inquiry", ([
                "name" : "����ƨ�£�\n",
                "here" : "�����۾��㲻�ῴ����\n",
	    "Ԭ�س�" : "����ƭ�ӡ�ֻ���������ɵ�ϲ�������\n",
	    "��������" : "����ƭ�ӡ�ֻ���������ɵ�ϲ�������\n",
	    "book" : "���С����Լ����𣿿ɷ��С��һ�ģ����¸м����㡣\n",
	    "���Լ�" : "���С����Լ����𣿿ɷ��С��һ�ģ����¸м����㡣\n",	    
	 ]) );
}

	
int accept_object(object me, object ob)
{
	object plan;

	if(userp(ob)) return 0;

	if( (string)ob->query("name")=="�����Լ���" )
	{
		command("jump");
		command("thank" + me->query("id"));
		command("say ��λ" + RANK_D->query_respect(me) + "����С����ֿ�ѡ�\n������Ҳ��һ���飬�˸���׳Ԫ�����Ļ�ۡ�\n��ϧС�������ޱ����в��������壬��������"+ RANK_D->query_respect(me) +"�� ��\n");
		carry_object("/d/obj/book/plan");
		command("give plan to " + me->query("id"));
		return 1;
	}
/*	else if( (string)ob->query("id")=="book" )
	{
		message_vision("������ʿæ��ͷϸ��������\n");
		command("sigh");
		message_vision("������ʿ��$N������л"+RANK_D->query_respect(me)+"���顣\n��ϧ���ǡ����Լ�����С�����Ÿ����ķ��������Եһ����\n", me);
		command("give book to " + me->query("id"));
		return 1;
	}*/
}