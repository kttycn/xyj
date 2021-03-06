
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
                name = CYN"你";
        } else if (wizardp (me)) {
                ob = find_player(arg);
                if(!ob) ob = find_living(arg);
                if(!ob) ob = LOGIN_D->find_body(arg);
                if(!ob || !me->visible(ob)) return notify_fail("没有这个人。\n");
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

[1;36m【月影奇缘大闹天宫】[2;37;0m

──────────[1;31m【大闹天宫】[2;37;0m────────────

[33m〖[2;37;0m[36mhelp dntg1 [33m〗[2;37;0m    [37m寻访水帘洞，称王花果山[2;37;0m
[33m〖[2;37;0m[36mhelp dntg2 [33m〗[2;37;0m    [37m单骑闯龙宫，力挚千钧棒[2;37;0m
[33m〖[2;37;0m[36mhelp dntg3 [33m〗[2;37;0m    [37m大闹阎罗府，除名生死簿[2;37;0m
[33m〖[2;37;0m[36mhelp dntg4 [33m〗[2;37;0m    [37m官封弼马温，放马南天门[2;37;0m
[33m〖[2;37;0m[36mhelp dntg5 [33m〗[2;37;0m    [37m大败李天王，官拜齐天圣[2;37;0m
[33m〖[2;37;0m[36mhelp dntg6 [33m〗[2;37;0m    [37m偷吃仙蟠桃，气走七仙女[2;37;0m
[33m〖[2;37;0m[36mhelp dntg7 [33m〗[2;37;0m    [37m计赚赤脚仙，瑶池偷仙酒[2;37;0m
[33m〖[2;37;0m[36mhelp dntg8 [33m〗[2;37;0m    [37m醉闯兜率宫，偷吃灵丹药[2;37;0m
[33m〖[2;37;0m[36mhelp dntg9 [33m〗[2;37;0m    [37m大战灌江口，变化降杨戬[2;37;0m
[33m〖[2;37;0m[36mhelp dntg10[33m〗[2;37;0m    [37m练就火眼睛，脱困老君炉[2;37;0m

[33m〖[2;37;0m[36mdntg <某人>[33m〗[2;37;0m    [37m显示某人大闹天宫的资料。[2;37;0m

─────────────────────[35m【月影奇缘】[2;37;0m───

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
    write (name+"还没有做过大事。\n");
  }
  else
  {
    write (name+"大闹天宫已经过了"+chinese_number(nb)+"关：\n");
    who->set("dntg/number",nb);
    strs = (string *)sort_array (strs, 1);
    for (i = 0; i < nb; i++)
    {
      write (HIR"  ★"HIR+strs[i]+"\n"NOR);
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
    write (name+HIR"大闹天宫已经功德圆满 \n"NOR);
  }
  else
  {
    write (name+"大闹天宫还须过 "HIR+chinese_number(nb)+NOR+CYN" 关：\n");
    strs = (string *)sort_array (strs, 1);
    for (i = 0; i < nb; i++)
    {
      write ("    "+strs[i]+"\n");
    }
  }
  return 1;
}

