inherit ITEM;

void create()
{
	set_name("��Ԫ��", ({"hunyuan dou","dou"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�˶����쳤�������ڲ���ذ�����\n");
		set("unit", "��");
		set("owner_name","�����ɹ�");
		set("owner_id","chi meng");
	}
}

