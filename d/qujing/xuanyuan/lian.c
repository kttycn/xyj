
inherit ROOM;
void create()
{
set("short","���뷿");
set("long",@LONG
	
	������ط��������С�������ĳ��ĵط���������ɵ�
���ǵ�С��槼�Ϊ����ÿ��С�����ȥ�Ժ��ܺ���һ����
���������ص��ڱ���ٸ����ѡ��һЩ�����˵�ľ�ˣ���С��
��������ϰ��һ��С���������ɱ��cisha��ľ�������ӵ�����

LONG);
set("exits", ([
	"north" : __DIR__"nei1",
]));
set("objects", ([
	__DIR__"npc/bingma":2,
	 __DIR__"npc/master2":1,
]) );
setup();

}


void init()
{
add_action("do_cisha","cisha");
}
int do_cisha()
{
	 object me=this_player();
	 if(me->is_busy())
	return notify_fail("����æ���ء�\n");
	 if((string)me->query("family/family_name")!="��ԯ��Ĺ")
	return notify_fail("�㲻������ ��ԯ��Ĺ�ģ��ò��������ӵ�����\n");
	if(me->query("combat_exp")>100000)
	return notify_fail("���ȥ��һ�������.\n"); 
	if(me->query("faith")>200)
		return notify_fail("���Ѿ�����Ҫ�����ֵط����ӵ���.\n");
tell_object(me,"���������ľ�˵�Ҫ����λ����ȥ����ʱ��е����������û���˸�����.\n");

	 me->start_busy(2);
		me->add("faith",1);
		me->add("combat_exp",10);
		me->add("potential",2);
	me->add("kee",-50);
	 return 1;
}
