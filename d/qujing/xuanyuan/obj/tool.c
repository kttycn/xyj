
inherit ITEM;
void create()
{
        set_name("��ǯ", ({"tool"}));
        set_weight(1000);
                set("unit", "��");
                set("value", 50);
                set("material", "wood");
                set("wield_msg", "$N��$n�������У�\n");

     set("no_get",1);
        setup();
}
void init()
{
add_action("do_make", "zao");
}
int do_make(string arg)
{
   object me=this_player();
   string env;
   if(!me->query("gm/dan"))
     return notify_fail("���������������?��ô����ô����\n");
   if(!arg && arg != "dan" )
     return notify_fail("��Ҫ��ʲô��\n");

  if(me->is_busy())
    return notify_fail("����æ���أ�\n");
   env=environment(me)->query("short");
  if(env!="[1;33m������[m")
     return notify_fail("������ʲô������\n");

   if((int)me->query("kee") <80)
     return notify_fail("��̫���ˣ�ЪЪ�ɣ�\n");
message_vision("$N�����ǯ,������¯�еĻ������ˡ�\n", me);
   me->start_busy(2);
call_out("zhai1",1,me);
call_out("zhai2",2,me);
call_out("zhai3",3,me);
call_out("zhai4",4,me);
   return 1;
}
void zhai1(object me)
{
   message_vision("$N��һ�Ѳ�ҩ�Ž�������¯��\n", me);
}
void zhai2(object me)

{
   message_vision("$Nֻ��һ��Ĺ���¯�еĲ�ҩ�����һ����ɫ������\n",
me);
}
void zhai3(object me)
{
   message_vision("$N�������ȷ磬¯�еĻ�����ˡ���ʱ$N������һ���ɵ���\n", me
);
}
void zhai4(object me)
{
   object where=environment(me);
	object dan=new("/d/qujing/xuanyuan/obj/foxdan");
   dan->move(me);
   me->delete("gm/dan");
   tell_object(me,"���¯��ȡ�������õ��ɵ���\n");
   me->add("sen", -50);
   me->add("faith",1);
   me->add("potential",8);
   me->add("combat_exp",10);
}
