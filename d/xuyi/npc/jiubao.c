// �����硤���μǡ��汾(����)
 
// by jing 2000.7.14


inherit F_VENDOR_SALE;

void create()
{
  reload("xuyi_jiu_bao");
  set_name("�Ʊ�", ({"jiu bao", "bao"}));
  set("shop_id", ({"jiubao", "bao"}));
  set("gender", "����");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "jiuguan": "/d/xuyi/obj/jiuguan",
             ]) );

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

