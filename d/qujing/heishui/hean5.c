//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "�Ӱ�");
  set ("long", @LONG
���ˮ�������޾����������ݵ���ïʢ������«έ֪ʱ�ڣ�
̲ͷ���ݶ����档�������������У�ϪԴ������ࡣ����
������괦��˭��������ˮ�ӣ�
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hean4",
  "northeast" : __DIR__"road4",
]));
        set("outdoors", "heishui");


  setup();
}

