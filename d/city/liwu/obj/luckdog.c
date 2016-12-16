#include <ansi.h>

inherit NPC;

string *fail_action=({
	"kill",
	"steal",
	"touxi",
	"ansuan",
	"chat*",
});

void create()
{
	set_name("���͹�", ({ "haba dog" ,"gou","dog"}) );
	set("title", HIY"���鹷"NOR);
	set("race", "Ұ��");    
	set("long", "����һֻ�ܿɰ��ĳ��ﹷ������ҡ��β�Ͷ��㡸��������ֱ�С�\n");
	set("attitude", "friendly");
	set("age", 2);
	set("str", 40);
	set("cor", 40);
	set("int", 40);

	set("limbs", ({ "ͷ��", "ǰצ", "���", "β��", "����"}) );
	set("verbs", ({  "claw","bite" }) );

	set_temp("apply/attack", 10);
	set_temp("apply/defense", 20);
	set("combat_exp",1500);
	set_skill("unarmed",20);
	set_skill("dodge",30);
	set_skill("parry",30);
	set("kee", 500);
	set("max_kee", 500);
	set("sen", 200);
	set("max_sen", 200);  
	set("is_monitored",1);
	setup();
   
}

void init()
{
    add_action("accept_order", "order");
}


int accept_order(string verb)
{
	object me,dog;
	string name, dothing,action,temp;
	int i;
	me = this_player();

	if( !verb || sscanf(verb, "%s to %s", name, dothing)<2 )
		return notify_fail("��Ҫ����˭��ʲ���£�\n");
                
	dog=present(name,environment(me));
	if(dog!=this_object())
	{
		return 0;
	} 
	if(!dog)
		return notify_fail("�������Ʒ��\n");

	if(dog->query("boss_id")!=me->query("id"))
		return notify_fail("��ֻ���͹�������İɣ�\n");

	for(i=0;i<sizeof(fail_action);i++)
	{
		sscanf(dothing,"%s %s",action,temp);
		if(action==fail_action[i])
			return notify_fail("��Ĺ��͹�����ҡ��ҡͷ���ƺ���Ը�����������\n");
	}
	tell_room(environment(me),me->name(1)+"�����"+dog->query("name")+"˵�˼��仰��"
		+dog->query("name")+"�����ҡ��ҡβ�͡�\n",me);

	tell_object(me,"���"+dog->query("name")+"˵����"+dothing+"����"
		+dog->query("name")+"�����ҡ��ҡβ�͡�\n");
	command( dothing );           
	return 1;
}

int accept_info(object me, string command)
{
	return (string)me->query("id") == (string)query("boss_id");
}


int accept_object(object me, object obj)
{   
	if(this_object()->query("boss_id")!=me->query("id"))
	{
		tell_object(me,"���붾���˼ҵļ�����ѽ��\n");
		return 0;
	}
	if(obj->query("food_supply"))
		message_vision(this_object()->query("name")+"���˵ض�$N����������ֱ�� ��\n",me);
	else
		message_vision(this_object()->query("name")+"��$Nҡ��ҡβ�� ��\n",me);
	return 1;
}
