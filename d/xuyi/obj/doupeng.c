// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

#include <armor.h>
inherit SURCOAT;

void create()
{
	set_name("����", ({ "dou peng" }));
	set("long", "����һ����ɫ���Ķ���\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 200);
		set("armor_prop/armor", 3);
	}
	setup();
}

