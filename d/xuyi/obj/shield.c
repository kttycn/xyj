// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("������", ({ "tianlong dun", "dun","shield" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 10000);
		set("material", "skin");
		set("armor_prop/armor", 50);
		set("armor_prop/dodge", -10);
	}
	setup();
}



