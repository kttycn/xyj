inherit ROOM;
void create()
{
       set("short","С��");
       set("long",@LONG
������һ��С·����֪��ͨ���Ķ���С�����Է�����Ĵ��ţ�
�ƺ��ڰ�ʾ��ʲô����·���ԵĲ�Խ��Խ�ܼ��ˣ�������ԼԼ
������Щ���ס�
LONG)
;
            set("exits",([
                      "east" : __DIR__"tudi3",
                        "west" : __DIR__"tudi1",
                        ]));
     setup();
}
