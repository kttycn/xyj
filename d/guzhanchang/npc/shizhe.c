// lao ren, 9-28-97 pickle

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string kick_back();

void create()
{
  set_name("��ڤʹ��", ({ "shizhe", "zhe" }));

  set("gender", "����");
  set("age", 100);

  set("str", 20);
  set("per", 130);
  set("cor", 30);
  set("cps", 75);
  set("kar", 100);
  set("int", 40);
  set("con", 40);
  set("spi", 40);

  set("long","
����ǳ�ڤ����ػ�����

");
  set("title", "����");
  set("combat_exp", 2000000);
  set("daoxing", 2000000);


  set_skill("literate", 150);
  set_skill("unarmed", 100);
  set_skill("force", 100);
  set_skill("lengquan-force", 100);
  set_skill("axe", 150);
  set_skill("sword", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("sanban-axe", 180);
  set_skill("xiaofeng-sword", 100);
  set_skill("spells", 160);
  set_skill("baguazhou", 160);
  set_skill("yanxing-steps", 100);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("axe", "sanban-axe");
  map_skill("parry", "sanban-axe");
  map_skill("dodge", "yanxing-steps");
  map_skill("sword", "xiaofeng-sword");

  set("max_sen", 4500);
  set("max_kee", 3500);
  set("force", 1500); 
  set("max_force", 1500);
  set("force_factor", 40);
  set("max_mana", 3000);
  set("mana", 3000);
  set("mana_factor", 50);

  set("inquiry", ([
           	"������"  : (: kick_back :),
           	"sky"  : (: kick_back :),
]) );


  setup();
  carry_object("/d/obj/weapon/axe/huafu")->wield();
  carry_object("/d/obj/armor/jinjia")->wear();
}

string kick_back()
{
    object me=this_player();

    message_vision(CYN"$n˵��������ô֪��������ģ����ˣ�������Ե����������һ�̰ѣ�\n"NOR, me, this_object());
    message_vision(CYN"��ڤʹ��˦�����䣬������ǰһ��...��\n"NOR, me);
    me->move("/d/guzhanchang/sky");
    message_vision("$NƮƮȻ�� ..\n", me);
    return "";
}
int accept_fight(object me)
{
  command("say ������粻���㶯�֣�");
  return 0;
}

void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");
}
int do_none()
{
        object me = this_object();
        message_vision("������磬������������\n",me);
        return 1;
} 

