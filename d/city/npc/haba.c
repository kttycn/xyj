//hapagou.c ���͹�
#include <ansi.h>
#include <command.h>
string ask_me();
inherit NPC;

void create()
{
	set_name("÷��", ({ "meiling", "miss"}) );
	set("title", "�������д�");
	set("race", "����");
	set("gender", "Ů��" );
	set("age", 16);
	set("str", 22);
	set("int", 30);
	set("per", 30);
	set("con", 30);

	set("long",
"���ǲ����ݵ�Ů�д���������Ǻ������Ӵ��\n");
	set("combat_exp", 2000000);
	set("attitude", "friendly");

	set("max_kee", 10000);
	set("max_sen", 10000);
	set("inquiry", ([
		"������" : "������ǣ���Ҫ����\n",
		"������" :  (: ask_me :),
        "����"   : "�㣨help bobing����֪���ˡ�\n",
	]) );
	setup();
}

string ask_me()
{
        object* ob;
        int i;
        ob = users();

        if ( !wizardp(this_player()) ) return "����Ȩ�ٿ������ᣡ\n";

        for ( i=sizeof(ob); i>0; i-- ) {
                ob[i-1]->move("/d/city/bobing");
        }
        command("chat ������Ҫ�ۻ��ˣ���ҿ�����\n");
        return "�ã����ڲ�������ʽ��ʼ��ȫ�弯�ϣ�\n";
}
void init()
{
add_action("do_save","save");
add_action("do_smash","smash");
add_action("do_exert","call");
add_action("do_exert","quit");
add_action("do_exert","exert");
add_action("do_exert","exercise");
add_action("do_exert","dazuo");
add_action("do_exert","respirate");
add_action("do_exert","tuna");
add_action("do_exert","practice");
add_action("do_exert","lian");
add_action("do_exert","study");
add_action("do_exert","du");
}

int do_save(string arg)
{
        command("say "+this_player()->query("name")+"�����������̵ġ�\n");
        return 1;
}
int do_smash(string arg)
{
        command("say "+this_player()->query("name")+"����ʦ�����Ҳ����ɱ�˵ġ�\n");
        return 1;
}
int do_exert(string arg)
{
        command("say "+this_player()->query("name")+"��ר�Ĳ����ɣ�\n");
        return 1;
}
