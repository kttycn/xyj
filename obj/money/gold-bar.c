#include <ansi.h>
inherit MONEY;
//inherit ITEM;
void create()
{
	set_name(HIY"��Ӱ����"NOR, ({"gold-tiao", "bar", "gold-bar"}));
	set_weight(3200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "jintiao");
		set("long", HIY"һ����Ӱ��Ե�Ľ�����������ʯͷ����׿�����е�ȫ���񣬷�����ȫ����ʦ��ȫ�Ҹ���\n"NOR);
		set("unit", "��");
		set("base_value", 100000000);
		set("base_unit", "��");
		set("base_weight", 12);
	}
	set_amount(1);
}

