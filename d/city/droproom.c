#include <ansi.h>

inherit ROOM;
int do_drop(object me, object obj);
int do_enter(string arg);
string money_str(int count);

void create()
{
	set("short", HIY"������"NOR);
	set("long", 

"\n����ǰ����һ��˶��������ѡ������ǳ����������ķ���ѻ�����\n"+
"�л�����ʶ�ĺ�����ң�������������ӷ�����ǰ�������"+HIR"(drop)\n"NOR+
"�������������������Ϻ����и���С�Ķ�(cave)��\n\n"
	);
	set("exits", ([
		"up" : __DIR__"center",
		"east" : __DIR__"menwc",
		"west" : __DIR__"manwc",
	]));
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/fei" : 1,
	]));
	set("item_desc", ([ /* sizeof() == 1 */
		"cave" : "һ����С�Ķ���˵����������(enter)��ȥ�ġ�"
	]));

	set("no_fight", 1);
	set("no_magic", 1);
	setup();
}

void init()
{
	add_action("do_enter", "zuan");
	add_action("do_enter", "enter");
    add_action("do_main", "drop");
}

int do_main(string arg)
{
	object me=this_player();
	object obj, *inv, obj2;
	int i, amount;
	string item;

	if(me->is_busy())
		return notify_fail("����æ���أ�����\n");

	if(!arg) return notify_fail("��Ҫ����ʲô������\n");

	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ�������\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("��û����ô���" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_drop(me, obj);
		else {
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if(do_drop(me, obj2)) { // succeed to drop
   		        obj->set_amount( (int)obj->query_amount()-amount );
				return 1;
			}
			return 0;
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_drop(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("������û������������\n");
	return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
   int count = 0;
   object money;
   if(me->is_busy())
      return notify_fail("����æ���أ�����\n");
	if (obj->move(environment(me))) {
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
					if (obj->query("id")=="thousand-cash" || obj->query("id")=="gold"
					|| obj->query("id")=="silver" || obj->query("id")=="coin")
						message_vision( sprintf("$N����һ%s$n��\n",obj->query("unit")),me, obj );
					else { message_vision( sprintf(HIC"$N��һ%s$n"+HIC"�ӽ������ѡ�\n"NOR,obj->query("unit")),me,obj);
					if( !obj->query("no_drop") )
					{
						if (obj->query("value")>1 && obj->query("value")<100)
							count=obj->query("value")/2;
						else if (obj->query("value") == 0)
							return 1;
						else
							count = 100;
						me->add("balance",count);
						tell_object(me,HIY"������л�ͷ�϶���"HIR+money_str(count)+"\n"NOR);
					}
					destruct(obj);
				}
			}
		}
		return 1;
	}
	return 0;
}
string money_str(int count)
{        
	string output;
	if (count / 10000) {
		output = chinese_number(count / 10000) + "���ƽ�";
		count %= 10000;
	}
	else
		output = "";
	if (count / 100) {
		output = output + chinese_number(count / 100) + "������";
		count %= 100;
	}
	if (count)
		return output + chinese_number(count) + "��ͭ��";
	return output;
}
int do_enter(string arg)
{
	mapping skl;
    string *sname;
    int i,how=0;
	object room;
	object who = this_player();

	if(!arg || arg != "cave")
		return notify_fail("��Ҫ�����\n");
	if(!( room = find_object("/d/fenghuang/zhongxin")) )
		room = load_object("/d/fenghuang/zhongxin");
	if ( who->query("family/family_name") && 
	( who->query("family/family_name")!="�����" ||
	!who->query("xmark/ѧԱ") ))
	{
		message_vision("$N��������������ͻȻһ������������$Nȫ�����ս��ˣ�\n",who);
		who->unconcious();
		return 1;
	}
	if (((int)who->query("combat_exp")+(int)who->query("daoxing")/2) <10000 || (int)who->query("mud_age")<18000)
	{
		message_vision("$N��������������ͻȻһ������������$Nȫ�����ս��ˣ�\n",who);
		who->unconcious();
		return 1;
	}
      
	if ((int)who->query("combat_exp") >=3000 ) 
	{
		skl = who->query_skills();
		if(skl) sname  = keys(skl);
		for(i=0; i<sizeof(skl); i++)
			if (skl[sname[i]] >= 10)how=how+1; 
			if(how<3)
			{
				message_vision("$N��������������ͻȻһ������������$Nȫ�����ս��ˣ�\n",who);
				who->unconcious();
				return 1;
			}
	} 
	if(objectp(room))
	{
		tell_room(environment(who), who->query("name")+"��Ȼ���������ѣ����С���������ˡ�\n", who);
		who->move(room);
		tell_object(who, HIW"�������С������ǰ��Ȼһ������Ȼ�����˴�˵�еķ�˳ǡ�\n"NOR);
		tell_room( room, HIB"����ǰһ����"+who->query("name")+"��֪�Ӻδ����˳�����\n"NOR, who);
	}
	return 1;
}
