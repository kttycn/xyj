
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
              set_name("����"+HIW+"��ѩ"+NOR+"���԰�", ({ "board" }) );
            set("location", "/u/yudian/workroom");
            set("board_id", "yudian_b");
            set("long",     "������˲��ڼң��������ԣ�лл��\n" );
	setup();
          set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
