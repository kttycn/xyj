//Cracked by Roath
// anabook.c
//stone creat
//20020222

inherit ITEM;

void init();
int do_read(string arg);

void create()
{
        set_name("�����Լ���", ({"wanyan book","book","shu","ana"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long",
	"������Լ�����ٶ�ҳ���߽ǽ������΢΢���Ƶķ����ϲԾ�������д�š����Լ�����\n");
        set("material", "paper");
        set("value", 500);   
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
	string *ana = ({
		"�����Թ�����𣬸��ǿ�����������ڣ�",
		"��ˮ���������䣬�����¹���ѩ��",
		"����Ѱ��ǧ�ٶȡ���Ȼ���ף�����ȴ�ڣ��ƻ���ɺ����",
		"ǧ���������縳����������˭�ߡ�",
		"ǧ�Ž�ɽ��Ӣ�����٣�����ı������鿸�̨�������ܱ������紵ȥ��",
		"�����񾩣�ӯӯ���ӣ�������������ż��",
		"����¥���ݶ��С�������������˼�ᡣ",
		"����꣬׷��˼��ҹҹ���ǣ���������˯��",
		"�����죬��Ҷ�أ���ɫ���������Ϻ��̴䡣",
		"��ɢ��Ҵң��˺�������껨ʤȥ��졣��ϧ���껨���ã�֪��˭ͬ��",
		"ȥ��Ԫҹʱ�����е����硣�µ�����ͷ����Լ�ƻ��",
		"��Զ��������������紺ˮ��",
		"����᳦��ӯӯ���ᡣ¥��Ī��Σ���С�",
		"���б�����ϣ���������Բȱ�����¹���ȫ����Ը�˳��ã�ǧ�ﹲ濾ꡣ",
		"����¥���ݶ��С�������������˼�ᡣ",
		"��ˮ���������䣬�����¹���ѩ��",		
		});
	me=this_player();
	where=environment(me);

    	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("�ļ�Ҫ����������\n");
    	if( me->is_busy() )
        		return notify_fail("������æ���أ����й������ļ�...\n");
   	if( me->is_fighting() )
        		return notify_fail("̫�д��˰ɣ����ʱ������...\n");
	if( where->query("no_fight") )
			return notify_fail("�˴����˴���������\n");

	if( (int)me->query_skill("literate",1)<70 )
		return notify_fail("�㷭���ļ��۾���������˼��䣬����û������ɶ��˼��\n");
	if( (int)me->query_skill("literate",1)>85 )
		return notify_fail("�����ķ������Ѿ��������裬����鲻�����㳤�����١�\n");

	sen_cost = 15 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("������ͷ���ۻ��������˯������Ϣ��Ϣ�ˡ�\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("literate", 1)/3+(int)me->query("int")+1;
	me->improve_skill("literate", gain);

    	message_vision("$N���Ų��ļ�ר�����µ������" + ana[random(sizeof(ana))] + "\n", me);
		
	return 1;
}

