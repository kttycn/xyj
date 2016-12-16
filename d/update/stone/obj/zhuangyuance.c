//Cracked by Roath
// zhuangyuance.c
// stone
// 20020219

inherit ITEM;

void init();
int do_read(string arg);

void create()
{
        set_name("��״Ԫ�ߡ�", ({"plan","zhuangyuan ce","book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long",
	"�����Լ�������Ĵ������װ��ֵķ���������������д�š�״Ԫ�ߡ���ī���ƺ������¡�\n");
        set("material", "paper");
        set("value", 600);   
        }
}

void init()
{
	add_action("do_read", "read");
	add_action("do_read", "study");
}

int do_read(string arg)
{
	object me, where;
	int sen_cost, gain;
	string *plan = ({
		"һ���һ��¶��һ����һƬ�졣",
		"һʱȰ���Կڣ�����Ȱ�����顣",
		"һ�Ÿ������ʿͣ�ǧ�������Ĵ�ҡ�",
		"һ�����в����磬��߹�����Ǭ����",
		"һ˫���ۿ����磬��ǻ��Ѫ��֪�ѡ�",
		"���䶫�������ݣ�һ��ǧ�������ˡ�",
		"���¶�ʱ��ѧ�ʣ��������Ｔ���¡�",
		"����˳����������������Ҫ��һ�����ġ�",
		"ǧ������˫�ܱʣ���ʱ����һƪʫ��",
		"�������������ϣ������޺��³�Բ��",
		"����ɴ���׷�䣬ֻ�ǵ�ʱ���Ȼ��",
		"�´������ղ��ڣ�Ϊ���������㲡�",
		"�޿��κλ���ȥ��������ʶ�������",
		"�����޾��������ĵؽ�Ѱ˼�顣",
		"���ʱ�ѱ����ѣ����������ٻ��С�",
		"ֱ����˼�����棬δ����������",
		"�϶�Ӧ��͵��ҩ���̺�����ҹҹ�ġ�",
		"ҹ��һ�����Σ�����ʮ�����顣",
		"������������գ��˺޲��ط����¡�",
		"ʮ��ƻ��˪���죬�����˿���껪��",
		"�����ε����໥��ֻĽԧ�첻Ľ�ɡ�",
		"���޲ʷ�˫�ɼ���������Ϭһ��ͨ��",
		"�����Ƴ���ǰ�£�Ͷʯ����ˮ���졣",
		"ˮ�ʯ�·��ɺ���ɽ������Ա��졣",
		"������Ƹ�������һ̶���¾���ۡ�",
		"����֦ͷ�����ѣ��仨ˮ������¡�",
		"�˼侻������Т���ĵع�����ʥ�͡�",
		"��ɽ��ˮ��ɽ�㣬��عŷ�Ű��㡣",
		"���ͻ�������أ��������������졣",
		"�������������꣬�������㻨�ͷ硣",	
		});
	me=this_player();
	where=environment(me);

    	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("��Ҫ����������\n");
    	if( me->is_busy() )
        		return notify_fail("������æ���أ����й��򹥶����Լ�...\n");
   	if( me->is_fighting() )
        		return notify_fail("̫�д��˰ɣ����ʱ�����߼�...\n");
	if( where->query("no_fight") )
			return notify_fail("�˴����˴���������\n");

	if( (int)me->query_skill("literate",1)<139 )
		return notify_fail("�����Ų߼�������˼�����˼��䣬����û������ɶ��˼��\n");
	if( (int)me->query_skill("literate",1)>150 )
		return notify_fail("�����Ĳŷ����Ѿ��������裬����鲻�����㳤�����١�\n");

	sen_cost = 25 + (40-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("������ͷ�����ͣ������˯������Ϣ��Ϣ�ˡ�\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("literate", 1)/10+(int)me->query("int")+1;
	me->improve_skill("literate", gain);

    	message_vision("$N���Ų�߼�������˼�����" + plan[random(sizeof(plan))] + "\n", me);
		
	return 1;
}

