// by gslxz@mhsj 6/1/2001

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIG"�ٶ���"NOR , ({"pidu zhu", "zhu"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
  set("unit", "��");
set("no_sell",1);
set("no_give",1);
      set("no_drop",1);
    set("long", "һ�����ıٶ��飬���������ⶾ(jiedu)��\n");
       set("value", 2000000);
    set("drug_type", "�ɵ�");
  }
  setup();
}

int init ()
{ if (!wizardp(this_player())) {

                set("no_drop","��ô����ıٶ��飬��������! \n");
                set("no_give","��ô����ıٶ��飬�����Լ����Ű�! \n");
//                        set("no_sell","��ô��Ķ������˼���ô�����! \n");
  }

  add_action ("do_jiedu","jiedu");
 return 1;
}
int do_jiedu (string arg)
{
  string *msgs = ({
    "$N"HIG"���ⶾ������������Ħ����\n"NOR,
  });
  object me = this_player(1);

  if (me->is_busy())
    return notify_fail (HIG"��������æ�ţ��������Լ��ⶾ��\n"NOR);
  message_vision (msgs[random(sizeof(msgs))],me);
  me->start_busy(1/2,0);if ((me->query("kar")+me->query_temp("spring/cure_times")) > 1)
  {
    if (! me->update_condition())
      return 1;     
message_vision ("$N"HIR"��Ȼ�������³�һ̲��Ѫ�����ϵĶ��Ѿ�����ˡ�\n"NOR,me);
    me->clear_condition();
//    me->unconcious();
  }   
me->add_temp("spring/cure_times",1);
  return 1;
}

int valid_leave(object me, string dir)
{
  me->delete_temp("spring/cure_times",1);
//  return ::valid_leave(me, dir);
}



