// �����硤���μǡ��汾(����)
 
// create by jing 2000.7.24

void reset_balance(object me);
inherit BANK;
#include <ansi.h>

void create ()
{
	set ("short", "Ǯׯ");
	set ("long", @LONG

����һ���¿���Ǯׯ���ϰ�Ǯ�����С�ͷ���Ҫ����Ǯׯ���ϰ壬ֻΪ��
�ܹ����������Ǵӹ�̨�ﲻʱ����������ͭ�����̵���������
LONG);

	set("exits", ([
		"north"  : __DIR__"jiedao7",
	]));
	set("objects", ([
		__DIR__"npc/banker"   : 1,
	]));

	setup();
}


void init()
{
    reset_balance(this_player());
    ::init();
}

void reset_balance(object me)
{
    int myexp=me->query("combat_exp")/1000;
    int allowed, removed_gold;
    string myid=me->query("id");
    string NPCNAME="Ǯ����";

    if(myexp<1) myexp=1;
    if(myexp>100) myexp=100;
    allowed=myexp*1000000;//each year can have 100 gold, range 100-10000. 
    if (me->query("balance") > allowed)
    {
   me->set("balance_old", me->query("balance"));
   me->set("balance", allowed);
   removed_gold = (me->query("balance_old") - me->query("balance"))/10000;
   log_file("MONEY_RESET", ctime( time() )+"��κ�����ս���"+me->query("name")+"("+me->query("id")+")"+removed_gold+"���ƽ�\n");
   tell_object(me, GRN+NPCNAME+"����Ķ�������˵����"+RANK_D->query_respect(me)+
     "���⡢���治֪��ô˵�Ǻã�����\n"NOR);
   tell_object(me, GRN+NPCNAME+"����Ķ�������˵����"+
     "����κ��������ǰ���참���������ϵĻƽ���·������\n"NOR);
   tell_object(me, GRN+NPCNAME+"����Ķ�������˵����"+
     "���������°����ϱ�⣬���ϵ�Ǯ��ȫ���乫�ˣ�����\n"NOR);
    }
    return;
}

