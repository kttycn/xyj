// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */
 
 
//huayuan.c
#include <ansi.h>
inherit ROOM;
void create ()
{
   set ("short", "��԰");
   set ("long", @LONG

������ˮĸ����ĺ�԰���ļ��紺���ٻ�ʢ��������ˮĸ���ﾫ����ֲ
����֥(lingzhi)�������ɲ����������˵���ǵ����ʥ��ʦ����������
�Ǵ����ã��������ڸ�ˮĸ���ˮĸ���ﾫ���������������˺ܴ��ճɡ�
������ˮĸ����Ĺ뷿��
LONG);
  set("outdoors", 1);
   set("item_desc", (["lingzhi" : "һ�국��ɫ����֥�����˿�����Ԫ������ \n", ]));

   set("exits", 
   ([ //sizeof() == 1
     "east" : __DIR__"guifang",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
    "/d/xuyi/npc/sun"  : 1,
    "/d/xuyi/obj/moli"  : 1,
   ]));
   set("no_lingzhi", 0);

   setup();
}

void init()
{
   add_action("do_dig", "dig");
   add_action("do_dig", "wa");
}

int do_dig(string arg)
{

   object ob, me;
   
   me=this_player();

   if( (!arg) || (arg != "ling zhi" && arg != "lingzhi" && arg !="��֥") )
     return notify_fail("��Ҫ��ʲô��\n");

        if (objectp(present("sun shenjiang", environment(me))))
        return notify_fail("���񽫴�ŭ������Ķ�����������Ҷ��ء�\n");

   if( !(ob = me->query_temp("weapon")) || ( (string)ob->query("skill_type")!="axe" && (string)ob->query("skill_type")!="blade" && (string)ob->query("skill_type")!="sword"  && (string)ob->query("skill_type")!="halberd" &&
     (string)ob->query("skill_type")!="halberd") ) 

     return notify_fail("���Ҹ��ù��߰ɡ�\n");

   if (query("no_lingzhi"))
     return notify_fail("���Ǹ����������ְɣ���Ȼ�´���ʲô�أ�\n");


   ob=new("/d/xuyi/obj/lingzhi");
           ob->move(me);
   message_vision("$N�ڳ�һ��"+MAG"��֥��"NOR+"��С������زص��˻��\n", me);
   set("no_lingzhi", 1);
   call_out("regenerate", 3000);
   return 1;
}

int regenerate()
{
   set("no_lingzhi", 0);
   return 1;
}

