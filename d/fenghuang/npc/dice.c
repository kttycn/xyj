inherit ITEM;
void create()
{
        set_name("����",({"dice"}) );
        set("long","һ����������ӣ����������Ĳ�֮�⣬����Ҳû��ʲ���ô��ɡ�\n");
        set_weight(20);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
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
        message_vision("$N�ӻ����ó�һ�����ӣ�Ĭ���֮�ᣬһ�����ڵ��ϡ�\n",who);
        m=random(6)+1;
        message_vision("���ӵ������ת�˼�Ȧ֮�ᣬ$N������"+ m +"��\n",who);
        return 1;
}

