//stone 20020614
// /d/guzhanchang/obj/jiaosword.c

#include <weapon.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit SWORD;
void init();
void kaifengs();

void create()
{
        set_name(RED"���Խ�"NOR, ({ "jiaosword", "chijiao sword","sword" }));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", RED"һ��ɭɭ���⣬��������������������ְ���
ɫ�⻪����������һ���������ɣ����������
֮��������Ϊ��Ŀ���ഫ���и���֮ʿ����Ѫ��
�棨kaifengs)��"NOR);
		set("no_sell", "��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
		set("no_put", 1);
		set("no_drop", "��ôϡ���ı������㲻����ϧ��\n");
		set("no_give", "�����ǧ��һ����������а������������ˣ�\n");
		set("no_get", "�㱻���ϵ�ɷ��һ�ƣ�����һ����æ�����ض��³��Խ���\n");
		set("value", 30000);
		set("replace_file", "/d/obj/weapon/sword/xijian");
		set("material", "steel");		
		set("wield_msg", RED"$N������һ̽����ৡ���һ�����$n"+RED"����ʱ����һ��ҫĿ�ĳ��֮�⡣\n"NOR);
		set("unwield_msg", RED"��$Nһ�����ε�̾Ϣ�����һ����$N��$n������С�\n"NOR);
		set("weapon_prop/courage", 3);
	}
	init_sword(90);
	set("is_monitored",1);
	setup();
}

void init()
{
	add_action("do_kaifeng", "kaifengs");
}
int do_kaifeng(string arg)
{
	object who = this_player();
	object jiaosword;
	object newjiaosword;
	string newjiaosword_given;
	newjiaosword_given = "/d/guzhanchang/obj/jiaosword1.c";

	if(who->is_fighting())
		return notify_fail("���������أ���������\n");
	if(who->is_busy())
		return notify_fail("�㻹���⹤��?��æ����!\n");
	if(!jiaosword = present("jiaosword",who))
		return notify_fail("�㻹ȱ��"+RED "���Խ�" NOR +",��ô��ʩչ��Ѫ�����桹��?\n");
	if ( jiaosword->query("equipped")=="wielded" )
		return notify_fail("���Խ�����ժ�²��ܿ��棡\n");
	 if( (!arg) || !((arg == "jiaosword") || (arg == "���Խ�")))
                return notify_fail("��Ҫ��Ѫ����ʲô��\n");
        if( who->query("kee") < (int)(who->query("max_kee")/3))
//                who->receive_damage("kee",(int)who->query("max_kee")*20/100);
                return notify_fail("��������̫�أ�Ҫ��Ѫ����Ļ�����Ԧ���˳���Ѫ����\n"); 
        if( (int)who->query("force") < 1000 )
                return notify_fail("����������㣬Ҫ��Ѫ����Ļ������»��ܳ��Է��ɡ�\n");
        if( (int)who->query("mana") < 2000 )
                return notify_fail("��ķ���������ӯ������ʩչ��Ѫ�����桹��ͨ��\n");
        if( (int)who->query("bellicosity") < 100 )
                return notify_fail("���ɱ�������أ�����ʩչ��Ѫ�����桹��ͨ��\n");                                                                       
        if ( !(newjiaosword_given->in_mud()) ) 
	{			
		message_vision("$N������⣬������ֽ�ָ���¾�����ָͷ���ڽ��ϻ���......\n\n
"+HIR"$Nŭ�ȵ���������֮Ѫ��Ϊ�����棡��"NOR+"\n\n
"+RED"ͻ��������Ѫ�������ҫ��������񣬱�ֱ��ͦ��������̥���ǣ��쳣������"NOR+"\n
"+RED"�����ֳ�һ�������׶�ĳ��Բ��Ʒ���......"NOR+"\n
"+HIR"$N���еĳ��Խ���Ϊ������Ѫ������\n\n"NOR,who);
		message_vision("$N���ϸ��ֳ�һ˿��Ц......\n\n",who);
		newjiaosword= new("/d/guzhanchang/obj/jiaosword1");
		newjiaosword->move(who);
		who->add("kee", -(int)who->query("max_kee")*10/100);
//		who->add("max_kee", -(int)who->query("max_kee")*10/100);
		who->start_busy(4);
		destruct(this_object());
		MONITOR_D->report_rumor_object_msg(who, "��Ѫ��������õ��ˡ�"+HBRED"����Ѫ��"NOR+HIR"�� �ˣ�");		
	} else {
		message_vision("$N������⣬������ֽ�ָ���¾�����ָͷ���ڽ��ϻ���......\n\n
"+HIR"$Nŭ�ȵ���������֮Ѫ��Ϊ�����棡��"NOR+"\n\n
ֻ�����Խ���Ѫ�����һ�������Խ�����һ�����ֱ����������ʧ��...\n",who);
	}
	destruct(this_object());
	return 1;
}