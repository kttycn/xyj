#include <ansi.h>
string status_color(int current, int max);
void refresh_qn(object me);
void refresh_exp(object me);
void refresh_qi(object me);
void refresh_jing(object me);
void refresh_neili(object me);
void refresh_jingli(object me);
void refresh_weapon(object me);
void refresh_armor(object me);
void refresh_ring(object me);
void refresh_food_water(object me);

void show_two_screen(object ob)
{
	mapping my;
	int i;
	my = ob->query_entire_dbase();
	write(CLR);
	write(FR(8));
	for (i=1;i<=5;i++)
	 write(SET(i,64)""+HIW+BOLD+"��"NOR);
	write(SET(2,67)+HIY+"���ֳ֣�"NOR);
	if (ob->query_temp("wielded")) 
	 write(find_object(ob->query_temp("wielded"))->query("name"));
	else write(HIW"��"NOR);
	write(SET(3,67)+HIY+"������"NOR);
	if (ob->query_temp("weared")) 
	 write(find_object(ob->query_temp("weared"))->query("name"));
	else write(HIW"��"NOR);
	write(SET(4,67)+HIY+"�������"NOR);
	if (ob->query_temp("peidaied")) 
	 write(find_object(ob->query_temp("peidaied"))->query("name"));
	else write(HIW"��"NOR);
	write(SET(5,67)+HIM+"�Զ���"NOR);
	write(SET(2,2));
	write(HIY"����ѧ���� "HIM + my["combat_exp"]);
	write(SET(2,34));
	write(HIY"�����С���"HIY + my["daoxing"]);	
	write(SET(3,2));
	write(HIY"����Ѫ����");
	write(SET(3,14));
	printf(NOR"%s%5d/ %5d %s(%3d%%)" NOR,
        status_color(my["kee"], my["eff_kee"]), 
        my["kee"], 
        my["eff_kee"],
        status_color(my["eff_kee"], my["max_kee"]),
        my["eff_kee"] * 100 / my["max_kee"]);
        write(SET(4,2));
        write(HIY"�����񡿣�");
        write(SET(4,14));
	printf(NOR"%s%5d/ %5d %s(%3d%%) " NOR,
        status_color(my["sen"], my["eff_sen"]), 
        my["sen"], 
        my["eff_sen"],
        status_color(my["eff_sen"], my["max_sen"]),
        my["eff_sen"] * 100 / my["max_sen"]);
        write(SET(3,34));
        write(HIY"����������");
        write(SET(3,46));
	printf(NOR"%s%4d/ %4d (+%d)   " NOR,
        status_color(my["force"], my["max_force"]),
        my["force"], 
        my["max_force"],
        my["force_factor"] );
        write(SET(4,34));
        write(HIY"����������");
        write(SET(4,46));
	printf(NOR"%s%4d/ %4d (+%d)   " NOR,
        status_color(my["mana"], my["max_mana"]),
        my["mana"], 
        my["max_mana"],
        my["mana_factor"] );
        write(SET(5,2));
        write(HIW"��ʳ���");
        write(SET(5,14));
        printf(NOR"%s%5d/ %5d      ",
        status_color(my["food"], ob->max_food_capacity()),
        my["food"], 
        ob->max_food_capacity());
        write(SET(5,34));
        write(HIW"����ˮ����");
        write(SET(5,46));
        printf(NOR"%s%4d/ %4d      ",
        status_color(my["water"], ob->max_water_capacity()),
        my["water"], 
        ob->max_water_capacity());
        write(SET(6,0));
        write(HIW+BOLD"������������������������������������������ "HIC"��Ӱ��Ե"HIW" ��������������������"NOR);
        write(SET(1,0));
        write(HIW+BOLD"����������������������������������������������������������������������������������"NOR);
        write(SET(8,0));
}
void refresh_screen_all(object ob)
{
	write(SAVEC);
	refresh_qi(ob);
	refresh_jing(ob);
	refresh_neili(ob);
	refresh_jingli(ob);
	refresh_weapon(ob);
	refresh_armor(ob);
	refresh_ring(ob);
	refresh_food_water(ob);
	refresh_exp(ob);
	refresh_qn(ob);
	write(REST);
}
string status_color(int current, int max)
{
        int percent;

        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}
void refresh_exp(object me)
{
	write(SAVEC);
	write(SET(2,15)"             ");
	write(SET(2,15)+HIM+""+me->query("combat_exp")+NOR);
	write(REST);
}


void refresh_qn(object me)
{
	write(SAVEC);
	write(SET(2,46)"         ");
	write(SET(2,46)+HIY+""+me->query("potential")+NOR);
	write(REST);
}


void refresh_qi(object me)
{
	mapping my = me->query_entire_dbase();
	write(SAVEC);
	write(SET(3,14));
	printf(NOR"%s%5d/ %5d %s(%3d%%)" NOR,
        status_color(my["kee"], my["eff_kee"]), 
        my["kee"], 
        my["eff_kee"],
        status_color(my["eff_kee"], my["max_kee"]),
        my["eff_kee"] * 100 / my["max_kee"]);write(REST);
}

void refresh_jing(object me)
{
	mapping my = me->query_entire_dbase();write(SAVEC);
        write(SET(4,14));
	printf(NOR"%s%5d/ %5d %s(%3d%%)" NOR,
        status_color(my["sen"], my["eff_sen"]), 
        my["sen"], 
        my["eff_sen"],
        status_color(my["eff_sen"], my["max_sen"]),
        my["eff_sen"] * 100 / my["max_sen"]);write(REST);
}

void refresh_neili(object me)
{
	mapping my = me->query_entire_dbase();write(SAVEC);
	write(SET(3,46));
	printf(NOR"%s%4d/ %4d (+%d)   " NOR,
        status_color(my["force"], my["max_force"]),
        my["force"], 
        my["max_force"],
        my["force_factor"] );write(REST);
}

void refresh_jingli(object me)
{
	mapping my = me->query_entire_dbase();write(SAVEC);
	write(SET(4,46));
	printf(NOR"%s%4d/ %4d (+%d)   " NOR,
        status_color(my["mana"], my["max_mana"]),
        my["mana"], 
        my["max_mana"],
        my["mana_factor"] );write(REST);
}

void refresh_food_water(object me)
{
	mapping my = me->query_entire_dbase();write(SAVEC);
	write(SET(5,14));
        printf(NOR"%s%5d/ %5d      ",
        status_color(my["food"], me->max_food_capacity()),
        my["food"], 
        me->max_food_capacity());
        write(SET(5,46));
        printf(NOR"%s%4d/ %4d      ",
        status_color(my["water"], me->max_water_capacity()),
        my["water"], 
        me->max_water_capacity());write(REST);
}

void refresh_weapon(object me)
{
	mapping my = me->query_entire_dbase();write(SAVEC);
	if (me->query_temp("wielded")) 
	 write(SET(2,85)""+find_object(me->query_temp("wielded"))->query("name"));
	else write(HIW"��"NOR);write(REST);
}
void refresh_armor(object me)
{
	mapping my = me->query_entire_dbase();write(SAVEC);
	if (me->query_temp("weared")) 
	 write(SET(3,85)""+find_object(me->query_temp("weared"))->query("name"));
	else write(HIW"��"NOR);write(REST);
}
void refresh_ring(object me)
{
	mapping my = me->query_entire_dbase();write(SAVEC);
	if (me->query_temp("peidaied")) 
	 write(SET(1,85)""+find_object(me->query_temp("peidaied"))->query("name"));
	else write(HIW"��"NOR);write(REST);
}
