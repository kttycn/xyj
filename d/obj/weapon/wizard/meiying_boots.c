#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
	set_name(MAG"��Ӱ��ѥ"NOR, ({"meiying shenxuan", "meiying", "shoes" }) );
	set("long", "��֪�ú������ɣ�ͨ��ʰ���ɫ��͸��һ�����ص���Ϣ��\n");
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("material", "boots");
		set("armor_prop/armor", 32);
		set("armor_prop/dodge", 26);
		set("armor_prop/personality", 2);
		set("value", 0);
	}
	setup();
}

