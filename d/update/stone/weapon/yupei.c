#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(MAG"紫龙玉佩"NOR, ({"yu pei", "yupei"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
		set("value", 20000);
		set("long", "一根乌色项链，中间悬挂着一块碧玉，玉作椭圆形，两旁雕刻着
十八宗佛像，栩栩如生，呼之欲出，上方雕的是道教之祖，下面
则刻着佛家释祖，中间则系一只玉球，都是淡绿色，如仔细观
看，球里面隐现着一条紫色金龙，光华闪闪，球下方，刻着十六
个古体篆字；“紫龙王佩，天地之奇，怀之维德，永勿矢离。\n");
		set("no_sell", 1);
		set("material", "steel");
		set("armor_prop/spells", 10);
		set("armor_prop/armor", 20);
		
        }
	setup();
}

