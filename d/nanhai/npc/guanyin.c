// guanyin.c ��������
// By Dream Dec. 19, 1996

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int rank_me();
int do_drop(object, object);
string ask_me();
int ask_tree();
string avenge();

void create()
{
	set_name("��������", ({ "guanyin pusa", "guanyin", "pusa" }));
	set("title", "�ȿ���Ѵ�ȴ�");
	set("long", @LONG
��Բ�ĵ£���������ü��С�£�����˫�ǡ�����������
ޥ�԰����١���������٤ɽ�ϴȱ�������������������
LONG);
	set("gender", "Ů��");
	set("age", 35);
	set("attitude", "peaceful");
	set("rank_info/self", "ƶɮ");
	set("rank_info/respect", "��������");
	set("class", "bonze");
        	set("str",24);
	set("per",100);//means no rong-mao description.
	set("max_kee", 5000);
	set("max_gin", 5000);
	set("max_sen", 5000);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 145);
	set("max_mana", 3000);
	set("mana", 6000);
	set("mana_factor", 150);
	set("combat_exp", 2000000);
	set("daoxing", 10000000);

	set_skill("literate", 280);
	set_skill("spells", 300);
	set_skill("buddhism", 300);
	set_skill("unarmed", 250);
	set_skill("jienan-zhi", 250);
	set_skill("dodge", 280);
	set_skill("lotusmove", 280);
	set_skill("parry", 280);
	set_skill("force", 280);
	set_skill("lotusforce", 280);
	set_skill("staff", 280);
	set_skill("lunhui-zhang", 280);
	set_skill("hammer",290);
	set_skill("bighammer",290);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
	map_skill("hammer", "bighammer");
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
		(: perform_action, "staff", "fuhu" :),
	}) );
	set("inquiry", ([
		"����" : (: avenge :),
		"��ħ" : (: ask_me :),
		"ҽ��" : (: ask_tree :),
		"��ƿ" : (: ask_tree :),
		"ְλ": (: rank_me :),
	]));

	create_family("�Ϻ�����ɽ", 1, "����");

	setup();
	carry_object("/d/nanhai/obj/jiasha")->wear();
	carry_object("/d/nanhai/obj/nine-ring")->wield();
}

string ask_me()
{
	object obj;
	if((int)this_player()->query("combat_exp") < 280000 )
		return "���ǵ���л����ħ��\n";
	message_vision("������$NЦ��������howdo����Ե��\n", this_player());
	return "����...";
}

void init()
{
	add_action("do_how", "howdo");

	if( query("started") != 1 )
	{
		set("started", 1);
		call_out("generate_book", 36000);//10 hours
	}
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "����ɽ�뷨��ʦ")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
	if( (string)me->query("family/family_name") == "�Ϻ�����ɽ"){
		if( exp <= 500000 ) {
			return notify_fail("��������ѧ̫�ͣ���������Ҫʲôְλ��\n");
		} else if(exp <= 1000000 ){
			me->set("nick", HIY"�Ϻ�����"NOR+RED"��"BLU"֪��Сɮ"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", HIY"�Ϻ�����"NOR+RED"��"YEL"��������"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", HIY"�Ϻ�����"NOR+RED"��"RED"�޺�����"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", HIY"�Ϻ�����"NOR+RED"��"MAG"��������"NOR);
		} else {
			me->set("nick", HIY"�Ϻ�����"NOR+RED"��"CYN"��ң����"NOR);
		}
		tell_object(me, "������������˵���������"+me->query("nick")+"��\n");
		tell_room(environment(me),
"����������"+me->query("name")+"˵���������"+me->query("nick")+"��\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","�����豾�ŵ���"+me->query("name")+""+me->query("nick")+HIC"һְ�������λ�ɳ����������");
		me->save();  
	}
	return 1;
}

void generate_book()
{
	remove_call_out("generate_book");
	set("available", 1);
}

int do_how(string arg)
{
	object me, book;

	me = this_player();
	if( query("available") == 1 )
	{
		set("available", 0);
		book = new("/d/obj/book/forcebook2");
		book -> move(this_player());
		message_vision("����Ե�����㡣\n", me);
		command("chat "+this_player()->query("name")+"��Ե���õ�����ħɽ�ľ��¾���");
		remove_call_out("generate_book");
		call_out("generate_book", 36000);//10 hours
		return 1;
	}
	else return notify_fail("�����Ĳ���ʱ��\n");
}

int clean_up()
{
	return 0;
}

void attempt_apprentice(object ob)
{
	if (!((string)ob->query("bonze/class") =="bonze" )) {
		command("say �ҷ�����ͨ���" + RANK_D->query_respect(ob) + "�����������������š�\n");
		write("�����ӹ�����������δ��ȳ�����Ϊ���졣\n");
		return;
	}	
	if (((int)ob->query_skill("buddhism", 1) < 100 )) {
		command("say " + RANK_D->query_respect(ob) + "���ڷ��Ͽ��ޣ������ѳ�������\n");
		return;
	}
	command("pat " + ob->query("id") );
	command("say �ã�������ҷ��ŵĺõ��ӡ�ֻҪ���Ŭ�����������������\n");

	command("recruit " + ob->query("id") );
	return;	
}
void die()
{
	int i;
	string file;
	object *inv;

        if( environment() ) {
        message("sound", "\n\n��������ҡͷ̾�����������ϣ�����ħ�ϣ����伲�࣬���˶�֮��\n\n", environment());
        command("sigh");
        message("sound", "\n�������������ƣ��ǲ�����������ȥ�ˡ�����\n\n", environment());
        inv = all_inventory(this_object());
	for(i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("no_drop")) continue;
		do_drop(this_object(), inv[i]);
//		if (stringp(file = find_command("drop")) && 
//			call_other(file, "do_drop", this_object(), inv[i])) ;
	}
	}

	destruct(this_object());
}

int do_drop(object me, object obj) {
  if (obj->move(environment(me))) {
      //d_mana>0 is for "bian". mon 11/05/97
      if((obj->query_temp("d_mana"))>0) {
            if( obj->query_temp("is_living")==1 )
                 message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
            else {
                 message_vision( sprintf("$N����һ%s$n��\n",
                 undefinedp(obj->query_temp("unit"))?
	                 "��":obj->query_temp("unit")
                         ), me, obj );
           }
      } else {
           if( obj->is_character() )
                  message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
           else {
             message_vision( sprintf("$N����һ%s$n��\n", obj->query("unit")),
                     me, obj );
             if( !obj->query("value") && !obj->value() ) {
                tell_object(me,"��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ���
		   ��\n");
                destruct(obj);
             }
           }
      }
      return 1;
  }
  return 0;
}


void unconcious()
{
	die();
}
void announce_success (object who)
{
	int i;

	if (who->query("obstacle/meihouwang") == "done" ||
	! who->query_temp("liuer-mihou_killed") )
	{
		destruct(this_object());
		return;
	}
	i = random(600);
	who->add("obstacle/number",1);
	who->set("obstacle/meihouwang","done");
	who->add("daoxing",i+4000);
	who->add("score", 10);
	command("chat "+who->query("name")+"ʶ�Ƽٺ�����ȡ�ذ�����");
	message("channel:chat",HIW"������ն������������(Guanyin pusa)��"+who->query("name")+"��������ȡ������ʮ���أ�\n"NOR,users());
	tell_object (who,"��Ӯ����"+COMBAT_D->chinese_daoxing(i+4000)+"�ĵ��У�\n");
	destruct (this_object());
	who->save();
	return;
}
int ask_tree()
{
	object who=this_player();

	if ( !who->query_temp("kill_tree")||who->query("ask_jingping"))
		return notify_fail("�ú����£�����ɧ��ƶ�᣿");
	switch(who->query_temp("guanyin_ask_tree")) {
		case 0:
			tell_object(who,"��������˵�����������ú��֪�ô��������˲ι��������쿪�رٵ��������Ԫ���˵���֮\n�棬��Ҳ�������֣�����ô�ʹ�����������\n");
			who->set_temp("guanyin_ask_tree",1);
			break;
		case 1:
			tell_object(who,"��������˵���������⾻ƿ�׵ĸ�¶ˮ�����ε��������硣��\n");
			who->set_temp("guanyin_ask_tree",2);
			break;
		case 2:
			command("sigh");
			command("say �����ǻ��ĺ�ͷ�����ǣ��ҵľ�ƿ�����ǽ�ȥ�ˣ���ȥ�������ɡ�");
			who->set_temp("guanyin_ask_tree",3);
			who->set_temp("ask_jingping",1);
			break;
		default:
			command("say �����ǻ��ĺ�ͷ����������û��û�ˣ���ʱ��ȥ������ʱ��");
			break;
	}
	return 1;
}
string avenge()
{
	object who=this_player(),killer,where;
	string killid;
	if((string)who->query("family/family_name")!="�Ϻ�����ɽ")
		return ("�㲻�Ǳ��ŵ��ӣ��������Һθɣ�");
	if(who->query("faith")<1000)
		return ("���ڱ���������������������Ŭ�����С�");
	if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
		return ("ƶ��δ����Ѷ");
	killid=who->query("kill/last_killer");
	killer=find_living(killid);
	if(!killer||!userp(killer))
		return ("����ƶ�ỹ����һ��");
	command("say ƶ�����ȥΪ�㱧��");
	who->set("avenge/mud_age",who->query("mud_age"));
	where=environment(who);
	tell_room(where,"ֻ���������������һָ��\n");
	tell_room(where,"������պ��ڣ���ȥ��"+killer->query("name")+"ץ����\n");
	tell_room(environment(killer),"�������һֻ���ֽ�"+killer->query("name")+"ץ���ˡ�\n");
	killer->move(where);
	tell_room(where,killer->query("name")+"���ӿ�������������\n");
	command("say ������������ɱ�����Ϻ�����ɽ����");
	this_object()->kill_ob(killer);
	return("��������");
}
int accept_object(object who, object ob)
{
	if ( ob->query("id") == "sheng lingzhu" )
	{
		if( who->query("obstacle/zhu") )
		{
			command("say "+who->query("name")+"�����Ѿ��һ�ʥ������ѽ��\n");
			return 1;
		}
		command("wa");
		remove_call_out("check");
		call_out("check",2,who);
		return 1;
	}
	return 1;
}
void check(object who)
{
	int i;
	if (who->query("combat_exp") < 10000)
		return;
	if ( who->query("obstacle/zhu") == "done" )
		return ;
	i = random(600);
	who->add("obstacle/number",1);
	who->set("obstacle/zhu","done");
	who->add("daoxing",i+10000);
	who->add("score", 10);
	command("chat "+who->query("name")+"���ҷ������һ�ʥ���飡");
	message("channel:chat",HIW"������ն������������(Guanyin pusa)��"+who->query("name")+"��������ȡ������ʮ�أ�\n"NOR,users());
	tell_object (who,"��Ӯ����"+COMBAT_D->chinese_daoxing(i+10000)+"�ĵ��У�\n");
	who->save();
	who->start_busy(2);
}
        
