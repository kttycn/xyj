//Cracked by Roath
inherit F_CLEAN_UP;
int main(object me,string arg)
{
   object ob;
if(!arg) return notify_fail("��Ҫdetectʲô��\n");
  ob= present(arg,environment(me));
if(!ob) return notify_fail("û���������\n");
if(interactive(ob)) {write("���"+ob->query("name")+"("+ob->query("id")+")Ϊ��interactive��\n");return 1;}
else return notify_fail("�����Ϊ non-interactive\n");
}
