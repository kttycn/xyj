//By waiwai@mszj 2000/10/26

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "Ұ����ҽ��������");
	set("long", 

HIB"\n��������վ��Ұ����ҽ�ݵ��������ȫ��һ�ѵ��ɹŴ��\n"+
"������һ��������С��������ٺٵ���Ц��......ǽ�Ϲ���\n"+
"һ��Сľ���� "+HIR"(paizi)\n\n"NOR);
	set("item_desc", ([
		"paizi": HIC"���� "+HIR"\"bianxing id\""+HIC" ����ʼ���������� \n\n"NOR,
	]));

	set("objects", ([
		__DIR__"npc/menggu" : 1,
	]));
 
	setup();
}
void init()
{
	add_action("do_bianxing","bianxing");
}

int do_bianxing(string arg)
{
	object me,ob;
	string msg;

	me=this_player();
	ob = present(arg, environment(me));

	if (arg) {
		message_vision(HIR"$Nû���ü���Ӧ,ֻ��"+HIG"�ɹŴ��"+HIR"������,"+HIW"��.... "+HIR"$N�̲�ס��ʹ��������һ�������˹�ȥ......\n\n"NOR,this_player());
		if(random(20))
		{
			if(ob->query("gender")=="Ů��") ob->set( "gender", "����" );
			else ob->set( "gender", "Ů��" );
			msg = HIM "��ҥ������ĳ�ˣ���˵ "HIW+me->query("name")+"("+capitalize(ob->query("id"))+")"+
			HIM" ��ϧ���ʣ����ɹŴ��ҽ�ݳɹ�������һ�αȽϱ�̬�ı�������������\n"NOR;
		}
		else
		{
			ob->set("gender", "����" );
			msg = HIM "��ҥ������ĳ�ˣ���˵ "HIW+me->query("name")+"("+capitalize(ob->query("id"))+")"+
			HIM" ���ɹŴ��ҽ��������������ʧ���ˣ�����\n"NOR;
		}
		message("shout", msg, users());
		me->save();
		me->unconcious();
		me->move("/d/changan/bx1");

		return 1;
	}
}
