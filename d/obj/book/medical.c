// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

inherit ITEM;

void create()
{
	set_name("��ҩ����", ({"medical", "book"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name": "medical",
			"sen_cost": 20,
			"difficulty": 20,
			"max_skill":100,
		]) );
	}
}

