// stone 20020617
//sealpaper.c

inherit ITEM;

void create()
{
	set_name("��ֽ", ({"seal paper", "paper"}));
	set_weight(50);
	if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long","����һ�Ż�ֽ��ֽ����һЩģģ�������ּ�����ϧ�Ѿ���������ˡ�\n");
	set("unit", "��");
	set("value", 0);
	}
	setup();
}

