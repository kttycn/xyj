// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/dongkou.c


inherit ROOM;

void create ()
{
  set ("short", "ถดฟฺ");
  set ("long", @LONG

าฐิฦฦฌฦฌฃฌัþฒÝÜทÜทกฃตüีฯผโทๅฃฌปุยอนลตภกฃึปผ๛วเหษดไ
ึ๑าภาภฃฌยฬม๘ฑฬฮเศฝศฝกฃษฝสฏัยวฐยถณ๖าปถดฟฺฃฌถดรลลิาป
ฟ้วเสฏษฯะดืลฃบ
[33m
                กรกรกรกรกรกรกรกรกร
                กร [1;31mปฦท็ม๋ปฦท็ถด [2;37;0m[0;33mกร
                กรกรกรกรกรกรกรกรกร[m


LONG);

  set("exits", ([
        "southdown" : __DIR__"huangfeng2",
        "north" : __DIR__"dong1",
      ]));
     set("objects", ([
                __DIR__"npc/baoxianfeng": 1 ]) );

        set("outdoors", __DIR__);
       
  setup();
}
int valid_leave (object me, string dir)
{
        if (dir == "north" ) {
        if (objectp(present("bao xianfeng", environment(me))) 
        && !wizardp(me) )
        return notify_fail("ฑชฯศทๆถ๑บÝบÝตฤตษมหฤใาปัÛฃฌย๎ตภฃบีาหภ,ปฦท็ถดาฒธายาดณฃก\n");
        }
  return 1;
}
