//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "�ӵ�");
  set ("long", @LONG 
�����Ǻ�ˮ��֮�ס������濴�˺�ˮɫ��ڣ����������Ͽ���
ˮɫȷ������͸����ˮ�пտյ�������һ��С��Ҳû�С�ֻ
�а��ϵĲ�֦�ݲݣ���ˮ��Ʈ����ȥ�� ǰ��ˮ���������·�
���Կ���һ����ۡ��
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hedi4",
  "northeast" : __DIR__"hedi6",
]));
        setup();
} 

