#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_UNIQUE;

void create()
{
	set_name(HIC "����ս��" NOR, ({ "qinglong zhanjia", "zhanjia" ,"armor"}) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		 set("long", HIC"һ���ö���ʥ������֮�����Ƶ�ս�ף�����������\n"NOR);
    		set("material", "gold");
    		set("unit", "��");
    		set("value", 0);
    		set("no_sell", "��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
    		set("no_put", "������ս��װ����������ȥ��\n");
    		set("no_drop", "��ôϡ������ı���ʥ�£����˶��ϧѽ��\n");
    		set("no_give", "����Ǳ���ʥ�°������������ˣ�\n");
    		set("no_get", HIC"�����������ս��,ͻȻ����ս�����ֳ���ɫ�Ķ���ʥ��������������צ���㲻�ɵ�ս�ľ���\n"NOR);
    		set("armor_prop/armor", 100);//�ο���������60set("unit", "��");
		set("armor_prop/dodge", -2);
	}
	set("is_monitored",1);
	setup();
}


