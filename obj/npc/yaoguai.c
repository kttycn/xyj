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
   set_skill("unarmed", 200);
   set_skill("dodge", 200);
   set_skill("blade", 200);
   add_temp("apply/damage", 50);
   setup();
   carry_object("/d/obj/cloth/shoupiqun")->wear();
   carry_object("/d/qujing/jilei/obj/armor")->wear();
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

