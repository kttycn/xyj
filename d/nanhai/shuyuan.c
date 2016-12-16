//Cracked by Roath
// Room: /d/nanhai/shuyuan
inherit ROOM;
#include <ansi.h>

string *strs = ({
	"�����ᣡһ�����ߣ����ǲ���˵��������֮��̰�����¡�\n",
	"�����ᣡ�����������£���Ӧ̰�����ǹ�˵���ܸ��¡�\n",
	"����ɫ���ң����������ң�������а�������ܼ�������\n",
	"�����ᣡ��������ʵ��������˵�ø��¶ࣻ�Ը����޹ʣ�����˵�ø��¶ࡣ\n",
	"�����ᣡ�����ƺΣ����������۲���\n",
	"���ǣ��������������ۡ�\n",
	"�����ᣡ�����ƺΣ����������۲���\n",
	"���ǣ��������������ۡ�\n",
	"�����ᣡ�����ƺΣ������л��۲���\n",
	"���ǣ����������л��ۡ�\n",
	"�����ᣡ�����ƺΣ������з��۲���\n",
	"���ǣ����������з��ۡ�\n",
	"�����ᣡ�����ƺΣ������з��۲���\n",
	"���ǣ����������з��ۡ�\n",
	"�����ᣡ�����ƺΣ����������ɳ����˵��ɳ����\n",
	"���ǣ���������˵��ɳ��\n",
});
     
void init();
void check_time(object where);
void nianjing(object where);
void finish_nianjing(object where);

void create ()
{
	set ("short", "��Ժ");
	set ("long", @LONG

�����������ɽ��Ժ������ϰ��������鼮������ɽ���˵���
��������߻�������ʶ�ֵģ�������������з������𷨵ģ�
���������޵�������
LONG);

	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"zoulang",
	]));
	set("objects", ([ /* sizeof() == 3 */
		"/d/obj/book/san.c" : 1,
		"/d/obj/book/staffbook" : 1,
		"/d/obj/book/jingang" : 1,
		__DIR__"npc/shami" : 1,
	]));
	set("light_up", 1);

	setup();
}

void init()
{
	remove_call_out("check_time");
	check_time(this_object());
	add_action("do_nianjing", "nianjing");
}

void check_time(object where)
{
	mixed *local = localtime(time()-900000000);
	int t = local[2] * 60 + local[1]; //Сʱ*60+����
	int phase=((int)(t%120));

	if(phase==73&&(!query("nanhai/start_nianjing"))) nianjing(where);
	if(phase==77&&query("nanhai/start_nianjing")) finish_nianjing(where);
	call_out("check_time",40,where);
}

void nianjing(object where)
{
	message("channel:es",HIY+"���Ϻ�����ɽ���ݰ�����(Xing zhe)�����˸������!\n"+NOR,users());
	where->set("nanhai/start_nianjing",1);
} 

int do_nianjing()
{ 
	object who=this_player();

	if(who->is_busy())
		return notify_fail("����æ���ء�\n");
	if(!this_object()->query("nanhai/start_nianjing"))
		return notify_fail("���������ʱ���ء�\n");
	if((string)who->query("family/family_name")!="�Ϻ�����ɽ")
		return notify_fail("���ɵ��Ӳ����������\n");
	tell_object( who,"���ü��Ŀ������΢�̣�"+strs[random( sizeof(strs) )] );
	who->start_busy(5);
	if ( (int)who->query("faith")<800 )
		who->add("faith",1);
	who->improve_skill("buddhism",random((int)(who->query("spi")+who->query("int"))/2),1);
	who->add("combat_exp",30);
	who->add("daoxing",30);
	who->add("potential",10);
	who->receive_damage("kee",20);
	who->receive_damage("sen",20);
	tell_object(who,"�������Ĵ�˷𷨽����ˣ�\n");
	return 1;
}

void finish_nianjing(object where)
{
	tell_object(where,"Ժ�⴫�������������ȴԭ���Ǿ��ν����ˡ�\n");
	tell_object(where,"�ݰ��������������λʦ�ֵ���ȥ�ɣ����ν�����!\n");
	where->delete("nanhai/start_nianjing");
}
