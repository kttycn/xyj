#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        object ob;
        string pet_id;
        string *id_list, *t_list;       
        if (!me->query("pet/pet_id"))
          return notify_fail("�����ڲ�û�������\n");
        if (environment(me)->query("short")=="��̨")
           return notify_fail("��̨����ô�ܽг����æ��\n");
        pet_id=me->query("pet/pet_id");
        id_list = ({ pet_id });
        t_list = explode( pet_id, " ");
        if( sizeof(t_list) > 1 )   {
                id_list += t_list;
        }
        ob=find_player(pet_id);
if( !ob ) ob=find_living(pet_id);
        if( !ob ) ob = LOGIN_D->find_body(pet_id);
        if( !ob ) {
                ob=new("/d/eastway/npc/pet");
                ob->set("owner",getuid(me));
                  ob->restore();
                ob->set_name(ob->query("name"),id_list);
                 ob->set("default_actions", (: call_other, "/adm/daemons/race/beast.c", "query_action" :));
                ob->setup();
        } else if (ob->query("owner") != me->query("id"))
                   return notify_fail("������ĳ��ﲻ������Ļ��ˣ��㻹������ȥ���Ұɣ�\n");
        ob->move(environment(me));
        message_vision("$Nһ�����ڣ�$n�˷ܵش�Զ����$N������\n",me,ob);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ�� recall

���ָ����������ٻ�����ʧ�ĳ��
HELP
 );
        return 1;
}

