// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/huangfeng8.c


inherit ROOM;

void create ()
{
  set ("short", "�Ʒ���");
  set ("long", @LONG

����Ƶ������ط��ᡣ���۵Ĳ��ɴ�أ��̲�����һ��
СϪ��·������ˮ�����ˣ���Ȼһ��������ɫ��������ͨ
�������ȡ��·��

LONG);

  set("exits", ([
        "westdown" : "/d/qujing/liusha/dadao1",
        "southeast" : __DIR__"huangfeng7",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
