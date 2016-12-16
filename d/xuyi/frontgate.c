#include <ansi.h>
inherit ROOM;

int do_knock(string arg);
void create()
{
    set("short", "��ǰ�㳡");
    set("long",

    "\n�����Ǵ�ʥ����ǰ�Ĺ㳡���㳡��ʯ���̾ͣ��ͻ�����������ʵƽ\n"
"̹����Ȼ�����Զ��ȴ�������ɡ���ǰ����ǽ���ߣ��������ݣ���\n"
"�����Ⱥ���ͭɫ����(gate)���Ǻ�����֮���������ƶ����Ϸ�һ\n"
"����ң����ɷ���������ĸ����֣�\n\n"
HIY"                    ����ʥ���¡�\n\n"NOR
"ԶԶ��ȥ��������̨ͤ¥���ģ��󣬹���������լ�����ƣ�����\n"
"��֮ʢ��ʤ����̨�����ӵ������ʤ�ص���ɽ���¡� \n");
    set("exits", ([
  "south" : __DIR__"xiaolu22",
    ]));

    set("outdoors", 1);
    set("item_desc",([ 
        "gate" : "һ���������ߵ����ɼľ��ͭ���š�\n"
    ]));
    set("objects",([
    ]));
//    set("no_clean_up", 0);
    setup();
}

void init()
{
        add_action("do_knock","knock");
}

int do_knock(string arg)
{
      object me, room;
      me = this_player(); 

    if (query("exits/north"))
        return notify_fail("�����Ѿ��ǿ����ˡ�\n");
      if (!arg || arg != "gate")
      {
            return notify_fail("������ʲô��\n");
      }

    if(!( room = find_object(__DIR__"dadian")) )
        room = load_object(__DIR__"dadian");
    if(objectp(room))
    {
        set("exits/north", __DIR__"dadian");
        message_vision("$N������������ţ�ֻ��֨��һ����"
            "һλСɳ��Ӧ���򿪴��ţ��������´�����$N��\n",
            this_player());
        room->set("exits/south", __FILE__);
        message("vision", "���洫��һ����������Сɳ��Ӧ����ǰ�Ѵ��ſ���\n", room);
        remove_call_out("close_gate");
        call_out("close_gate", 10);
    }
        return 1;
}

int close_gate()
{
    object room;

    if(!( room = find_object(__DIR__"dadian")) )
        room = load_object(__DIR__"dadian");
    if(objectp(room))
    {
        delete("exits/north");
        message("vision", "ƹ��һ�����������˰Ѵ��Ź����ˡ�\n",
            this_object());
        room->delete("exits/south");
            message("vision", "Сɳ����ǰ�Ѵ��Ź���������\n", room);
    }
    else message("vision", "һ��紵������������������\n", room);
}

int valid_leave(object me, string dir)
{
    if ( dir == "north" )
    {
    if ( (me->query("family/family_name") != "����ɽ"))
    {    
     if( present("tongpai", me) )
    {
      write("Сɳ�ֺ�ʮΪ�񣬲����ÿ���˵����ԭ���ǹ�ͼݵ�����������\n");
     return 1;
     }
    if (me->query("class") == "yaomo")
     return notify_fail("Сɳ����ʱ������ֿ��һ��ѩ���Ľ䵶���������λε�\n"
                "�����׼����ؿڣ���üŭĿ��˵�������аħ������������ҹ�����\n"
                "�Ժ��ٸ��߽���ʥ����һ��������ʱ��ն�����ǵĹ��ȣ�\n"); 
    if (me->query("class") == "youling")
     return notify_fail("Сɳ����ʱ������ֿ��һ��ѩ���Ľ䵶���������λε�\n"
                "�����׼����ؿڣ���üŭĿ��˵�������аħ������������ҹ�����\n"
                "�Ժ��ٸ��߽���ʥ����һ��������ʱ��ն�����ǵĹ��ȣ�\n");

     return 1;
     return notify_fail("Сɳ��ʩ��һ�񣬵������²��Ӵ���ͣ�ʩ����ء�\n");
  }
   return 1;
  } 
        return ::valid_leave(me, dir);
}
