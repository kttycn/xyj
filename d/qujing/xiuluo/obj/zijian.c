// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
int do_hesword();

void create()
{
        set_name(HIR"��"HIG"۫"HIC"��"NOR, ({ "ziying sword","sword","ziying"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("unit", "��");
		set("long","һ���Ž�,�����Ͽ���"+MAG"����۫��"NOR+"����,������һ��������������.\n");
		set("value", 9000);
		set("no_give","��ô�õı��������? ���뵳��û��? \n");
        set("no_drop","��ô�õı����ȥ�� ! ԭ���Ա���û�¸�ѽ !!!\n");
        set("no_sell", 1);
		set("material", "blacksteel");
		set("wield_msg",MAG"$N����΢�ţ�һ����������,�����Զ�����,����$N����.\n");
		set("unwield_msg","$N�Ҽ���ҡ,"+MAG"��۫��"NOR+"�����зɻ�����.\n");
	}
	init_sword(130);//ԭ����100��������̫����
	setup();
}

int init()
{
	add_action("do_hesword", "hesword");
	return 1;
}
int do_hesword()
{
	object who = this_player();
	object ziyingjian,qingsuojian;
	object doublesword;

	if(who->is_fighting())
		return notify_fail("���������أ���������\n");
	if(who->is_busy())
		return notify_fail("�㻹���⹤��?��æ����!\n");
         if(!ziyingjian = present("ziying sword",who))
		return notify_fail("�㻹ȱ��"+HIM "��۫��" NOR +",��ô["+HIR"˫���ϱ�"NOR+"]��?\n");
         if(!qingsuojian = present("qingsuo sword",who))
		return notify_fail("�㻹ȱ��"+HIC "������" NOR +",��ô["+HIR"˫���ϱ�"NOR+"]��?\n");
	if( ! who->query("sword_hesword") == 1 ) 
		return notify_fail("ûѧ˫���Ͻ�֮����ô�ҺϽ���?\n");
	message_vision("$N���Ὣ˫������,�������� !\n\nͻȻ,һ����������,"+MAG"����"NOR+"�Զ�����,���������� \n�������һ��,һ����������,"+HIC"����"NOR+"�������,����������\n\n������һ��"+HIC"��"NOR+"����"+MAG"��"NOR+"����������.�ҽ����ں� 
\nһ����Х,�����ж��һ��"+HBRED"����˫��\n\n"NOR,who);
	message("channel:rumor",HIR+"��ҥ�ԡ�ĳ�ˣ�"+who->query("name")+"�õ� ["+HBRED"����˫��"NOR+HIR"] �ˣ�\n"+NOR,users() );
	tell_object(who,"�㲻�ɵ�΢΢һЦ......\n");
	doublesword = new("/d/obj/weapon/sword/doublesword");
	doublesword->move(who);
	destruct(qingsuojian);
	destruct(this_object());
	return 1;
}
