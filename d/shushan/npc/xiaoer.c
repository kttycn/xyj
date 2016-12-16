//����ɽ���ɡ�mhxy-yushu 2001/2
inherit F_VENDOR_SALE;
void create()
{
  reload("shushan_xiaoer_er");
  set_name("��С��", ({"xiao er","xiaoer","xiao","waiter","er"}));
  set("shop_id", ({"xiaoer", "xiao", "er", "waiter","er"}));
  set("gender", "����");
  set("combat_exp", 1000);
  set("age", 26);
  set("per", 14);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);
  set("vendor_goods", ([
    "jiudai": "/d/moon/obj/jiudai",
    "gourou": "/d/ourhome/obj/gourou",
     "jitui": "/d/ourhome/obj/jitui",
  "fusheyan": "/d/shushan/obj/fusheyan",
     "jitui": "/d/shushan/obj/hedinghong",
  "huasheng": "/d/ourhome/obj/huasheng",
    ]) );

  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  add_money("silver", 1);
}

void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
  add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
  if( !ob || !visible(ob) || environment(ob) != environment() ) return;
  switch( random(3) ) {  
    case 0:
      say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
            + "������ЪЪ�ţ������Ѱɡ�\n");
      break;
  }
}

int accept_object(object who, object ob)
{
  if (ob->query("money_id") && ob->value() >= 300) 
  {
    tell_object(who, "С��һ������˵������л���ϣ��͹�����¥ЪϢ��\n");
    who->set_temp("rent_paid",1);
    return 1;
  }
  return 0;
}
