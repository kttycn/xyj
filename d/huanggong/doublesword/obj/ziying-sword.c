// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

int do_hesword();

void create()
{
//      set_name(HIR"��"HIG"۫"HIC"��"NOR, ({ "ziying sword","sword","ziying","ziying-sword"}));
	set_name(MAG"��۫��"NOR, ({ "ziying-sword","sword","ziying sword"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","һ���Ž�,�����Ͽ���"+MAG"����۫��"NOR+"����,������һ�������������֡�\n");
		set("value", 9000);
		set("no_give","��ô�õı��������? ���뵳��û��? \n");
       		set("no_drop","��ô�õı����ȥ�� ! ԭ���Ա���û�¸�ѽ !!!\n");
       		set("no_sell", 1);
       		set("no_get", "�㱻�����ϵĺ���һ����һ�����£�����һ�ɣ����������л��䣡\n");
		set("material", "blacksteel");
		set("wield_msg",MAG"$N����΢�ţ�һ����������,�����Զ�����,����$N���֡�\n");
		set("unwield_msg","$N�Ҽ���ҡ,"+MAG"��۫��"NOR+"�����зɻ�����.\n");
		set("weapon_prop/spirituality", 3);
	}
	init_sword(130);//ԭ����100��������̫����
	set("is_monitored",1);
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
	string doublesword_given;
	doublesword_given = "/d/huanggong/doublesword/obj/doublesword.c";
//	qingsuojian="/d/ourhome/honglou/dreamland/obj/qingsuo-sword.c";

	if(who->is_fighting())
		return notify_fail("���������أ���������\n");
	if(who->is_busy())
		return notify_fail("�㻹���⹤��?��æ����!\n");
	if(!ziyingjian = present("ziying sword",who)) //�����٣�Ҫ����ziyingjian
		return notify_fail("�㻹ȱ��"+HIM "��۫��" NOR +",��ô["+HIR"˫���ϱ�"NOR+"]��?\n");
	if(!qingsuojian = present("qingsuo-sword",who)) //����qingsuojian
		return notify_fail("�㻹ȱ��"+HIC "������" NOR +",��ô["+HIR"˫���ϱ�"NOR+"]��?\n");
//	if( ! who->query("sword_hesword") == 1 ) 
//		return notify_fail("ûѧ˫���Ͻ�֮����ô�ҺϽ���?\n");
	if ( ziyingjian->query("equipped")=="wielded" || 
	qingsuojian->query("equipped")=="wielded" )
		return notify_fail("��������ժ�²���˫����赣�\n");
        if ( !(doublesword_given->in_mud()) ) //MUD��������˫��
	{
		message_vision("$N���Ὣ˫������,�������� !\n\n
ͻȻ,һ����������,"+MAG"����"NOR+"�Զ�����,����$N���� \n
$N�����һ��,һ����������,"+HIC"����"NOR+"�������,����$N����\n\n������һ��"+HIC"��"NOR+"����"+MAG"��"NOR+"����������,�ҽ����ں�...\n 
һ����Х��$N���ж��һ��"+HBRED"����˫��\n\n"NOR,who);
//		tell_object(who,"$N���ɵ�΢΢һЦ......\n");
		message_vision("$N���ɵ�΢΢һЦ......\n\n",who);
		doublesword = new("/d/huanggong/doublesword/obj/doublesword");
		doublesword->move(who);
		MONITOR_D->report_rumor_object_msg(who, "�õ� ["+HBRED"����˫��"NOR+HIR"] �ˣ�");
	} else {
		message_vision("$N���Ὣ˫������,�������� !\n\nͻȻ,һ����������,"+MAG"����"NOR+"�Զ�����,����$N���� \n�������һ��,һ����������,"+HIC"����"NOR+"�������,����$N����\n\n������һ��"+HIC"��"NOR+"����"+MAG"��"NOR+"����������,�ҽ����ں�...\n
\n�ִ�Ƭ�̣�˫������һ����һ�ж���ʧ�ˡ�\n",who);
	}
	destruct(qingsuojian);
	destruct(ziyingjian);
	return 1;
}

