// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// yahuan1.c

inherit NPC;

void create()
{
       set_name("Ѿ��", ({"yahuan"}));
       set("long","һ��СѾ�������Ų�ˮ�ź���С��̫�ӡ�\n");
       set("gender", "Ů��");
       set("age", 16);
       set("attitude", "friendly");
       set("shen_type", 1);
   set("combat_exp", 500);
   setup();
        carry_object("/d/obj/cloth/skirt")->wear();
}

