//EDIT BY LUCAS
#include <ansi.h>
inherit NPC;

void create()
{
       set_name("������", ({"youwu gongzhu","gongzhu","youwu"}));

        set("long","�����������������ã�\n������˪����ѩ,ӳ��ճ¶������.ӣ����������,������ϼѬ��ȹ��\n");
       set("gender", "Ů��");
       set("age", 20);
       set("int", 30);
       set("title", "��������");
       set("attitude", "peaceful");
       set("combat_exp", 1000000);
       set("rank_info/respect", "��������");
       set("class","dragon");
       set("per", 40);
       set("max_kee", 1000);
       set("max_sen", 8000);
       set("force", 1000);
       set("max_force", 1000);
       set("force_factor", 50);
       set("max_mana", 1000);
       set("mana", 1000);
       set("mana_factor", 80);
       set_skill("literate", 120);
       set_skill("unarmed", 100);
       set_skill("dodge", 150);
       set_skill("force", 120);
       set_skill("parry", 130);
       set_skill("fork", 100);
       set_skill("spells", 150);
       set_skill("seashentong", 140);
       set_skill("dragonfight", 100);
       set_skill("dragonforce", 100);
       set_skill("dragon-cha", 100);
       set_skill("dragon-steps", 150);
       map_skill("spells", "seashentong");
       map_skill("unarmed", "dragonfight");
       map_skill("force", "dragonforce");
       map_skill("fork", "dragon-cha");
       map_skill("parry", "dragon-cha");
       map_skill("dodge", "dragon-steps");

        set("chat_chance",5);
        set("chat_msg", ({
                "����˵��: ��˵�е���Ƥ���ǵ��������������֮�������������ʶ��ʶ��\n",
                "����̾��: ��������Ƥ�׺��������������ڣ���ô���ܽ�ȥ�����أ�\n",
        }) );
          set("inquiry", ([
                "��ڣ" : "�����������صء���������ȥ�ʸ����ɡ�\n",
                "��Ƥ��" : "�����ǵ��������������֮����������˵���Լ����������������\n",
        ]));


    create_family("��������", 2, "ˮ��");
        setup();

        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/sea/obj/yincha")->wield();
}

