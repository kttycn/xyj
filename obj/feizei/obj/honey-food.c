// honey.c ������¶
// stone 20020415
//add_mana 4

#include <ansi.h>
inherit ITEM;

void init();
void eat();

void create()
{
	set_name("������¶",({HIY"honey"NOR,"fengwang milu", "milu"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�ٻ������������ɵ��ٻ����еİ�ֻ��������
������ɽȪˮ�ط����죬���������������洦��\n");
		set("unit", "��");
		set("value", 2000);
		set("no_drop","��ô����ķ�����¶�����˶��ϧѽ��\n");
		set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
        set("remaining", 4);
        set("food_supply", 30);
    }
	
	setup();
}

void init()
{
	add_action("do_chi", "eat");
}


int do_chi(string arg)
{
	object me = this_player();
	
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("����һ��������û����ɡ�\n");
    if(   (int)this_player()->query("food")
       >= (int)this_player()->max_food_capacity() )
     return notify_fail("���Ѿ��Ե�̫���ˣ��ٳԾͳ����ˡ�\n");

    this_player()->add("food", (int)query("food_supply"));
//    	me->add_maximum_force(4);
	me->add_maximum_mana(1);

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
	if ( query("remaining") )
	{
   		 message_vision("$N����һ�������¶���˼��ڡ�һ������ֱ͸�θ���$N���þ���ö��ˡ�\n", this_player());
   		 tell_object(me, "��ֻ��һ�������ϳ���̨���´����裬ȫ����̩......\n" NOR);
	} else 
	{ 
   		 message_vision("$N����������һ�������¶��ø�Ǭ�����������������죬��ζ���\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}