inherit ROOM;

void create ()
{
  set ("short", "��̲");
  set ("long", @LONG
������������̲����Ŀ������Զ��Ϧ�����䣬�л����죬
�յú��Ͻ���������ˮ��һɫ֮���������Ÿ��ĺ���
�淫������������ˮ�����ԣ�����ɪɪ����һ���̺���
��ͼ��
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"yandong",
  "west" : __DIR__"haitan2",
]));

        set("outdoors", "xihai");

  setup();
}

