#include <ansi.h>
inherit MONEY;
//inherit ITEM;
void create()
{
	set_name(HIY"��Ӱ��ש"NOR, ({"gold-zhuan", "brick", "gold-brick"}));
	set_weight(6400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "jinkuai");
		set("long", HIY"һ����Ӱ��Ե�Ľ�ש��������ʯͷ����׿�����е�ȫ���񣬷�����ȫ����ʦ��ȫ�Ҹ���\n"NOR);
		set("unit", "��");
		set("base_value", 10000000000);
		set("base_unit", "��");
		set("base_weight", 24);
	}
	set_amount(1);
}

