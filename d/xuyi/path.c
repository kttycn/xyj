// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
  set ("short", "青石小道");
  set ("long", @LONG

一条青石小道由海滩延伸到远方。道路两旁不远有一些村庄，炊烟袅袅升
起。村庄周围是一块块的田地，田里有一些正在耕作的农人。但见土地肥
沃，麦浪千顷，酒香暗送，村歌处处，好一派歌舞升平之景！
LONG);

  set("objects", ([ /* sizeof() == 1 */

]));
  set("outdoors", 1);
  
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"island",
  "northwest" : __DIR__"path1",
]));

  setup();
}


