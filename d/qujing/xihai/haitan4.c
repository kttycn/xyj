inherit ROOM;

void create ()
{
  set ("short", "��̲");
  set ("long", @LONG
�����������£����Ĺ���ʱ������ҹ��������¶���ƣ���
����һ�����Բ�»�����������������Ļ�£���Ƶ�
ɳ̲Ҳ�·��ڻ����������㾲�С�Ω�������󰣬���ڲ�
�����е��ﳪ�͡�
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"haitan3",
  "south" : __DIR__"xihai",
]));
        set("outdoors", "xihai");


  setup();
}

