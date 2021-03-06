//jiantong.c
//stone
//20020219
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("轩辕剑童", ({ "xuanyuan jiantong","tongzi","jiantong" }));
	set("looking", "眉清目秀，顽皮可爱。
是由轩辕剑的剑鞘幻化而成轩辕童子。轩辕剑童的好
奇心很强，完全是小孩子的心，跟老成持重的轩辕剑
仙一老一少，形成强烈对比。\n");
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
        "轩辕剑童唱道：吕洞宾，乘风飘，肩背龙剑斩群妖；悲心救苦传妙道，至今万古姓名标。\n\n",
        
        "轩辕剑童咏道：韩湘子，品玉萧，志学修行家室抛；雪拥篮关难行马，曾度文公上九霄。\n\n",
        
        "轩辕剑童歌道：曹国舅，爱逍遥，不恋荣华卸锦袍；世上万般修行好，手执云阳仙板敲。\n\n",
        
	"轩辕剑童歌道：李铁拐，相咆哮，黑脸浓眉脚又跷；虔心修练长生法，拄拐登云蔼蔼飘。\n\n",
	
        "轩辕剑童吟道：汉钟离，性儿矫，炽透人情事态枭；终南山上修妙道，列位仙班道行高。\n\n",
        
	"轩辕剑童唱道：何仙姑，容貌娇，懒伴红尘愿寂寥；苦志真修千百载，也归仙界可逍遥。\n\n",
	
        "轩辕剑童吟道：蓝采和，年纪小，最爱修行却富饶；名山修炼成真果，使执棕蓝驾海潮。\n\n",
        
        "轩辕剑童咏道：张果老，年纪高，须发苍苍两鬓萧；倒骑驴子呵呵笑，竟把繁华世界抛。\n\n",
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
	message("vision", name() +HIY "嘻嘻一笑道，“我玩够了，我先走了”。化作一道金光钻入了轩辕剑鞘中。\n"NOR, environment(), this_object() );
	if(objectp(own=this_object()->query("possessed")))
		own->add_temp("number",-1);
	destruct(this_object());
}

void show(object who)
{
//	string *cname = ({"左护法", "右护法"});
//	string *ename = ({"-left", "-right"});

	string *cname = ({"轩辕童子"});
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

	message_vision(HIY"突然轩辕剑鞘发出金黄色的光芒，光芒逐渐聚集成一个小童。
小童对$N嘻嘻一笑说道：又有好玩的啊，我来了！\n"NOR, who);
	command("follow "+who->query("id"));

//	set("owner_id", (string)who->query("id")); 原来是owner，下面也如此
	set("own_id", (string)who->query("id")); 
	set_leader(who);
}

void relay_whisper(object me, string msg)
{
	if (query("own_id") != me->query("id"))
	{
		message_vision((string)this_object()->query("name") + "对着$N说道：“我不和你玩！”\n", me);
		return;
	}
   
	if( strsrch(msg, "chat") != -1 ||
	strsrch(msg, "tell") != -1 ||
	strsrch(msg, "apprentice") != -1 ||
	strsrch(msg, "recruit") != -1 ) 
		return;

	message_vision((string)this_object()->query("name") + "对着$N点了点头。\n", me);
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
                message("sound", HIY"\n\n轩辕童子一噘嘴，喊道：不跟你玩了！\n
眼前一闪，轩辕童子化作一道金光钻入了轩辕剑鞘中，不见了。\n"NOR, environment());
        }

        destruct(this_object());
//	::die();
}
