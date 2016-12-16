inherit NPC;

mapping *way;
object cart;
object protector;
string oldlong;

mapping *read_table(string);
void give_reward();
void to_rob();
void be_protect();
void go();

void create()
{
	object ob;
	set_name("��ҩ��ʿ", ({"drug daoshi"}) );
	set("gender", "����" );
	set("age", 25);
	set("combat_exp",1000000);
	set("attitude", "friendly");
	set("vendetta_mark", "authority");
	set("per",22);
	set("chat_chance", 15);
	set("chat_msg",({
		"��ʿ˵������ǰ;��֪�Ƿ�ȫ����\n",
		"��ʿ��������������ҩ�����ǳ��������衣\n",
	}) );
	set("force",4000);
	set("max_force",2000);
	set("force_factor",100);
	set("max_mana",2000);
	set("mana",40000);
	set("mana_factor",100);

	set_skill("stick",120);
	set_skill("parry",120);
	set_skill("qianjun-bang",150);
	set_skill("force",140);
	set_skill("wuxiangforce",150);
	set_skill("jindouyun",150);
	set_skill("dodge",150);
	set_skill("spells",140);
	set_skill("dao",150);

	map_skill("stick","qianjun-bang");
	map_skill("parry","qianjun-bang");
	map_skill("force","wuxiangforce");
	map_skill("dodge","jindouyun");
	map_skill("spells","dao");

	set("chat_chance_combat",90);
	set("chat_msg_combat", ({
		"��ʿ�󺰵��������Ĳ��ţ���ҩ��Ҳ����Ҫ�١���\n",
		(: perform_action, "stick.qiankun" :),
		(: cast_spell, "dingshen" :),
		(: cast_spell, "light" :),
		(: cast_spell, "thunder" :),
		(: be_protect :)
	}) );

	setup();
	add_money("silver", 50);
	carry_object("/d/lingtai/obj/cloth")->wear();
	carry_object("/d/lingtai/obj/bang")->wield();
}

void init()
{
	add_action("do_husong","husong");
}

int do_husong(string arg)
{
	object me=this_player();

	if((string)me->query("family/family_name")!="����ɽ���Ƕ�")
		return notify_fail("��������ҡ��ҡͷ�������Ǳ������ˡ�\n");
	if(environment(me)->query("short")!="������"||this_object()->query("be_husong"))
		return notify_fail("��������ҡ��ҡͷ����ε�ҩ���Ѿ����˻����ˣ��������Ĵ�ܡ�\n");
    if(me->query("faith")<800)
		return notify_fail("��������ҡ��ҡͷ���������ֵ�û��ɣ�\n");

	this_object()->set("be_husong",1);
	me->set_temp("protecting",cart);
	me->set_leader(this_object());
	protector=me;
	tell_object(me,"�������˶���Ц��Ц��������ô��������������һ���ˡ�\n");
	call_out("wait_go",5);    
	return 1;
}

void wait_go(object where)
{
	tell_room(where,"��������˵����������׼������װ��׼��������\n");
	command("nod");      
	command("say ��֪˭Ը������(husong)�ң�");   
//   oldlong=where->query("long");
  // where->set("long",oldlong+"\n����һ��ҩ��׼�����������ǣ��軤��(husong)һ����\n");
	call_out("begin_go",5,where);
}

void begin_go(object where)
{
	tell_room(where,"��������˵������ʱ�����Ǹó����ˡ�\n");
	command("say �Ǻã�������ͳ�����");
//   where->set("long",oldlong);
// go();
	call_out("go",5);
}

void go()
{
	int i,j;
	object robber;
	string *cmds;
	object me = this_player();

	remove_call_out("go");
	for(i=0;i<sizeof(way);i++)
	{
		if (base_name(environment()) != way[i]["room_file"]) continue;
		cmds=explode(way[i]["cmd_table"],";");
		break;
	}
	robber=present("mengmian dahan",environment());
	if (this_object()->is_fighting() || (robber && robber->name()=="�����"))
	{
		command("say ��������");
		call_out("go",5);
		return;
	}
	if (random(100)<15)
	{
		to_rob();
		call_out("go",10);
		return;
	}
	for(j=0;j<sizeof(cmds);j++)
		command(cmds[j]);
	cart=new("/d/obj/npc/jiefei");
	cart->move(environment());
	message_vision("ҩ�ĳ�¡¡ʻ�˹�����\n",this_object());
			
       /* if (way[i]["delay_time"] < 1 )
	{
		give_reward();
		return;
	}*/
 //       call_out("go",way[i]["delay_time"]);
	call_out("go", 1 );
	return;
}       
void be_protect()
{
	int i,j,flag;
	object *inv,*enemy;
	
	inv=all_inventory(environment());
	enemy=query_enemy();
// if one of the protectors wants to kill... then heis out of the loop
	for(j=0;j<sizeof(enemy);j++)
		enemy[j]->delete_temp("protecting");

	for (i=0;i<sizeof(inv);i++)
		if (objectp(cart) && inv[i]->query_temp("protecting")==cart)
		{
			flag=1;
			for(j=0;j<sizeof(enemy);j++)
			{
				inv[i]->kill_ob(enemy[j]);
				enemy[j]->kill_ob(inv[i]);
			}
	    }
	if(!flag) return;
	message_vision("$N����������Ͽ쵲ס����\n",this_object());
	
}	
void get_quest(string file)
{   
	way=read_table(file);
}
void to_rob()
{
	int i;
	object robber;
	
	message_vision("��Ȼ������һȺ�ٷˣ�\n",this_object());
	for (i=0;i<=random(5)+1;i++)
	{
		robber=new("/d/obj/npc/jiefei");
		robber->move(environment());
		robber->kill_ob(this_object());
		this_object()->kill_ob(robber);
		robber->set_leader(this_object());
	}
	be_protect();
	
}
	
mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}
void set_protector(object prot)
{       protector=prot; }
object query_protector()
{       return protector;       }

void set_cart(object dartcart)
{       cart=dartcart;  }
object query_cart()
{       return cart;    }

void die()
{
	object killer,where;
	object *inv,pro_team;
	int values;
	int i;
	
	values=0;
	killer=query_temp("last_damage_from");
	if (objectp(protector))
	{
	     protector->add("faith",-5);
	     protector->save();
	     tell_object(protector,"��մ������������˵�ŭ�⣺\n");
	     tell_object(protector,"����һ�����鶼�첻�ã�һ�ѷ��\n");
	}
	
	if (objectp(killer))
	{
		command("chat ҩ�ı�"+killer->query("name")+"�����ˣ�");
		message_vision(killer->query("name")+"��ҩ�ĳ������������е�ҩ�ģ�\n");
		inv=all_inventory(cart);
		for(i=0;i<sizeof(inv);i++)
		{
			if (userp(killer))
			{
				inv[i]->move(killer);
			}
			else
				destruct(inv[i]);
		}
		destruct(cart);
		where=environment(killer);
		while(killer=present("mengmian dahan",where))destruct(killer);
	}
	
	::die();
}
void give_reward()
{   
	object *inv,pro_team;
	int i,reward;

	reward=6000+random(4000);
	if (objectp(protector)) 
	{
		pro_team=protector;
		pro_team->add("faith",10);
		pro_team->add("combat_exp",reward);
		pro_team->add("potential",reward/3);
		pro_team->save();
		tell_object(pro_team,"���д������������˵Ļ�������ģ�����Ϊ�������µ��ӡ�\n");
	}
		
	destruct(cart);
	inv=all_inventory(environment());

	for (i=0;i<sizeof(inv);i++)
		if (inv[i]->query_temp("protecting")==cart && !userp(inv[i]))
			destruct(inv[i]);
	destruct(this_object());
	
	return;
}
