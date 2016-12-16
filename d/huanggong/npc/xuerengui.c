
inherit NPC;
#include <ansi.h>
#include "greeting.h"
string ask_bad(object me);
int do_job();
int ask_done();

void create()
{
	set_name("Ѧ�ʹ�", ({ "xue rengui", "xue", "rengui" }) );
	set("gender", "����");
	set("age", 35);
	set("long","Ѧ�ʹ��ǳ����Ǿ����ᶽ������ʹ����ⰲȫ��\n");
	set("combat_exp", 350000);
	set("title", HIR"�����ᶽ"NOR);
	set("nickname", HIY"�¹�����"NOR);
	set("attitude", "friendly");
	set("per", 25);
	set("str", 35);
	set("max_kee", 850);
	set("max_gin", 600);
	set("max_mana", 500);
	set("mana", 500);
	set("force", 600);
	set("max_force", 600);
	set("force_factor", 35);
	set_skill("spear", 80);
	set_skill("unarmed", 80);
	set_skill("changquan", 70);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("bawang-qiang", 70);
	set_skill("yanxing-steps", 70);
	map_skill("spear", "bawang-qiang");
	map_skill("parry", "bawang-qiang");
	map_skill("dodge", "yanxing-steps");
	map_skill("unarmed", "changquan");
	set("inquiry", ([
		"�ӷ�": (: ask_bad :),
		"�س�" : (: do_job :),
		"job"  : (: do_job :),
		"���" : (: ask_done    :),
		"done" : (: ask_done    :),
	]));
	setup();

	carry_object("/d/obj/weapon/spear/tiespear")->wield();
	carry_object("/d/obj/armor/tongjia")->wear();
}

void init ()
{
	greeting2(this_player());
}

int accept_fight(object me)
{
	command("say ��Ϊ��ǰ���������������Ұƥ����գ�");
	return 0;
}


string ask_bad(object me)
{
	me=this_player();
//    if ( me->query("office_number") > 300 )
//        return ("�������ʹ�ݡ�");
	if(me->query("combat_exp") < 100000 )
		return ("����ô�ܷ�����ȥ�أ�");
	return "/d/obj/bad"->query_yao(me);
}

int accept_object(object who, object ob)
{
	int exp, dx;
	string bname = who->name()+"��"+who->query("bad/name") + "��ͷ­";

	if ( (string)ob->query("name") != bname )
		return notify_fail("Ѧ�ʹ�ŭ�����㾹�Һ�Ū�ң�\n");

	if (!ob->query("killer") ||ob->query("killer") != who->query("id"))
		return notify_fail("Ѧ�ʹ��ŭ��������ɱ��Ҳ������,С���ұ��㣡\n");
	exp =who->query("combat_exp");
	dx = who->query("daoxing");
	who->add("office_number", 1);
	if( random(2) )
	{
		if (exp< 1500 )
			who->add("combat_exp", exp/2000 );
		else
			who->add("combat_exp", 1501);
	}
	else {
		if (dx< 1500 )
			who->add("daoxing", dx/2000 );
		else
			who->add("daoxing", 1501);
	}
	who->add("potential", 50 + random(100) );
	command("smile");
//	command("touch " + who->query("id"));
	tell_object(who,"Ѧ�ʹ���ͷ������Ӧ�ý�����\n");
	who->delete("bad");
	return 1;
}


int do_job()
{      
	object me;
	me = this_player(); 

	if( me->query("job/sxy-done")>0)
	{
		tell_object(me,"������Ȱ��ϴε����񱨸����Ժ������Ҫ����\n");
		return 1;
	} 
	else 
		if( me->query("job/sxy")>0)
		{
			tell_object(me,"���������Ҫ�������ˣ���ȥ�سǡ�\n");
			return 1;
		}
		else 
			if( me->query("combat_exp")<60000)
			{
                tell_object(me,"��Ϊ��͢Ч��֮�Ŀɱ������سǲ��Ƕ�Ϸ����Ҫ����������\n");
                return 1;
    }

    message_vision(CYN"Ѧ�ʹ��$N˵���������ȥ�ɣ�Ϊ��͢Ч�����������ٽݾ��ߡ�\n"NOR,me); 
        me->set("job/sxy", 1);
        me->apply_condition("sxy-job", 8);
        return 1;   
}

int ask_done()
{      

        object me,ob;
        int gong,exp,pot,money;
        me = this_player();
        gong = me->query("job/gong");
        exp = gong * 100;
        pot = gong * 30;
        money = gong * 100; 
        
    if( me->query("job/sxy-done")< 1)
    {
                tell_object(me,"�������û����ء�\n");
                return 1;
    }

    message_vision(CYN"Ѧ�˹��$N˵�������ò���Ϊ��������Ӧ��ˡ�\n"NOR,me);
    message_vision(CYN"Ѧ�ʹ��$N˵�������ܹ�����" + gong + "������\n"NOR,me);     
    message_vision(CYN"Ѧ�ʹ��$N˵�����ý�����" + exp + "�㾭�飬" + pot + "��Ǳ�ܣ�" + money + "�����ӣ�"+gong + "���ֵ��\n"NOR,me);        
    me->add("combat_exp",exp);
    me->add("potential",pot);
    me->add("office_number",gong);
    me->delete("job/gong");
    me->delete("job/sxy");
    me->delete("job/sxy-done");
    ob=new("/obj/money/silver");
    ob->set_amount(money);
    ob->move(me);
    return 1;
}

