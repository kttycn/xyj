
// toulu.c

inherit ITEM;

int decayed;

void create()
{
	set_name("无名尸体", ({ "wutou corpse", "corpse" }) );
	set("long", "这是一具无头尸体。\n");
	set("short","尸体");
	set("unit", "具" );
	set_weight(2000);
	decayed = 0;
	if( clonep(this_object()) ) call_out("decay", 180, 1);
}

// int is_corpse() { return decayed < 2; }
// int is_character() { return decayed < 1; }
// int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }


void decay(int phase)
{
	decayed = phase;
	switch(phase) {
		case 1:
			say( query("name") + "开始腐烂了，发出一股难闻的恶臭。\n" );
			switch(query("gender")) {
				case "男性":{
					set_name("腐烂的无头男尸", ({ "wutou corpse", "无头尸体" }) );
					break;
				}
				case "女性":{
					set_name("腐烂的无头女尸", ({ "wutou corpse", "无头尸体" }) );
					break;
				}
				default:{
					set_name("腐烂的无头尸体", ({ "wutou corpse", "无头尸体" }) );
					break;
				}
//by maxim jiang 1997.7.15

			}
			set("long","这具无头尸体显然已经在这里有一段时间了，正散发著一股腐烂的味道。\n");
			call_out("decay", 120, phase + 1);
			break;
		case 2:
			say( query("name") + "被风吹乾了，变成一具骸骨。\n" );
			set_name("一具枯乾的没有头骨的骸骨。", ({ "haigu", "骸骨" }) );
			set("long", "这副骸骨已经躺在这里很久了。\n");
			call_out("decay", 600, phase + 1);
			break;
		case 3:
			say( "一阵风吹过，把" + query("name") + "化成骨灰吹散了。\n" );
			if( environment() ) {
				object *inv;
				int i;

				inv = all_inventory(this_object());
				for(i=0; i<sizeof(inv); i++) inv[i]->move(environment());
			}
			destruct(this_object());
			break;
	}
}
