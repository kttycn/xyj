// spell_d.c.
#include <ansi.h>
/* table for �����������
   */
mapping t_ke=([
	"jin": "mu",
	"mu": "tu",
	"tu": "shui",
	"shui": "huo",
	"huo": "jin",
]);
mapping t_sheng=([
	"jin": "shui",
	"mu": "huo",
	"tu": "jin",
	"shui": "mu",
	"huo": "tu",
]);
mapping sx_name=([
	"jin" : HIY"��ϵ"NOR,
	"mu"  : HIG"ľϵ"NOR,
	"shui": HIC"ˮϵ"NOR,
	"huo" : HIR"��ϵ"NOR,
	"tu"  : YEL"��ϵ"NOR,
]);

string query_shuxing_chinese(string name)
{
	if(sx_name[name]) return sx_name[name];
	return "δ֪";
}

/* determine whether two ���� are �����
   if spell1 ���� spell2, then return = 1.
   if spell1 ��   spell2, then return = -1.
   otherwise, return 0.
   */
int skill_xiangke(string spell1, string spell2)
{
    int neutral=0;
    int result;
    if(t_ke[spell1]==spell2) {
 // spell1 can ���� spell2.
		result=1;
	} else if(t_sheng[spell1]==spell2){
		result=-1;
	}else{
		result=neutral;
    }
    return result;
}
/* determine whether two players' ���� are �����
   only effective between two players,
   or a NPC against a player,
   can't a player take advantage of a npc.
   if obj1 �� obj2, then return = 1.
   if obj1 �� obj2, then return = -1.
   otherwise, return 0.
   */
int check_xiangke(object obj1, object obj2)
{
    int neutral=0;
    int result;
    string skill1, skill2;
    skill1=obj1->query_skill_mapped("spells");
    skill2=obj2->query_skill_mapped("spells");
    if(!skill1||!skill2)return 0;
    // need at least 20 level of special spells.
    if((int)obj1->query_skill(skill1,1)<20) return neutral;
    if((int)obj2->query_skill(skill2,1)<20) return neutral;
    skill1=SKILL_D(skill1)->query_shuxing();
    skill2=SKILL_D(skill2)->query_shuxing();
    result=skill_xiangke(skill1, skill2);
    return result;
}
int attacking_cast_success(object attacker, object target, int success_adj)
{
	int ap, dp, success;
	int xk;

	ap = attacker->query_skill("spells");
	ap = ( ap * ap * ap / 10 ); //this is from skill.
	ap = ap*(1+attacker->query("daoxing")/500000);
	ap = ap+attacker->query("daoxing");
	dp = target->query("daoxing") + target->query("combat_exp")/3;
 //note here, daoxing is also useful in avoiding been casted.
	success = 0;
	if ( success_adj < 20 ) success_adj = 20;
	else if( success_adj > 500 ) success_adj = 500;
	ap = ap*success_adj/100;
 // mon 01/22/99
	xk=check_xiangke(attacker, target);
	if(xk==1) {
		dp=dp/5;
	} else if(xk==-1) {
		ap=ap/5;
	}
	if( random(100)>dp*100/(ap+dp) ) success = 1;
	return success;
}

int attacking_cast_damage(object attacker, object target, int damage_adj)
{
	int a_fali, d_fali, damage;
	int xk;
	if( damage_adj < 50 ) damage_adj = 50;
	else if( damage_adj > 200 ) damage_adj = 200;
 //will use current fali...but do not allow it exceeds 2 time of the max.
	a_fali = attacker->query("mana");
	if( a_fali > 2*attacker->query("max_mana") )
		a_fali = 2*attacker->query("max_mana");
	d_fali = target->query("mana");
	if( d_fali > 2*target->query("max_mana") )
		d_fali = 2*target->query("max_mana");
 //fali and shen.
	a_fali=a_fali/20+random(attacker->query("eff_sen") / 20);
	d_fali=d_fali/20+random(target->query("eff_sen") / 20);
 //mana_factor, here the attacker has some advantage.
 //the damage_adj higher, the better for attacker.
	a_fali+=(2*damage_adj/100)*(attacker->query("mana_factor"));
	d_fali+=(2*damage_adj/100)*random(target->query("mana_factor"));
	xk=check_xiangke(attacker, target);
	if(xk==1) {
		d_fali/=5;
	} else if(xk==-1) {
		a_fali/=5;
	}
	damage=(a_fali-d_fali)/2;
 //for backfire, we need let it be serious...
	if( damage < 0 ) damage = damage - target->query("mana_factor");
 //here increase the damage, since previously it's included in random()
	damage = damage*damage_adj/100; //last damage scaled again.
 //finally, we need let the spell level useful...
 //the setting is, at enabled level 200, the damage will double.
	if( damage > 0 )
	{
		damage += (damage*(int)attacker->query_skill("spells"))/300;
	}
	else if ( damage < 0 )
	{
		damage += (damage*(int)target->query_skill("spells"))/300;
	}
	return damage;
}
//the victim use defense.
void apply_damage(object winner, object victim,
int damage, string damage_type, string msg_hit)
{
	int i, type, damage_apply;
	object *inv;
	string shuxing;
	int def_count = 0;
	string *msg_defence = ({
		"ֻ��$N��$nϼ��һ����\n",
		"ֻ��$N��$nϼ��������\n",
		"ֻ��$N��$nϼ����һ����\n",
		"ֻ��$N��$nϼ����һ����\n"
	});
	if( damage <= 0 ) return;
	if(damage_type == "qi" || damage_type == "kee")
	{
		type = 0;
	}
	else if(damage_type == "shen" || damage_type == "sen")
	{
		type = 1;
	}
	else
	{
		type = 2;
	}
	damage_apply=damage;
	if(winner->query_skill_mapped("spells"))
		shuxing = SKILL_D(winner->query_skill_mapped("spells"))->query_shuxing();
	else shuxing = "δ֪";
 //check if the victim equipped defense fabao...
	inv = all_inventory(victim);
	for( i=0; i<sizeof(inv); i++)
	{
		if( !inv[i]->query("spell_defence") || !inv[i]->query("equipped") )
			continue;//not a equipped armor.
		if(!inv[i]->query("spell_defence/"+shuxing))
			continue;
		damage_apply=damage_apply-
		damage*inv[i]->query("spell_defence/"+shuxing+"/value")/100;
		if(inv[i]->query("spell_defence/"+shuxing+"/msg"))
			message_vision(inv[i]->query("spell_defence/"+shuxing+"/msg"),victim,inv[i]);
		else
			message_vision(msg_defence[def_count],victim,inv[i]);
		def_count++;
		if(def_count==4)def_count=0;

	}//end of for i=0 loop.
 //finally we can make damage to the victim...
	if( damage_apply <= 0 ){
		message_vision("���$N�Ĺ�����ȫ����ס��\n", winner, victim);
	return;
	}
	message_vision(msg_hit, winner, victim);
	if( type==0||type==2 )
	{
		victim->receive_damage("kee", damage_apply, winner);
		victim->receive_wound("kee", damage_apply/2, winner);
		COMBAT_D->report_status(victim);
	}
	if( type==1||type==2 )
	{
		victim->receive_damage("sen", damage_apply, winner);
		victim->receive_wound("sen", damage_apply/2, winner);
		COMBAT_D->report_sen_status(victim);
	}
	return;
}
/*
weiqi 981206
attacking-cast...called from spells function.
a typical call would be:
 SPELL_D->attacking_cast(
  me,
   //attacker
  target,
   //target
  success_adj,
   //success adjustment
  damage_adj,
   //damage adjustment
  "both",
   //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
  HIC "$N����ָͷѸ������ͻȻ����һ�磡��Ȼ��������������һ����$n��ȥ��\
n" NOR,
   //initial message
  HIC "���$n���յý�ͷ�ö\n" NOR,
   //success message
  HIC "����$n����һ���Ͷ��˿�����\n" NOR,
   //fail message
  HIC "���ǻ��汻$n�Է���һ�ƣ�����$N�ؾ��ȥ��\n" NOR,
   //backfire initial message
  HIC "���̫������ɣ�$n���յý�ͷ�ö\n" NOR
   //backfire hit message. note here $N and $n!!!
 );
*/
void attacking_cast(
	object attacker,
	object target,
	int success_adj,
	int damage_adj, //default value is 100 for this 2 parameters.
	string damage_type, //must be "shen"/"sen", "qi"/"kee" or "both"(default)
	string msg_init,
	string msg_success,
	string msg_fail,
	string msg_backfire_init,
	string msg_backfire_success)
{
	int damage;
 //first, show the initial message...
	message_vision( msg_init, attacker, target );
 //calculate if the casting can happen...
	if( attacking_cast_success(attacker, target, success_adj) == 0 )
	{
		message_vision( msg_fail, attacker, target );
  //let the target kill attacker.
		target->kill_ob(attacker);
		return;
	}
	damage = attacking_cast_damage(attacker, target, damage_adj);
	if( damage > 0 ){ //attacker hit target
		apply_damage(attacker, target, damage, damage_type, msg_success);
	}else if( damage < 0 ) //backfire
	{
		message_vision(msg_backfire_init, attacker, target);
		apply_damage(target, attacker, -damage, damage_type, msg_backfire_success);
	}
	else //damge=0
		message_vision(HIB "������ñ�$N�Է�����ס��˭Ҳû�гԿ���\n" NOR, target);
 //let the target kill attacker.
	target->kill_ob(attacker);
	return;
}
