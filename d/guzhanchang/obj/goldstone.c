// created 20020425 stone
// goldstone.c

inherit ITEM;
#include <ansi.h>
void init();
void lians();

void create()
{
 	set_name(HIY"���ʯ"NOR,({"shitou","shitou","stone"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long","����һ����˸�ŵ��ƹ��ʯͷ��������һ���ʯ��\n");
        set("material", "stone");
        set("value", 0); 
	}        
	setup();
}

void init()
{
        add_action("do_lians", "lians");
        add_action("do_lians", "liangold");
        add_action("do_lians", "��");
}
int do_lians(string arg){
	object ob,me;
	me=this_player();
	
	if( (!arg) || !((arg == "shitou") || (arg == "���ʯ")))
                return notify_fail("��Ҫ���ڷ�����ʲô��\n");
        if (me->is_busy()) 
        	return notify_fail("��������æ���ء�");        
	if( (int)me->query("kee") < 200)
		return notify_fail("������������ˣ�������������������\n");
	if( (int)me->query("sen") < 200)
		return notify_fail("��������־���壬ǿ���˹��������߻���ħ��Σ�ա�\n");
	if( (int)me->query_skill("force", 1) < 200)
		return notify_fail("����ڼҹ��򻹲�����ǿ���˹����»������ˣ�\n");	
	if( (int)me->query("force") < 2000 )
                return notify_fail("����������㣬���ܷ����Ȼ�������ҵ���������\n");
        if( (int)me->query("mana") < 2000 )
                return notify_fail("��ķ���������ӯ������ʩչ����ʯ�ɽ���ͨ��\n");
	if( !this_object()->id(arg) ) return 0;
	ob=new("/obj/money/gold.c");
	message_vision("$N�ӻ���ȡ��һ��ʯͷ��\$N�͵�����һ����������ϥ���£���ʯͷ��˫�����¸�ס��\n\n", me);
	me->start_busy(8);
	message_vision(HIR"һ���$N��ɫ�Ǻ죬ͷ��ð��˿˿���̣�$N��˫�֣�ȴ����������졣\n\n"NOR,me);	
	message_vision("$N���е�ʯͷ��������С��һ���ս�ʯͷ����ζɢ�˿�����\n�����$N���е�ʯͷ�������ˣ�$N�������У�ȴ����һ��ƳγεĽ��ӡ�\n",me);
	ob->move(me);
	ob -> move(this_object());
	me->set("force", 0);
	me->set("mana", 0);
//	me->add("force", -50);
//	me->add("nama", -50);
	destruct(this_object());
	return 1;		
}