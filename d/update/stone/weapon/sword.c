// yitian-jian 倚天剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIC"倚天剑"NOR,({ "yitian jian", "yitian", "sword", "jian" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 0);
		set("rigidity", 9);
		set("sharpness", 9);
		set("material", "steel");
		set("weapon_prop/dodge", 5);
		set("weapon_prop/parry", 5);
		set("treasure",1);
		set("wield_force", 300);
		set("wield_maxforce", 700);
		set("wield_str", 22);
		set("wield_msg", HIY"$N“唰”的一声抽出倚天剑挽了个剑花，但见寒芒吞吐，电闪星飞。\n$N不由得从心底升起一股凌云豪气。\n"NOR);
		set("long", "是一把三尺长短的金色宝剑，金鳞闪闪，剑柄上嵌着一个颗明珠，划尖处现着一颗龙头，龙口不远的地方，还嵌了一粒细小珠儿，一柄金黄色的宝剑，剑柄上全发出十彩豪光，宛如慧星运行空际，瑰丽绝伦，\n而剑身迸出万道金芒，千条彩瑞，红莲朵朵，隐蕴风雷。最奇的是金芒中幻出一条紫色龙影，金鳞闪烁，龙口喷出一颗五彩圆球，回转不已，似实似虚，剑柄上，刻着四个虫形古字，麟儿文学素养极高，一看却认出那是“轩辕至宝“剑鞘里面，也系一种金黄色的金属制成，上包蚊皮，蚊皮上缀着明珠数百颗，全用金黄色的天蚕丝交织而成，光华闪闪，巧夺天工
		\n");                
		set("unwield_msg", HIY "倚天剑幻作一道白光，「唰」地飞入剑鞘。\n" NOR);                
	}
	init_sword(170);
	setup();
}
