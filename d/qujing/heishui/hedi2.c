//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "�ӵ�");
  set ("long", @LONG 
�����Ǻ�ˮ��֮�ס������濴�˺�ˮɫ��ڣ����������Ͽ���
ˮɫȷ������͸����ˮ�пտյ�������һ��С��Ҳû�С�ֻ
�а��ϵĲ�֦�ݲݣ���ˮ��Ʈ����ȥ��
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"hedi1",
  "north" : __DIR__"hedi3",
]));
        setup();
}


