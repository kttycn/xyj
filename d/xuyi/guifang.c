
inherit ROOM;
#include <ansi.h>;
void create()
{
        set("short", "�뷿");
        set("long", @LONG

������ˮĸ����Ĺ뷿��һ���ž��ŵ�һ�����Ƶ�������ֻ�����е���һ
֧������յ�������������������ɴ�����ӣ���ɫ�б�������һֻ��ɫ
�ķ�ˣ����Ϲ���һ��������Ůͼ������һ�ż��Ϲ���һ��������������
ͣ��һֻ�����ġ��������и���ױ̨(tai)��ǽ�Ϲ���һ�ڱ���(sword)��
��Ƥ�̿ڣ��������Ƿ�����
LONG );
        set("exits", ([ /* sizeof() == 1 */
             "east" : __DIR__"door",
             "west" : __DIR__"huayuan",
        ]));
        set("objects", ([
  "/d/xuyi/npc/shuimu" : 1,
  "/d/xuyi/npc/yahuan" : 1,
        ]));
        set("item_desc", ([
                "sword"  : "����ˮĸ������õ�ˮ�±�����\n",
                "tai"    : "����һ�ź�����ױ̨���뿪�ĳ���б���ż����ʻ���\n"
        ]));
//        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("do_move", "push");
        add_action("do_move", "move");
        add_action("do_pick", "pick");
        add_action("do_pick", "zhai");
}

int do_move(string arg)
{
        object paper, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="tai" )
        {
                if ((me->query("family/master_id") !="shuimu niangniang") &&
                        objectp(present("shuimu niangniang", environment(me))))
                {
                        return notify_fail(
"ˮĸ����ȵ�����λ" + RANK_D->query_respect(me) + "���㲻����㷭�˼Ҷ�����\n");
                        return 1;
                }
                if (!query("had_book"))
                {
                        message_vision(
"$N������������룬����������һ���顭��\n", this_player());
                        paper = new("/d/obj/book/halberd2");
                        paper->move(this_player());
                        set("had_book", 1);
                        return 1;
                }
                message_vision(
"$N������������룬��������ɶ��û�С���\n", this_player());
                return 1;
        }
        return 0;
}

int do_pick(string arg)
{
        object sword, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="sword" )
        {
                if (objectp(present("shuimu niangniang", environment(me))))
                {
                        return notify_fail(
"ˮĸ����ȵ�����λ" + RANK_D->query_respect(me) + "������ô��������˼Ҷ����أ�\n");
                        return 1;
                }
                if (!query("had_sword"))
                {
  if ("/d/obj/weapon/sword/wsword"->in_mud()){
                message_vision(
"$N����ȥժ�������ŷ���ֻʣ�����ˣ�������ͱ�����ȡ���ˡ���\n", this_player());
                        return 1;
                     }
                        message_vision(
"$N�����ժ�±������������濪�ġ���\n", this_player());
                        sword = new("d/obj/weapon/sword/wsword");
                        sword->move(me);
                        set("had_sword", 1);
                        return 1;
                }
                message_vision(
"$N����ȥժ�������ŷ���ֻʣ�����ˣ�������ͱ�����ȡ���ˡ���\n", this_player());
                return 1;
        }
        return 0;
}

