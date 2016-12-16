inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(HIC"∑ÔªÀ≥«¡Ù—‘∞Â"NOR, ({ "board" }) );
        set("location", "/d/fenghuang/zhongxin");
        set("board_id", "fenghuang_b");
        set("long", "’‚ «∑ÔªÀ≥«µƒ¡Ù—‘∞Â°£\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

