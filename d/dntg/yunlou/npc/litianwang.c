inherit NPC;

string *list=({
	"yg-putuo",
	"yg-moon",
	"yg-wzg",
	"yg-fangcun",
	"yg-hell",
	"yg-jjf",
	"yg-dragon",
	"yg-xueshan",
	"yg-wudidong",
	"yg-shushan",
	"yg-hyd",
	"yg-pansi",
	"yg-xuyi",
	"yg-wusheng",
	"yg-phoenix",
	"yg-xy",
});

int work_me();
int delete_ask(object me);
 
void create()
{
	set_name("�", ({ "li jing", "jing", "li" }) );
	set("gender", "����" );
	set("long", "�����������������Ԫ˧������ʮ������콫�������ޱߡ�\n");
	set("age",40);
	set("title", "��������");
	set("str", 40);
	set("int", 30);
	set("con", 30);
	set("spi", 30);
	set("per", 30);
	set("class", "xian");
	set("attitude", "heroism");
	set("combat_exp", 1500000);
	set("daoxing", 2000000);
	set("max_kee", 2000);
	set("max_sen", 2000);
	set("force",5000);
	set("max_force",3000);
	set("force_factor", 150);
	set("mana", 5000);
	set("max_mana", 3000);
	set("mana_factor", 150);

	set("eff_dx", 600000);
	set("nkgain", 600);

	set_skill("unarmed",170);
	set_skill("dodge",170);
	set_skill("parry",170);
	set_skill("sword", 180);
	set_skill("force", 170);
	set_skill("spells", 170);
 	set_skill("changquan", 170);
	set_skill("liangyi-sword", 180);
	set_skill("baguazhou", 170);
	set_skill("moshenbu", 170);
	set_skill("lengquan-force", 170);
	map_skill("unarmed", "changquan");
	map_skill("force", "lengquan-force");
	map_skill("spells", "baguazhou");
	map_skill("sword", "liangyi-sword");
	map_skill("parry", "liangyi-sword");
	map_skill("dodge", "moshenbu");
	
	set("chat_chance",1);
	set("chat_msg", ({
		name()+"˵������λ���ɿ�Ըȥ�½�������\n",
	}));

	seteuid(getuid());

	set("inquiry", ([
		"mieyao": (: work_me :),
		"kill": (: work_me :),
		"����": (: work_me :),
	]));

	setup();
	carry_object("/d/obj/fabao/huangjin-baota");
	carry_object("/d/obj/armor/jinjia")->wear();
	carry_object("/d/sky/obj/zhanyaojian")->wield();
}
 
int work_me()
{
	object ghost, me;
	int t, lvl;
	me=this_player();
       
	if (me->query_temp("asked/lijing")) return 1;
	me->set_temp("asked/lijing",1);
	call_out("delete_ask",1,me);
	//for first time.
	if(!me->query("mieyao")) {
	    me->set_temp("mieyao/level",1);
		lvl = me->query_temp("mieyao/level");
		call_out("start_job", 1, me);
		return 1;
	}
	lvl = me->query_temp("mieyao/level");
	if( (t=(int)me->query("mieyao/time_start")) &&
		!me->query("mieyao/done")) {

	    if(t<=time() &&
		time()<t+1800) {
			command("heng");
			command("say �Ϸ�������ȥ����"+me->query("mieyao/name")+"��\n");
			return 1;
	    }
	    // failed, decrease lvl.
	    if(lvl>0) lvl--;
	    me->set_temp("mieyao/level",lvl);

	    // allow ask again.
	} else { // job done
//	    if(t<=time() && time()<t+360) {
//			message_vision("$N������������һ����˵"+"����λ"+RANK_D->query_respect(me)
//				+",��ħ�ѳ���,������ȥЪϢ��\n",this_object(), me);
//			return 1;
//	    }
	    // succeed, increase lvl.
	    if(lvl<9) lvl++; // total 10 levels: 0, ..., 9
	    else lvl=1; // reach the top level, reduce difficulty.
	    me->set_temp("mieyao/level",lvl);
	}
	me->delete("mieyao/time_start");
	call_out("start_job", 1, me);
	return 1;
}
int start_job(object me)
{
	string where;
	object ghost;
	int lvl;

	if(environment(me)!=environment()) return 1;
	if(me->query("mieyao/time_start")) return 1;
	me->delete("mieyao/done");

	// determine levels.
	// use temp mark, if quit, then start over.
	lvl=me->query_temp("mieyao/level");

	ghost = new(__DIR__+list[random(sizeof(list))]);
	where=ghost->invocation(me, lvl);

//	message_vision("���ֵȼ���"+lvl+"\n",this_object());
	message_vision("$N���������������½�һ�Σ�\n",this_object());
	message_vision("$N��$n˵��������"+where+"Ϊ��������"
		+"����ȥ������\n"
		,this_object(),me);
	me->set("mieyao/time_start", time());
	me->set("mieyao/id",ghost->query("id"));
	me->set("mieyao/name",ghost->query("name"));
	return 1;
}
int delete_ask(object me)
{
	me->delete_temp("asked/lijing");
	return 1;
}
