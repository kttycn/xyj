// created 20020314 stone
// shiban.c

inherit ITEM;

void init();
void breaks();

void create()
{
 	set_name("ʯ��",({"shiban", "flagstone", "ban", "shi ban"}));
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long","����¥��һ��ʯ�壬����������֣�ģģ���������������\n");
        set("material", "stone");
        set("value", 0); // reduced price because now shop's selling
        		// price variable.
	}        
	setup();
}

void init()
{
        add_action("do_breaks", "breaks");
        add_action("do_breaks", "pi");
         add_action("do_breaks", "��");
}
int do_breaks(string arg){
	object ob,me;
	me=this_player();
	
	if( (!arg) || !((arg == "shiban") || (arg == "ʯ��")))
                return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_busy()) 
        	return notify_fail("��������æ���ء�");        
	if( (int)me->query("kee") < 200)
		return notify_fail("������������ˣ�������������������\n");
	if( (int)me->query("sen") < 200)
		return notify_fail("��������־���壬ǿ���˹��������߻���ħ��Σ�ա�\n");
	if( (int)me->query_skill("unarmed", 1) < 30)
		return notify_fail("���ȭ�Ź��򻹲�������㲻���ֻ����\n");
	if( (int)me->query_skill("force", 1) < 30)
		return notify_fail("����ڼҹ��򻹲�����ǿ���˹����»������ˣ�\n");
	if( (int)me->query("force") < 300 )
                return notify_fail("�������������\n");
	if( !this_object()->id(arg) ) return 0;
	ob=new("/d/obj/book/anabook.c");
	message_vision("$N�����������������������һ��С���졣\n", me);
	me->start_busy(3);
	message_vision("ͻȻ��$N˫�ۻ��������һ��������������Ϊ����һ������ʯ�塣\n��ʱʯ���Ϊ���ء���ʯ���е���һ��������$Næ���뻳�С�\n",me);
	ob->move(me);
//	ob -> move(this_object());
	me->add("force", -50);
	destruct(this_object());
	return 1;		
}