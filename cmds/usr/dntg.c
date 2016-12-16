
inherit F_CLEAN_UP;

#include <ansi.h>
#include <dntg.h>

int telling1 (object who);
int telling2 (object who);

string name;

int main(object me, string arg)
{
        object ob;

        if( !arg ) {
                ob = me;
                name = CYN"��";
        } else if (wizardp (me)) {
                ob = find_player(arg);
                if(!ob) ob = find_living(arg);
                if(!ob) ob = LOGIN_D->find_body(arg);
                if(!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");
                name = ob->query("name");
        } else
                return 0;

        telling1(ob);
        telling2(ob);

        return 1;
}

int help()
{
        write(@TEXT

[1;36m����Ӱ��Ե�����칬��[2;37;0m

��������������������[1;31m�������칬��[2;37;0m������������������������

[33m��[2;37;0m[36mhelp dntg1 [33m��[2;37;0m    [37mѰ��ˮ��������������ɽ[2;37;0m
[33m��[2;37;0m[36mhelp dntg2 [33m��[2;37;0m    [37m���ﴳ��������ֿǧ����[2;37;0m
[33m��[2;37;0m[36mhelp dntg3 [33m��[2;37;0m    [37m�������޸�������������[2;37;0m
[33m��[2;37;0m[36mhelp dntg4 [33m��[2;37;0m    [37m�ٷ������£�����������[2;37;0m
[33m��[2;37;0m[36mhelp dntg5 [33m��[2;37;0m    [37m������������ٰ�����ʥ[2;37;0m
[33m��[2;37;0m[36mhelp dntg6 [33m��[2;37;0m    [37m͵������ң���������Ů[2;37;0m
[33m��[2;37;0m[36mhelp dntg7 [33m��[2;37;0m    [37m��׬����ɣ�����͵�ɾ�[2;37;0m
[33m��[2;37;0m[36mhelp dntg8 [33m��[2;37;0m    [37m�����ʹ���͵���鵤ҩ[2;37;0m
[33m��[2;37;0m[36mhelp dntg9 [33m��[2;37;0m    [37m��ս�཭�ڣ��仯�����[2;37;0m
[33m��[2;37;0m[36mhelp dntg10[33m��[2;37;0m    [37m���ͻ��۾��������Ͼ�¯[2;37;0m

[33m��[2;37;0m[36mdntg <ĳ��>[33m��[2;37;0m    [37m��ʾĳ�˴����칬�����ϡ�[2;37;0m

������������������������������������������[35m����Ӱ��Ե��[2;37;0m������

TEXT
        );
        return 1;
}

int telling1 (object who)
{
  int size = sizeof(obstacles);
  string *names = keys(obstacles);
  string *strs = allocate (size);
  int nb = 0;
  int i;

  for (i = 0; i < size; i++)
  {
    strs[i] = "none";
  }

  for (i = 0; i < size; i++)
  {
    if (who->query("dntg/"+names[i])=="done")
    {
      strs[nb] = obstacles[names[i]];
      nb++;
    }
  }
  if (nb == 0)
  {
    write (name+"��û���������¡�\n");
  }
  else
  {
    write (name+"�����칬�Ѿ�����"+chinese_number(nb)+"�أ�\n");
    who->set("dntg/number",nb);
    strs = (string *)sort_array (strs, 1);
    for (i = 0; i < nb; i++)
    {
      write (HIR"  ��"HIR+strs[i]+"\n"NOR);
    }
  }
  return 1;
}

int telling2 (object who)
{
  int size = sizeof(obstacles);
  string *names = keys(obstacles);
  string *strs = allocate (size);
  int nb = 0;
  int i;

  for (i = 0; i < size; i++)
  {
    strs[i] = "none";
  }

  for (i = 0; i < size; i++)
  {
    if (who->query("dntg/"+names[i])!="done")
    {
      strs[nb] = obstacles[names[i]];
      nb++;
    }
  }

  if (nb == 0)
  {
    write (name+HIR"�����칬�Ѿ�����Բ�� \n"NOR);
  }
  else
  {
    write (name+"�����칬����� "HIR+chinese_number(nb)+NOR+CYN" �أ�\n");
    strs = (string *)sort_array (strs, 1);
    for (i = 0; i < nb; i++)
    {
      write ("    "+strs[i]+"\n");
    }
  }
  return 1;
}

