
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
                name = CYN"Äã";
        } else if (wizardp (me)) {
                ob = find_player(arg);
                if(!ob) ob = find_living(arg);
                if(!ob) ob = LOGIN_D->find_body(arg);
                if(!ob || !me->visible(ob)) return notify_fail("Ã»ÓĞÕâ¸öÈË¡£\n");
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

[1;36m¡¾ÔÂÓ°ÆæÔµ´óÄÖÌì¹¬¡¿[2;37;0m

©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[1;31m¡¾´óÄÖÌì¹¬¡¿[2;37;0m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤

[33m¡¼[2;37;0m[36mhelp dntg1 [33m¡½[2;37;0m    [37mÑ°·ÃË®Á±¶´£¬³ÆÍõ»¨¹ûÉ½[2;37;0m
[33m¡¼[2;37;0m[36mhelp dntg2 [33m¡½[2;37;0m    [37mµ¥Æï´³Áú¹¬£¬Á¦Ö¿Ç§¾û°ô[2;37;0m
[33m¡¼[2;37;0m[36mhelp dntg3 [33m¡½[2;37;0m    [37m´óÄÖÑÖÂŞ¸®£¬³ıÃûÉúËÀ²¾[2;37;0m
[33m¡¼[2;37;0m[36mhelp dntg4 [33m¡½[2;37;0m    [37m¹Ù·âåöÂíÎÂ£¬·ÅÂíÄÏÌìÃÅ[2;37;0m
[33m¡¼[2;37;0m[36mhelp dntg5 [33m¡½[2;37;0m    [37m´ó°ÜÀîÌìÍõ£¬¹Ù°İÆëÌìÊ¥[2;37;0m
[33m¡¼[2;37;0m[36mhelp dntg6 [33m¡½[2;37;0m    [37mÍµ³ÔÏÉó´ÌÒ£¬Æø×ßÆßÏÉÅ®[2;37;0m
[33m¡¼[2;37;0m[36mhelp dntg7 [33m¡½[2;37;0m    [37m¼Æ×¬³à½ÅÏÉ£¬Ñş³ØÍµÏÉ¾Æ[2;37;0m
[33m¡¼[2;37;0m[36mhelp dntg8 [33m¡½[2;37;0m    [37m×í´³¶µÂÊ¹¬£¬Íµ³ÔÁéµ¤Ò©[2;37;0m
[33m¡¼[2;37;0m[36mhelp dntg9 [33m¡½[2;37;0m    [37m´óÕ½¹à½­¿Ú£¬±ä»¯½µÑîê¯[2;37;0m
[33m¡¼[2;37;0m[36mhelp dntg10[33m¡½[2;37;0m    [37mÁ·¾Í»ğÑÛ¾¦£¬ÍÑÀ§ÀÏ¾ıÂ¯[2;37;0m

[33m¡¼[2;37;0m[36mdntg <Ä³ÈË>[33m¡½[2;37;0m    [37mÏÔÊ¾Ä³ÈË´óÄÖÌì¹¬µÄ×ÊÁÏ¡£[2;37;0m

©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[35m¡¾ÔÂÓ°ÆæÔµ¡¿[2;37;0m©¤©¤©¤

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
    write (name+"»¹Ã»ÓĞ×ö¹ı´óÊÂ¡£\n");
  }
  else
  {
    write (name+"´óÄÖÌì¹¬ÒÑ¾­¹ıÁË"+chinese_number(nb)+"¹Ø£º\n");
    who->set("dntg/number",nb);
    strs = (string *)sort_array (strs, 1);
    for (i = 0; i < nb; i++)
    {
      write (HIR"  ¡ï"HIR+strs[i]+"\n"NOR);
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
    write (name+HIR"´óÄÖÌì¹¬ÒÑ¾­¹¦µÂÔ²Âú \n"NOR);
  }
  else
  {
    write (name+"´óÄÖÌì¹¬»¹Ğë¹ı "HIR+chinese_number(nb)+NOR+CYN" ¹Ø£º\n");
    strs = (string *)sort_array (strs, 1);
    for (i = 0; i < nb; i++)
    {
      write ("    "+strs[i]+"\n");
    }
  }
  return 1;
}

