#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIY"�����"NOR, ({ "jingang zhao", "zhao", "cloth" }) );
	set("long",@LONG    
����һ��������������ģ�ͨ������ɽѩ��˿֯�ɣ������ޱ�
���������ˡ�������������ǰ�ɴ�Ħ����Я����ԭ��аħ��֮���ף�
���Ƿ�����Ͻ�ħ������
LONG);
	set("unit","��");
	set("material", "cloth");
	set("wear_msg", HIY "ֻ����������һ����$Nչ��һ����������������������ϡ�
˲ʱ������Ϊ֮ʧɫ������ǧ�������ƶ�䣬һ��ׯ������\n" NOR);
	set("remove_msg", HIY "$N������ִ����������������۵���СС��һ�š�\n" NOR);
	set("armor_prop/armor", 1000);
	set("armor_type", "cape");
	set("light",1);
	setup();
}
