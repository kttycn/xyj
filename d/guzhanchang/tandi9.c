//stone 20020613
// /d/guzhanchang/tandi9.c

inherit ROOM;
#include <tandi.h>

void create ()
{
  set ("short", "̶��");
  set ("long", @LONG

����Ҳ�����˲β�����ʯ����ʯ��������ҷ�һ���ˮ�ݣ�
ˮ����ˮ��Ʈɢ�����緢˿�Ƶġ�С�ݼ们���������������
�Ĺ��㡣��Щ�㲻����״��һ���е������׵���е�����̹���
�еļ���Բ������ɫ�����߲ʷ׳ʣ����½�롣��ʯ֮�䣬��
ɢ����һЩ�������к����˵İ׹ǣ�

LONG);
  set("exits", ([
        "southwest":   __DIR__"tandi11",
        "east":        __DIR__"tandi8",
        ]));
  set("objects",([
        "/d/jz/obj/fish2" : 2,
        ]));
  setup();
}