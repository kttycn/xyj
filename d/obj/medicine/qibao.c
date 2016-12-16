// qibao.c

#include <ansi.h>
#include "medicine.h"

void create()
{
	set_name(HIB"�߱����׵�" NOR, ({"qibaomeiran dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�Ų�̫������ҩ�裬���ں���֮�֣���˵�з��ϻ�֮ͯ��Ч��\n");
		set("base_unit", "��");
		set("value", 100000);
		set("unit","��");
		set("weight", 80);
		set("only_do_effect", 1);
		set("mixture", ([
			"herb" : ([
				"shenglg"  : 1,
				"xuejie"   : 1,
				"xuelian"  : 1,
				"lurong"   : 1,
				"hafen"    : 1,
				"honghua"  : 1,
				"hugu"     : 1,
				"zzfen"    : 1,
				"heshouwu" : 1,
				"renshen"  : 1,
				"dangui"   : 1,
				"fuzi"     : 1
			]),
			"force"                : 300,
			"gin"                 : 50,
			"time"                 : 5,
			"min_level"            : 140,
			"shenlong-mixin"       : 200,
		]));
        }
        setup();
}

int do_eat(string arg)
{
	mapping my;
	object me=this_player();
	if(! arg || arg!="qibaomeiran dan")
	{
		write("��ʹ��ʲôҩ��\n");
		return 1;
	}

	my = me->query_entire_dbase();

	if (time() - me->query_temp("last_eat/qibao") < 120)
	{
		write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
		return 1;
	}

	me->set_temp("last_eat/qibao", time());

	message_vision(HIG "$N" HIG "����һ��" + name() +HIG "���������Ϸ����˱仯��\n", me);

	if ( my["age"] > 18 )
		tell_object(me, HIG "��о��Լ������������������������ˣ�\n" NOR);
	else
		tell_object(me, HIG "��������ҩƬû�ж��Ч����\n" NOR);

	log_file("static/using", sprintf("%s(%s) eat �߱����׵� at %s.\n",
		me->name(1), me->query("id"), ctime(time())));

	my["eff_gin"] = my["max_gin"];
	my["gin"] = my["max_gin"];
	my["eff_kee"] = my["max_kee"];
	my["kee"] = my["max_kee"];
	if (my["force"] < my["max_force"])
		my["force"] = my["max_force"];
	if (my["age"]>18)
		me->add("age_modify", -86400);
	me->start_busy(3);
	destruct(this_object());
	return 1;
}
