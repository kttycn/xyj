// hudieclip.c
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
	set_name(HIG"�������"NOR, ({"hudie jia", "hudie clip","clip"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("long", HIG"�Ǻ�����У���ʽ���ӣ�����һƬ���̹⻪������ȴ�ų�
�����⣬����������һ����֪����һ����ֵ���ǵı��\n"NOR);
		set("value", 10000000);
		set("material", "plant");
		set_weight(10);
		set("armor_prop/armor", 30);
		set("armor_prop/personality", 5);
		set("wear_msg", "$N����ذ�һֻ$n�������ޱߣ�ǡ��һֻ��������������ޡ�\n");
		set("unequip_msg", "$N����ذ�$n�����ޱ�ժ��������\n");
		set("female_only", "����Ů�˼ҵ������һ��������Ҳ������߲��ߣ�");
	}
	set("is_monitored",1);
	setup();
}
