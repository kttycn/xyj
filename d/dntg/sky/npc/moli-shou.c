// huguo-tianwang.c
//created 4-8-97 pickle
inherit NPC;
 
void create()
{
        set_name("ħ����", ({ "moli shou", "chiguo tianwang", "shou", "tianwang", "wang" }) );
        set("gender", "����" );
        set("long","
�Ĵ�����֮һ�����ű����󹬰�ȫ���ص�����ͬС�ɡ���
���书�ƺ�������һ�ɣ������������������ɱ�־��У���
û����֪����ʲô��Ҳ������Ϊ��ˣ���ʲŷ�����������
���Ρ�\n"
        );
	set("class", "xian");
	set("title", "�ֹ�����");
        set("age",43);
        set("str",30);
        set("int",37);
        set("max_kee",1200);
        set("kee",1100);
        set("max_sen",1100);
        set("sen",1100);
        set("combat_exp",1000000);
        set("daoxing",1200000);
        set("force",2500);
        set("max_force",1500);
        set("mana",2500);
        set("max_mana",1500);
        set("force_factor", 70);
        set("mana_factor",80);

        set("eff_dx", 450000);
        set("nkgain", 450);

        set_skill("unarmed",140);
	set_skill("changquan", 150);
        set_skill("parry",140);
        set_skill("dodge",150);
        set_skill("mace",150);
	set_skill("spells", 140);
        set_skill("wusi-mace",150);
        set_skill("force",140);
	set_skill("moshenbu", 150);
	map_skill("dodge", "moshenbu");
        map_skill("mace","wusi-mace");
        map_skill("parry","lunhui-zhang");
	map_skill("unarmed", "changquan");
        set("inquiry", ([
                "name" : "���¾��ǳֹ���������ʥ�Ͱ��ر����š�",
                "here" : "������Ǳ����ţ������Ǻ󹬽��ء�",
        ]) );
        setup();
	carry_object("/d/obj/fabao/biyu-pipa");
        carry_object("/d/obj/weapon/mace/copperjian")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}
