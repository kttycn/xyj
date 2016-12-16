inherit ROOM;
#include <ansi.h>
string *strs = ({
	"�۱����ߣ�һһ��֮�������������롣һһ�����߰�ǧ��Ѯ��",
	"��������߱���Ҷ���޲����㡣һһ��Ҷ�����챦ɫ��",
	"����ɫ�У�����ɫ�⣻�������裩ɫ�У�����ɫ�⣻",
	"���ɫ�У������⣻���ɫ�У��������̹⣻",
	"ɺ�����꣬һ���ڱ�����Ϊӳ�Ρ�",
	"�����������ָ����ϣ�һһ���ϣ�����������",
	"һһ���䣬���������������������",
	"����ͯ�ӣ���Ȼ���У�һһͯ�ӣ��������������٤Ħ�ᣬ",
	"��Ϊ���",
	"��Ħ��⣬�հ���Ѯ������ͺϰ������£����ɾ�����",
	"�ڱ��д�ɫ�����ߡ�",
	"������������൱��ҶҶ��Ρ����Ҷ�䣬�������",
	"Ҷ����Ȼ���߱�����һһ��Ҷ���ݹ����ȶ�ʮ����Ѯ����Ҷǧɫ��",
	"�а��ֻ���������󣻡��������������̴��ɫ���������֣�",
	"��תҶ�䣬ӿ������������ƿ���д���������ɴ����������ǣ�",
	"�Ǳ����У�ӳ����ǧ��ǧ���磬һ�з��£�ʮ�������������֡�",
	"�������ѣ��൱�ε�һһ��֮���ۼ�����֦Ҷ��������������� ",
	"��Ϊ���룬�����Ĺۡ�",
});
void check_time(object where);
void nianjing(object where);
void finish_nianjing(object where);
int do_open(string arg);
int do_close(string arg);

void create()
{
	set("short", "��ʥ���±���");
	set("long",@LONG 

    ����һ�����Ĵ�������һ����Լ��ʮ��ߵķ��汦��ͨ��
���ҫ�ۡ������������ƣ����������������̴ľ������������һ����
ɼ����(gate)����
LONG );
	set("exits", ([
		"north" : __DIR__"taijie",
		"east" : __DIR__"zoulang3",
	])); 
	set("valid_startroom", 1);
    set("item_desc",([ 
        "gate" : "һ���������ߵ����ɼľ��ͭ���š�\n"
    ]));
	set("objects",([
		"/d/nanhai/npc/shami" : 1,
		__DIR__"npc/heshang" : 2,
	]));
	setup();
}
 
void init()
{
	remove_call_out("check_time");
	check_time(this_object());
	add_action("do_nianjing", "nianjing");
	add_action("do_open", "open");
	add_action("do_close", "close");
}

void close_gate()
{
	object room;

	if(!( room = find_object("/d/xuyi/frontgate")) )
		room = load_object("/d/xuyi/frontgate");
	if(objectp(room))
	{
		delete("exits/south");
		message("vision", "Сɳ����ǰ�Ѵ��Ź���������\n", this_object());
		room->delete("exits/north");
		message("vision", "ƹ��һ�����������˰Ѵ��Ź����ˡ�\n", room);
	}
} 

int do_close(string arg)
{
	if (!query("exits/south"))
		return notify_fail("�����Ѿ��ǹ��ŵ��ˡ�\n");

	if (!arg || (arg != "gate" && arg != "south"))
		return notify_fail("��Ҫ��ʲô��\n");

	message_vision("$N��Сɳ�ֵ��˵�ͷ��\n", this_player());

	remove_call_out("close_gate");
	call_out("close_gate", 2);

	return 1;
} 

int do_open(string arg)
{
	object room;

	if (query("exits/south"))
		return notify_fail("�����Ѿ��ǿ����ˡ�\n");

	if (!arg || (arg != "gate" && arg != "south"))
		return notify_fail("��Ҫ��ʲô��\n");

	if(!( room = find_object("/d/xuyi/frontgate")) )
		room = load_object("/d/xuyi/frontgate");
	if(objectp(room))
	{
		set("exits/south", "/d/xuyi/frontgate");
		message_vision("$Nʹ���Ѵ��Ŵ��˿�����\n", this_player());
		room->set("exits/north", __FILE__);
		message("vision", "֨��һ�����������˰Ѵ��Ŵ��ˡ�\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}

	return 1;
}

void check_time(object where)
{
	mixed *local = localtime(time()-900000000);
	int t = local[2] * 60 + local[1];
	int phase=((int)(t%120));

	if(phase==17&&(!query("xuyi/start_nianjing"))) nianjing(where);
	if(phase==20&&query("xuyi/start_nianjing")) finish_nianjing(where);
	call_out("check_time",40,where);
}

void nianjing(object where)
{
	message("channel:es",HIY+"����������ɽ����ʥ��ʦ������(Guoshiwang pusa)����ͽ�������!\n"+NOR,users());
	where->set("xuyi/start_nianjing",1);
} 

int do_nianjing()
{ 
	object who=this_player();

	if(who->is_busy())
		return notify_fail("����æ���ء�\n");
	if(!this_object()->query("xuyi/start_nianjing"))
		return notify_fail("���������ʱ���ء�\n");
	if((string)who->query("family/family_name")!="����ɽ")
		return notify_fail("���ɵ��Ӳ����������\n");
	tell_object( who,"���ü��Ŀ������΢�̣�"+strs[random( sizeof(strs) )] );
	who->start_busy(5);
	if ( (int)who->query("faith")<800 )
		who->add("faith",1);
	who->improve_skill("fumozhou",random((int)(who->query("spi")+who->query("int"))/2),1);
	who->add("combat_exp",30);
	who->add("daoxing",30);
	who->add("potential",10);
	who->receive_damage("kee",20);
	who->receive_damage("sen",20);
	tell_object(who,"�������ķ�ħ������ˣ�\n");
	return 1;
}

void finish_nianjing(object where)
{
	tell_object(where,"Ժ�⴫�������������ȴԭ���Ǿ��ν����ˡ�\n");
	tell_object(where,"�ݰ��������������λʦ�ֵ���ȥ�ɣ����ν�����!\n");
	where->delete("xuyi/start_nianjing");
}
