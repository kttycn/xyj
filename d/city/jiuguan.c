#include <ansi.h>
inherit ROOM;

string *city = ({
	"yinfeng",
	"huanhua",
	"erengu",
});

int do_jun(object);

void create ()
{
	set ("short", "小酒馆");
	set ("long", @LONG

小酒馆不大，屋中零乱的摆了几张方桌，几条长凳。小柜台上摆了些
酒坛，所卖也不过是些花生米，老白干之类。累了一天的苦力人总爱
凑到一起喝几杯，吹吹牛，消磨时光。小二托着酒壶，穿梭在桌椅之
间。猜拳行令之声、笑骂声、叱喝声响成一片。也分不清那些是良家
百姓、哪些是响马强人。这里真说得上是龙蛇混杂。成为雇佣士兵的
好去处。
LONG);

	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"beiyin2",
		"south" : __DIR__"beiyin4",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/jia" : 1,
		__DIR__"npc/kuli" : 2,
	]));
	set("no_fight", 1);
	set("no_magic", 1);
	set("resource", ([ /* sizeof() == 1 */
		"water" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_zhaomu", "zhaomu");
	add_action("do_money", "xiang");
	add_action("do_muji", "muji");
}

int do_zhaomu(string args)
{
	object me=this_player();

	if(!args || (args != "soilder"))
		return notify_fail("这里只可以募集士兵。其他的大家可是没有兴趣的哦！\n");
	if(!me->query("office_number"))
		return notify_fail("你还没有做官呢。征兵干啥？想当强盗造反不成？\n");
	if(do_jun(me) >= (me->query("office_number")*10))
		return notify_fail("你手下兵员已经满额，没有多余的指标了。要想多带兵。快去建功立业吧！\n");
	message_vision("你彭的一下将酒壶甩在地上。剧烈的响声招来了大家惊异的目光。你清了清喉咙，
大声说道：有没有人跟我去当兵呀？\n",me);
	tell_object(me,"你的最大带兵数为："+chinese_number(me->query("office_number")*10)+"人。目前缺额:"+chinese_number(
	me->query("office_number")*10 - do_jun(me))+". \n");
	tell_object(me,"征兵是要以金钱作为本钱的。没有军饷或者军饷太低，是没有人愿意跟你走的。\n
募兵你要先付一年的军饷，以后就不用再花钱了。你要出多少月饷募兵？(最低十两白银)\n");
	tell_object(me,"请打出你要给的月饷(xiang)。\n");
	me->set_temp("zhaomu_ing",1);
	return 1;
}

int do_money(string arg)
{
	object me=this_player();
	int pts;
	
	if(!me->query_temp("zhaomu_ing"))
		return notify_fail("你先要引起大家的注意才行。\n");
	if( !arg || !sscanf(arg, "%d", pts)) 
		return notify_fail("指令格式：yuexiang <每月每个士兵的饷银>\n");
	if(pts<10)
		return notify_fail("这么点钱就想募兵呀，还是你自己去得了。\n");
	if(me->query("balance")/(1200*pts) < 100)
		return notify_fail("你的存款太少，还是去设法多赚点钱再来吧！\n");
	me->set("soilder_pay",pts);
	tell_object(me,"以你目前的财力，可以募兵："+me->query("balance")/(1200*pts)+"人。\n");
	tell_object(me,"实际缺额："+chinese_number((int)me->query("office_number")*10 - do_jun(me))+"，你要募集多少人?\n");
	tell_object(me,"请用muji <人数> 来决定.\n");
	me->delete_temp("zhaomu_ing");
	me->set_temp("give_pay",1);
	return 1;
}

int do_muji(string arg)
{
	object me=this_player();
	int pts,train;

	if(!me->query_temp("give_pay")) return notify_fail("你不开工资，谁给你白干呀？\n");
	if( !arg || !sscanf(arg, "%d", pts)) 
		return notify_fail("指令格式：muji <士兵数>\n");
	if(pts > (me->query("office_number")*10 - do_jun(me)) ) 
		return notify_fail("你不能募集多过你最大带兵数的人数。\n");
	message_vision("只见人头涌动。这些无事生非之徒纷纷过来报名。你从中挑了一些看上去精壮之人。\n",me);
	tell_object(me,"你征召了"+chinese_number(pts)+"名士兵。\n");
	me->add("balance",-pts*1200);
	train=me->query("train_level")*me->query("soilder")+10*pts;
	me->add("soilder",pts);
	train=train/(me->query("soilder"));
	me->set("train_level",train);   //士兵的训练度。
	message("vision",HIY+"【三界快报】:"+me->query("name")+"在长安酒馆募集了"+chinese_number(pts)+
"名士兵.\n"+NOR,users());
	me->delete_temp("give_pay");
	return 1;
}

int do_jun(object me)
{
	int soilder, i;
	
	soilder=me->query("soilder");
	for( i = 0; i < sizeof(city); i ++ ) {
		if( me->query("city/"+city[i]+"sold"))
			soilder += me->query("city/"+city[i]+"sold");
	}
	return soilder;
}
