#include <armor.h>
#include <ansi.h>
inherit BOOTS; 
void create()
{
	set_name(HIB "��Ƥѥ"NOR, ({ "boots", "pi xue", "xue" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "˫");
		set("long", "����һ˫���Ϻ���Ƥ����Ƥѥ����˵�ɻ�����ڡ�\n");
		set("value", 40000);
		set("armor_prop/dodge", 5);
	}
	setup();
}

