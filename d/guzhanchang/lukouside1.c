// /d/guzhanchang/lukouside.c
//stone 

inherit ROOM;

void create ()
{
  set ("short", "�ȵ�С��");
  set ("long", @LONG

һ��������С·���������Ǻ��Ļ�����·��û��һ�Ųݻ���ľ��
һ����紵��������һ�����ĳ�������������Ȼ�γɵ��ұڣ���
�Ϲ�ͺͺ�ģ����Ǳ������������Ƶģ�����������Գ�Ҳ����
���ϡ�������һ��С�������ϱ��ǹ�ս������ַ��

LONG);

  set("exits", ([
             "north": __DIR__"lukou0",
             "southeast": __DIR__"lukou-1",
      ]));

//  set("objects", ([
//      ]));
  replace_program(ROOM);

  setup();
}


