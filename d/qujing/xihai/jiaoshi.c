//edit by lucas

inherit ROOM;

void create ()
{
  set ("short", "��ʯ��");
  set ("long", @LONG
�����ǽ�ʯ�ķ�϶�������ɺ�������缸�Ⱦ޴������һ��
�ڵ�ס����ĺ�����ֻ�����������޵İ����ͺڰ���һ��С
�������ڵ��ϵ�һ����ʯ�ϣ������Ŷ�������Ϣ��
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"haidi4",
]));
        set("objects", ([
       "/d/qujing/heishui/npc/xiaoyao":1,
        ]));
        set("no_magic",1);
        setup();
}

