// By Canoe 2001,03,25
#include <ansi.h>
inherit NPC;

string do_zhinv(object me);

void create()
{
	set_name(HIM"ţ��"NOR, ({ "niu lang"}));
	set("title", "���µ�һ������");
	set("gender", "����");
	set("age",25);
	set("long", "ԭ���Ǹ���ţ�ޣ�����֯Ů�మ������һ˫��Ů���󱻷�����������\nֻ��ÿ������³��߲���ȵ����ᡣ\n��������� about zhinv.\n");
	
	set("inquiry", ([
		"zhinv" : (: do_zhinv :),
		"֯Ů" : (: do_zhinv :),
	]) );
	
	setup();
	carry_object("/d/obj/cloth/choupao")->wear();
	
}

string do_zhinv(object me)
{
	me=this_player();
	if(me->query("obstacle/niulang")=="done")   {
		command("miss ");
		return("�Һ������Ѿ����Ҹ��ˣ�");
	}
	if((string)me->query_temp("ask_niulang")=="done")
		return("������λ���ɸϿ춯��ȥ����ĸ����˵��ɣ�\n");
	if((int)me->query("combat_exp")<800000 || (int)me->query("daoxing")<800000)
		return ("��λ���ɵĹ����ƺ����������Ҳ�������ȥ��\n");
	me->set_temp("ask_niulang","done");
	return(WHT+"��ĸ���ﲻ׼�Һ����Ӽ�����!���а취��\n"+ NOR);
}
