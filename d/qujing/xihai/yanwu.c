inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
�������������������䳡����˳��Ӣ�������ڴ��ٿ�����
�����ᣬ�����������ܣ���������ʿ�����ܷ���������
ɫɫ����������꫽������������У���λ��������վ����
�ߣ����ӵ����ؿ�������λ����֮�͡�
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "enter" : __DIR__"dian", 
                "southdown" : __DIR__"gate", 
                "east" : __DIR__"lgroom", 
                "west" : __DIR__"bqroom", 
        ]));
        set("no_fight",1);
        set("objects", ([
                 "/d/qujing/xihai/npc/huwei":3, 
        ]));


        setup();
}

//void init ()
//{
//  add_action ("do_enter","enter");
//}
/*
int do_enter (string arg)
{
	object me;
	me = this_player ();

	message_vision ("$Nװ��һ�����򾲵����ӣ���ҡ��ڵ������ߡ�\n",me);
	if (! me->query_temp("apply/name") ||
	me->query_temp("apply/name")[0] != "����С��")
	{
		message_vision ("\n���������µ����������Ļ쵰��������������һ�ţ���$N���˳�ȥ��\n",me);    
		me->move(__DIR__"haidi5");
		return 1;
	}
	else
		message_vision ("\n��������Ц������ԭ���Ǹ�С��ү���ŵģ������ˣ�������������\n",me);    
	me->move(__DIR__"dian");
	return 1;
}
*/
int valid_leave(object me, string dir)
{
	if (dir == "enter" ) {
		message_vision ("$Nװ��һ�����򾲵����ӣ���ҡ��ڵ������ߡ�\n",me);
		if( ( !me->query_temp("apply/name") || 
		me->query_temp("apply/name")[0] != "����С��") && !wizardp(me) )
		{
			message_vision ("\n���������µ����������Ļ쵰��������������һ�ţ���$N���˳�ȥ��\n",me);    
			me->move(__DIR__"haidi5");
			return notify_fail("���������������ߣ�ʲô�˶���������ߣ�\n");
		}
		else if (wizardp(me))
			message_vision ("\n��������Ц������������ô�пյ��������������ˣ�������������\n",me);
		else
			message_vision ("\n��������Ц������ԭ���Ǹ�С��ү���ŵģ������ˣ�������������\n",me);
		return ::valid_leave(me, dir);
	}
	return ::valid_leave(me, dir);
}

