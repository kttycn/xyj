//modified by vikee
//2000-12-29 20:15

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

void remove_effect(object me, int enhance,int damage,object weapon);

int perform(object me, object target)
{
      object weapon=me->query_temp("weapon");
      int enhance,damage,howlong,skill_sword;

      if (!weapon) return 0;
      if (me->query_temp("wzg-powerup"))
        return notify_fail("С���߻���ħ��\n");
      if (!me->is_fighting())
             return notify_fail("��û���ڴ�ܣ�\n");
      if (me->query_skill("zhenyuan-force",1)<80)
          return notify_fail("����ڹ�̫��������Խ�������\n");
      if (me->query_skill("sanqing-jian",1)<80) 
          return notify_fail("�㻹���ȰѾ��������ڽ����ϰɡ�\n");
    if (me->query_skill("kaishan-chui",1)<80)
        return notify_fail("��Ŀ�ɽ��̫��ˡ�\n");
      if (me->query("force")<200)
           return notify_fail("���������̣����Գ��С�\n");
     
    me->add("force", -200);
   
    message_vision(HIY"$N�趯����"+weapon->name()+
     HIY"���Խ�������ʹ����ɽ���������е������Ѷ��ֿ����ۻ����ң�Ŀ�ɿڴ���\n"NOR,me);
    weapon->set_temp("original/use_apply_skill",weapon->query("use_apply_skill"));
    weapon->set_temp("original/skill_type",weapon->query("apply/skill_type"));
    weapon->set_temp("original/skill_type2",weapon->query("skill_type"));
    weapon->set("use_apply_skill",1);
    weapon->set("apply/skill_type","hammer");
    weapon->set("skill_type","hammer");

    enhance=me->query_skill("sword")/3;
    skill_sword=me->query_skill("sword");
    me->add_temp("apply/attack", enhance);  
    damage=weapon->query("weapon_prop/damage");
    me->add_temp("apply/damage",damage);                
    me->set_temp("wzg-powerup", 1);    
    me->reset_action();
    me->start_call_out( (: call_other, __FILE__, "remove_effect", 
           me, enhance,damage,weapon:), skill_sword/5);
   
    return 1;
} 
void remove_effect(object me,int enhance,int damage,object weapon)
{
    if (weapon) {
      weapon->set("use_apply_skill",weapon->query_temp("original/use_apply_skill"));
      weapon->set("apply/skill_type",weapon->query_temp("original/skill_type"));
      weapon->set("skill_type",weapon->query_temp("original/skill_type2"));
    }
    me->add_temp("apply/attack",-enhance);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("wzg-powerup");    
    me->reset_action();
}

