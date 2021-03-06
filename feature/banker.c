//banker.c
// Each banker should support do_ + check, convert, deposit, withdraw 4 commands
// snowman

#include <dbase.h>

void enough_rest()
{
	delete_temp("busy");
}

int do_check()
{
	object me = this_player();
	int total = me->query("balance");

	if (total <= 0){
		me->set("balance", 0);
		write("您在敝商号没有存钱。\n");
		return 1;
	}
	write(this_object()->name()+"悄悄告诉你：您在弊商号共存有"+MONEY_D->money_str(total)+"。\n");
	return 1;
}

int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2, exp;
	object from_ob, to_ob;
	object me;
        
	if (query_temp("busy"))
		return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

	me = this_player();
        exp = me->query("combat_exp",1);
	if (!arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3)
		return notify_fail("命令格式：convert|duihuan <数量> <货币单位> to <新货币单位>\n");

	from_ob = present(from + "_money", me);
	if (!from_ob)
		return notify_fail("你身上没有带这种钱。\n");

        if (exp<15000 && from_ob->query("id") == "thousand-cash")
        return notify_fail("你功夫还未入流，那里来的这麽多钱？\n");

	to_ob = present(to + "_money", me);
	if (!to_ob && file_size("/clone/money/" + to + ".c") < 0)
		return notify_fail("你想兑换成什么？\n");

	if (amount < 1)
		return notify_fail("你想白赚啊？\n");

	if ((int)from_ob->query_amount() < amount)
		return notify_fail("你带的" + from_ob->name() + "不够。\n");

	bv1 = from_ob->query("base_value");
	bv2 = to_ob ? to_ob->query("base_value") : call_other("/clone/money/" + to, "query", "base_value" );

	if (bv1 < bv2) amount -= amount % (bv2 / bv1); 

	if (amount == 0)
		return notify_fail("这些" + from_ob->name() + "不够换。\n");

// allowed to convert now
	to_ob = new("/clone/money/" + to);
	to_ob->set_amount(amount * bv1 / bv2);
	if (!to_ob->move(me)) {
		destruct(to_ob);
		return notify_fail("你带不了那么多钱。\n");
	}

	set_temp("busy", 1);    

	from_ob = present(from + "_money", me);

	message_vision(sprintf("$N从身上取出%s%s%s，换成了%s%s%s。\n",
		chinese_number(amount), from_ob->query("base_unit"), from_ob->name(),
		chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), 
		to_ob->name()), me);
	from_ob->add_amount(-amount);

	call_out("enough_rest", 1);

	return 1;
}

int do_deposit(string arg)
{
	string what;
	int amount;
	object what_ob, me;
	int limit;

	if (query_temp("busy"))
		return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
		return notify_fail("命令格式：deposit|cun <数量> <货币单位>\n");

	what_ob = present(what + "_money", me);
	if (!what_ob)
		return notify_fail("你身上没有带这种钱。\n");

	if (amount < 1)
		return notify_fail("你想存多少" + what_ob->name() + "？\n");

	if ((int)what_ob->query_amount() < amount)
		return notify_fail("你带的" + what_ob->name() + "不够。\n");

	limit = me->query("combat_exp") * 50;
	limit -= me->query("balance");
	if (limit < what_ob->query("base_value") * amount)
		return notify_fail("你不能存那么多的钱。\n");
// deposit it
	set_temp("busy", 1);    

	me->add("balance", what_ob->query("base_value") * amount);
	message_vision(sprintf("$N拿出%s%s%s，存进了银号。\n", 
		chinese_number(amount), what_ob->query("base_unit"), 
		what_ob->name()), me);
	what_ob->add_amount(-amount);

	call_out("enough_rest", 1);
	return 1;
}

int do_withdraw(string arg)
{
	int amount, v;
	string what;
	object me, to_ob;

	if (query_temp("busy"))
		return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
		return notify_fail("命令格式：withdraw|qu <数量> <货币单位>\n");

	if (file_size("/clone/money/" + what + ".c") < 0)
		return notify_fail("你想取出什么钱？\n");

	if (amount > 21474)
		return notify_fail("你想作弊吗？这里可不是你找ＢＵＧ的地方。\n");
	if (amount < 20)
		return notify_fail("因为取款手续费是百分之五，所以数目必须不少于二十。\n");
	amount -= amount % 20;

	what = "/clone/money/" + what;
	if ((v = amount * what->query("base_value")) > me->query("balance"))
		return notify_fail("你没有存那么多的钱。\n");

	to_ob = new(what);
	to_ob->set_amount(amount - amount / 20);
	if (!to_ob->move(me)) {
		destruct(to_ob);
		return notify_fail("你带不了那么多钱。\n");
	}
	set_temp("busy", 1);
	me->add("balance",  -v);
	message_vision(sprintf("$N从银号里取出%s%s%s。\n",
		chinese_number(amount - amount / 20), what->query("base_unit"), 
		what->name()), me);
	write("你被扣除了"
		+chinese_number(amount/20)
		+what->query("base_unit")
		+what->name()
		+"的手续费。\n");

	call_out("enough_rest", 1);
	return 1;
}
