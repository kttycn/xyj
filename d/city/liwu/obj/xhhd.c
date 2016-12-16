

#include <ansi.h>

inherit ITEM;

 void create()
{
	set_name(HIG "С���굤" NOR, ({"xiaohuanhun dan", "dan"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "һö���������������ĵ�ҩ��\n");
		set("value", 20000);
	}
	set("is_monitored",1);

	setup();
}

void init()
{
	if (!wizardp(this_player())) {
		set("no_get"," �ٺ٣����ΰ�! \n");
		set("no_drop","��ô����Ķ�������������! \n");
		set("no_give","��̫�����˰ɣ�\n");
	}
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();
	int i, level, which=0,max_level=0;
	mapping skill_status;
	string *sname;

	if( !living(me) ) return notify_fail("���뵱����\n");

	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	skill_status = me->query_skills();
	sname  = keys(skill_status);

	for(i = 0; i < sizeof(skill_status); i++) 
	{
		level = skill_status[sname[i]] ;  
		if(level>max_level)
		{
			max_level=level;
			which=i;
		}
	}

	if(max_level>100)
	me->set_skill(sname[which],max_level+2);
	else if(max_level>50) me->set_skill(sname[which],max_level+4);
	else me->set_skill(sname[which],max_level+8);

	message_vision(HIB"$N����һöС���굤������һ˿˿�Ļص������ڣ��о��ü���! \n"NOR,me);
	destruct(this_object());
	return 1;
}
