inherit ITEM;
void create()
{
	set_name( "����ɽ������", ({ "book", "shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����д�������������,��������һ��������ɽ��ʦ�ɷ����顣\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name": "taoism",
			"dx_required": 1000,
			"sen_cost": 30,
			"difficulty": 30,
			"max_skill": 50,
		]) );
	}
}

