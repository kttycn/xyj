//shushan2 by yushu@SHXY 2000.12
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("���ǽ�", ({"qixing sword", "sword", "jian",
"qixing"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ��������ɫ�ı�����\n");
                set("unit", "��");
		set("wield_msg",
"һ��������ɫ��$n�ӽ����е������䵽����$N�����С�\n");
		set("unwield_msg",
"$N�����е�$n�������䣬����¶��һ˿Ц�⣡\n");
              set("value",12000);
		set("weapon_prop/courage", 10);
        }
        init_sword(60);
        setup();
}
