inherit ROOM;

void create ()
{
  set ("short", "��̲");
  set ("long", @LONG
ʱ�����磬���յ�ͷ��������㡣��̲�����ﶼ����ʧ��
�١���Ÿ������ط��ţ�ʱ���ӹ�ˮ�棬����˵�ǲ�ʳ��
����˵��Ϊ��������Ƭ�̵�����������һֻСС�ı��ǣ�
Ҳ�������Ǻ�ʵ�ļ׿��У��ܿ�����ļ尾��
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"haitan1",
  "southwest" : __DIR__"haitan3",
]));
        set("outdoors", "xihai");


  setup();
}

