//created by smile 12/13/1998
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_UNIQUE;

void create()
{
        set_name(YEL"���令��"NOR, ({ "zhuque huwan", "huwan","wrists" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", YEL"һ���ñ���ʥ������֮��׹����ƵĻ��󣬽��������\n"NOR);
    		set("material", "gold");
    		set("unit", "��");
    		set("value", 0);
    		set("no_sell", "��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
    		set("no_put", "�����令��װ����������ȥ��\n");
    		set("no_drop", "��ôϡ������Ļ��ֱ�����˶��ϧѽ��\n");
    		set("no_give", "����ǻ��ֱ��ﰡ�����������ˣ�\n");
    		set("no_get", YEL"����������令��ͻȻ�������ֽ�ɫ�ı���ʥ�����䣬������צ���㲻�ɵ�ս�ľ���\n"NOR);
    		set("armor_prop/armor", 100);
        }
        set("is_monitored",1);
        setup();
}

