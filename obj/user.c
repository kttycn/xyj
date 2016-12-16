// user.c

#include <origin.h>
#include <ansi.h>
#include <user.h>
#include <command.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;
inherit F_BACKUP;
inherit F_ENCODING;

nosave int last_age_set;

void create()
{
	::create();
	set_name("ʹ�������", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
	message("system", "�ն˻���̬�趨Ϊ " + term_type + "��\n", this_object());
}

void reset()
{
	if( (int)query("potential") - (int)query("learned_points") < 100 )
		add("potential", 1);
	if( (int)query("thief") > 0 )
		add("thief", -1 );
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id;

	id = query("id", 1);
	if( !id ) id = geteuid();
	if( !id ) id = getuid();
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

// save(1) will only save player data, do not touch autoload.
// used by /feature/vendor_sale.
// normal save should use save() or save(0).
// mon 5/12/98
int save(int raw)
{
	int res;

	if(!raw) save_autoload();
	res = ::save();
	if(!raw) clean_up_autoload();		// To save memory
	return res;
}

int backup()
{
	int res;

	save_autoload();
	res = ::backup();
	clean_up_autoload();		// To save memory
	return res;
}

// This function updates player's age, called by heart_beat()
void update_age()
{
	// Update the time we spend on mudding, using method from TMI-2 mudlib.
    if(environment()&&environment()->query("no_time")){
        last_age_set = time();
        return;
    }
	if( !last_age_set ) last_age_set = time();
	add("mud_age", time() - last_age_set);
	last_age_set = time();
	set("age", 14 + ((int)query("mud_age") + (int)query("age_modify"))/86400);
	if((int)query("mud_age")%86400 < 10)
	{
		if(query("combat_exp")<1000) return;
		tell_object(this_object(),HIG"ף�����տ��֣���ϲ�㽫����ر���������\n"NOR);
		tell_object(this_object(),"ȥ����¥��ҹ����Ҫ��������ȥ�ɡ�\n");
		this_object()->set("birth",1);
	}
}

void setup()
{
	mapping	fabao_map;
	string  *fabao_list, *id_list, *t_list;
	int		i;
	object	newob;
	string  fabao_id;

	// We want set age first before new player got initialized with
	// random age.
	update_age();

	::setup();
	restore_autoload();

    // here We restore the self-made fabao
	fabao_map = query("fabao");
    if( !mapp(fabao_map) )
		return;

	fabao_list = keys(fabao_map);
	for(i=0; i<sizeof(fabao_list); i++)  {
        newob = new("/obj/fabao");
        if( newob )   {
            newob->set("owner_id", query("id"));
            newob->set("series_no", fabao_map[fabao_list[i]]);
            if( !newob->restore() )   {
				tell_object(this_object(), "���� restore fabao. \n");
				destruct(newob);
				continue;
			}
			fabao_id = (string)newob->query("id");
			if(!fabao_id) { // mon 9/5/98
			    destruct(newob);
			    continue;
			}
			fabao_id = replace_string(fabao_id, " ", "_");
			newob->set("id", fabao_id);
			seteuid(fabao_id);
			export_uid(newob);
			seteuid(getuid());

			id_list = ({ fabao_id });
			t_list = explode(fabao_id, "_");
			if( sizeof(t_list) > 1)   {
				id_list += t_list;
			}
			newob->set_name(newob->query("name"), id_list);
			if( stringp(newob->query("default_file")) )
				newob->set_default_object( newob->query("default_file") );

			newob->save();
            newob->move(this_object());
        }
    }
}

private void user_dump(int type)
{
	switch(type) {
		case DUMP_NET_DEAD:
			tell_room( environment(), query("name") + "���߳���"
				+ chinese_number(NET_DEAD_TIMEOUT/60)
			       	+ "���ӣ��Զ��˳�������硣\n");
		//	command("quit");
			// mon 7/5/98 to force quit.
			QUIT_CMD->main(this_object(),"",1);
			break;
		case DUMP_IDLE:
       if((!query("env/invisibility") && !environment(this_object())->query("chat_room")) && !wizardp(this_object())){
			tell_object( this_object(), "�Բ������Ѿ��������� " 
				+ IDLE_TIMEOUT/60 + " �����ˣ����´�������\n");
			tell_room( environment(), "һ��紵�����������е�" + query("name")
				+ "��Ϊһ�ѷɻң���ʧ�ˡ�\n", ({this_object()}));
			//command("quit");
			// mon 7/5/98
			QUIT_CMD->main(this_object(),"",1);
			return;
                      }
	              break;
		default: return;
	}
}

// net_dead: called by the gamedriver when an interactive player loses
// his network connection to the mud.
private void net_dead()
{
	object link_ob;

	if( objectp(link_ob = query_temp("link_ob")) )  {
	  if(!link_ob->is_character()) {
	    link_ob->set("last_on", time());
	    link_ob->set("last_from", query_ip_name(this_object()));
	    link_ob->save();
	  }
        }

	if( userp(this_object()) ) 
	    CHANNEL_D->do_channel(this_object(), "sys", "�����ˡ�",0,1);

	// used in logind for IP check
	set_temp("netdead_ip", query_ip_number(this_object()));

    remove_call_out("do_net_dead");
    call_out("do_net_dead",15);
}

// delay the actual net_dead mark to prevent
// use net_dead to avoid killing.
// mon 7/5/98
private void do_net_dead()
{
	object link_ob;

	if(!this_object()) return;

	// not net_dead any more.
	if(interactive(this_object())) return;

	set_heart_beat(0);
	if( objectp(link_ob = query_temp("link_ob")) )  {
	  destruct(link_ob);
        }

	// Stop fighting, we'll be back soon.
	add_netdead_enemy();
	remove_all_enemy();

	set_temp("netdead", 1);
	if( userp(this_object()) ) {
	    call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
	    if (!this_object()->query("env/invisibility"))
	        tell_room(environment(), query("name") + "�����ˡ�\n", this_object());
	} else {
		command("quit");
	}
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
	set_heart_beat(1);
	set_temp("netdead",0);
	remove_netdead_enemy();
	remove_call_out("user_dump");
	remove_call_out("do_net_dead");
	tell_object(this_object(), "����������ϡ�\n");
}

