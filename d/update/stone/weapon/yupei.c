#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(MAG"��������"NOR, ({"yu pei", "yupei"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("value", 20000);
		set("long", "һ����ɫ�������м�������һ�����������Բ�Σ����Ե����
ʮ���ڷ���������������֮�������Ϸ�����ǵ���֮�棬����
����ŷ�����棬�м���ϵһֻ���򣬶��ǵ���ɫ������ϸ��
����������������һ����ɫ�������⻪���������·�������ʮ��
������׭�֣����������壬���֮�棬��֮ά�£�����ʸ�롣\n");
		set("no_sell", 1);
		set("material", "steel");
		set("armor_prop/spells", 10);
		set("armor_prop/armor", 20);
		
        }
	setup();
}

