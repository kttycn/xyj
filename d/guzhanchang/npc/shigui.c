// /d/guzhanchang/npc/shigui.c ʳʬ��
// stone 20020621

/************************************************************/
#include <ansi.h>
inherit NPC;

int accept_object(object me, object ob);
/************************************************************/

void create()
{
  set_name("ʳʬ��", ({"shi gui", "yao", "gui", "monster"}));
  set("long","����һ��ȫ��մ���˻����ĺ��ǣ���Ȼ����һЩ������ڹǼ��ϡ�\n");
  set("gender", "����");
  set("age", 40+random(15));
  set("attitude", "peaceful");
  set("combat_exp", 200000);
  set("daoxing", 100000);

  set_skill("unarmed", 200);
  set_skill("parry", 200);
  set_skill("dodge", 200);
  set_skill("blade", 200);
  set_skill("kugu-blade", 200);
  map_skill("blade", "kugu-blade");
  map_skill("parry", "kugu-blade");
  map_skill("dodge", "kugu-blade");
  set("chat_chance", 20);
  set("chat_msg", ({
	"ʳʬ���������Ҳ��֪���������˶���ˣ��þ�û������ʬ�ˡ�\n",
	"ʳʬ�������������ˣ�������ʬ����ʲôζ���ˣ�\n",
	"ʳʬ����������ȥ���һ�ٰ���\n",
	}) );
  set("inquiry", ([
	"name":		"���֣�ʲô���֣�����Ͳ��ǵ��ˡ�",
	"here":		"��������Ǹ��Ƶط���Ҫ�����Ǹ����ʶ�������ҿ��ţ������ȥ����ʬ�����帣�ˣ�",
	"rumors":	"�ٺ٣��Ҷ��������ɺ�Щ���ˣ�����֪����ʲô��",
	"��ʬ":		"��......�ܳ��ϵ����ʵ���ʬ�ͺ��ˡ�",
	"ʬ��":		"ʬ�壬������ζ�����þ�û�����ˣ��������������",
	]));

  setup();
  carry_object("/d/obj/weapon/blade/blade")->wield();
}

/************************************************************/

void init()
{
    object ob;
    ::init();

    if (interactive(ob=this_player()) && !is_fighting())
    {
	remove_call_out("greeting");
	call_out("greeting", 1, ob);
    }
}

void greeting(object me)
{
    string myrude=RANK_D->query_rude(me);
    command("hehe "+me->query("id"));
    command("say ����"+myrude+"�������ʲô����û�д��ö���Т�������ţ�");
    return;
}
/************************************************************/
int accept_object(object me, object ob)
{
        if( (string)ob->query("id")=="corpse" )
    {
	command("say ��������С�ӹ�Ȼ��û�����ң�");
	message_vision(CYN"ʳʬ��һ�ӵ�ʬ�壬�����ſڴ��������......\n\n\n�����������˵�������óԣ��óԣ�������ζ����\n"NOR, me);
	me->add_temp("guzhanchang/gave_guard_corpse", 1);
	return 1;
    }
    command("say ʲô�����⣿");
    return 0;

}

/************************************************************/

void die()
{
    string msg;

    msg="ʳʬ��ɢ��һ�ѿݹǣ�����һ�ѻ�����\n";
    msg+=CYN"����˷����������Ц����ɱ��һ�Ѻ��ǣ������ǳ������룡�һ�����ģ�\n"NOR;
    if(environment())
	message("vision", msg, environment());
    destruct(this_object());
}
�