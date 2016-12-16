inherit ITEM;
#include "task.h"

void create()
{
	set_name("¶ú¶ä°Î×Ó", ({"er ba", "ba zi"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "Ë³·ç¶úµÄ¶ú¶ä°Î×Ó.\n");
		set("unit", "¼þ");
		set("owner_name","Ë³·ç¶ú");
		set("owner_id","longear");
	}
}
