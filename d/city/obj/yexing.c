//By waiwai@mszj 2000/09/28

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(HIB"ҹ����"NOR, ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","����һ�������������ĺ�ɫ��װ�¡�\n");
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 20);
	}
	setup();
}
