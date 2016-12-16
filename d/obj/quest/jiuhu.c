inherit ITEM;

#include "task.h"
void create()
{
	set_name("Òø¾Æºø", ({"yin jiuhu", "jiuhu"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "Öí°Ë½äºÈ¾ÆÓÃµÄ¾Æºø¡£\n");
		set("unit", "¼ş");
		set("owner_name","Öí°Ë½ä");
		set("owner_id","zhu bajie");
	}
}
