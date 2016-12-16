#include <ansi.h>
inherit NPC;
string ask_age()
{
        object me = this_player();
        object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;
        ob = filter_array(ob,
                (: $2->query("age")*12+$2->query("month")
                        < $1->query("age")*12+$1->query("month") :), me);
        no = sizeof(ob) + 1;
        return me->name()+RANK_D->query_respect(me)+"的年龄在【月影奇缘】目前中排名第"
                +chinese_number(no)+"。";
}
string ask_beauty()
{
        object me = this_player();
        object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;
        ob = filter_array(ob,
                (: $2->query("per")     < $1->query("per") :), me);
        no = sizeof(ob) + 1;
        return me->name()+RANK_D->query_respect(me)+"的容貌在【月影奇缘】目前中排名第"
                +chinese_number(no)+"。";
}
int ask_force()
{
        object me = this_player();
        object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;
        ob = filter_array(ob,
                (: $2->query("max_force")      < $1->query("max_force") :), me);
        no = sizeof(ob) + 1;
        command("say "+me->name()+RANK_D->query_respect(me)+"的内力在【月影奇缘】目前中排名第"
                +chinese_number(no)+"。");
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
        command("say "+me->name()+RANK_D->query_respect(me)+"的法力在【月影奇缘】目前排名第"
                +chinese_number(no)+"。");
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
        command("say "+me->name()+RANK_D->query_respect(me)+"的杀害玩家数在【月影奇缘】目前排名第"
                +chinese_number(no)+"。");
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
        command("say "+me->name()+RANK_D->query_respect(me)+"的杀害ＮＰＣ数在【月影奇缘】目前排名第"
                +chinese_number(no)+"。");
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
        command("say "+me->name()+RANK_D->query_respect(me)+"的武学在【月影奇缘】目前在线玩家中排名第"
                +chinese_number(no)+"。");
        message_vision(CYN "$N指着$n赞叹道：“"+me->name()+"是【月影奇缘】中第"
                +chinese_number(no)+"高手！”\n" NOR, this_object(), me);
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
        command("say "+me->name()+RANK_D->query_respect(me)+"的道行在【月影奇缘】目前在线玩家中排名第"
                +chinese_number(no)+"。");
        message_vision(CYN "$N指着$n赞叹道：“"+me->name()+"是【月影奇缘】中第"
                +chinese_number(no)+"高手！”\n" NOR, this_object(), me);
        return 1;
}

void create()
{
        set_name("唐僧",({"tang seng","seng","tang"}));
        set("gender","男性");
        set("age",40);
        set("per", 30);
        set("int", 30);
        set("kar", 30);
        set("str", 20);
        set("cor", 25);
        set("cps", 99);
        set("long", @LONG
他就是西天取经的唐僧了，佛法修为深不可测，西天取经造就无数生灵。
但是如果你要打听一些这个神话世界上的事情，他会很热心地告诉你。

打听年龄用 ask seng about age
打听容貌用 ask seng about beauty
打听道行用 ask seng about exp
打听ＰＫ用 ask seng about pk
打听法力用 ask seng about spells
打听内力用 ask seng about force
打听杀人用 ask seng about mk
打听道行用 ask seng about daoxing

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
        set("title", HIY "南无阿弥檀檽佛" NOR);
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

int accept_object(object me, object ob)
{
	int value;
	object ob1;

	if (ob->query("money_id") && (value=ob->value()) >= 100) 
	{
		message_vision("唐僧双手合十，微微一笑道：多谢施主了，愿我佛保估您。\n也罢，我就送你一程吧！\n\n唐僧一挥僧袍，映出五彩祥光，把$N围在当中........\n\n",me);
		tell_object(me,"你闭紧了双眼，耳中只听见风声呼呼........\n\n");		 
		me->move("/d/qujing/lingshan/daxiong");
		message_vision("\n\n一道五彩祥光闪过，$N从半空中掉了下来，跌了个大跟头。:(  \n\n$N慢慢从地上爬了起来，一边还揉着摔疼的腰。\n", me);
		me->start_busy(4);
		return 1;
	}
}