//shushan by yushu 2000.11
inherit ROOM;
void create ()
{
  set ("short","�ܵ�");
  set ("long", @LONG

��������ɽ�ɵ��ܵ����������涼���Ʋʣ����㿴������ա�
���¶��������ɾ�һ�㡣�㲻֪������Ǻã�ֻ����ǰ
�����ߡ�
LONG);

  set("exits", ([
  "north" : __DIR__"midao0",
    ]));
     set("no_fight", 1);
     set("no_magic", 1);
     set("no_get", 1);
     setup();
}
