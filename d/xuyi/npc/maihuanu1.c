// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
object flower;

void create()
{
       set_name("����Ů", ({"maihua nu","nu","girl"}));
       set("gender", "Ů��");
       set("combat_exp", 1000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
        set("vendor_goods", ([
                "flower": "/d/city/obj/flower",
        "hualan": "d/xuyi/obj/hualan",
        "rose": "/d/obj/flower/hua",
        "rose999": "/d/obj/flower/rose999",

        ]) );
       setup();

       carry_object("/d/obj/cloth/skirt")->wear();
       carry_object("/d/obj/cloth/shoes")->wear();
       add_money("silver", 1);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {  // 1/3 chance to greet.
            case 0 : command("say ���ڵĻ���������ѽ��"); break;
        }
}

int do_buy(string what)
{
    int have_money, need_money = 30000;
    object me = this_player();
    if(what != "flower") return 0;
    if(!flower) flower = new("/d/city/obj/flower");
    if(have_money = me->can_afford(need_money)) {
        if(have_money == 2) {
            tell_object(me, "��û���㹻����Ǯ������Ʊ��û���ҵÿ���\n");
            return 1;
        }
        me->pay_money(need_money);
        message_vision("$N������Ů����һ��"+flower->query("name")+"��\n", me);
        flower->move(me);
        flower=0;
    }
    else
        tell_object(me, "���Ǯ������\n");
    return 1;
}


void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

