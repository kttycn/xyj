//stone 20020613
///d/guzhanchang/dongkou.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ﾹȻ�쳣ƽ�����о�����һ������������������һ�¶���ʧ�ˣ�
Ҳû����Ϻ��û��͸���ں����ĺ�ˮ���·��Ƽ�һ���Ķ��ڣ�����
�ڹ�¡�ˣ�ʲôҲ�������������ɳʯ֮�䣬�������ŰײҲҵİ�
���Լ�һЩ����ĵ�����

LONG);
  set("exits", ([
        "enter":   __DIR__"cave",
        "east":        __DIR__"tandi11",
        ]));
	set("objects",([        	
        	__DIR__"obj/goldstone" : 1,
        ]));
  setup();
}
