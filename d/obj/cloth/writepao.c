#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��˿��", ({"baipao", "cloth"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һ����ɫ��˿�����ۣ��ü���ϸ����������ϸ�壬���������з��ˣ�\n");
		set("material", "cloth");
		set("unit", "��");
		set("value", 800);
		set("armor_prop/armor", 25);
	}
	setup();
}

