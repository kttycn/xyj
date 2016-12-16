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
		write("���ڱ��̺�û�д�Ǯ��\n");
		return 1;
	}
	write(this_object()->name()+"���ĸ����㣺���ڱ��̺Ź�����"+MONEY_D->money_str(total)+"��\n");
	return 1;
}

int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2, exp;
	object from_ob, to_ob;
	object me;
        
	if (query_temp("busy"))
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	me = this_player();
        exp = me->query("combat_exp",1);
	if (!arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3)
		return notify_fail("�����ʽ��convert|duihuan <����> <���ҵ�λ> to <�»��ҵ�λ>\n");

	from_ob = present(from + "_money", me);
	if (!from_ob)
		return notify_fail("������û�д�����Ǯ��\n");

        if (exp<15000 && from_ob->query("id") == "thousand-cash")
        return notify_fail("�㹦��δ�������������������Ǯ��\n");

	to_ob = present(to + "_money", me);
	if (!to_ob && file_size("/clone/money/" + to + ".c") < 0)
		return notify_fail("����һ���ʲô��\n");

	if (amount < 1)
		return notify_fail("�����׬����\n");

	if ((int)from_ob->query_amount() < amount)
		return notify_fail("�����" + from_ob->name() + "������\n");

	bv1 = from_ob->query("base_value");
	bv2 = to_ob ? to_ob->query("base_value") : call_other("/clone/money/" + to, "query", "base_value" );

	if (bv1 < bv2) amount -= amount % (bv2 / bv1); 

	if (amount == 0)
		return notify_fail("��Щ" + from_ob->name() + "��������\n");

// allowed to convert now
	to_ob = new("/clone/money/" + to);
	to_ob->set_amount(amount * bv1 / bv2);
	if (!to_ob->move(me)) {
		destruct(to_ob);
		return notify_fail("���������ô��Ǯ��\n");
	}

	set_temp("busy", 1);    

	from_ob = present(from + "_money", me);

	message_vision(sprintf("$N������ȡ��%s%s%s��������%s%s%s��\n",
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
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
		return notify_fail("�����ʽ��deposit|cun <����> <���ҵ�λ>\n");

	what_ob = present(what + "_money", me);
	if (!what_ob)
		return notify_fail("������û�д�����Ǯ��\n");

	if (amount < 1)
		return notify_fail("��������" + what_ob->name() + "��\n");

	if ((int)what_ob->query_amount() < amount)
		return notify_fail("�����" + what_ob->name() + "������\n");

	limit = me->query("combat_exp") * 50;
	limit -= me->query("balance");
	if (limit < what_ob->query("base_value") * amount)
		return notify_fail("�㲻�ܴ���ô���Ǯ��\n");
// deposit it
	set_temp("busy", 1);    

	me->add("balance", what_ob->query("base_value") * amount);
	message_vision(sprintf("$N�ó�%s%s%s����������š�\n", 
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
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
		return notify_fail("�����ʽ��withdraw|qu <����> <���ҵ�λ>\n");

	if (file_size("/clone/money/" + what + ".c") < 0)
		return notify_fail("����ȡ��ʲôǮ��\n");

	if (amount > 21474)
		return notify_fail("��������������ɲ������ң£գǵĵط���\n");
	if (amount < 20)
		return notify_fail("��Ϊȡ���������ǰٷ�֮�壬������Ŀ���벻���ڶ�ʮ��\n");
	amount -= amount % 20;

	what = "/clone/money/" + what;
	if ((v = amount * what->query("base_value")) > me->query("balance"))
		return notify_fail("��û�д���ô���Ǯ��\n");

	to_ob = new(what);
	to_ob->set_amount(amount - amount / 20);
	if (!to_ob->move(me)) {
		destruct(to_ob);
		return notify_fail("���������ô��Ǯ��\n");
	}
	set_temp("busy", 1);
	me->add("balance",  -v);
	message_vision(sprintf("$N��������ȡ��%s%s%s��\n",
		chinese_number(amount - amount / 20), what->query("base_unit"), 
		what->name()), me);
	write("�㱻�۳���"
		+chinese_number(amount/20)
		+what->query("base_unit")
		+what->name()
		+"�������ѡ�\n");

	call_out("enough_rest", 1);
	return 1;
}
