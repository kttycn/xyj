// edit by lucas
inherit ROOM;
#include <ansi.h>


void create()
{
        set("short", "������");
        set("long", @LONG  
�����ǰ�˳���޹��������ûʣ���̻Ի͡���ɴ���ʣ��ɻ�
Ʈ�㡣����Ϊ�㣬����Ϊ��������˶���ҹ������ڹ����ϣ�
�յ������޹�����㱡���˳��δ�ع�����޴���޹����
��һ�ˣ��Եÿյ����ġ��������ﲻ�٣���������ҿ���
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"zoulang7", 
                "east" : __DIR__"zoulang8", 
        ]));
  set("zhu_count",3);
        setup();
}
void init()
{
  add_action ("do_search","search");
}

int do_search (string arg)
{
  object me = this_player ();
  object where = this_object ();
  object zhu;

        if( (int)me->query("kee") < 50 )
                return notify_fail("��̫���ˣ�ЪЪ���Ұɡ�\n");
 if (query("zhu_count") < 1) 
  {
    message_vision ("$N���޹����Ĵ�������һ����ʲôҲû���ҵ���\n",me);  
    message_vision ("���������ù��ˡ����������ˣ�\n",me);  
    return 1;
  }
        if (  present("ye mingzhu", me) ) {
                return notify_fail("���˲�Ҫ̰�ģ�����һ�����Ӿ͹��ˡ�\n");
          }

  if (random(10))
  {
    message_vision ("$N���޹����Ĵ�������һ�����۵ù�Ǻ����ʲôҲû���ҵ���\n",me);  
   me->add("kee" , -30);
  }
  else
  {
    zhu = new (__DIR__"obj/zhu");
    message_vision ("$N���ִ�������Щ�������Ź⡣\n",me);  
    message_vision ("$N������һ�����ۣ��Ǽ�ֵ���ǵ�"HIW"ҹ����"NOR"��\n",me,zhu);
   me->add("kee" , -30);
    zhu->move(me);  
   add("zhu_count", -1);
  }
  return 1;
}


