// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;

void create()
{
	set_name("兵器架", ({ "rack" }) );
	set_weight(500000);
	set_max_encumbrance(40000);
	if( clonep() ) {
		object a,b,c,d,e;
		seteuid(getuid());
		if(a=new("/d/obj/weapon/halberd/huaji"))
			a->move(this_object());

		seteuid(getuid());
		if(d=new("/d/obj/weapon/hammer/hammer"))
			d->move(this_object());

		seteuid(getuid());
		if(b=new("/d/obj/weapon/sword/changjian"))
			b->move(this_object());

		seteuid(getuid());
		if(e=new("/d/obj/weapon/halberd/halberd"))
			e->move(this_object());

		set_default_object(__FILE__);
	} else {
		set("unit", "个");
		set("long", "这是一口寻常的架子，可以用来堆放一些杂物。\n");
		set("value", 0);
	}
}

int is_container() { return 1; }
