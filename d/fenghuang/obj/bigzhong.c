#include <weapon.h>
inherit HAMMER;
void create()
{
	set_name("����", ({ "giant bell" }) );
	set_weight(600000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���ں����Ѳ��ɿ��������ذ˴�������һЩ��������ͼ�Σ�������
�Ǽ�ͼ����һ��һǧ��\n");
		set("value", 3);
		set("material", "iron");
	}
	init_hammer(650);
	setup();
}
