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
  "up" : __DIR__"boat",
  "northeast" : __DIR__"hedi2",
]));
        setup();
}


