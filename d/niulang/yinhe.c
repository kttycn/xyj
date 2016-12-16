// By canoe 2001.03.25
inherit ROOM;
#include <room.h>
void create()
{
	set("short", "����");
	set("long", @LONG
        
�϶���ȡ��ؼ������΢����һ������ѡ����ɫ�Ŀ������۳ɵġ�
����������������Ż���һ���ģ�����źڰ�������У���ô��
��ɫ΢�����������ҫ�š��м����ų��˲�����Խ��ħ����
        
        
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"up"  : "/d/dntg/sky/tongmingdian",
		"east": __DIR__"yinheright",
		"west": __DIR__"yinheleft",
	]));
	set("objects", ([
	]) );
	setup();
}
void init()
{
	add_action("do_daqiao", "daqiao");
}
int do_daqiao(string arg)
{
	object me = this_player();
	object xique,zhinu;
	int i;
	if (me->query("combat_exp") < 800000 || me->query("daoxing") < 800000)
		return notify_fail("�������Ϊ��ĸ������ô�ᱻ�ȴ�Ӧţ��֯Ů��᣿\n");
	if (!me->query_temp("ask_wangmu"))
		return notify_fail("�㾭������ĸ�����ͬ�⣿\n");
	if (me->is_busy()) return notify_fail("��������æ���ء�\n");

	if (strsrch(NATURE_D->game_time(),"��������")==-1)
		return notify_fail("���ڲ����������գ�ϲȵ�ų���Ҳ������ߣ�\n");
	xique=present("xique", me);
	if(xique) {
		if (me->query_temp("daqiao")<(50-me->query("kar"))/3)
		{
			message_vision("$N�ӻ����ͳ�һֻϲȵ������ϣ���ذ�ϲȵ�ŷ��ڿ��С�\n",me);
			message_vision("ϲȵ����$N���˼�Ȧ�󣬾�Ȼ��������ϲȵ,�����ǲ�Щϲȵ��\n",me);
			me->add_temp("daqiao",1);
			destruct(xique);
			me->start_busy(random(5));   
			return 1;
		}
		else 	{
			message_vision("$N�ӻ����ͳ�һֻϲȵ������ϣ���ذ�ϲȵ�ŷ��ڿ��С�\n",me);
			message_vision("���ϵ�ϲȵԽ��Խ�࣬��Ȼ��$N��ǰ�������ȵ�ţ�����\n",me);
			message_vision("ţ�ɺ�֯Ů��ȵ��������ˣ�\n",me);
			zhinu=new("/d/niulang/npc/zhinu");
			zhinu->announce_success(me);
			destruct (zhinu); 
			me->delete_temp("askd_wangmu");
			me->delete_temp("daqiao");
			me->delete_temp("ask_niulang");
			me->start_busy(1);
			return 1;
		}
	}
	else return notify_fail("������û��ϲȵ��ô���ţ�\n");
}
