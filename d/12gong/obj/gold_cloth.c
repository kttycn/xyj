// by happ@YSZZ

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
//#include "chk_owner.c"

void create()
{
	set_name(HIY"�ƽ�ʥ��"NOR, ({ "huangjin shengjia", "armor" }) );
	set("long", "����һ����ս��������֮���ߺ�֮ˮ���Ĵ��ƶ��ɵ����ף��������ᣬ\nȴ�ɵ�ס�κ������Ĺ�����\n");
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_sell",1);
		set("no_give",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_put",1);
		set("value",10);
		set("wear_msg", HIY"ֻ����������һ����$N�ӱ�����ȡ��һ��$n"HIY"�������ϣ�ȫ���������Ľ�⡣\n"NOR);
		set("remove_msg", CYN"$N��$n"CYN"������������������ϸ�۳�һ�ţ���������ɫ��â��ʱ������ȥ��\n"NOR);
		set("material", "steel");
		set("armor_prop/armor",120);
	}
	setup();
}
int query_autoload() { return 1; }
