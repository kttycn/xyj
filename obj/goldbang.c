inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY"��ʯ�ɽ��"NOR ,({ "magic gold staff","staff" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������۵�Сľ������ȴ���Ա�(bians)��������Ǯ��\n");
                set("unit", "��");
                set("value", 100);
        }
        setup();
}
void init()
{
        add_action("do_bian","bians");
}
int do_bian(string arg)
{
        object me,money;
        me = this_player();
        if(!arg)
                return notify_fail("��Ҫ��ʲô��(coin,silver,gold,gold-coin)\n");
        if(!wizardp(me)) {
                tell_object(me,"�������ʦר�õģ���\n");
                message("vision","ͻȻ�����ϴ���һ���޴�����죬����"+me->name()+"��������������ʦר�õģ�\n"
        "�����Ŵ���������һ�����֣���"+me->name()+"���ϵ�"+this_object()->name()+"ץ��ȥ��\n"
        "ͬʱֻ��һ���������£�"+me->name()+"�������˹�ȥ��\n",environment(me),me);
                me->unconcious();
                destruct(this_object());
        }
        switch(arg)
        {
                case "coin":
                        money = present("coin_money",me);
                        if(!money) {
                                money = new("/obj/money/coin");
                                money->move(me);
                        }
                        break;
                case "silver":
                        money = present("silver_money",me);
                        if(!money) {
                                money = new("/obj/money/silver");
                                money->move(me);
                        }
                        break;
                case "gold":
                        money = present("gold_money",me);
                        if(!money) {
                                money = new("/obj/money/gold");
                                money->move(me);
                        }
                        break;
                case "gold-coin":
                        money = present("gold_money",me);
                        if(!money) {
                                money = new("/obj/money/gold-coin");
                                money->move(me);
                        }
                        break;
                default:
                        return notify_fail("��Ҫ��ʲô��(coin,silver,gold,gold-coin)\n");
        }
        message_vision("$N����$n��һ���ӱ���ö�ö��Ǯ��\n",me,this_object());
        money->add_amount(100);
        return 1;
}
