// story:zhengxi 征西

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "薛仁贵：大军驻下，就地埋锅造饭。",
        "尘土飞扬，三军一起忙碌。",
        "程咬金：薛仁贵呀，你怎么把大军停下了？",
        "薛仁贵：咋了，太阳都快落山了。",
        "程咬金：唉！今天晚上有人可要生病喽。",
        "薛仁贵：@#$%^& 什么意思？",
        "程咬金：你儿子薛丁山呀！",
        "薛仁贵疑惑道：不会吧，老虎叼了他去都没咋样，没那么容易就生病吧。",
        "程咬金：心病啊！",
        "薛仁贵：哦？",
        "程咬金：你儿子在外面学武的时候认识了一个小姑娘，叫樊梨花。",
        "薛仁贵：这小子不赖，有我当年遗风。",
        "程咬金：嘿嘿，现在有情报来：说是跳出来一个叫什么杨凡的正在猛追樊梨花，据说都快得手了。",
        "薛仁贵：靠！这女子怎么这么水性... 梨花的，我老婆等我十几年都没有变心。",
        "程咬金：你懂啥，时代变化啦！",
        "薛仁贵：他妈的，杨凡算哪头鸟？" HIC "来人啊！",
        "传令兵：元帅？",
        "薛仁贵：传我的命令，大军连夜开拔！",
        "三军轰然而起，扬尘而去。",
        "众士兵：他奶奶的，今天要吃夹生饭了。薛仁贵这混蛋！",
        "薛仁贵把他的随身武器给忘记了.......",
        (: give_gift :)
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}
string give_gift()
{
        STORY_D->give_gift("/clone/gift/yitianjian", 1,
                           HIM "\n“啪”的一声一棵万年灵芝掉到你面前。\n\n" NOR);
        return 0;
}
