// menggubing.c------yaoguai.c
//С����(yushu)�޸�
#include <ansi.h>
inherit NPC;

string *names = ({
  "ʨ��������",
  "�޵׶�����",
  "���ƶ�����",
  "�̲�̷����",
  "��ɽ����",
  "�׹Ƕ�����",
  "����ɽ����",
  "����ɽ����",
  "��˿������",
  "�̲�̶����",
  "ͨ�������",
});
void create()
{
   string str;
   set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai"}));
   set("long", "��׼��ɱ���ƻʵ۵����֡�\n");
   set("title", HIR"����Ƶ�"NOR);
   set("race", "Ұ��");
   set("age", 100+random(201));
   set("combat_exp", 500000+random(500001));
   set("daoxing", 500000+random(500001));
   set("limbs", ({ "ͷ��", "����", "ǰצ", "β��", "��Ƥ", "��צ"}) );
   set("verbs", ({ "bite", "claw"}) );
   set("attitude", "aggressive");
   set("per", 10);
   set("bdt", 1);
   set("max_kee", 1000);
   set("kee", 2000);
   set("sen", 2000);
   set("max_sen", 1000);
   set("force", 2000);
   set("mana", 2000);
   set("max_mana", 2000);
   set("max_force", 2000);
   set("force_factor", 75);
   set("mana_factor", 75);
   set_skill("parry", 200);
   set_skill("qixiu-jian",150);
   set_skill("kugu-blade",150);
   set_skill("unarmed", 200);
	set_skill("yinfeng-zhua",150);
   set_skill("dodge", 200);
   set_skill("spells",200);
   set_skill("yaofa",150);
   set_skill("blade", 200);
   set_skill("force",200);
   set_skill("huntian-qigong", 150);
   map_skill("blade","kugu-blade");
   map_skill("parry","kugu-blade");
   map_skill("dodge","kugu-blade");
   map_skill("spells","yaofa");
   map_skill("force","huntian_qigong");
   
   add_temp("apply/damage", 50);
   setup();
   carry_object("/d/obj/cloth/shoupiqun")->wear();
   carry_object("/d/qujing/jilei/obj/armor")->wear();
   carry_object("/d/obj/weapon/blade/blade")->wield();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && 
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner;
	message("vision",
		 name() + "˵��������ȥ�Ѵ��ƻʵ�ɱ�ˣ�\n\n"
		+ name() + "����ھ���һ���粻���ˡ�\n" , environment(),
		this_object() );
	destruct(this_object());
}

void die(){ destruct(this_object());}

