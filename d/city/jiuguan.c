#include <ansi.h>
inherit ROOM;

string *city = ({
	"yinfeng",
	"huanhua",
	"erengu",
});

int do_jun(object);

void create ()
{
	set ("short", "С�ƹ�");
	set ("long", @LONG

С�ƹݲ����������ҵİ��˼��ŷ������������ʡ�С��̨�ϰ���Щ
��̳������Ҳ������Щ�����ף��ϰ׸�֮�ࡣ����һ��Ŀ������ܰ�
�յ�һ��ȼ���������ţ����ĥʱ�⡣С�����žƺ�������������֮
�䡣��ȭ����֮����Ц������߳�������һƬ��Ҳ�ֲ�����Щ������
���ա���Щ������ǿ�ˡ�������˵���������߻��ӡ���Ϊ��Ӷʿ����
��ȥ����
LONG);

	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"beiyin2",
		"south" : __DIR__"beiyin4",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/jia" : 1,
		__DIR__"npc/kuli" : 2,
	]));
	set("no_fight", 1);
	set("no_magic", 1);
	set("resource", ([ /* sizeof() == 1 */
		"water" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_zhaomu", "zhaomu");
	add_action("do_money", "xiang");
	add_action("do_muji", "muji");
}

int do_zhaomu(string args)
{
	object me=this_player();

	if(!args || (args != "soilder"))
		return notify_fail("����ֻ����ļ��ʿ���������Ĵ�ҿ���û����Ȥ��Ŷ��\n");
	if(!me->query("office_number"))
		return notify_fail("�㻹û�������ء�������ɶ���뵱ǿ���췴���ɣ�\n");
	if(do_jun(me) >= (me->query("office_number")*10))
		return notify_fail("�����±�Ա�Ѿ����û�ж����ָ���ˡ�Ҫ����������ȥ������ҵ�ɣ�\n");
	message_vision("�����һ�½��ƺ�˦�ڵ��ϡ����ҵ����������˴�Ҿ����Ŀ�⡣�������������
����˵������û���˸���ȥ����ѽ��\n",me);
	tell_object(me,"�����������Ϊ��"+chinese_number(me->query("office_number")*10)+"�ˡ�Ŀǰȱ��:"+chinese_number(
	me->query("office_number")*10 - do_jun(me))+". \n");
	tell_object(me,"������Ҫ�Խ�Ǯ��Ϊ��Ǯ�ġ�û�о��û��߾���̫�ͣ���û����Ը������ߵġ�\n
ļ����Ҫ�ȸ�һ��ľ��ã��Ժ�Ͳ����ٻ�Ǯ�ˡ���Ҫ����������ļ����(���ʮ������)\n");
	tell_object(me,"������Ҫ��������(xiang)��\n");
	me->set_temp("zhaomu_ing",1);
	return 1;
}

int do_money(string arg)
{
	object me=this_player();
	int pts;
	
	if(!me->query_temp("zhaomu_ing"))
		return notify_fail("����Ҫ�����ҵ�ע����С�\n");
	if( !arg || !sscanf(arg, "%d", pts)) 
		return notify_fail("ָ���ʽ��yuexiang <ÿ��ÿ��ʿ��������>\n");
	if(pts<10)
		return notify_fail("��ô��Ǯ����ļ��ѽ���������Լ�ȥ���ˡ�\n");
	if(me->query("balance")/(1200*pts) < 100)
		return notify_fail("��Ĵ��̫�٣�����ȥ�跨��׬��Ǯ�����ɣ�\n");
	me->set("soilder_pay",pts);
	tell_object(me,"����Ŀǰ�Ĳ���������ļ����"+me->query("balance")/(1200*pts)+"�ˡ�\n");
	tell_object(me,"ʵ��ȱ�"+chinese_number((int)me->query("office_number")*10 - do_jun(me))+"����Ҫļ��������?\n");
	tell_object(me,"����muji <����> ������.\n");
	me->delete_temp("zhaomu_ing");
	me->set_temp("give_pay",1);
	return 1;
}

int do_muji(string arg)
{
	object me=this_player();
	int pts,train;

	if(!me->query_temp("give_pay")) return notify_fail("�㲻�����ʣ�˭����׸�ѽ��\n");
	if( !arg || !sscanf(arg, "%d", pts)) 
		return notify_fail("ָ���ʽ��muji <ʿ����>\n");
	if(pts > (me->query("office_number")*10 - do_jun(me)) ) 
		return notify_fail("�㲻��ļ�����������������������\n");
	message_vision("ֻ����ͷӿ������Щ��������֮ͽ�׷׹������������������һЩ����ȥ��׳֮�ˡ�\n",me);
	tell_object(me,"��������"+chinese_number(pts)+"��ʿ����\n");
	me->add("balance",-pts*1200);
	train=me->query("train_level")*me->query("soilder")+10*pts;
	me->add("soilder",pts);
	train=train/(me->query("soilder"));
	me->set("train_level",train);   //ʿ����ѵ���ȡ�
	message("vision",HIY+"������챨��:"+me->query("name")+"�ڳ����ƹ�ļ����"+chinese_number(pts)+
"��ʿ��.\n"+NOR,users());
	me->delete_temp("give_pay");
	return 1;
}

int do_jun(object me)
{
	int soilder, i;
	
	soilder=me->query("soilder");
	for( i = 0; i < sizeof(city); i ++ ) {
		if( me->query("city/"+city[i]+"sold"))
			soilder += me->query("city/"+city[i]+"sold");
	}
	return soilder;
}
