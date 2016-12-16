//2001.03.22 at fei
inherit NPC;
#include <ansi.h>
int give_bonnet();
int give_dan();
int answer_me();
int accept_object(object who, object ob)
{
	if( (string)ob->query("id")=="loyal bonnet" )
	{
		who->set("fei/bonnet",0);
		command("say �ý�û����ٽ費�ѡ�");
		return 1;
	}
}
void create()
{
	set_name(HIY"�Ʒ�"NOR, ({"guan jia","guanjia"}));
	set ("long", @LONG
    ���������︺�����ҷ�����(gift)Ŷ��
    �����ϻ�����ʦ����(bonnet)��!
    �������ȥ����(ask)�����ǵã���ʦ����������Ҫ��Ŷ��
LONG);
	set("gender", "����");
	set("title",HIG"�����ܼ�"NOR);
	set("age", 20);
	set("per", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("inquiry", ([
		"bonnet":(:give_bonnet:),
		"gift":(:give_dan:),
		"����":(:give_dan:),
		"��ʦ����":(:give_bonnet:),
		"����":(:give_bonnet:),
		"name":(:answer_me:),
	]));
	setup();
}
void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

int answer_me()
{
	command("say ���ǳ����ܼ���㣬�����﷢����ʦ���ں����������ҵġ�\n");
	return 1;
}
int give_dan()
{
	int i,lvl = 50;
	object dan;
	object who=this_player();
	mapping skills;
	string *sk;
	if (!userp(who))
	{
		command("heng");
		command("say ʲôСèС��Ҳ��Ҫ�����");
		command("qi");
		return 1;
	}
	if (who->query("fei/gift")==2)
	{
		message_vision("$N����$n����һ����\n",this_object(),this_player());
		command("say ����ֻ�������Σ�����Ͳ����ˣ�");
		return 1;
	}
	skills = who->query_skills();
	if (mapp(skills)) {
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			if (skills[sk[i]]>55 
			|| who->query("daoxing")>51000
			|| who->query("combat_exp")>51000
			|| who->query("max_force")>510
			|| who->query("max_mana")>510)
			{
				message_vision(CYN"$N����$n̾�˿�����\n"NOR,this_object(),who);
				command("say ���Ѿ������������ʱ���ˡ�������������к����棡");
				return 1;
			}
	}
	if (!who->query("fei/gift"))
	{
		who->set("combat_exp",50000);
		who->set("daoxing",50000);
		who->set("maximum_force",500);
		who->set("max_force",500);
		who->set("force",500);
		who->add("potential",10000);
	}
	who->set("maximum_mana",500);
	who->set("max_mana",500);
	who->set("mana",500);
	if (mapp(skills)) {
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			skills[sk[i]]=lvl;
	}
	message_vision("$N����"HIR"������������!"NOR"\n$N��һָ��$nֻ����������Ѫ���ڣ��ƺ���ѧ�����ж�����������\n",this_object(),this_player());
	who->add("fei/gift",1);
	return 1;
}
int give_bonnet()
{
	object bonnet;
	object who=this_player();
	if (!userp(who))
	{ 
		command("heng");
		command("say ʲôСèС��Ҳ��Ҫ��������");
		command("qi");
		return 1;
	}
	if (this_player()->query("fei/bonnet")=="got")
	{
		message_vision("$N����$n����һ����\n",this_object(),this_player());
		command("say �ϴθ���Ļ�û���أ������ˣ�");
		return 1;
	}
	bonnet=new("/d/lingtai/obj/faguan");
	bonnet->move(who);
	message_vision("$N����������������!ֻ������ѩ�ɣ�$N���һ����ʦ���ڡ�\n$N��$nһ����ʦ���ڡ�\n",this_object(),this_player());
	who->set("fei/bonnet","got");
	command("say �����˼ǵû���Ŷ�������´β����ˣ�");
	return 1;
}
void greeting(object ob)
{
	int i;
	mapping skills;
	string *sk;

	if( !ob || !visible(ob) || environment(ob) != environment() )
		return;
	if( ob->query("fei/gift")==2 || ob->query("age")>16 || ob->query_temp("ask_feigift"))
		return;
	skills = ob->query_skills();
	if (mapp(skills)) {
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			if (skills[sk[i]]>=55
			|| ob->query("daoxing")>51000
			|| ob->query("combat_exp")>51000
			|| ob->query("max_force")>510
			|| ob->query("max_mana")>510)
				return;
	}
	tell_object(ob,name()+"���ص�˵������Ҫ���������Ұ�����������ֻ�����λ���Ŷ����������\n"NOR);
	tell_object(ob,name()+"���ص�˵�����������ֿ�ǧ��Ҫ���ԣ����Ǹ��Ʒ�˵����ʲô��ʧ�����ɲ��ܣ���\n"NOR);
	tell_object(ob,name()+"���ص�˵��"HIR"��������Ҫ�Ȱ�ʦ��ѧ�ù������������һ�������\n"NOR);
	tell_object(ob,name()+"���ص�˵��"HIR"��Ȼ����ȥ����ǰ����ѧ�Ĺ�����ѧ������������һ�������\n"NOR);
	tell_object(ob,name()+"���ص�˵��"HIR"����Ū���ޣ����Լ�Ū���ˣ��ҿɲ����⳥��ġ���\n"NOR);
	ob->set_temp("ask_feigift",1);
/*
if (random(10))
{
  switch(random(19))
  {
   case 0:
	message("system", HIM"������������ŨŨ�Ľ�������,���ھ�Ҫ����!\n"NOR,users());
	break;
   case 1:
	message("system", HIR"���һ����غ��ڿ���Ѥ�õ�����...\n"NOR,users());
	break;
   case 2:
	message("system", HIG"��Ӱ��Եȫ����ʦף���´����!\n"NOR,users());
	break;
   case 3:
	message("system", HIM"��Ӱ��Եȫ����ʦף���µ�һ����������!!\n"NOR,users());
	break;
   case 4:
	message("system", HIY"��Ӱ��Եȫ����ʦף���µ�һ�깤��˳��!\n"NOR,users());
	break;
   case 5:
	message("system", HIY"��Ӱ��Եȫ����ʦף�������һ��ѧϰ����!\n"NOR,users());
	break;
   case 6:
	message("system", HIG"��Ӱ��Եȫ����ʦף�������һ�����彡��!\n"NOR,users());
	break;
   default:
	break;
  }
}
*/
}
