//	����֮�� ������
//	by happ@YSZZ 2000.4.15
//	/d/qujing/xuanyuan/dream.c

inherit ROOM;
#include <ansi.h>

void create()
{
set("short","���");
set("long",@LONG

�����������쪣�һƬ��ɳ��ǰ���ƺ��и����������ϣ��㿴����Χ
�ľ�ɫ��ò�ͣ������ƽʱ�����Ļ������ྶͥ�����˻�������˲�
����ড�

LONG);
setup();
}

void init()
{
	object ob = this_player();
	remove_call_out("appear");
	call_out("appear",3,ob);
}

void appear(object ob)
{
	object bigan=new(__DIR__"npc/bigan");
	object where=this_object();

	if( present("bi gan") )
	return;

	message_vision(HIC"��Ȼһ���������ؿڣ����Ű���񱼶�����\n"NOR,ob);
	bigan->move(where);
}

