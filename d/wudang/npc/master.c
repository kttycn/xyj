// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
//wudang master
//lpg 19991005
// xuer modify jiangli 2001/02/11

#include <ansi.h>
inherit NPC;

void create()
{
   set_name("��ħ����", ({"master dangmo", "master", "dangmo", "tianzun"}));
   set("title", "�嵱��"HIY"ͳ�����䣬��������"NOR"��");
   set("gender", "����" );
   set("age", 65);
   set("per", 24);
   set("str", 30);
   set("long", "
   ���������˷��ĵ�ħ����
ͳ������֮λ������������а���˷����ּ�⣻�����������㣬
̤������꣬�������񽫣����ʨ�ӣ����޶������ս�������
�������գ��˷�Ԫʼ������١����վ����䵱ɽ������̫�͵\n\n");
   set("class", "dao");
   set("combat_exp", 2800000);
   set("attitude", "peaceful");
   create_family("�嵱ɽ", 1, "��ʦ");
   set("rank_info/respect", "����");
   set_skill("unarmed", 350);
   set_skill("wuxing-quan", 300);
   set_skill("dodge", 350);
   set_skill("baguazhen", 360);
   set_skill("parry", 380);
   set_skill("sword", 360);
   set_skill("sanqing-jian", 350);
   set_skill("staff", 360);
   set_skill("fumo-zhang", 360);
   set_skill("force", 380);   
   set_skill("wuxiangforce", 380);
   set_skill("spells", 380);
   set_skill("dao", 380);
   map_skill("spells", "dao");
   map_skill("force", "wuxiangforce");
   map_skill("unarmed", "wuxing-quan");
   map_skill("sword", "sanqing-jian");
   map_skill("dodge", "baguazhen");
   map_skill("staff", "fumo-zhang");

   set("max_kee", 4500);
   set("max_sen", 4500);
   set("force", 5000);
   set("max_force", 2500);
   set("mana", 7000);
   set("max_mana", 3500);   
   set("force_factor", 100);
   set("mana_factor", 150);

   set("spell_qiankun_on", 1); //to use cast qiankun, must set this.
   set("chat_chance_combat", 60);
   set("chat_msg_combat", 
   ({
     (: cast_spell, "qiankun" :),
   }) );

   set("inquiry", ([
     "name": "ƶ����ħ��\n",
     "here": "�������嵱ɽ��ס�Ķ��ǳ�ħ�ĵ�ʿ��\n",
   ]) );

   setup();
   carry_object("/d/obj/cloth/xianpao")->wear();
   carry_object("/d/obj/weapon/sword/changjian")->wield();
}
//LPG 19991016 ��ħ������
void announce_success (object ob)
{
	mapping skills = ob->query_skills();
	string name, str;
	string *names;
	object silver = new ("/obj/money/gold");
	int i,j;
	if (ob->query_temp("killme_applied") == "done")
	{
		ob->delete_temp("killme_applied");
		ob->delete_temp("ask_jiang");
		command("chat "+"�Ź������״�����" +ob->query("name")+"("+ob->query("id")+")"+"Ч�����䣬�������£�������ħ������������");
        switch( random(7) )
        {
			case 0:
				i = random(180);
				ob->add("potential",i+60);
				str = sprintf("%s(%s)�����õ�%d��Ǳ�ܣ�",ob->name(1),geteuid(ob),i+60);
				tell_object (ob,"\n����ս�����ã��㻹Ӯ����"+chinese_number(i+60)+"��Ǳ�ܵĽ�����\n");
				break;
        	case 1:
				i = random(120);
				ob->add("potential",i+60);
				str = sprintf("%s(%s)�����õ�%d��Ǳ�ܣ�",ob->name(1),geteuid(ob),i+60);
				tell_object (ob,"\n����ս�����ã��㻹Ӯ����"+chinese_number(i+60)+"��Ǳ�ܵĽ�����\n");
				break;
        	case 2:
				i = random(60);
				ob->add("potential",i+60);
				str = sprintf("%s(%s)�����õ�%d��Ǳ�ܣ�",ob->name(1),geteuid(ob),i+60);
				tell_object (ob,"\n����ս�����ã��㻹Ӯ����"+chinese_number(i+60)+"��Ǳ�ܵĽ�����\n");
				break;
			case 3:
				i = random(180);
				ob->add("combat_exp",i+600);
				str = sprintf("%s(%s)�����õ�%d����ѧ���飬",ob->name(1),geteuid(ob),i+600);
				tell_object (ob,"\n����ս�����ã��㻹Ӯ����"+chinese_number(i+600)+"����ѧ���飡\n");
				break;
			case 4:
				i = random(200);
				ob->add("daoxing",i+600);
				str = sprintf("%s(%s)�����õ�%d����У�",ob->name(1),geteuid(ob),i+600);
				tell_object (ob,"\n����ս�����ã��㻹Ӯ����"+COMBAT_D->chinese_daoxing(i+600)+"�ĵ��У�\n");
				break;
			case 5:
				if (sizeof(skills) == 0) {
					name = "force";
				} else {
					names = keys(skills);
					name = names[random(sizeof(names))];
				}
				i = random(1800);
				ob->improve_skill(name, i+ob->query("combat_exp")/800);
				str = sprintf("%s(%s)�����õ�%d��%s���ܣ�",
					ob->name(1),geteuid(ob), i+ob->query("combat_exp")/800, to_chinese(name));
				tell_object (ob,"\n����ս�����ã��㻹Ӯ����"+chinese_number(i+ob->query("combat_exp")/800)+
					"��"+to_chinese(name)+"���ܵĽ�����\n");
				break;
			case 6:
				i = random(ob->query("combat_exp")/50000);
				silver->set_amount(i+10);
				tell_object (ob,"\n����ս�����ã��㻹Ӯ����"+chinese_number(i+10)+
					"�����ӵĽ�����\n");
				if(!(silver->move(ob)))
					silver->move(environment(ob));
				str = sprintf("%s(%s)�����õ�%d�����ӣ�",ob->name(1),geteuid(ob),i+10);
				message_vision ("$N�ݸ�$nһ�����ӡ�\n",this_object(),ob);
				break;
		}
		ob->add("score", 2);
		ob->save();
	}
//lpg 19991129 ��������ɱ����������
	j=((ob->query("max_mana")+ob->query("max_force"))/200+1);
	if ((ob->query_temp("killme_number")>1) && (ob->query_temp("killme_number") > j))
	{
		ob->delete_temp("killme_number");
//		j=random(j)+1;
		command("chat "+"���Ź������״�����" +ob->query("name")+"("+ob->query("id")+")"+
			"�����Ϳ࣬������ħ����"+chinese_number((ob->query("max_mana")+
			ob->query("max_force"))/200+1)+"�Σ����ٽ�������");
		switch( random(6) )
		{
			case 0:
				i = random(180);
				ob->add("potential",(i+60)*j);
				str +=  sprintf("������������%d�Σ��õ�%d��Ǳ�ܣ�",
					(ob->query("max_mana")+ob->query("max_force"))/200+1, (i+60)*j);
				tell_object (ob,"\n����Ӯ����"+chinese_number((i+60)*j)+"��Ǳ�ܵĽ�����\n");
				break;
			case 1:
				i = random(120);
				ob->add("potential",(i+60)*j);
				str += sprintf("������������%d�Σ��õ�%d��Ǳ�ܣ�",
					(ob->query("max_mana")+ob->query("max_force"))/200+1, (i+60)*j);
				tell_object (ob,"\n����Ӯ����"+chinese_number((i+60)*j)+"��Ǳ�ܵĽ�����\n");
				break;
			case 2:
				i = random(60);
				ob->add("potential",(i+60)*j);
				str += sprintf("������������%d�Σ��õ�%d��Ǳ�ܣ�",
					(ob->query("max_mana")+ob->query("max_force"))/200+1, (i+60)*j);
				tell_object (ob,"\n����Ӯ����"+chinese_number((i+60)*j)+"��Ǳ�ܵĽ�����\n");
				break;
			case 3:
				i = random(100);
				ob->add("potential",(i+60)*j);
				str += sprintf("������������%d�Σ��õ�%d��Ǳ�ܣ�",(ob->query("max_mana")+
					ob->query("max_force"))/200+1, (i+60)*j);
				tell_object (ob,"\n����Ӯ����"+chinese_number((i+60)*j)+"��Ǳ�ܵĽ�����\n");
				break;
			case 4:
				i = random(160);
				ob->add("potential",(i+60)*j);
				str += sprintf("������������%d�Σ��õ�%d��Ǳ�ܣ�",(ob->query("max_mana")+
					ob->query("max_force"))/200+1, (i+60)*j,);
				tell_object (ob,"\n����Ӯ����"+chinese_number((i+60)*j)+"��Ǳ�ܵĽ�����\n");
				break;
        	case 5:

				if (sizeof(skills) == 0) {
					name = "force";
				} else {
					names = keys(skills);
					name = names[random(sizeof(names))];
				}
				i = random(1800);
				ob->improve_skill(name, (i+ob->query("combat_exp")/10000)*j);
				str += sprintf("������������%d�Σ��õ�%d��%s���ܣ�",(ob->query("max_mana")+
					ob->query("max_force"))/200+1, (i+ob->query("combat_exp")/10000)*j,
					to_chinese(name), );
				tell_object (ob,"\n����Ӯ����"+chinese_number((i+ob->query("combat_exp")/10000)*j)+"��"+
				to_chinese(name)+"���ܵĽ�����\n");
				break;
		}
		ob->add("score", 5);
		ob->save();
	}
	CHANNEL_D->do_channel( this_object(), "sys",str);
	str += sprintf("ʱ�䣺%s\n", ctime(time()));
	log_file("wudang", str);
}
