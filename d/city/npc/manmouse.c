//By waiwai @xyj-shxy  2000/07/10
//mouse.c

inherit F_VENDOR_SALE;
#include <ansi.h>

void create()
{
       reload("mouse");
       set_name(HIG "ˮ����" NOR, ({"suozhang mouse","mouse"}));
       set("title",HIW"����"NOR);
       set("gender", "����");
        set("combat_exp", 100000);
       set("age", 26);
       set("per", 104);
       set("str", 10000);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 1000);
        

       setup();

       carry_object("/d/obj/cloth/linen")->wear();
       add_money("silver", 1);
}

void init()
{       
        object ob=this_player();
	object me=this_object();

        ::init();

        if ( ((string)ob->query("gender")=="Ů��") &&
((int)ob->query("env/invisibility")  == 0) &&
((string)environment(me)->query("short")==HIM"���շ��вޡ�"NOR) )
        {

                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        switch( random(1) ) {
                case 0:
          command("rumor* ֻ��ˮ�������������" HIR+ ob->query("name") +HIM "�����������å����Ȼ�����в������ˣ�\n"NOR);
	   command("kick " + ob->query("id"));
          ob->move("/d/city/menwc");
              ob->unconcious();
           
                break;
        }
}

int accept_object(object who, object ob)
{
	if (ob->query("money_id","gold") && ob->value() >= 300000)
               who->set("water",0);
       if (ob->query("money_id","gold") && ob->value() >= 300000)
               who->set("food",0);
	{
		tell_object(who, "����һ������˵������л���ϡ�\n");
		
             
		return 1;
	}
	return 0;
}
