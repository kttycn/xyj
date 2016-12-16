inherit ITEM;
void create()
{
        set_name("骰子",({"dice"}) );
        set("long","一个六面的骰子，除了拿来赌博之外，看来也没有什麽用处吧。\n");
        set_weight(20);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","粒");
                set("value",10);
        }
        setup();
}

void init()
{       add_action("do_roll","roll");}

int do_roll(string arg)
{
        int m;
        object who;
        who=this_player();
        if (arg != "dice") return 0;
        message_vision("$N从怀里拿出一粒骰子，默念几声之後，一把掷在地上。\n",who);
        m=random(6)+1;
        message_vision("骰子滴溜溜地转了几圈之後，$N掷出了"+ m +"点\n",who);
        return 1;
}

