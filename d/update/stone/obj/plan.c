//Cracked by Roath
// plan.c
// stone
// 20020219

inherit ITEM;

void init();
int do_read(string arg);

void create()
{
        set_name("〖状元策〗", ({"plan","zhuangyuan ce","book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "册");
	set("long",
	"这册书约有三、四寸多厚，蓝底白字的封面上银钩铁划写着“状元策”，墨迹似乎还犹新。\n");
        set("material", "paper");
        set("value", 600);   
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
	string *plan = ({
		"一点草一点露，一个人一片天。",
		"一时劝人以口，百世劝人以书。",
		"一门父子三词客，千古文章四大家。",
		"一粒米中藏世界，半边锅内煮乾坤。",
		"一双冷眼看世界，满腔热血酬知已。",
		"三间东倒西歪屋，一个千锤百炼人。",
		"世事洞时皆学问，人情练达即文章。",
		"交友顺带三分侠气，做人要存一点素心。",
		"千古文章双管笔，四时风雅一篇诗。",
		"天若有情天亦老，月如无恨月常圆。",
		"此情可待成追忆，只是当时已惘然。",
		"衣带渐宽终不悔，为伊消得人憔悴。",
		"无可奈何花落去，似曾相识燕归来。",
		"无穷无尽是离愁，天涯地角寻思遍。",
		"相见时难别亦难，东风无力百花残。",
		"直道相思了无益，未妨惆怅是清狂。",
		"嫦娥应悔偷灵药，碧海青天夜夜心。",
		"夜月一帘幽梦，春风十里柔情。",
		"人生自是有情痴，此恨不关风与月。",
		"十里苹湖霜满天，寸寸青丝愁年华。",
		"对月形单望相互，只慕鸳鸯不慕仙。",
		"身无彩凤双飞冀，心有灵犀一点通。",
		"闭门推出窗前月，投石惊破水中天。",
		"水帷石下方成海，山不矜高自报天。",
		"半坞白云耕不尽，一潭明月钧天痕。",
		"好鸟枝头亦朋友，落花水面皆文章。",
		"人间净土须忠孝，心地功夫在圣贤。",
		"秀山青水青山秀，香柏古风古柏香。",
		"风送花香红满地，雨滋青树碧连天。",
		"天连碧树青滋雨，地满红香花送风。",	
		});
	me=this_player();
	where=environment(me);

    	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("书要拿起来读。\n");
    	if( me->is_busy() )
        		return notify_fail("你现在忙着呢，哪有功夫攻读策略集...\n");
   	if( me->is_fighting() )
        		return notify_fail("太托大了吧？打架时还读策集...\n");
	if( where->query("no_fight") )
			return notify_fail("此处不宜大声喧哗。\n");

	if( (int)me->query_skill("literate",1)<139 )
		return notify_fail("你照着策集若有所思地念了几句，不过没明白是啥意思。\n");
	if( (int)me->query_skill("literate",1)>150 )
		return notify_fail("你在文才方面已经很有造诣，这册书不会让你长进多少。\n");

	sen_cost = 25 + (40-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("你现在头晕脑胀，昏昏欲睡，该休息休息了。\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("literate", 1)/10+(int)me->query("int")+1;
	me->improve_skill("literate", gain);

    	message_vision("$N拿着册策集若有所思念道：" + plan[random(sizeof(plan))] + "\n", me);
		
	return 1;
}

