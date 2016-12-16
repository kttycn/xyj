// changan wusheng
// room1.c

inherit ROOM;
#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create()
{
	set ("short", "��ʥ���");
	set ("long", @LONG

������֮ʥ��Ĵ�Ʈ���ŴӰ˸������������������̡���
ϸ�����ð˸��󶦣���Զ��֮����������˿˿���̣����д�
�㣬��������������Ʈ�ݣ��޲������Ŀ��������˸����л���
�Ű����Ĺ⣬ʹ���������κλ��Ҳ��ҹͨ����
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"northwest": __DIR__"room4",
		"north": __DIR__"shijie5",
		"northeast": __DIR__"room5",
		"west": __DIR__"room3",
		"east": __DIR__"room2",
		"south": __DIR__"guangchang",
	]));
	set("objects", ([
		"/d/wusheng/obj/danlu": 1,
		"/d/wusheng/npc/zhangmen": 1,]));
	set("no_clean_up", 0);
	set("outdoors", "wusheng");
	setup();
}
void init()
{
	object who=this_player();
	object where=this_object();
	if( (string)who->query("family/family_name")=="��ʥ��" ) {
		call_out("heal_up", 9, who);
	}
	remove_call_out("sounding");
	call_out("sounding", random(10), this_object());
	remove_call_out("check_time");
	check_time(where);
	add_action("do_hear","hear");
}
int sounding(object where)
{
    string *msgs=({
    "�˸�����ͬʱƮ��һ�����̡�\n",
    "�˸����е����ͬʱ���˼�����\n",
    "��������Ϻ��ڴ����������\n",
    "����Ĺ��̻���һ��������\n",
  });
  tell_room (where,msgs[random(sizeof(msgs))]);
}

int heal_up(object who)
{
        if( !who || environment(who) != this_object() ){
		 return 1;
	}
/*
	if( (int)who->query("max_sen")==(int)who->query("eff_sen")
	&& 	(int)who->query("max_kee")==(int)who->query("max_kee") ){
		return 1;
	}
	
*/
        who->set("eff_gin", (int)who->query("max_gin"));
        who->set("eff_kee", (int)who->query("max_kee"));
        who->set("eff_sen", (int)who->query("max_sen"));

        message_vision("��������Ʈ��$N��$N�������˼�������\n", who);
        write("������Լ��ľ�����Ѫһ���Ӷ��ָ��ˡ�\n");

	if( (int)who->query("food") < (int)who->max_food_capacity() )
		who->set("food", (int)who->max_food_capacity());
	if( (int)who->query("water")< (int)who->max_water_capacity())
		who->set("water", (int)who->max_water_capacity());


        return 1;
}
void check_time(object where)
{
	mixed *local = localtime(time()-900000000);
	int t = local[2] * 60 + local[1];

	int phase=((int)(t%120));
	if(phase==31&&(!query("wusheng/start_jiangjing"))) jiang_jing(where);
	if(phase==34&&query("wusheng/start_jiangjing")) finish_jing(where);
	call_out("check_time",40,where);
}

void jiang_jing(object where)
{
	message("channel:es",HIY+"��ʥ����ʥ�š�������(Master dadi)�����ڿ��������似����λ���ӵ����������\n"+NOR,users());
	tell_object(where,"�����������۵�����������֮������֮������֮���Ƴ�֮��\n");
	tell_object(where,"�����������۵���������������Ī���������¡�\n");
	tell_object(where,"�����������۵���������֮�𣬵�֮�󣬷�Ī֮��������Ȼ��\n");
	tell_object(where,"�����������۵��������ʵ���֮������֮����֮��֮����֮��֮����֮��֮���������У�Ϊ�����ѣ��������ס���ν���¡�\n");
	tell_object(where,"........................................\n");
	set("wusheng/start_jiangjing",1);
}
void finish_jing(object where)
{
	tell_object(where,"������˵���������Ϣ�ɡ�\n");
	set("wusheng/start_jiangjing",0);
}
int do_hear()
{
	object yao;
	object me=this_player();

	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	if(!query("wusheng/start_jiangjing"))
		return notify_fail("�����ۻ�û�п�ʼ��������Ǭ������\n");

	if((string)me->query("family/family_name")!="��ʥ��")
		return notify_fail("���ɵ��Ӳ�����������\n");
	if(me->query("faith")>800)
		return notify_fail("�����۶���˵���������ȥ��Щ�������������ˡ�\n");
	tell_object(me,"�㲻���������۵��似��Ϊ���������ˡ�\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("xiantian-force",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"������������Ǭ���������ˣ�\n");
	return 1;
}
