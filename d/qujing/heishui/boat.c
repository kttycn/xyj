//edit by lucas

inherit ROOM;
int do_open(string arg);
void create ()
{
  set ("short", "ľ��");
  set ("long", @LONG

����һ���������õ�ľ��������խС��ֻ����������Ҳ�����⡣
С��˨�ڲ�����ӿ�ĺ�ˮ���ߣ������±�����ֹ�Ľ�ˮ���ң
ң�λΡ��������Ǻ�ƽ���Ĵ�����������ܾ�����ʲô������
�ģ������п�ľ��(board)�ƺ������⡣ 
LONG);

        set("item_desc", ([
 "board" : "����һ��ľ�壬�����ڴ����ϣ���������ƿ���\n", 
        ]) );

        set("outdoors", "heishui");

        setup();
}

void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
            object me, zhou;
        me=this_player();

        if( !arg || arg != "board" ) {
                return notify_fail("��Ҫ��ʲô?\n");
        }
    if( !(zhou=present("bishui zhou", me)))
         {
             message_vision("ľ���Ȼ�ƿ���$Nһ��С������ˮ�У�Ǻ�˼���ˮ�����Ǳ�����������������\n",this_player());  
     me->add("kee",-100);  
     me->add("sen",-100); 
     return 1;
         }
         else
         {
     message_vision("$Nʹ��һ������ľ��ҿ����ֳ�һ��������Ķ��ڡ�\n",this_player());
        message_vision("$Nһ��С�ģ����ص�����ȥ��\n", this_player()); 
   me->move("/d/qujing/heishui/hedi1");        return 1;
         }
}

