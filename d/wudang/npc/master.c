// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
//wudang master
//lpg 19991005
// xuer modify jiangli 2001/02/11

#include <ansi.h>
inherit NPC;

void create()
{
   set_name("荡魔天尊", ({"master dangmo", "master", "dangmo", "tianzun"}));
   set("title", "五当「"HIY"统摄真武，剪伐天下"NOR"」");
   set("gender", "男性" );
   set("age", 65);
   set("per", 24);
   set("str", 30);
   set("long", "
   这就是威镇八方的荡魔天尊。
统摄真武之位，剪伐天下妖邪，乃奉玉帝旨意；后又披发跣足，
踏腾蛇神龟，领五雷神将，巨虬狮子，猛兽毒龙，收降东北方
黑气妖氛，乃奉元始天尊符召。今日静享武当山，安逸太和殿。\n\n");
   set("class", "dao");
   set("combat_exp", 2800000);
   set("attitude", "peaceful");
   create_family("五当山", 1, "祖师");
   set("rank_info/respect", "天尊");
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
     "name": "贫道荡魔。\n",
     "here": "这里是五当山，住的都是除魔的道士。\n",
   ]) );

   setup();
   carry_object("/d/obj/cloth/xianpao")->wear();
   carry_object("/d/obj/weapon/sword/changjian")->wield();
}
//LPG 19991016 除魔任务奖励
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
		command("chat "+"闻龟蛇五雷传报，" +ob->query("name")+"("+ob->query("id")+")"+"效法真武，剪伐天下，降妖除魔，功德无量！");
        switch( random(7) )
        {
			case 0:
				i = random(180);
				ob->add("potential",i+60);
				str = sprintf("%s(%s)灭妖得到%d点潜能，",ob->name(1),geteuid(ob),i+60);
				tell_object (ob,"\n除了战斗所得，你还赢得了"+chinese_number(i+60)+"点潜能的奖励！\n");
				break;
        	case 1:
				i = random(120);
				ob->add("potential",i+60);
				str = sprintf("%s(%s)灭妖得到%d点潜能，",ob->name(1),geteuid(ob),i+60);
				tell_object (ob,"\n除了战斗所得，你还赢得了"+chinese_number(i+60)+"点潜能的奖励！\n");
				break;
        	case 2:
				i = random(60);
				ob->add("potential",i+60);
				str = sprintf("%s(%s)灭妖得到%d点潜能，",ob->name(1),geteuid(ob),i+60);
				tell_object (ob,"\n除了战斗所得，你还赢得了"+chinese_number(i+60)+"点潜能的奖励！\n");
				break;
			case 3:
				i = random(180);
				ob->add("combat_exp",i+600);
				str = sprintf("%s(%s)灭妖得到%d点武学经验，",ob->name(1),geteuid(ob),i+600);
				tell_object (ob,"\n除了战斗所得，你还赢得了"+chinese_number(i+600)+"点武学经验！\n");
				break;
			case 4:
				i = random(200);
				ob->add("daoxing",i+600);
				str = sprintf("%s(%s)灭妖得到%d点道行，",ob->name(1),geteuid(ob),i+600);
				tell_object (ob,"\n除了战斗所得，你还赢得了"+COMBAT_D->chinese_daoxing(i+600)+"的道行！\n");
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
				str = sprintf("%s(%s)灭妖得到%d点%s技能，",
					ob->name(1),geteuid(ob), i+ob->query("combat_exp")/800, to_chinese(name));
				tell_object (ob,"\n除了战斗所得，你还赢得了"+chinese_number(i+ob->query("combat_exp")/800)+
					"点"+to_chinese(name)+"技能的奖励！\n");
				break;
			case 6:
				i = random(ob->query("combat_exp")/50000);
				silver->set_amount(i+10);
				tell_object (ob,"\n除了战斗所得，你还赢得了"+chinese_number(i+10)+
					"两金子的奖励！\n");
				if(!(silver->move(ob)))
					silver->move(environment(ob));
				str = sprintf("%s(%s)灭妖得到%d两金子，",ob->name(1),geteuid(ob),i+10);
				message_vision ("$N递给$n一包金子。\n",this_object(),ob);
				break;
		}
		ob->add("score", 2);
		ob->save();
	}
//lpg 19991129 增加连续杀妖次数奖励
	j=((ob->query("max_mana")+ob->query("max_force"))/200+1);
	if ((ob->query_temp("killme_number")>1) && (ob->query_temp("killme_number") > j))
	{
		ob->delete_temp("killme_number");
//		j=random(j)+1;
		command("chat "+"又闻龟蛇五雷传报，" +ob->query("name")+"("+ob->query("id")+")"+
			"不辞劳苦，接连除魔超过"+chinese_number((ob->query("max_mana")+
			ob->query("max_force"))/200+1)+"次，望再接再励！");
		switch( random(6) )
		{
			case 0:
				i = random(180);
				ob->add("potential",(i+60)*j);
				str +=  sprintf("连续灭妖超过%d次，得到%d点潜能，",
					(ob->query("max_mana")+ob->query("max_force"))/200+1, (i+60)*j);
				tell_object (ob,"\n你又赢得了"+chinese_number((i+60)*j)+"点潜能的奖励！\n");
				break;
			case 1:
				i = random(120);
				ob->add("potential",(i+60)*j);
				str += sprintf("连续灭妖超过%d次，得到%d点潜能，",
					(ob->query("max_mana")+ob->query("max_force"))/200+1, (i+60)*j);
				tell_object (ob,"\n你又赢得了"+chinese_number((i+60)*j)+"点潜能的奖励！\n");
				break;
			case 2:
				i = random(60);
				ob->add("potential",(i+60)*j);
				str += sprintf("连续灭妖超过%d次，得到%d点潜能，",
					(ob->query("max_mana")+ob->query("max_force"))/200+1, (i+60)*j);
				tell_object (ob,"\n你又赢得了"+chinese_number((i+60)*j)+"点潜能的奖励！\n");
				break;
			case 3:
				i = random(100);
				ob->add("potential",(i+60)*j);
				str += sprintf("连续灭妖超过%d次，得到%d点潜能，",(ob->query("max_mana")+
					ob->query("max_force"))/200+1, (i+60)*j);
				tell_object (ob,"\n你又赢得了"+chinese_number((i+60)*j)+"点潜能的奖励！\n");
				break;
			case 4:
				i = random(160);
				ob->add("potential",(i+60)*j);
				str += sprintf("连续灭妖超过%d次，得到%d点潜能，",(ob->query("max_mana")+
					ob->query("max_force"))/200+1, (i+60)*j,);
				tell_object (ob,"\n你又赢得了"+chinese_number((i+60)*j)+"点潜能的奖励！\n");
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
				str += sprintf("连续灭妖超过%d次，得到%d点%s技能，",(ob->query("max_mana")+
					ob->query("max_force"))/200+1, (i+ob->query("combat_exp")/10000)*j,
					to_chinese(name), );
				tell_object (ob,"\n你又赢得了"+chinese_number((i+ob->query("combat_exp")/10000)*j)+"点"+
				to_chinese(name)+"技能的奖励！\n");
				break;
		}
		ob->add("score", 5);
		ob->save();
	}
	CHANNEL_D->do_channel( this_object(), "sys",str);
	str += sprintf("时间：%s\n", ctime(time()));
	log_file("wudang", str);
}
