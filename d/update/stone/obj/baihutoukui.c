//created by smile 12/13/1998
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"�׻�ս��"NOR, ({ "baihu zhankui", "zhankui","bonnet" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIW"һ��������ʥ�ް׻�֮�������Ƶ�ս��������������\n"NOR);
    		set("material", "gold");
    		set("unit", "��");
    		set("value", 0);
    		set("no_sell", "��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
    		set("no_put", "��׻�ս��װ����������ȥ��\n");
    		set("no_drop", "��ôϡ������ı���ʥñ�����˶��ϧѽ��\n");
    		set("no_give", "����Ǳ������а������������ˣ�\n");
    		set("no_get", HIW"��������׻�ս����ͻȻ�׻�ս��������ɫ������ʥ�ް׻���������צ���㲻�ɵ�ս�ľ���\n"NOR);
    		set("armor_prop/armor", 100);
        }
        set("is_monitored",1);
        setup();
}

