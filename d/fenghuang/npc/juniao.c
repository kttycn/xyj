inherit NPC;

void create()
{
        set_name("����ͭ����", ({ "ju niao", "niao" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ���͵ľ���\n");
        set("attitude", "peaceful");
        
        set("str", 30);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "���", "���", "���" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 250000);

        
        set_temp("apply/attack", 50);
        set_temp("apply/damage", 50);
        set_temp("apply/armor", 50);

        setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
            this_player()->query_temp("������")) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }       
}


