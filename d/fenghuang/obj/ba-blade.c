#include <weapon.h>
#include <ansi.h>
//inherit SSERVER;
inherit BLADE;

void create()
{
	set_name( HIY"��"HIM"��"HIW"֮"HIC"��"NOR,({"bazhe dao","blade","dao"}) );
	set("long",
		"�ɹ»�Ұ���Թ����������ģ������������˵ӵ��ǿ���ħ�ԡ�"
	);
	set("no_drop","�������Ӳ��˵ģ�Ҳ���ܸ����ˡ�");
	set("no_give",1);
	set("no_put",1);
	set("no_sell",1);
	set_weight(500);
	if (clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("value",100000);           
		set("material", "gold");
	}
	init_blade(100);
	setup();        
}

