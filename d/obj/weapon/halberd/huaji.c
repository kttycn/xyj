#include <weapon.h>

inherit HALBERD;

void create()
{
	set_name("���컭�", ({ "fangtian huaji", "huaji", "halberd","ji" }));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�˳��صķ��컭ꪣ������ޱȣ����ʺ���ս����ʹ�á�\n");
		set("value", 1000);
		set("material", "blacksteel");
	}
	init_halberd(35);
	setup();
}

