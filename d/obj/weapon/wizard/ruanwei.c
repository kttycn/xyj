// ruanwei jia

#include <armor.h>

inherit ARMOR;

void create()
{
    set_name( "��⬼�",({ "ruanwei jia","jia", }) );
    set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "һ����ƮƮ�ġ��������񵹴̵Ļ��ס�\n");
		set("material", "copper");
		set("value",0);
		set("armor_prop/armor", 75);
		set("armor_prop/dodge", -5);
	}
	setup();
}