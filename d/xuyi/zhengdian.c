// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "正殿");
  set ("long", @LONG

进了正殿大厅，放眼四顾，只见满厅金碧辉煌，玉柱盘龙，松梁舞凤。朱
瓦金砖，楹柱中堂悬满了字画，正中是龙案高高在上，白玉台阶铺着大红
地毯。这里是处理国事所在，不过现在国王没有临朝，所以显得空荡荡的。
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

