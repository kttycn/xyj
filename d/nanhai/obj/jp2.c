// jingping.c ��ƿ 

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
	set_name("��ƿ", ({"jingping", "bottle"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�Ϻ�����ʢˮ�ľ�ƿ��\n");
		set("unit", "��");
		set("value", 5000);
		set("max_liquid", 500);
	}

	set("liquid", ([
		"type": "water",
		"name": "ʥˮ",
		"remaining": 10,
		"drunk_apply": 20,
	]));
}
void init()
{
	add_action("do_pour","pour");
}

int do_pour(string arg)
{
	object ob = this_player();
	object where = environment(ob);

	if( ! arg || arg != "water" )
		return notify_fail("��Ҫ��ʲô�Ӿ�ƿ�е�������\n");
	if( !environment(environment())->query("killed") )
		return notify_fail("�����ò��ž�ƿ��\n");                
	if( query("liquid/remaining") < 1 )
		return notify_fail("ƿ���е�ʥˮ�Ѿ����ȹ��ˡ�\n");
	if( where->query("short") != "������" )
		return notify_fail("��������Լ�Ҫȥ����ģ�\n");

	message_vision("$N�Ѿ�ƿ�е�ˮ�����ĵ����˲ι����ϣ��漣�����ˡ�\n",ob);
	message_vision(HIG"�˲ι������Ͼͷ�������ѿ��\n"NOR,ob);
	remove_call_out("reware");
	call_out("reward",3,ob);
	where->delete("killed");
	return 1;
}

void reward(object ob)
{
	int i;

	string name=ob->query("name");

	if( ob->query("obstacle/wzg") == "done" )
		return;
	if( !ob->query_temp("kill_tree") )
		return;
	if( !ob->query_temp("kill_fuxing");
		return;

	i = random(600);
	ob->add("obstacle/number",1);
	ob->set("obstacle/wzg","done");
	ob->add("daoxing",i+3000);
	who->add("score", 10);
	message("channel:chat",HIC"�����ġ���Ԫ����(Zhenyuan daxian)��"+name+"��ׯ�۾Ȼ��˲ι�����\n"NOR,users());
	message("channel:chat",HIW"������ն������������(Guanyin pusa)��"+ob->query("name")+"��������ȡ���ھŹأ�\n"NOR,users());
	tell_object (ob,"��Ӯ����"+COMBAT_D->chinese_daoxing(i+3000)+"�ĵ��У�\n");
	ob->save();
	destruct(this_object());
	return;
}
