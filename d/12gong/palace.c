// by HAPP@YSZZ

inherit ROOM;

void create ()
{
	set ("short", "�ƽ�ʥ��");
	set ("long",
		@LONG
[36m[5m     p                  p         p[2;37;0m
[1;33m    /\[2;37;0m[5m[36m     p      p  [2;37;0m[1;33m  /\        /\
   /__\   /\_____/\   /__\      /__\
   |. |_=_|. . . .|_=_=_=_=_=_=_|. |
   |. |. .|  ___  |. . . . . . .|. |    [1;36m�ŵ����ڴ�ִ����[2;37;0m
[1;33m   |. |   | |   | |             |. |
 __|__|___|_|___|_|_____________|__|__
/          /   /                      \

[2;37;0m
LONG);

	set("no_fight", 1);
	set("no_magic", 1);

	set("exits", ([
		"down"  :       __DIR__"topalace3",        
	]));

	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/athena" : 1,
	]));
	setup();
}
