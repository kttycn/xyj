// /d/guzhanchang/lukou0.c
//stone 

inherit ROOM;

void create ()
{
  set ("short", "�ȵ�");
  set ("long", @LONG

�˴���һ��ƽ̹�Ŀյء����涸�ڣ����ϴ�ݲ����������������
Σ����죬�������У������Ƿ���Ҳ�ѷ�Խ������������ɽ�ȣ�
����Σ��֮�䣬����Ʈ�졣�ϱ���һ��С·��������һ����ˮ̶��

LONG);

  set("exits", ([
             "west": __DIR__"pondside",
             "south": __DIR__"lukouside",
      ]));

//  set("objects", ([
//      ]));
  replace_program(ROOM);
  setup();
}


