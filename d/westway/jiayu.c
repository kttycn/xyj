//Cracked by Roath
// create by snowcat.c 4/8/1997
// room: /d/westway/jiayu.c

inherit ROOM;

void create ()
{
  string dir;
  set ("short", "������");
  set ("long", @LONG

һ����ΰ�Ĺؿ�������Ⱥɽ֮�У��������ǳ��������Ĺؿڣ�
���ش��ƹ���������š�������������ͨ����������ļ���
��·��ֻ������һƬãã�����纣һ��л���ʲôҲ����
����������ͨ����ƹ����أ��ϱ���һ��СС��������
̨������

LONG);

/*
  dir = __DIR__;
  dir[strlen(dir)-8] = 0;
*/
  dir = "/d/qujing/";
  set("exits", ([
        "east"      : __DIR__"shizhan",
              "westup"      : "/d/qujing/shuangcha/shanlu1",
        "southup"   : __DIR__"fenghuo",
      ]));
  set("objects", ([
                __DIR__"npc/wujiang": 2 ]) );

  set("outdoors", "changan-west");

  setup();
}

int valid_leave (object me, string dir)
{
  	if (dir == "west"){
    		message_vision ("$N����һԾ�����ãã�����У�\n",me);
  	}
	if (dir == "southup" && !wizardp(me) && 
	objectp(present("wu jiang", environment(me))) )
        return notify_fail("�߹��ؽ��µ����ǲ������ȥ�ĵط���\n");
	return 1;
}


