//stone 20020613
//  /d/guzhanchang/tandi1.c

inherit ROOM;
#include <tandi.h>

void create ()
{
  set ("short", "̶��");
  set ("long", @LONG

����Ҳ�����˲β�����ʯ����ʯ��������ҷ�һ���ˮ�ݣ�
ˮ����ˮ��Ʈɢ�����緢˿�Ƶġ�С�ݼ们��������������
�Ĺ��㡣��Щ�㲻����״��һ���е������׵���е�����̹���
�еļ���Բ������ɫ�����߲ʷ׳ʣ����½�롣��ʯ֮�䣬��
ɢ����һЩ�������к����˵İ׹ǣ�

LONG);
  set("exits", ([
        "south"  : __DIR__"tandi2",
        "north":   __DIR__"tandi3",
        "up":   __DIR__"shuitan",
        ]));
  set("objects",([
        "/d/jz/obj/fish2" : 2,
        __DIR__"obj/goldstone" : 1,
        __DIR__"obj/skull" : 1,
        "/d/obj/weapon/sword/tiejian" : 1,
        ]));
  setup();
}
