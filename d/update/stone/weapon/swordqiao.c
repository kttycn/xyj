// ����.c �ֽ�

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
//inherit HANDS;
inherit SWORD;

void create()
{
	set_name(YEL"����"NOR, ({ "xianyuan jianqiao", "jianqiao", "sword" }));
	set_weight(25000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", YEL"����ǧ��Ž���ԯ���Ľ��ʣ������ڵ����Ľ��ɫ��â֮�С�
����ϵһ�ֽ��ɫ�Ľ����Ƴɣ��ϰ���Ƥ����Ƥ��׺������
���ٿţ�ȫ�ý��ɫ�����˿��֯���ɣ��⻪�������ɶ��칤��
��˵����ԯ��ͯ�û����ɣ�Σ��ʱ�̣�������ٻ�(zhaohuan)
���������Լ���\n"NOR);
		set("rigidity",100);
		set("no_put", 1);
		set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
		set("no_drop", 1);
		set("no_get", YEL"�������ԯ���ʣ�ͻȻ���ɫ�Ĺ�â����ס�㣬��ֻ������̨������������ˬ��\n"NOR);
		set("no_give", "��ԯ�������������ˣ�\n");
		set("value", 300000);
/*		set("armor_prop/strength",3);
		set("armor_prop/courage",3);
		set("armor_prop/composure",3);
		set("armor_prop/intelligence",3);
		set("armor_prop/spirituality",3);
		set("armor_prop/constitution",3);
		set("armor_prop/personality",15);
		set("armor_prop/karma",3);*/
		set("material", "steel");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������\n");
	}
	set("is_monitored",1);
	init_sword(50);
	setup();
}

