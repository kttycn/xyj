//flower.c
inherit ITEM;

void create()
{
    set_name("[1;31m��õ��[2;37;0m", ({ "red flower", "rose","flower" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�使�����εĻ�õ�塣\n");
		set("unit", "��");
		set("value", 100);
		set("material", "plant");
		set("armor_prop/armor", 0);
		set("armor_prop/personality", 3);
		set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
		set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");
		set("female_only", 1);
	}
    setup();
}
