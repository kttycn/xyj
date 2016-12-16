inherit ROOM;
void init();
void create()
{
        set("short", "��ڣ");
        set("long", @LONG 
�ݹǱ�أ��������ݣ�������������Ա��������֮����
ֻ���������ι�״�����������У���һ������(skeleton)
����һ��ѩ��Ƥ�ף���Ȼ������ڣ���У���Ȼ�ѳɰ׹ǣ�
�Ը���һ�����;��ף��Ծ����µĸо���
LONG);
        set("exits", ([
            "out" : __DIR__"yandong",
        ]));
        set("remove_available" , 1);
        set("item_desc", ([
      "skeleton" : "���ǵ����ݺ��������������������������󱻰�˳\n��ɱ����������˳Ҳ�������ڣ�����������ڣ֮�ڡ���\n��һ����ɫƤ�ף������������(remove)����\n",
        ]) );
        setup();
}

void init()
{
           object me = this_player();
        add_action("do_remove", "remove");
            me->set_temp("long", 0); 
}

int do_remove(string arg)
{
       object me,obj,killer;

       me = this_player();
       if( !arg || arg!="skeleton" )
              return notify_fail("��Ҫ��ʲô? \n");
       if ( query("remove_available") )
       {
         message_vision("$N���������ضԿݹǿ���������ͷ,����Ƥ��ȡ�¡�
\n",this_player() );
         obj = new (__DIR__"obj/jia");
         obj->move(me);
         add("remove_available", -1);
         me->start_busy(3);
         if ( me->query_temp("long") ) return 1;
         killer = new (__DIR__"npc/kulou") ;
         message_vision("\n��������ͻȻ������ϣ����һ��������������������$N������\n"
         "��$N�ȵ������ӸҶ���������Ķ�����Ҳ�Ҷ���\n", me);
         killer->move(environment(me));
         killer->kill_ob(me);
         me->set_temp("long", 1);
       return 1;
       }
    message_vision ("$N�߸����˵�����������ץȥ��ȴʲôҲû�õ���\n",me);  
    message_vision ("ԭ����Ƥ����ͱ��������ˡ�\n",me);  

       return 1;
}

int valid_leave(object me, string dir)
{
        if (objectp(present("kulou long", environment(me))) && 
                     (dir == "out")&& living(present("kulou long", environment(me))))
                return notify_fail("��������ס�ſڣ�Ҫ�����һ��ս��\n");
        return ::valid_leave(me, dir);
}

