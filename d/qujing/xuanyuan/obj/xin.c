//  ����֮�� ������
//  by happ@YSZZ 2000.4.15
//  /d/qujing/xuanyuan/obj/heart.c

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("[31m�ȸɵĺ���[m", ({"bigan heart","heart"}));
        set_weight(1000);
                set("unit", "��");
                set("heart",1);
                set("value", 50);
                setup();
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
     object me=this_player();
     if(!arg && arg != "heart" )
     return notify_fail("��Ҫ��ʲô��\n");

    if(me->is_busy())
    return notify_fail("����æ���أ�\n");
    message_vision(HIY"��һ��µ�Ͱѱȸɵ��ĳ�����ȥ��\n"NOR,me);
    me->add("mana",200);
    destruct(this_object());
    return 1;
}
