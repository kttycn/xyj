// Room: /d/jjf/keting.c

inherit ROOM;
#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ſڹ���һ����ң����顸������˽���ĸ����֣�������������
���顣�����ҽ�վ�����ԡ��ؽ������ڵ��е�̫ʦ���ϣ���ŭ������
������������������ͷЦ��Ц��Ҳ������Ϊû����˵�������ϵ�
���պ����ࡣ
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"stone_road",
  "north" : __DIR__"front_yard2",
  "west" : __DIR__"side_keting",
  "east" : __DIR__"dining_room",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/jiajiang" : 2,
  __DIR__"npc/qinqiong" : 1,
]));
  set("valid_startroom", 1);

  setup();

  call_other("/obj/board/jjf_b", "???");
}
void init()
{
	object where=this_object();

	remove_call_out("check_time");
	check_time(where);
	add_action("do_hear","hear");
}
void check_time(object where)
{
	mixed *local = localtime(time()-900000000);
	int t = local[2] * 60 + local[1];

	int phase=((int)(t%120));
	if(phase==59&&(!query("fighter/start_yanwu"))) jiang_jing(where);
	if(phase==62&&query("fighter/start_yanwu")) finish_jing(where);
	call_out("check_time",40,where);
}

void jiang_jing(object where)
{
	message("channel:es",HIY+"��������������(Qin qiong)�����ڿ�ʼ���䣬������ע���ˡ�\n"+NOR,users());
	tell_object(where,"�������������������֮��ս�ߣ���Ϊ����ʤ���Դ���֮��ʤ������ʤ�ڼ�����ʤ�ڵС�\n");
	tell_object(where,"���������������������ս�ߣ���Ϊ����ʤ������ʹ��֮�ؿ�ʤ��\n");
	tell_object(where,"�������������������Ի��ʤ��֪��������Ϊ������ʤ�ߣ���Ҳ����ʤ�ߣ���Ҳ��\n");
	tell_object(where,"����������������������㣬�������ࡣ�����߲��ھŵ�֮�£��ƹ��߶��ھ���֮�ϣ������Ա���ȫʤҲ��\n");
	tell_object(where,"........................................\n");
	set("fighter/start_yanwu",1);
}
void finish_jing(object where)
{
	tell_object(where,"����˵���������Ϣ�ɡ�\n");
	set("fighter/start_yanwu",0);
}

int do_hear()
{
	object yao;
	object me=this_player();

	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	if(!query("fighter/start_yanwu"))
		return notify_fail("����û��˵����\n");

	if((string)me->query("family/family_name")!="������")
		return notify_fail("���ɵ��Ӳ�����������\n");
	if(me->query("faith")>800)
		return notify_fail("�������˵���������ȥ��Щ�������������ˡ�\n");
	tell_object(me,"�㲻���������������������ˡ�\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("bawang-qiang",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"�������İ���ǹ�������ˣ�\n");
	return 1;
}
