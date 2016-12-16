//seal.c
//stone amend

#include <ansi.h>
 
inherit ITEM;
 
void create()
{
        set_name(YEL"ץ���"NOR, ({"ghost seal", "seal", "paper"}));
        set_weight(100);
        if(clonep())
                set_default_object(__FILE__);
        else {

        set("long","һ�Ż����˷�����ҷ���ֽ��\n");
        set("unit", "��");
        set("value", 0);
        set("no_put",1);
        set("no_sell",1);
        }
        setup();
}

string long()
{
        if(query("finished"))
                return "һ������ظд�˼���������ҷ���ֽ��\n"+
                "�Ѿ���һֻ���������ס�ˡ�\n";
        if(stringp(query("desc")))
                return "һ������ظд�˼���������ҷ���ֽ������(burn)��ץ��\n"+
                "ֻ�����滭�ţ�\n"+
                query("desc");
}

void init()
{
        add_action("do_burn", "burn");
        	if( (int)this_object()->query("created") != 1 )
	{
		this_object()->set("created", 1);
		remove_call_out ("destroy_seal");
		call_out ("destroy_seal", 900);//15 mins

	}
}

int do_burn(string arg)
{
        object room, me;
        string name;
        
        if(!arg||!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        me=this_player();
        
        if(query("finished"))
                return notify_fail("�����Ѿ���һֻ���ˣ����ȥ������ظ�ɡ�\n");
        if(!query("master")||query("master")!=me)
        {
                message_vision(RED"$N��һ������ħ��ֿ���������һ�ӣ�������һ��ץ�����������\n\n"NOR, me);
                message_vision("���ʲô��û�з�����\n", me);
                destruct(this_object());
                return 1;
        }
        
        room=environment(me);
        message_vision(RED"$N��һ������ħ��ֿ���������һ�ӣ�������һ��ץ�����������\n\n"NOR, me);
        if(file_name(room)+".c"!=query("file_name"))
        {
                message_vision("���ʲô��û�з�����\n", me);
                destruct(this_object());
                return 1;
        }
        name=({ "��ͷ", "����", "����", "�෢"})[random(4)];

        message_vision(HIB"ֻ��һ������������"+name+"���Ѿ���ץ���������ס��\n"NOR, me);
        set("finished", 1);
        return 1;
}

void destroy_seal()
{
	object seal1 = this_object();
  	object who = environment(seal1);
  	object sealpaper;
	message_vision("һ��紵����" + (string)this_object()->query("name") + "�ķ��佥����ȥ��ֻ����һ�Ż�ֽ����$N���С�\n", environment(this_object()));
	sealpaper = new (__DIR__"sealpaper");
        sealpaper->move(who);
        destruct(seal1);
}

