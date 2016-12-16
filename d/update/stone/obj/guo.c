//snowqinseng.c
//stone
//20020221

#include <ansi.h>
inherit ITEM;

int do_eat(string);
void destroy();
void init();

void init()
{
	if(this_player()==environment())
		add_action("do_eat", "eat");
}

void create()
{
	set_name(HIW"ǧ��ѩ��"NOR, ({HIR"xue shen"NOR,"xueshen","snowshen"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIW"����һ��ͨ��ѩ�ף���Ө��͸��ǧ��ѩ�Ρ�һ����֪����Ѱ��֮�\n"NOR);
		set("value", 900000);
		set("drug_type", "��Ʒ");
	}
	set("is_monitored",1);
	setup();
}

void create()
{
	set_name(HIR"ǧ��ѩ��"NOR, ({HIR"xue shen"NOR,"xueshen","snowshen"}));
	set_weight(800);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��������������γɵ������ӡ�\n");
		set("unit", "��");
		set("material", "bone");
	}
	setup();
}

int init()
{
	add_action("do_mo","mo");
	check_owner();
	return 1;
}
int do_mo(string arg)
{
	string type;
	object who = this_player();
	object ob;

	if(who->is_fighting())
		return notify_fail("��������˵��\n");
	if(who->is_busy())
		return notify_fail("����æ����!\n");
	 if (!arg)
 return notify_fail("�����������ӱ��ʲô������(sword blade stick hammer fork axe spear staff whip)\n");
	else
	{
		sscanf(arg,"%s",type);
		switch(type)
		{

case "sword":
	message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" տ¬"NOR+HIW"�� \n"NOR,who);
	message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR" տ¬"+HIW"�� "NOR+YEL"�ˣ�\n\n"+NOR,users() );

	ob = new("/d/shendian/babu/obj/gujian");
	ob->move(who);
	destruct(this_object());
	break;
case "blade":
	message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" ����"NOR+HIW"�� \n"NOR,who);
	message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR" ����"+HIW"�� "NOR+YEL"�ˣ�\n\n"+NOR,users() );
	ob = new("/d/shendian/babu/obj/gudao");
	ob->move(who);
	destruct(this_object());
	break;
case "stick":
	message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" ����"NOR+HIW"�� \n"NOR,who);
	message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR" ����"+HIW"�� "NOR+YEL"�ˣ�\n\n"+NOR,users() );
	ob = new("/d/shendian/babu/obj/gustick");
	ob->move(who);
	destruct(this_object());
	break;
case "hammer":
	message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" ����"NOR+HIW"�� \n"NOR,who);
	message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR" ����"+HIW"�� "NOR+YEL"�ˣ�\n\n"+NOR,users() );
	ob = new("/d/shendian/babu/obj/guhammer");
	ob->move(who);
	destruct(this_object());
	break;
case "fork":
	message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" �·�"NOR+HIW"�� \n"NOR,who);
	message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR" �·�"+HIW"�� "NOR+YEL"�ˣ�\n\n"+NOR,users() );
	ob = new("/d/shendian/babu/obj/gufork");
	ob->move(who);
	destruct(this_object());
	break;
case "axe":
	message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" ��Ȫ"NOR+HIW"�� \n"NOR,who);
	message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR" ��Ȫ"+HIW"�� "NOR+YEL"�ˣ�\n\n"+NOR,users() );
	ob = new("/d/shendian/babu/obj/guaxe");
	ob->move(who);
	destruct(this_object());
	break;
case "spear":
	message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" ��¯"NOR+HIW"ǹ \n"NOR,who);
	message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR"��¯"+HIW"ǹ"NOR+YEL"�ˣ�\n\n"+NOR,users() );
	ob = new("/d/shendian/babu/obj/guqiang");
	ob->move(who);
	destruct(this_object());
	break;
case "staff":
	message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" ����"NOR+HIW"�� \n"NOR,who);
	message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR"����"+HIW"��"NOR+YEL"�ˣ�\n\n"+NOR,users() );
	ob = new("/d/shendian/babu/obj/gustaff");
	ob->move(who);
	destruct(this_object());
	break;
case "whip":
	message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" ����"NOR+HIW"�� \n"NOR,who);
	message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR" ����"+HIW"�� "NOR+YEL"�ˣ�\n\n"+NOR,users() );
	ob = new("/d/shendian/babu/obj/guwhip");
	ob->move(who);
	destruct(this_object());
	break;
		}
		return 1;
	}
}
