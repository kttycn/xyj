//shushan2 by yushu@SHXY 2000.12
#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("���Ҳ�", ({"qingyi chan", "chan", "staff"}) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 15000);
		set("material", "iron");
		set("long", "����һ�����������Ҳ����ִֵ���ͷ��һ����\n");
		set("wield_msg", "$N����һ��������$n�����˵Ĳ�ͷ����������\n");
		set("unequip_msg", "$N�����������е�$n��\n");
	}
	init_staff(50);
	setup();
}
