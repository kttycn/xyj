// /d/guzhanchang/obj/skull.c
//stone 20020624

#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("�׹�����",({"ku lou", "skull", "kulou"}));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","
                
һ���ײҲҵ�����ͷ�ǣ����������ڶ������ۿ����������㣬
�·�����������Ц�أ��㵹��һ������æ�����ı����۾���
\n");
                set("unit","��");
                set("value",5000);
                set("material","bone");
                set("wield_msg","$Nץס$n�ı��ӣ�����úܲ�˳�֣���Ҳ�����硣\n");
                set("unwield_msg","$N��$n�Ż������У�˦��˦��ʹ���֡�\n");
        }
        init_hammer(5);
        setup();
}
