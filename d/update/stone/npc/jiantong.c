//jiantong.c
//stone
//20020219
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��ԯ��ͯ", ({ "xuanyuan jiantong","tongzi","jiantong" }));
	set("looking", "ü��Ŀ�㣬��Ƥ�ɰ���
������ԯ���Ľ��ʻû�������ԯͯ�ӡ���ԯ��ͯ�ĺ�
���ĺ�ǿ����ȫ��С���ӵ��ģ����ϳɳ��ص���ԯ��
��һ��һ�٣��γ�ǿ�ҶԱȡ�\n");
	set("attitude", "friendly");
	set("class", "swordsman");
	set("age", 8);
	set("max_sen", 6000);
	set("max_kee", 6000);
	set("max_mana", 6000);
	set("mana", 10000);
	set("max_force", 5000);
	set("mana_factor", 225);
	set("force_factor", 225);
	set("force",5000);
	set("combat_exp", 800000);   
	set("daoxing", 4000000);
	set("str", 40);
	set("con", 80);
	set("chat_chance",20);
        set("chat_msg", ({
        "��ԯ��ͯ���������������˷�Ʈ���米����նȺ�������ľȿഫ�����������������ꡣ\n\n",
        
        "��ԯ��ͯӽ���������ӣ�Ʒ������־ѧ���м����ף�ѩӵ���������������Ĺ��Ͼ�����\n\n",
        
        "��ԯ��ͯ������ܹ��ˣ�����ң�������ٻ�ж���ۣ�����������кã���ִ�����ɰ��á�\n\n",
        
	"��ԯ��ͯ����������գ�������������Ũü�����Σ�������������������յ��ư���Ʈ��\n\n",
	
        "��ԯ��ͯ�����������룬�Զ��ã���͸������̬�ɣ�����ɽ�����������λ�ɰ���иߡ�\n\n",
        
	"��ԯ��ͯ���������ɹã���ò��������쳾Ը���ȣ���־����ǧ���أ�Ҳ���ɽ����ң��\n\n",
	
        "��ԯ��ͯ���������ɺͣ����С�������ȴ���ģ���ɽ�����������ʹִ�����ݺ�����\n\n",
        
        "��ԯ��ͯӽ�����Ź��ϣ���͸ߣ��뷢�Բ�������������¿�ӺǺ�Ц�����ѷ��������ס�\n\n",
        }));
	set_skill("parry", 300);
	set_skill("dodge", 200);
	set_skill("force", 300);
	set_skill("zixia-shengong", 300);
	set_skill("spells", 300);
	set_skill("taoism", 300);
	set_skill("sword", 300);
	set_skill("unarmed", 300);
	set_skill("hunyuan-zhang",300);
	set_skill("yujianshu", 300);
	set_skill("seven-steps", 300);
	map_skill("dodge", "seven-steps");
	map_skill("force", "zixia-shengong");
	map_skill("sword", "yujianshu");
	map_skill("unarmed", "hunyuan-zhang");
	map_skill("parry", "yujianshu");
	map_skill("spells", "taosim");
	setup();
	carry_object("/d/obj/weapon/sword/qingfeng")->wield();
	carry_object("/d/obj/armor/jinjia")->wear();
}

void leave()
{
	object own = this_player();
	message("vision", name() +HIY "����һЦ���������湻�ˣ��������ˡ�������һ�������������ԯ�����С�\n"NOR, environment(), this_object() );
	if(objectp(own=this_object()->query("possessed")))
		own->add_temp("number",-1);
	destruct(this_object());
}

void show(object who)
{
//	string *cname = ({"�󻤷�", "�һ���"});
//	string *ename = ({"-left", "-right"});

	string *cname = ({"��ԯͯ��"});
	string *ename = ({"-jiantong"});
	int current = 0;
	current = (int)who->query_temp("number");

//	if(current < 1 || current > 2 )
	if(current < 1 || current > 1 )
	{
		destruct(this_object());
		return;
	}

	this_object()->set_name(cname[current-1], ({ (string)who->query("id")+ename[current-1] }) );   

	message_vision(HIY"ͻȻ��ԯ���ʷ������ɫ�Ĺ�â����â�𽥾ۼ���һ��Сͯ��
Сͯ��$N����һЦ˵�������к���İ��������ˣ�\n"NOR, who);
	command("follow "+who->query("id"));

//	set("owner_id", (string)who->query("id")); ԭ����owner������Ҳ���
	set("own_id", (string)who->query("id")); 
	set_leader(who);
}

void relay_whisper(object me, string msg)
{
	if (query("own_id") != me->query("id"))
	{
		message_vision((string)this_object()->query("name") + "����$N˵�������Ҳ������棡��\n", me);
		return;
	}
   
	if( strsrch(msg, "chat") != -1 ||
	strsrch(msg, "tell") != -1 ||
	strsrch(msg, "apprentice") != -1 ||
	strsrch(msg, "recruit") != -1 ) 
		return;

	message_vision((string)this_object()->query("name") + "����$N���˵�ͷ��\n", me);
	if (msg)
	{
		call_out ("relaying", 1+random(3), msg);
	}
}

void relaying (string msg)
{
	command ("follow none");
	command (msg);
}
int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 120);
		return 1;
	}
	return ::heal_up() + 1;
}


void init()
{
	object me=this_player();
	object own;
	int i;
	::init();

	if ( (string)this_object()->query("own_id") == (string)me->query("id") )
	{
		this_object()->set_leader(me);
	}

	if( this_object()->query("own_id") != 0 )
	{
		own = find_player( (string)this_object()->query("own_id") );
		if( !own ) own=find_living( (string)this_object()->query("own_id") );
		if( !own )
		{
			call_out ("leave", 1);
		}
	}
}

void die()
{
	object own;
	if(objectp(own=this_object()->query("possessed")))
		own->add_temp("number",-1);
	if( environment() ) {
                message("sound", HIY"\n\n��ԯͯ��һ���죬���������������ˣ�\n
��ǰһ������ԯͯ�ӻ���һ�������������ԯ�����У������ˡ�\n"NOR, environment());
        }

        destruct(this_object());
//	::die();
}
