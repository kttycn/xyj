inherit ITEM;

int do_move(string arg);

void init()
{
        add_action("do_move", "move");
}

void create()
{
        set_name("��ֽ", ({"zhenzhi","zhen zhi"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "\n����һ����ͭ��ֽ���͹��������������˾�����(move)��\n");
                set("unit", "��");
                set("material", "steel");
                set("no_get", "\n������������ֽ����ȴ���������̶������ϣ�����˾�ţ����֮����Ҳû��������\n");
        }
        setup();
}

int do_move(string arg)
{
        object me;
        string dir;
        me = this_player();
        if( !arg ) {
                return notify_fail("��Ҫ�ƶ�ʲô?\n");
        }

        if( arg=="zhenzhi" ) {
                if(!me->query_temp("mishi"))
                message_vision("\n$N������ͭ��ֽ���£��������������Ұ⶯��\n", this_player());
                if(me->query_temp("mishi"))
                {
                message_vision(
                "$N����ת����ͭ��ֽ����Ȼǽ�ں��һ����ת��������$N�������ҡ�\n", this_player());
                me->move("/d/qujing/heishui/mishi");
                me->delete_temp("mishi");
                }
        }
        if( sscanf(arg, "zhenzhi %s", dir)==1 ) {
                if( dir=="left" ) {
                message_vision("$N����ͭ��ֽ������������һ�£��о����󴥶�����ʲô������Ŧ��\n", this_player());
                if(!me->query_temp("move"))
                me->set_temp("move", 1);
                else 
                me->set_temp("move", 0);
                return 1;
                }
                if( dir=="right" ) {
                        message_vision("$N����ͭ��ֽ������������һ�£��о����󴥶�����ʲô������Ŧ��\n", this_player());
                if (me->query_temp("move") )        
                        {
                        me->set_temp("mishi", 1); 
                        me->delete_temp("move");
                        }
                return 1;
                }
                else {
                        write("��Ҫ����ͭ��ֽ�����ƶ���\n");
                        return 1;
                      }
        }
return 1;
}

