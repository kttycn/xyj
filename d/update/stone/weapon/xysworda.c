#include <ansi.h>
#include <weapon.h>
inherit SWORD; 
inherit F_UNIQUE;
void create()

{
        set_name( HIY"��ԯ��"NOR , ({ "xuanyuan sword", "sword" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
HIY"����һ���ƽ�ɫ֮ǧ��Ž�����˵��������������ԯ�Ƶۻ���
���֮�����񽣣������̲�����֮����Ϊն����ħ��������\n" NOR
);
//              set("value", 0);
          	set("no_sell", "��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
		set("no_put", "����Ž�װ����������ȥ��\n");
		set("no_drop", "��ôϡ�������������������˶��ϧѽ��\n");
		set("no_give", "�����������а������������ˣ�\n");
		set("no_get", "�����������ͻȻ��ԯ���ֳ������⣬������һ����æ�������˻�ȥ��\n");
                set("material", "gold"); 
                set("replace_file", "/d/obj/weapon/sword/qingfeng");
                set("wield_msg",HIY "ͻȻ���ܽ���ʢ���·��ɫ���⣬�������ǣ�����ϸ����ֻ��$N�����Ѷ���һ��$n��\n" NOR);
                set("unwield_msg", "���˲�䰵��,$N�����е�"HIY"$n"NOR+"��������Ľ��ʡ�\n");
                set("armor_prop/strength",5);//����
		set("armor_prop/courage",12);//��ʶ
		set("armor_prop/composure",3);//����
		set("armor_prop/intelligence",8);//����
		set("armor_prop/spirituality",5);//����
		set("armor_prop/constitution",4);//����
		set("armor_prop/personality",9);//��ò
		set("armor_prop/karma",6);//��Ե
                set("male_only", 1);
        }
	
//	init_sword(180, TWO_HANDED);
        set("is_monitored", 1);
        init_sword(180); 
        setup();

}


void owner_is_killed(object killer)
{
        message_vision("\n"YEL"��ԯ��"NOR+"���ڵ��ϣ�˲�����ʢ��ͻȻ����ʧ�ˡ�\n",killer);
        destruct(this_object());
}
mixed hit_ob(object me, object victim, int damage_bonus)
{   
        if ( !((string)me->query("gender")=="����")) return 0;
        if (random(8)<2) return 0;
        if ( !((string)victim->query("gender")=="Ů��")){
     victim->busy(random(1));
     victim->receive_damage("kee", 25);
     victim->receive_wound("sen", 25);
//    return HIY "��ԯ���������ҫ�۵Ľ�⣬�����$N����������$n���ɵ�ս�ľ���\n" NOR;
    return HIY "$Nһ����Х��������ԯ���������������ص�һ�ӣ�
��ԯ�����ֳ������ɫ��â�������������������$n��
��â����֮���·��������˵ľ����Ƶģ�$n�е�һ��ѣ�Ρ�\n" NOR;
//    return HIY "��â����֮�����·������˾���㣬$n������ս�ľ���\n" NOR;
			
			}
    return 0;
}

void init()
{
        check_owner();
}

int ji_ob(object victim)
{
        object fabao=this_object();
        object me=this_player();
        object where=environment(me);

        int my_spi;

        int vic_enchant, vic_dx, vic_mana;
        int damage;

        fabao->set("spi", 0);
         fabao->add("spi", 6000);
        if( me->is_busy() )
 return notify_fail("����æ���أ��޷�����"+HIY"��ԯ����\n"NOR);
        if( !victim )
                return notify_fail("��������˲������\n");
        if( where->query("no_magic") )
    return notify_fail("���ﲻ�ܼ�"+HIY"��ԯ����\n"NOR);
        if( !me->is_fighting() )
                return notify_fail("ֻ��ս���в��ܼ�����\n");
        if( (int)me->query("mana") < 100 )
 return notify_fail("��ķ������ܿ���"+HIY"��ԯ����\n"NOR);

message_vision(YEL"\n$N���һ����ȥ!����ֻ��$n"+YEL"��������һ�»���һ�����ɫ����צ�����ɵ���ա�\n"NOR, me, fabao);

message_vision(YEL"���Ǽ���ɫһ�䣡$n"+YEL"��Х����"+HIW"$N"+YEL"ӭ��ն�£�\n"NOR, victim, fabao);
        if( !victim->is_fighting(me) )
        {
                if( living(victim) )
                {
                        if( userp(victim) )
                                victim->fight_ob(me);
                        else
                                victim->kill_ob(me);
                }
                me->kill_ob(victim);
        }

        me->add("mana", -100);
        me->receive_damage("sen", 100);
        me->start_busy(1+random(3));

        my_spi = query("spi");
        fabao->set("spi", my_spi*3/2);
        //������ɹ�
        vic_mana = (int)victim->query("mana");
        vic_dx = (int)victim->query("daoxing");
        vic_enchant = (int)victim->query("mana_factor");

        if( random(vic_dx/1000) > my_spi )
        {
message_vision(HIY"\n���$N���μ����������$n"+HIY"�Ĺ��ơ�\n"NOR, victim, fabao);
        }
        else
                if( random(vic_mana) > my_spi )
                {
message_vision(WHT"\n$N��һָ���һ������������ֻ��$n"+WHT"����һ���������ɵ���"+HIR"$N"+HIW"���С�\n"NOR, victim, fabao);
                        fabao->move(victim);
                }
                else
                {
                        damage = 0;
                        damage = 100 + my_spi/2 - random(vic_mana/10) - vic_enchant*2;
                        if( damage < 0 ) damage = 0;
                        if( damage > 2000 ) damage = 2000;

                        if( damage > 0 )
                        {
message_vision(HIY"\n���$N"+HIY"�������������������֮��$n"+HIY"�Ѿ�����"+HIW"$N"+HIY"������,\n"+HIY"        ����һ�ᣬ��Ѫ���������\n\n"+"        $n"+HIW"ͨ�����ʵ��,��������ǿ��.\n"NOR, victim, fabao,victim);
                                victim->receive_damage("kee", damage);
                                victim->receive_wound("kee", damage/2);
                                fabao->add("spi",100);
                                COMBAT_D->report_status(victim);
                        }
                }
        return 1;
}

int ji (string target)
{
        object fabao = this_object ();
        object me = this_player();
        string name=fabao->query("name");
        object victim;

        if (!target)
                return notify_fail("�����˭��"+name+"��\n");
        victim=present(target,environment(me));
        return fabao->ji_ob(victim);
}

