// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������������������Ĺˣ�ֻ��������̻Իͣ�������������������
�߽�ש����������������ֻ��������������߸����ϣ�����̨�����Ŵ��
��̺�������Ǵ���������ڣ��������ڹ���û���ٳ��������Եÿյ����ġ�
LONG);

  set("exits", ([
        "south"  : __DIR__"hualang",
        "north"  : __DIR__"jitan",
      ]));
  set("objects", ([

      ]));
//  set("outdoors", __DIR__);

  setup();
}

int valid_leave(object me, string dir)
{
		if(dir =="north" && me->query("id")=="fei zei" ||("id") == "thief" ||("id") == "zei")
			return 0;
		return ::valid_leave(me, dir);
}

