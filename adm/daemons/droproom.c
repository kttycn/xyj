//droproom.c @waiwai  2000/07/10
//������ֹ��Ǯ�����ã��������
//�Ǹ�bug���ã��Ҳ�֪��д���ԭ��
//��������ô���

#include <ansi.h>

inherit ROOM;
int do_drop(object me, object obj);
string money_str(int count);
void create()
{
        set("short", HIY"������"NOR);
        set("long", 

"\n����ǰ����һ��˶��������ѡ������ǳ����������ķ���ѻ�����\n"+
"�л�����ʶ�ĺ�����ң�������������ӷ�����ǰ�������"+HIR"(drop)\n"NOR+
"����������\n\n"
       );
        set("exits", ([
          "up" : __DIR__"center",
          "east" : __DIR__"menwc",
          "west" : __DIR__"manwc",
        ]));
        set("objects", 
        ([ //sizeof() == 1
 //      "/d/changan/npc/ouyangke1": 1,
        ]));

        set("no_fight", 1);
        set("no_magic", 1);
        setup();
}

void init()
{
    add_action("do_main", "drop");
}

int do_main(string arg)
{
   object me=this_player();
   object obj, *inv, obj2;
   int i, amount;
   string item;

        if(me->is_busy())
           return notify_fail("����æ���أ�����\n");
 
   if(!arg) return notify_fail("��Ҫ����ʲô������\n");

   if(sscanf(arg, "%d %s", amount, item)==2) {
     if( !objectp(obj = present(item, me)) )
        return notify_fail("������û������������\n");
     if( !obj->query_amount() )
        return notify_fail( obj->name() + "���ܱ��ֿ�������\n");
     if( amount < 1 )
        return notify_fail("����������������һ����\n");
     if( amount > obj->query_amount() )
        return notify_fail("��û����ô���" + obj->name() + "��\n");
     else if( amount == (int)obj->query_amount() )
        return do_drop(me, obj);
     else {
        obj2 = new(base_name(obj));
        obj2->set_amount(amount);
        if(do_drop(me, obj2)) { // succeed to drop
            obj->set_amount( (int)obj->query_amount()-amount );
            return 1;
        }
        return 0;
     }
   }

   if(arg=="all") {
     inv = all_inventory(me);
     for(i=0; i<sizeof(inv); i++) {
        do_drop(me, inv[i]);
     }
     write("Ok.\n");
     return 1;
   }

   if(!objectp(obj = present(arg, me)))
     return notify_fail("������û������������\n");
   return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
   int count;
   object money;
   if(me->is_busy())
      return notify_fail("����æ���أ�����\n");
   if (obj->move(environment(me))) {
    if((obj->query_temp("d_mana"))>0) {
     if( obj->query_temp("is_living")==1 )
            message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
     else {
       message_vision( sprintf("$N����һ%s$n��\n",   
         undefinedp(obj->query_temp("unit"))?
         "��":obj->query_temp("unit")
         ), me, obj );
     }
        } else {
     if( obj->is_character() )
            message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
     else {
  if (obj->query("id")=="thousand-cash" || obj->query("id")=="gold"
          || obj->query("id")=="silver" || obj->query("id")=="coin")
    message_vision( sprintf("$N����һ%s$n��\n",obj->query("unit")),me, obj );
else { message_vision( sprintf(HIC"$N��һ%s$n"+HIC"�ӽ������ѡ�\n"NOR,obj->query("unit")),me,obj);
//   if (obj->query("value")>1)
//    {
//    count=obj->query("value")/2;
//    me->add("balance",count);
//    tell_object(me,HIY"������л�ͷ�϶���"HIR+money_str(count)+"\n"NOR);
//    }
     destruct(obj);
     }}
        }
       return 1;
       }
       return 0;
}
string money_str(int count)
{        
        string output;
        if (count / 10000) {
                output = chinese_number(count / 10000) + "���ƽ�";
                count %= 10000;
        }
        else
                output = "";
        if (count / 100) {
                output = output + chinese_number(count / 100) + "������";
                count %= 100;
        }
        if (count)
                return output + chinese_number(count) + "��ͭ��";
        return output;
}
