inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY"点石成金棒"NOR ,({ "magic gold staff","staff" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一根不起眼的小木棒，但却可以变(bians)出无数的钱。\n");
                set("unit", "根");
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
                return notify_fail("你要变什么？(coin,silver,gold,gold-coin)\n");
        if(!wizardp(me)) {
                tell_object(me,"这个是巫师专用的！！\n");
                message("vision","突然从天上传来一个巨大的声响，对着"+me->name()+"吼道：这个可是巫师专用的！\n"
        "紧接着从天上伸下一个大手，将"+me->name()+"身上的"+this_object()->name()+"抓了去。\n"
        "同时只见一道闪电劈下，"+me->name()+"劈得晕了过去。\n",environment(me),me);
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
                        return notify_fail("你要变什么？(coin,silver,gold,gold-coin)\n");
        }
        message_vision("$N挥舞$n，一下子变出好多好多的钱。\n",me,this_object());
        money->add_amount(100);
        return 1;
}
