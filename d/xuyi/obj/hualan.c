// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;

void create()
{
        set_name("��໨��", ({ "zhubian hualan", "hualan" }) );
        set_weight(500);
        set_max_encumbrance(500);
        set_max_items(1);
        if( clonep() ){
     object flower;
        seteuid(getuid());
        if(flower=new("/d/obj/flower/juhua"))
        flower->move(this_object());

        set_default_object(__FILE__);
      }  else {
                set("unit", "��");
                set("long", "����һ�����������ɵĻ�����������������ľջ���\n");
     set("value", 5000);
        }
}

int is_container() { return 1; }

