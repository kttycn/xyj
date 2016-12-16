

#include <ansi.h>

inherit NPC;

string ask_for_present();

void create()
{
    set_name("��������", ({ "liwu man", "man" }) );
	set("title", HIY"����"+HIW" ʹ��"NOR);
	set("gender", "����" );

	set("age", 400);
	set("str", 100);
	set("con", 100);
	set("dex", 100);
	set("int", 100);
         
	set("long",
		"�ף��������������ô��ʥ�������ŵ�һģһ�����Ǻ�...\n"
		"���������﷢������������������Ҫ��(ask men about ���)\n" );

	set("combat_exp", 8000000);
	set("attitude", "friendly");
	
	set("inquiry", ([
		"���"   : (: ask_for_present :),
	]) );

	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 5000);
	set("max_jing", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali",300);

	set_skill("dodge", 500);
	set_skill("unarmed", 500);
	set_skill("parry", 500);
	set_skill("force",500);
	set_skill("sword",500);
	set_skill("literate",500);

	set_skill("seven-steps",500);
	set_skill("yujianshu",500);
	set_skill("hunyuan-zhang",500);
	set_skill("zixia-shengong",500);
     
	map_skill("force", "zixia-shengong");
	map_skill("parry", "yujianshu");
	map_skill("sword", "yujianshu");
	map_skill("unarmed", "hunyuan-zhang");
	map_skill("dodge", "seven-steps");
        
	set_temp("apply/attack", 500);
	set_temp("apply/defense", 200);


	set("chat_msg_combat", ({
//		(: perform_action, "cuff.jingang" :),
		(: exert_function, "recover" :),
		(: exert_function, "huti" :),
	}) );


	setup();
	carry_object("/d/city/liwu/obj/yuyi")->wear();
	carry_object("/d/obj/weapon/sword/bijian")->wield();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}


void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;

      command("say ������������İɣ�\n");
}

string ask_for_present()
{ 
	mapping *holiday= ({
		([
			"name":             HIR"Ԫ��"NOR,
			"year":             "either",
			"month":            "Jan",
			"day":              "01",
		]),
		([
			"name":             HIC"��Ϧ"HIB"ҹ"NOR,
			"year":             "2001",
			"month":            "Jan",
			"day":              "23",
		]),
		([
			"name":             HIR"��"+HIC"��"NOR,
			"year":             "2001",
			"month":            "Jan",
			"day":              "24",
		]),
		([
			"name":             HIR"Ԫ����"NOR,
			"year":             "2001",
			"month":            "Feb",
			"day":              "07",
		]),
		([
			"name":             HIR"���˽�"NOR,
			"year":             "either",
			"month":            "Feb",
			"day":              "14",                    
		]),
		([
			"name":             HIG"���ʸ�Ů��"NOR,
			"year":             "either",
			"month":            "Mar",
			"day":              "08",
		]),
		([
			"name":             MAG"���˽�"NOR,
			"year":             "either",
			"month":            "Apr",
			"day":              "01",
		]),
		([
			"name":             HIW"������"NOR,
			"year":             "either",
			"month":            "Apr",
			"day":              "05",
		]),
		([
			"name":             HIR"�����Ͷ���"NOR,
			"year":             "either",
			"month":            "May",
			"day":              "01",
		]),
		([
			"name":             HIW"�����"NOR,
			"year":             "either",
			"month":            "May",
			"day":              "04",
		]),
		([
			"name":             HIW"ĸ�׽�"NOR,
			"year":             "2001",
			"month":            "May",
			"day":              "13",
		]),
		([
			"name":             HIG"��һ��ͯ"NOR+"��",
			"year":             "either",
			"month":            "Jun",
			"day":              "01",                    
		]),
		([
			"name":             HIW"���׽�"NOR,
			"year":             "2001",
			"month":            "Jun",
			"day":              "17",
		]),
		([
			"name":             HIW"������"NOR,
			"year":             "2001",
			"month":            "Jun",
			"day":              "25",
		]),
		([
			"name":             HIY"��Ϧ"HIB"ҹ"NOR,
			"year":             "2001",
			"month":            "Aug",
			"day":              "25",                    
		]),
		([
			"name":             HIB"��ʥ"NOR+"��",
			"year":             "2001",
			"month":            "Sep",
			"day":              "02",                    
		]),
		([
			"name":             HIY"����"NOR+"�� OR "HIR"�����"NOR,
			"year":             "2001",
			"month":            "Oct",
			"day":              "01",                    
		]),
		([
			"name":             HIY"����"NOR+"��",
			"year":             "2001",
			"month":            "Oct",
			"day":              "25",                    
		]),
		([
			"name":             HIW"ʥ����"NOR,
			"year":             "either",
			"month":            "Dec",
			"day":              "25",
		]),
	});
    object me,ob;
    mapping skl, today;
    string *sname;
    int i,how=0,what_day=100;
    string week, month, year, day, time;
    string check;
    
    sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);
   if(day=="")
    sscanf(ctime(time()), "%s %s  %s %s %s", week, month, day, time,year);

    me = this_player();

    for(i=0;i<sizeof(holiday);i++)
	{
		today = holiday[i];
		if(today["year"]!="either") {
			if(year==today["year"]&&month==today["month"]&&day==today["day"])
				what_day=i;
		} else if(month==today["month"]&&day==today["day"])
			what_day=i;
	}
    if(what_day==100)
		return "���������ʲô����Ү��\n";
    
    if ((int)me->query("combat_exp") <30000 || (int)me->query("mud_age")<18000)
        return "�ٺ٣������������ƭ�ң�û�ţ���\n";
      
    if ((int)me->query("combat_exp") >=300 ) 
         {
		
	    skl = me->query_skills();
	if(skl) sname  = keys(skl);
            for(i=0; i<sizeof(skl); i++)
                   if (skl[sname[i]] >= 10)how=how+1; 
                          if(how<3)
                            return "�����ˮƽ����ȥ��һ�������\n";
	
          } 
     today = holiday[what_day];   

     check=year+today["name"];
     
     if( today["name"]==HIG"���ʸ�Ů��"NOR && me->query("gender")!="Ů��")
     {
     	command("xixi");
     	return me->query("name")+"����һ��������Ҳ���"+today["name"]+CYN"��\n"NOR;
     }
     if( today["name"]==HIG"��һ��ͯ"NOR+"��" && me->query("age")>16)
     {
     	command("xixi");
     	return me->query("name")+"���������Ѿ������ˣ���"+today["name"]+CYN"������С���ӵ����ˣ�\n"NOR;
     }
     if(me->query("goodday_gift")==check)
       return "ÿ����һ�ݣ���Ҫ��ô̰�ĺò��ã�\n";

     ob = new("/d/city/liwu/obj/red");
     ob->move(me);
     me->set("goodday_gift",check);
     return today["name"]+"���֣�\n"+"�������˸�"+me->query("name")+"һ��"+HIR"���"NOR+"��\n";
}
