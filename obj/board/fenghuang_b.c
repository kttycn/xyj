inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(HIC"��˳����԰�"NOR, ({ "board" }) );
        set("location", "/d/fenghuang/zhongxin");
        set("board_id", "fenghuang_b");
        set("long", "���Ƿ�˳ǵ����԰塣\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

