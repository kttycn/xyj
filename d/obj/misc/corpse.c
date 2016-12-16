
// toulu.c

inherit ITEM;

int decayed;

void create()
{
	set_name("����ʬ��", ({ "wutou corpse", "corpse" }) );
	set("long", "����һ����ͷʬ�塣\n");
	set("short","ʬ��");
	set("unit", "��" );
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
			say( query("name") + "��ʼ�����ˣ�����һ�����ŵĶ����\n" );
			switch(query("gender")) {
				case "����":{
					set_name("���õ���ͷ��ʬ", ({ "wutou corpse", "��ͷʬ��" }) );
					break;
				}
				case "Ů��":{
					set_name("���õ���ͷŮʬ", ({ "wutou corpse", "��ͷʬ��" }) );
					break;
				}
				default:{
					set_name("���õ���ͷʬ��", ({ "wutou corpse", "��ͷʬ��" }) );
					break;
				}
//by maxim jiang 1997.7.15

			}
			set("long","�����ͷʬ����Ȼ�Ѿ���������һ��ʱ���ˣ���ɢ����һ�ɸ��õ�ζ����\n");
			call_out("decay", 120, phase + 1);
			break;
		case 2:
			say( query("name") + "���紵Ǭ�ˣ����һ�ߺ��ǡ�\n" );
			set_name("һ�߿�Ǭ��û��ͷ�ǵĺ��ǡ�", ({ "haigu", "����" }) );
			set("long", "�⸱�����Ѿ���������ܾ��ˡ�\n");
			call_out("decay", 600, phase + 1);
			break;
		case 3:
			say( "һ��紵������" + query("name") + "���ɹǻҴ�ɢ�ˡ�\n" );
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
