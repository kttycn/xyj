#include <ansi.h>
inherit ITEM;
void create()
{
 set_name("[1;33m����������[2;37;0m", ({ "desk","zuozi"}));
        set("long",
"\n[1;36m����ʯͷ�����űʼǱ����Ե�����[2;37;0m\n"
"\n[1;36m�����Ȼ��һ̨IBM��ԭװ�ʼǱ����ԣ�[2;37;0m\n");
set_weight(500);
set_max_encumbrance(10000);
if( clonep() )
{
                object a;
                  seteuid(getuid());
if(a=new("/d/update/stone/obj/computer"))
                  a->move(this_object());
                set_default_object(__FILE__);
set("no_get", 1);
 setup();
}
}
 int is_container() { return 1; }
      
