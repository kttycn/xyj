#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "�֮��" NOR, ({ "qiongji zhishi","key","yaoshi","qiongjizhishi" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���ܿ����ħ���ĺڰ�֮��. \n");
		set("unit", "��");
		set("material", "gold");
		set("no_give", 1);
	}
	setup();
}

void init ()
{
	call_out ("destruct_me",600,this_object());
}

void destruct_me (object me)
{
	message_vision(HIY "ֻ��һ������������֮���ѷ������!\n" NOR,me);
	destruct (me);
}

