//stone 20020613
///d/guzhanchang/dong.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "黑洞");
  set ("long", @LONG

水流在上面结成无数个小的漩涡，以飞快的速度，旋转着向下落去，
而你就处在这漩涡的中心，水流的快降使各个小漩涡相互吸引，不
断积聚，最后结成一个硕大无比的大漩涡，漩涡的中心竟然立着一
根铁柱，铁柱底部有着一个不小的缺口，潭水就从这里飞泄而出。
缺口下面深不可测，如果你不赶快（[1;35mout[m）的话，不久你就要
被黑洞吞噬！

LONG);
  setup();
}

void init()
{
        object ob = this_player();
        remove_call_out("down");
        call_out("down",2,ob);
        add_action("do_out","out");
}
int do_out()
{
    object ob = this_player();

    string place = "/d/guzhanchang/tandi1";
    place[strlen(place)-1] = '0'+random(11);

    message_vision(HIC"只见$N手抓脚蹬，忍着全身的酸痛，拼拿地地沿着铁柱向上爬。\n"NOR,ob);
    ob->move(place);
    return 1;
}

void down(object ob)
{

        message_vision(HIW"$N觉着自己的身体已经禁不住旋涡的牵扯，$N好象看见来自地府的牛头马面向你走来。\n",ob);
        message_vision("随着$N最后一点元气的耗尽，$N的身体就快要被黑暗之渊吞没了！！！\n"NOR,ob);
        ob->add("kee",-50);
//        ob->start_busy(2);
}

