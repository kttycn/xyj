//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG 
�����Ǻ��񸮵ĳ������Ĵ��ǻ��������������Ϻ�����ͺ�
�ʡ����������ݳޣ�̰ͼ�ڸ�֮������������ʳ�ﾫ���ɿڡ�
���������ÿ��ʳ�ﶼ�ǰ��ն��������ı�׼���ơ�
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zoulang3",
]));

        set("objects", ([
       "/d/qujing/xihai/obj/xiaren" : 1,
       "/d/qujing/xihai/obj/xierou" : 1,
       "/d/qujing/xihai/obj/fish" : 1,
       "/d/qujing/xihai/obj/baoyu" : 1,
        ])); 

        setup();
} 

