#include <ansi.h>
inherit ROOM;
inherit F_SAVE;
string SAVE_NAME;

void create()
{
	set ("short", "演兵场");
	set ("long", @LONG

你眼前一亮，只见这里纵横数百丈，军队队容整齐，喊声震天。战旗
猎猎作响！来往小校匆匆忙忙，生怕一下不小心，脑袋落地。远方将
台上站着一位身着金铠，异常威武的将军，挥动着小旗，正在操练着
军队。

LONG);

	set("exits", 
	([ //sizeof() == 4
		"southeast" : __DIR__"center",
	]));

	setup();
}   

void init()
{
	add_action("do_caoyan", "caoyan");
	add_action("do_status", "status");
	set("no_clean_up", 1);
}

int do_caoyan(string arg)
{
	object me=this_player();
	if(me->query("soilder")<=0)
		return notify_fail("你连一个士兵也没有，怎么训练军队。\n");

	if( me->query("train_level") >= 200 )
		return notify_fail("你的军队的训练度已经不能再提高了！\n");

	if(me->query("balance") < (me->query("soilder")+1)*1000)
		return notify_fail("你的资金不足，还是先多赚点钱吧。\n");
	tell_object(me,"你的军队的训练度上升了。\n");
	me->add("train_level",1);
	me->add("balance",-(me->query("soilder")*1000));
	save();
	return 1;
}
int do_status(string arg)
{
	object me=this_player();
	object ob;
	string one;
	printf("                   "+this_object()->query("short")+"\n"+
	"军队人数:"+me->query("soilder")+"     军队训练度:"+me->query("train_level")+"\n");
	return 1;
}
