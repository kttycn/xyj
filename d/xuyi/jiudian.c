// �����硤���μ�֮�����ͣ�
 
// create by jing 2000.7.13

inherit ROOM;

void create ()
{
  set ("short", "�ƹ�");
  set ("long", @LONG
 
���Ǳ���Ψһ��һ�ҾƵ꣬λ�������ĵ��Աߣ����������������˶�ϲ��
�������һ��������������Ļ����ϰ����Ļƾƣ��������Կ���Щ����
�����ﳩ����
LONG);
  set("no_clean_up", 1);

  set("exits", ([
        "north"   : __DIR__"jiedao1",
      ]));
  set("objects", ([
         __DIR__"npc/jiubao"   : 1,
      ]));

  set("resource", ([
   "water": 1
   ]) );


  setup();
   replace_program(ROOM);
}
 

