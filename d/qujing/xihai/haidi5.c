//edit by lucas

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG 
����ǰһ����ֻ��ǰ��һ���޴��ޱȵĹ�����������ˮΧ���С�
����Ϊ��������Ϊ����ˮ��Ϊש������Ϊ�Ρ�ʮ��һ�ȣ��Ų�
һ����̴��¯������Ʈ�㡣��Ů�������������㡣�������ᣬ
������衣���˼����Ҳ���ô˺����ӣ�
LONG);
  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"gate",
  "east" : __DIR__"haidi4",
]));
        setup();
}

