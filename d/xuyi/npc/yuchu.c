// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

//created bye night

inherit NPC;

void create()
{
        set_name("����", ({ "yu chu", "yuchu" }));
        set("str", 50);
        set("gender", "����");
        set("age", 50);
        set("long", "���ǻʹ���������ͨ������ʳ����⿡�\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");

        setup();
        carry_object("/d/xuyi/obj/guazi")->wear();
}

