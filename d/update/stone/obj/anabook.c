//Cracked by Roath
// anabook.c
//stone creat
//20020222

inherit ITEM;

void init();
int do_read(string arg);

void create()
{
        set_name("〖万言集〗", ({"wanyan book","book","shu","ana"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "册");
	set("long",
	"这册书大约有两百多页，边角皆起卷起，微微泛黄的封面上苍劲有力地写着“万言集”。\n");
        set("material", "paper");
        set("value", 500);   
        }
}

void init()
{
	add_action("do_read", "read");
	add_action("do_read", "study");
}

int do_read(string arg)
{
	object me, where;
	int sen_cost, gain;
	string *ana = ({
		"多情自古伤离别，更那堪、冷落清秋节！",
		"易水萧萧西风冷，满座衣冠似雪。",
		"众里寻他千百度。蓦然回首，那人却在，灯火阑珊处。",
		"千金纵买相如赋，脉脉此情谁诉。",
		"千古江山，英雄无觅，孙仲谋处。舞榭歌台，风流总被，雨打风吹去。",
		"杳杳神京，盈盈仙子，别来锦字终难偶。",
		"明月楼高休独倚。酒入愁肠，化作相思泪。",
		"黯乡魂，追旅思。夜夜除非，好梦留人睡。",
		"碧云天，黄叶地，秋色连波，波上寒烟翠。",
		"聚散苦匆匆，此恨无穷。今年花胜去年红。可惜明年花更好，知与谁同。",
		"去年元夜时，花市灯如昼。月到柳梢头，人约黄昏后。",
		"离愁渐远渐无穷，迢迢不断如春水。",
		"寸寸柔肠，盈盈粉泪。楼高莫近危阑倚。",
		"人有悲欢离合，月有阴晴圆缺，此事古难全。但愿人长久，千里共婵娟。",
		"明月楼高休独倚。酒入愁肠，化作相思泪。",
		"易水萧萧西风冷，满座衣冠似雪。",		
		});
	me=this_player();
	where=environment(me);

    	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("文集要拿起来读。\n");
    	if( me->is_busy() )
        		return notify_fail("你现在忙着呢，哪有功夫念文集...\n");
   	if( me->is_fighting() )
        		return notify_fail("太托大了吧？打架时还念书...\n");
	if( where->query("no_fight") )
			return notify_fail("此处不宜大声喧哗。\n");

	if( (int)me->query_skill("literate",1)<70 )
		return notify_fail("你翻开文集聚精会神的念了几句，不过没明白是啥意思。\n");
	if( (int)me->query_skill("literate",1)>85 )
		return notify_fail("你在文法方面已经很有造诣，这册书不会让你长进多少。\n");

	sen_cost = 15 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("你现在头晕眼花，昏昏欲睡，该休息休息了。\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("literate", 1)/3+(int)me->query("int")+1;
	me->improve_skill("literate", gain);

    	message_vision("$N拿着册文集专心致致地念道：" + ana[random(sizeof(ana))] + "\n", me);
		
	return 1;
}

