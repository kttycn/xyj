//edit bye lucas
inherit ROOM;

void create()
{
        set("long",@LONG 
�˴���һ�����ߵ����£����¾�����ӿ���ȵĺ�ˮ�ӡ�վ�ڴ˴���
Ω����ˮ���϶�ȥ�����±�����ֹ��Զ����Ÿ��㣬������������
���վ����ͣ����˸����ϲ���������Ħ��ѡ��˴�������Ӫ������
�ý�����ˮ������
LONG );
        set("no_clean_up", 0); 
        set("outdoors", "heishui");
  set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"shan", 
        ]));
        set("objects", ([
             "/d/qujing/xihai/npc/xiejiang" : 2,
             "/d/qujing/xihai/npc/xiabing" : 2,
        ]));

        setup();
}

