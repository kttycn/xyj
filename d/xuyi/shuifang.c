// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create()
{
        set("short", "王府睡房");
        set("long", @LONG

王府的一间睡房，房间干干净净，一张干净整洁的大床，供王府弟子们休
息睡觉。
LONG
        );

        set("sleep_room",1);
        set("if_bed",1);

        set("exits", ([
                "west" : __DIR__"piandian",
        ]));

        setup();
}


