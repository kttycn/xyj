//stone 20020613
///d/guzhanchang/dong.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "�ڶ�");
  set ("long", @LONG

ˮ����������������С�����У��Էɿ���ٶȣ���ת��������ȥ��
����ʹ��������е����ģ�ˮ���Ŀ콵ʹ����С�����໥��������
�ϻ��ۣ������һ��˶���ޱȵĴ����У����е����ľ�Ȼ����һ
�������������ײ�����һ����С��ȱ�ڣ�̶ˮ�ʹ������й������
ȱ��������ɲ⣬����㲻�Ͽ죨[1;35mout[m���Ļ����������Ҫ
���ڶ����ɣ�

LONG);
  setup();
}

void init()
{
        object ob = this_player();
        remove_call_out("down");
        call_out("down",2,ob);
        add_action("do_out","out");
}
int do_out()
{
    object ob = this_player();

    string place = "/d/guzhanchang/tandi1";
    place[strlen(place)-1] = '0'+random(11);

    message_vision(HIC"ֻ��$N��ץ�ŵţ�����ȫ�����ʹ��ƴ�õص�����������������\n"NOR,ob);
    ob->move(place);
    return 1;
}

void down(object ob)
{

        message_vision(HIW"$N�����Լ��������Ѿ�����ס���е�ǣ����$N���󿴼����Եظ���ţͷ��������������\n",ob);
        message_vision("����$N���һ��Ԫ���ĺľ���$N������Ϳ�Ҫ���ڰ�֮Ԩ��û�ˣ�����\n"NOR,ob);
        ob->add("kee",-50);
//        ob->start_busy(2);
}

