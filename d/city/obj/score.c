// score by cnd 2000

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(""HIY"��Ӱ��Ե���а�"NOR"", ({"score"}));
        set("long", "��Ӱ��Ե�ĸ���������������read������\n");
     set("no_get", "���ò���������������\n");
}

void init()
{
  add_action("do_read","read");
  add_action("do_list","list");
}

int do_list(string arg)
{
	string type;
	type="/adm/daemons/toptend"->query_type();
	write(type);
	return 1;
}

int do_read(string type)
{
	write("/adm/daemons/toptend"->topten_query(type));
	return 1;
}
