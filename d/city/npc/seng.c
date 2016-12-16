#include <ansi.h>
inherit NPC;
string ask_age()
{
	object me = this_player();
	object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
	int no;
	ob = filter_array(ob,(: $2->query("age")*12+$2->query("month")
	< $1->query("age")*12+$1->query("month") :), me);
	no = sizeof(ob) + 1;
	return me->name()+RANK_D->query_respect(me)+"����������Ӱ��ԵĿǰ��������"
		+chinese_number(no)+"��";
}
string ask_beauty()
{
	object me = this_player();
	object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
	int no;
	ob = filter_array(ob,(: $2->query("per") < $1->query("per") :), me);
	no = sizeof(ob) + 1;
	return me->name()+RANK_D->query_respect(me)+"����ò����Ӱ��ԵĿǰ��������"
		+chinese_number(no)+"��";
}
int ask_force()
{
	object me = this_player();
	object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
	int no;
	ob = filter_array(ob,(: $2->query("max_force") < $1->query("max_force") :), me);
	no = sizeof(ob) + 1;
	command("say "+me->name()+RANK_D->query_respect(me)+"����������Ӱ��ԵĿǰ��������"
		+chinese_number(no)+"��");
	return 1;
}
int ask_spells()
{
        object me = this_player();
        object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;
        ob = filter_array(ob,
                (: $2->query("max_mana")      < $1->query("max_mana") :), me);
        no = sizeof(ob) + 1;
        command("say "+me->name()+RANK_D->query_respect(me)+"�ķ�������Ӱ��ԵĿǰ������"
                +chinese_number(no)+"��");
        return 1;
}
int ask_pk()
{
        object me = this_player();
        object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;
        ob = filter_array(ob,
                (: $2->query("PKS")      < $1->query("PKS") :), me);
        no = sizeof(ob) + 1;
        command("say "+me->name()+RANK_D->query_respect(me)+"��ɱ�����������Ӱ��ԵĿǰ������"
                +chinese_number(no)+"��");
        return 1;
}
int ask_mk()
{
        object me = this_player();
        object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;
        ob = filter_array(ob,
                (: $2->query("MKS")      < $1->query("MKS") :), me);
        no = sizeof(ob) + 1;
        command("say "+me->name()+RANK_D->query_respect(me)+"��ɱ���ΣУ�������Ӱ��ԵĿǰ������"
                +chinese_number(no)+"��");
        return 1;
}
int ask_exp()
{
        object me = this_player();
        object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;
        ob = filter_array(ob,
                (: $2->query("combat_exp")      < $1->query("combat_exp") :), me);
        no = sizeof(ob) + 1;
        command("say "+me->name()+RANK_D->query_respect(me)+"����ѧ����Ӱ��ԵĿǰ���������������"
                +chinese_number(no)+"��");
        message_vision(CYN "$Nָ��$n��̾������"+me->name()+"����Ӱ��Ե�е�"
                +chinese_number(no)+"���֣���\n" NOR, this_object(), me);
        return 1;
}
int ask_daoxing()
{
        object me = this_player();
        object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;
        ob = filter_array(ob,
                (: $2->query("daoxing")      < $1->query("daoxing") :), me);
        no = sizeof(ob) + 1;
        command("say "+me->name()+RANK_D->query_respect(me)+"�ĵ�������Ӱ��ԵĿǰ���������������"
                +chinese_number(no)+"��");
        message_vision(CYN "$Nָ��$n��̾������"+me->name()+"����Ӱ��Ե�е�"
                +chinese_number(no)+"���֣���\n" NOR, this_object(), me);
        return 1;
}

void create()
{
        set_name("��ɮ",({"tang seng","seng"}));
        set("gender","����");
        set("age",40);
        set("per", 30);
        set("int", 30);
        set("kar", 30);
        set("str", 20);
        set("cor", 25);
        set("cps", 99);
        set("long", @LONG
����������ȡ������ɮ�ˣ�����Ϊ��ɲ⣬����ȡ������������顣
���������Ҫ����һЩ����������ϵ����飬��������ĵظ����㡣

���������� ask seng about age
������ò�� ask seng about beauty
���������� ask seng about exp
�����У��� ask seng about pk
���������� ask seng about spells
���������� ask seng about force
����ɱ���� ask seng about mk
���������� ask seng about daoxing
LONG);
        set("daoxing",1000000);
        set("combat_exp", 12345);
        set("max_force", 5000);
        set("class","bonze");
        set("force", 5000);
        set("max_mana", 7000);
        set("mana", 7000);
        set("max_sen", 5000);
        set("sen", 5000);
        set("max_kee", 5000);
        set("kee", 5000);
        set_skill("buddhism", 999);
        set_skill("spells", 412);
        set_skill("dodge", 21);
        set_skill("parry", 44);
        set_skill("force", 4);
        set_skill("literate", 973);
        set("title", HIY "���ް���̴����" NOR);
        set("attitude", "friendly");
        set("inquiry",([
                "spells": (: ask_spells :),
                "force": (: ask_force :),
                "pk": (: ask_pk :),
                "mk": (: ask_mk :),
                "age": (: ask_age :),
                "beauty": (: ask_beauty :),
                "exp": (: ask_exp :),
                "daoxing" : (: ask_daoxing :),
        ]) );
        setup();
        carry_object("/d/obj/cloth/jia_sha")->wear();
        
}
