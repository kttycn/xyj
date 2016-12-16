//flower.c
inherit ITEM;

void create()
{
    set_name("[1;31mºìÃµ¹å[2;37;0m", ({ "red flower", "rose","flower" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¶ä½¿ÑŞÓûµÎµÄ»ÆÃµ¹å¡£\n");
		set("unit", "¶ä");
		set("value", 100);
		set("material", "plant");
		set("armor_prop/armor", 0);
		set("armor_prop/personality", 3);
		set("wear_msg", "$NÇáÇáµØ°ÑÒ»¶ä$n´÷ÔÚÍ·ÉÏ¡£\n");
		set("unwield_msg", "$NÇáÇáµØ°Ñ$n´ÓÍ·ÉÏ³ıÁËÏÂÀ´¡£\n");
		set("female_only", 1);
	}
    setup();
}
