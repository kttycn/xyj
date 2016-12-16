#include <ansi.h>

inherit NPC;
string apply_gongming(object me);
int ask_xuewei();

string * xuewei_desc = ({
       BLU "��ä" NOR,
       BLU "ͯ��" NOR,
       BLU "���" NOR,
       CYN "����" NOR,
       CYN "��Ԫ" NOR,
       CYN "��ʿ" NOR,
       CYN "��Ԫ" NOR,
       GRN "��ʿ" NOR,
       GRN "̽��" NOR,
       GRN "����" NOR,
       GRN "״Ԫ" NOR,
       HIY "����Ժʿ" NOR,
       HIY "����˶ʿ" NOR,
       HIY "���ֲ�ʿ" NOR,
       HIY "����Ժ����" NOR,
       HIR "����ʿ" NOR,
       HIR "ѧʿ" NOR,
       HIR "�ڸ��ѧʿ" NOR,
       HIR "�ڸ��׸�" NOR,
       MAG "��ѧ����ʦ" NOR,
       HIW "ʥ��" NOR,
});

void create()
{
	set_name("��֪��", ({"he zhizhang", "he", "zhizhang"}));
	set("gender", "����");
	set("age", 55);
	set("title", "���Ӽ��ѧʿ");
	set("str", 25);
	set("int", 30);
	set("long", "��֪���ǹ��Ӽ��ѧʿ��ͳ��ȫ�����˿��Լ�������\n");
	set("combat_exp", 30000);
	set("daoxing", 50000);

	set("attitude", "friendly");
	set("class", "scholar");
	set_skill("unarmed", 50);
	set_skill("dodge",50);
	set_skill("literate", 100);
	set_skill("parry", 50);

	set("force", 500); 
	set("max_force", 500);
	set("inquiry", ([
		"name" : "��������ҳ�...�Ϸ��֪���ɻ��϶��͹��Ӽ��ѧʿ��ʵ�������ҵ���\n",
		"here" : "������ǹ��Ӽࡣ\n",
		"����ʶ��": "���ˣ��������Եط��ˣ�\n",
		"ѧϰ" : "ֻҪ�ܹܸ��϶������Ǿ��գ�\n",
		"����" : (: apply_gongming :),
		"ѧλ" : (:ask_xuewei:),
	]) );
	setup();
	carry_object("/d/obj/cloth/choupao")->wear();
}

int recognize_apprentice(object ob, object who)
{
/*
	object tongpai;
        if( !tongpai = present("tong pai", ob))
return notify_fail("��֪��Ц����û���ܹܸ����Ͽɣ����ǲ�������ѧ���ģ�\n");
	if((string)tongpai->query("player") != (string)ob->id())
return notify_fail("��֪�µ�����һ�ۣ�ѧ��֮���������ף�����\n");
*/  
      return 1;
}

string apply_gongming(object me)
{
	me=this_player();
	if( me->query("class") != 0 ) //means already has a class
	{
		return "���������ǹ������̣��ֺαع������ϣ�\n";
	}
	else
	{
		message_vision("��֪��˵�������������ǹ������̣��ֺαع������ϣ�\n", me);
		message_vision("��֪�¶�$N̾�˿���������Ȼ���������...\n", me);
		me->set("class", "scholar");
		if( me->query_skill("literate", 1) < 20 )
			return "�Ը��µĲ�ʶ����ֻ�ܴ�ͯ������\n";
		else if( me->query_skill("literate", 1) < 100 )
			return "�Ը��µĲ�ʶ��������Ż��ǿ��Եġ�\n";
		else    return "�Ը��µĲ�ʶ��������ѧʿû���⡣\n";
	}
}

int ask_xuewei()
{
	int lv;
	object ob = this_player();
	if (ob->query_temp("ask_xuewei"))
	{
		command("say "+ob->query("name")+"���㷳����ѽ��\n");
		return 1;
	}
	lv = (ob->query_skill("literate",1) / 10);
	if (lv >= sizeof(xuewei_desc)) lv = sizeof(xuewei_desc)-1; 
	if (lv < 3) 
		command("say "+ob->query("name")+"�����ǵ�īˮҲ����˼��? �������ѧλ������! \n");
	else if (lv < 10) 
		command("say "+ob->query("name")+"������������ǰ;���ܸ�������ѧλ���㣬�����ú�Ŭ��! \n");
	else
		command("say ��Ȼ�ǳ���������ǰ�˰���"+ob->query("name")+"���ҷǳ��������л���Ϊ����ѧλ! \n");
	message("channel:chat",HIY+"��ʥּ����֪��(He zhizhang)������һ�ʥּ������"+ob->query("name")+"("+ob->query("id")+")"+xuewei_desc[lv]+HIY"ѧλ���մˣ�\n"+NOR,users());
	ob->set("xuewei",xuewei_desc[lv]);
	ob->set_temp("ask_xuewei",1);
	return 1;
}
