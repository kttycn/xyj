// created 6/8/97 pickle
// lingjian.c

inherit ITEM;

void init();
void breaks();

void create()
{
       	set_name("����",({"zhuzi", "zhu", "zi", "zhuzi", "pillar"}));
	set_weight(100000);
/*        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long",
	"һ���������С���ӡ����滮��һЩ���������������ͼ����\n");
        set("material", "paper");
        set("value", 0); // reduced price because now shop's selling
	// price variable.
        set("skill", ([
                        "name": "spells",
                        "dx_required": 50,
                        "sen_cost": 20,
                        "difficulty": 25,
                        "max_skill": 40,
]) );
        }*/
	setup();
}

void init()
{
        add_action("do_breaks", "breaks");
}
int do_breaks(string arg){
	object ob,me;
	me=this_player();
	
	if( (!arg) || !((arg == "zhuzi") || (arg == "pillar")))
                return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_busy()) return notify_fail("��������æ���ء�");
        
	if( (int)me->query("kee") < 200)
		return notify_fail("������������ˣ�������������������\n");
	if( (int)me->query("sen") < 200)
		return notify_fail("��������־���壬ǿ���˹��������߻���ħ��Σ�ա�\n");
	if( (int)me->query_skill("unarmed", 1) < 30)
		return notify_fail("���ȭ�Ź��򻹲�������㲻���ֻ����\n");
	if( (int)me->query_skill("force", 1) < 30)
		return notify_fail("����������������棬ǿ���˹����»������ˣ�\n");
	if( (int)me->query("force") < 300 )
                return notify_fail("�������������\n");
	if( !this_object()->id(arg) ) return 0;
	ob=new("/d/obj/book/anabook.c");
	message_vision("$N�����������������������һ��С���졣\n", me);
	me->start_busy(3);
	message_vision("ͻȻ��$N˫�ۻ��������һ������������������Ϊ����һ���������ӡ���ʱ���Ӷ�Ϊ���ء��������е���һ��������\n",me);
	ob->move(me);
	me->add("force", -50);
	destruct(this_object());
	return 1;		
}