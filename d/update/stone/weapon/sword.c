// yitian-jian ���콣

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIC"���콣"NOR,({ "yitian jian", "yitian", "sword", "jian" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("rigidity", 9);
		set("sharpness", 9);
		set("material", "steel");
		set("weapon_prop/dodge", 5);
		set("weapon_prop/parry", 5);
		set("treasure",1);
		set("wield_force", 300);
		set("wield_maxforce", 700);
		set("wield_str", 22);
		set("wield_msg", HIY"$N��ৡ���һ��������콣���˸�������������â���£������Ƿɡ�\n$N���ɵô��ĵ�����һ�����ƺ�����\n"NOR);
		set("long", "��һ�����߳��̵Ľ�ɫ����������������������Ƕ��һ�������飬���⴦����һ����ͷ�����ڲ�Զ�ĵط�����Ƕ��һ��ϸС�����һ�����ɫ�ı�����������ȫ����ʮ�ʺ��⣬����������пռʣ��������ף�\n������ų������â��ǧ�����𣬺�����䣬���̷��ס�������ǽ�â�лó�һ����ɫ��Ӱ��������˸���������һ�����Բ�򣬻�ת���ѣ���ʵ���飬�����ϣ������ĸ����ι��֣������ѧ�������ߣ�һ��ȴ�ϳ����ǡ���ԯ�������������棬Ҳϵһ�ֽ��ɫ�Ľ����Ƴɣ��ϰ���Ƥ����Ƥ��׺���������ٿţ�ȫ�ý��ɫ�����˿��֯���ɣ��⻪�������ɶ��칤
		\n");                
		set("unwield_msg", HIY "���콣����һ���׹⣬��ৡ��ط��뽣�ʡ�\n" NOR);                
	}
	init_sword(170);
	setup();
}
