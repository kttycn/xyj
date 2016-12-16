//Cracked by Roath
inherit F_CLEAN_UP;
#include <dbase.h>
#include <login.h>
#include <ansi.h>

string *quest_lib=({
        "/d/obj/quest/quest_am.c",
        "/d/obj/quest/quest_cl.c",
        "/d/obj/quest/quest_fd.c",
        "/d/obj/quest/quest_fn.c",
        "/d/obj/quest/quest_wp.c",
//        "/d/obj/quest/quest_kl.c",
//        "/d/obj/quest/quest/wr.c",
});

string *quest_fail_msg = ({
    "���˿��㣬Ȼ����ʧ����ҡ��ҡͷ��ʲôҲ��˵��\n",
    "�������������������ƺ��ַ�����������ֻ���������һ����\n",
    "������ʣ���ʲô���������û���ã�����������\n"
    "��ɥ�������㣬����˵���������Ժ�ʧ����\n",
    "̾�˿����������������������ߣ���֪��ȴ��˹������ҵĿ���...��\n",
    "ҡ��ҡͷ�����ұ���Ӧ������ȥ��......��\n",
    "���һ�����������㾹����˲����ã�������\n",
    "������ļ�򣺡���Ҫ���ģ���֪���㾡����...��\n",
    "������ҡ��ҡͷ��˵����������¶�������.....��ȥ�ɡ���\n",
    "����ȥ�ܲ����ˣ�������üͷ����˵������ȥЪ�Űɡ�������\n"
    "������ţ�������û�á���������\n",
    "�ɻ�ؿ����㣺����ô���£���ô�㡣������\n",
    "ʧ���ؿ����㣬������ת��ͷȥ������������˵��ȥ�ˡ�\n",
    "�µ������Ǹ���Ͱ��\n",
    "һ���Դ���̾Ϣ����Ҳ�գ�Ҳ�ա�Ϊʦ����������Ϊͽ�ġ�\n"
});
string *quest_delay_msg = ({
    "�ƺ���Щ����������ô���ڲŰ������£����㡣������\n",
    "�ܲ����˵ؿ��������ۣ�һ�Բ������ְ�����ת�˹�ȥ������\n",
    "������һ�ۣ����������£����ڲŻ���....��\n",
    "���ǹ�ŭ����������˵��������ô���ڲŻ�����������\n",
    "�Ͱ���Ц��Ц������Ӧ��������ѽ....���˰�....��\n",
    "����ʧ����̾�˿���˵������������ô���ĥ�䣿����\n",
    "�����е����������о�������������˼���Ϊ�������أ�\n",
    "���ߵ�˵����ô����������Ҫô��ﹰ�����ˡ�\n",
    "һ���ò��ͷ����㻹֪��������������\n",
    "���ߵĺ�������С�£�ҲҪ��ô��ʱ�䣡\n",
});

int time_period(int timep, object me);

private string get_quest_fail_msg();
private string get_quest_delay_msg();
/////////////////////////////////////////////////////////////////////////////
int give_reward(object me,mapping quest)
{
    int bonus,num;
    
    bonus = quest["bonus"];
    bonus += random(bonus);
  me->add("combat_exp",4*bonus/5);
    me->add("potential",bonus/3);
    me->add( "faith", 1);
    tell_object(me,HIW"����ҳ϶������ˡ��㻹�õ���"+chinese_number(bonus*3/4)+
                "��ʵս�����"+chinese_number(bonus/5)+"��Ǳ�ܡ�\n"NOR);
    
    num=me->query_temp("quest_number");
    num++;
    if(num==10){
        num=0;
        me->add("combat_exp",500);
        me->add("potential",200);
        tell_object(me,HIW"��õ���"+chinese_number(500)+
                "��ʵս�����"+chinese_number(200)+"��Ǳ�ܵĸ��ӽ�����\n"NOR);
    }             
    me->set_temp("quest_number",num);   
    return 1;
}

int give_quest(object me,object ob)
{
    mapping quest ;
    int j,timep;  
    string tag ;

if( time() - me->query("cancel_time") < 30)
        {
         tell_object(me,ob->name()+"һ���Ĳ�����:������鶼�ɲ���,���������������!\n");
         return 1;
        }
    if ( !me->is_apprentice_of(ob) )  
    {
         tell_object(me,ob->name()+"�ɻ�ؿ����㣺����λ"+RANK_D->query_respect(me)+"��Ҫ��ʲô����\n");
         return 1;
    }
    if ( quest = me->query( "fy_quest" ) )
    {
           if ( me->query("task_time") && me->query("task_time") < time() )
           {
              if ( !quest["delay_msg"] )
                  tell_object( me, ob->name() + get_quest_delay_msg() );
              else
                  tell_object( me, replace_string(quest["quest_msg"],"$N",ob->query("name")));
              me->delete_temp("quest_number");
              me->delete("fy_quest");        
              me->delete("done_quest");
          }else if ( me->query("done_quest") == quest["quest"] ){
              tell_object( me, replace_string(quest["reward_msg"],"$N",ob->query("name")));
              give_reward(me,quest);
              me->delete("done_quest");
              me->delete("fy_quest");
              return 1;
          }
          else{
          tell_object(me,ob->name()+"�ɻ�ؿ����㣺����λ"+RANK_D->query_respect(me)+"���ǻ�������ô����\n");
          return 1;
        }
    }
    
    // �����ȹ���һ��quest��
         seteuid(getuid());
    quest = quest_lib[random(sizeof(quest_lib))]->query_quest(me);
    tell_object(me,replace_string(quest["quest_msg"],"$N",ob->query("name")));
    if ( quest["send_ob"] )
        new( quest["send_ob"] )->move(me);
    me->set("fy_quest", quest);
    me->delete("task_time");
    if (!(timep = quest["time"]))timep = 400+random(200);
    time_period( timep, me );
    me->set("task_time", time() + timep);
    return 1;
}

int time_period(int timep, object me)
{
    int t, d, h, m, s;
    string time;
    t = timep;
    s = t % 60; t /= 60;
    m = t % 60; t /= 60;
    h = t % 24; t /= 24;
    d = t;

    if ( d ) time = chinese_number(d) + "��";
    else time = "";

    if ( h ) time += chinese_number(h) + "Сʱ";
    if ( m ) time += chinese_number(m) + "��";
    time += chinese_number(s) + "��";

    tell_object(me,HIW "����" + time + "��ʱ��\nȥ�����ʦ����������\n"NOR);
    return 1;
}

int accept_object(object me, object who, object ob )
{
    mapping quest;

    if ( !me->is_apprentice_of(who))
    {
//        tell_object( me, who->name() + "�ɻ�ؿ����㣺��λ" +
  //          RANK_D->query_respect(me) + "��ʲô��˼��\n" );
        return 0;
    }
    if ( !(quest = me->query("fy_quest")))
    {
        tell_object(me, who->name() + "Ц��������Ҷ�����ʲô��\n");
        return 0;
    }
    if ( "��" + ob->query("name") != quest["quest"] || userp(ob) )
    {
        tell_object(me, who->name() + "��ü˵���ҵ����ɲ�������ȥ�����ѽ��\n");
        return 0;
    }
    if ( me->query("task_time") && ( me->query("task_time") < time() ) )
    {
        if ( !quest["delay_msg"] )
            tell_object( me, who->name() + get_quest_delay_msg() );
        else
            tell_object(me, quest["delay_msg"]);
        me->delete("fy_quest");
        me->delete_temp("quest_number");
        return 1;
    }
    else
    {
        tell_object( me, replace_string(quest["reward_msg"],"$N",who->query("name")));
        give_reward(me,quest);
        me->delete("fy_quest");
        return 1;
    }
}

string get_quest_fail_msg()
{
    return quest_fail_msg[ random( sizeof( quest_fail_msg ) ) ];
}

string get_quest_delay_msg()
{
    return quest_delay_msg[ random( sizeof( quest_delay_msg ) ) ];
}

int main(object me, string arg)
{
    object* inv;
  mapping quest;
    int i,nowtime;
    
    inv=all_inventory(environment(me));
    for(i=0;i<sizeof(inv);i++){
        if(me->is_apprentice_of(inv[i])){
           if(arg=="cancel"){
                if( me->query("faith")<50 )
                 return notify_fail("��ʦ�����ڻ����Ǻ������㣬����ȥ���ɡ�\n");
                else
                me->add("faith",-2);
                me->delete_temp("quest_number");
                me->delete("fy_quest");
                me->set("cancel_time",time());
                tell_object(me,inv[i]->query("name")+get_quest_fail_msg());
           }else
           give_quest(me,inv[i]);
           return 1;
        }
    }
    if(!(quest =  me->query("fy_quest")))
               return notify_fail("������û������\n");
    write("�����ڵ�������" + "��" + quest["quest"] + "����\n");
    nowtime = (int) me->query("task_time") - time();
    if( nowtime  > 0 )
                time_period(nowtime, me);
        else
                write("�������Ѿ�û���㹻��ʱ����������ˡ�\n");    
    return 1;
}

