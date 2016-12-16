// by night
// fid �޸�

#include <ansi.h>

inherit NPC; 
//inherit F_DEALER; 
void consider();
int ask_gift(); 
int ask_cake();
void create()
{
	set_name(HIB"ҹ"NOR+HIG"����"NOR, ({ "spirit" }) );
	set("nickname", MAG "����" NOR);
	set("gender", "Ů��" );
	set("age", 16);
	set("long", 
"����¥�����ˣ������ž���¥��һ������\n" );
	set("attitude", "friendly");
	set("shen_type", 1);
	set("class", "phoenix");

	set("str",21);
	set("int",28);
	set("con",40);
	set("per",40);

	set("kee", 2000);
	set("max_kee", 2000);
	set("sen", 1000);
	set("max_sen", 1000);
	set("force", 6000);
	set("max_force", 3000);
	set("mana", 6000);
	set("max_mana", 3000);
	set("force_factor", 300);
	set("combat_exp", 1000000);
	set("daoxing", 2500000);
	set_skill("blade",300);
	set_skill("dodge",300);

	set("inquiry", ([
		"��������" : "����������ϲ������Ŷ�����Բ����ˣ���\n", 
		"����" : (: ask_gift :),
		"��������" : (: ask_gift :),
		"Ǫ�����ֲ�" : (: ask_gift :), 
		"��������" : (: ask_cake :),      ]));

	set("chat_chance",30);
	set("chat_msg", ({
		"���������ó�һ��"+HIW"���������"NOR+"��ר�ĵض���������\n", 
		"�����������Ź�âһ��һ�������ĵ�˵������ôû�����������أ���\n",
		"��������Ц������˵����Ҫ����������ҾͶ��ˡ���\n",      }) );
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "shield" :),
	}) );
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: exert_function, "eyes" :),
	}) ); 
	set("vendor_goods", ({
		"/d/city/obj/candle",//�����·�����Զ��塣
	}));
	setup();
	carry_object("/d/city/obj/moon-dress")->wear();
	carry_object("/d/obj/weapon/blade/blade")->wield(); 
//        carry_object("/u/jave/obj/gun");
} 

int ask_cake()
{ 
	object ob;
	if (this_player()->query("birth"))
	{
		command("say ��ϲ��ϲ��ף�����տ��֣�\n");
		ob=new("/d/city/obj/cake");  //�����·�����Զ��塣
		ob->move(this_player()); 
		message_vision("\n$N����$nһ�����Ƶ����յ��⡣\n",  this_object(),this_player());
		this_player()->delete("birth"); 
		return 1;
	}
	return 0;
}
 
int ask_gift()
{
	if ( (string)this_player()->query("id")=="fid" )    {
		command("say �����������\n");
		this_player()->move("d/city/clubgate");
	}
	else
	{
		command("say Ҫ�����ǰɣ���ȥ�ɡ�\n"); 
		this_player()->move("d/city/clubgate");
		this_player()->delete("giftsp");
	}
	return 1;
}
void init()
{ 
	add_action("do_list", "list");
	add_action("do_buy", "buy"); 
	add_action("do_faint", "18mo");
	add_action("do_faint", "kiss");
	add_action("do_faint", "taste"); 
	add_action("do_faint", "hug");
	add_action("do_faint", "beg");
}
 
void unconcious ()
{
	die ();
}  
void die()
{
	object ob;
	command("sigh");
	message_vision(HIW"\n$N���ϳ���һ��͸��������һ��һ�ϼ䣬$N�ֱ��������ȡ�\n"NOR, this_object());
	set("kee", 2000);
	set("max_kee", 2000);
	set("sen", 1000);
	set("max_sen", 1000);
	set("force", 3000);
	set("max_force", 3000);
} 


int do_faint()
{
	object me, ob;
	me=this_object();
	ob=this_player();
	message_vision("$N��һ�죬˵������ѽ������ô�ܶ�������ô���������أ���\n" NOR, me);
	message_vision("˵�գ��������˾����$N��ǰһ�ڣ����˹�ȥ��\n",ob);
	ob->set("immortal",0);
	ob->delete("immortal");
	ob->unconcious();
	return 1;
}
