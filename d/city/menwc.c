//By waiwai@mszj  2000/07/10

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", HIM"���շ�Ů�ޡ�"NOR);
        set("long", 

"\n����ͨ�����ã��ɾ���ˬ���������ǵİ���С��Ͱ�����������ǽ�ߡ�\n"+
"ÿ����Ͱ�ϻ���һ���ҹ��������ǿ��Թ��ڱⵣ�ϵġ�ǽ�Ϲ���һ������\n"+
"ľˢ�����ڵ���ˮ�Ա�ǽ����һ������ "+HIR"(pai) \n"NOR);

  set("no_fight", 1);
  set("no_magic", 1);
  set("freeze",1);


	set("item_desc", ([
     "pai":  HBBLU+HIY" ( give mouse 30 gold ���԰��Լ�����ˮʳ�ｵΪ 0 ) \n"NOR,
	]));

        set("exits", ([ /* sizeof() == 4 */
   "west" : "/d/city/droproom",
]));
        set("objects", ([
        __DIR__"npc/menmouse" : 1,
        __DIR__"npc/fly" : 2,

                        ]) );
set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}
