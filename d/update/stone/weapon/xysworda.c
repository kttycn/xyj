#include <ansi.h>
#include <weapon.h>
inherit SWORD; 
inherit F_UNIQUE;
void create()

{
        set_name( HIY"轩辕剑"NOR , ({ "xuanyuan sword", "sword" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long",
HIY"这是一柄黄金色之千年古剑，传说是天界诸神赐于轩辕黄帝击败
蚩尤之旷世神剑：其内蕴藏无穷之力，为斩妖除魔的神器。\n" NOR
);
//              set("value", 0);
          	set("no_sell", "凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
		set("no_put", "这柄古剑装不进容器里去。\n");
		set("no_drop", "这么稀世难求的神兵宝剑，扔了多可惜呀！\n");
		set("no_give", "这可是神兵宝刃啊，哪能随便给人？\n");
		set("no_get", "你刚摸到剑身，突然轩辕剑现出万道金光，你心中一惊，忙把手缩了回去。\n");
                set("material", "gold"); 
                set("replace_file", "/d/obj/weapon/sword/qingfeng");
                set("wield_msg",HIY "突然四周金光大盛，仿佛金色阳光，摄人心魄，定睛细看，只见$N手中已多了一柄$n。\n" NOR);
                set("unwield_msg", "金光瞬间暗淡,$N将手中的"HIY"$n"NOR+"插入腰间的剑鞘。\n");
                set("armor_prop/strength",5);//力量
		set("armor_prop/courage",12);//胆识
		set("armor_prop/composure",3);//定力
		set("armor_prop/intelligence",8);//悟性
		set("armor_prop/spirituality",5);//灵性
		set("armor_prop/constitution",4);//体质
		set("armor_prop/personality",9);//容貌
		set("armor_prop/karma",6);//福缘
                set("male_only", 1);
        }
	
//	init_sword(180, TWO_HANDED);
        set("is_monitored", 1);
        init_sword(180); 
        setup();

}


void owner_is_killed(object killer)
{
        message_vision("\n"YEL"轩辕剑"NOR+"落在地上，瞬间金光大盛，突然又消失了。\n",killer);
        destruct(this_object());
}
mixed hit_ob(object me, object victim, int damage_bonus)
{   
        if ( !((string)me->query("gender")=="男性")) return 0;
        if (random(8)<2) return 0;
        if ( !((string)victim->query("gender")=="女性")){
     victim->busy(random(1));
     victim->receive_damage("kee", 25);
     victim->receive_wound("sen", 25);
//    return HIY "轩辕剑发出万道耀眼的金光，金光中$N犹如金甲天神，$n不由胆战心惊。\n" NOR;
    return HIY "$N一声轻啸，举起轩辕剑，由上至下重重的一挥，
轩辕剑中现出万道金色光芒，宛如万龙钻出般扑向$n，
光芒所到之处仿佛像能吸人的精魂似的，$n感到一阵眩晕。\n" NOR;
//    return HIY "光芒所到之处，仿佛能吸人精魂般，$n不禁胆战心惊。\n" NOR;
			
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
 return notify_fail("你正忙着呢，无法祭出"+HIY"轩辕剑。\n"NOR);
        if( !victim )
                return notify_fail("你想祭的人不在这里。\n");
        if( where->query("no_magic") )
    return notify_fail("这里不能祭"+HIY"轩辕剑。\n"NOR);
        if( !me->is_fighting() )
                return notify_fail("只有战斗中才能祭出。\n");
        if( (int)me->query("mana") < 100 )
 return notify_fail("你的法力不能控制"+HIY"轩辕剑。\n"NOR);

message_vision(YEL"\n$N大喝一声“去!”，只见$n"+YEL"「呼」地一下化做一条金黄色的六爪巨龙飞到半空。\n"NOR, me, fabao);

message_vision(YEL"霎那间天色一变！$n"+YEL"呼啸着向"+HIW"$N"+YEL"迎面斩下！\n"NOR, victim, fabao);
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
        //躲闪与成功
        vic_mana = (int)victim->query("mana");
        vic_dx = (int)victim->query("daoxing");
        vic_enchant = (int)victim->query("mana_factor");

        if( random(vic_dx/1000) > my_spi )
        {
message_vision(HIY"\n结果$N身形急闪，躲过了$n"+HIY"的攻势。\n"NOR, victim, fabao);
        }
        else
                if( random(vic_mana) > my_spi )
                {
message_vision(WHT"\n$N手一指大喝一声“来！”，只听$n"+WHT"发出一声轻哮！飞到了"+HIR"$N"+HIW"手中。\n"NOR, victim, fabao);
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
message_vision(HIY"\n结果$N"+HIY"来不及闪开，金光闪过之后，$n"+HIY"已经穿过"+HIW"$N"+HIY"的身体,\n"+HIY"        过了一会，鲜血才喷出来！\n\n"+"        $n"+HIW"通过这次实践,攻击力加强了.\n"NOR, victim, fabao,victim);
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
                return notify_fail("你想对谁祭"+name+"？\n");
        victim=present(target,environment(me));
        return fabao->ji_ob(victim);
}

