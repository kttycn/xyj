// quit.c

#include <command.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void do_quit(object, object);
int do_drop(object me, object obj);

void create() 
{
	seteuid(getuid());
	set("name", "����ָ��");
	set("id", "quit");
}

// if force_quit==1, then don't check whether allow quit.
// used by quit after disconnected or idled too long.
// mon 7/5/98
int main(object me, string arg, int force_quit)
{
	int dx, exp, mana, force;
	object link_ob;
	int flag = 0;

	dx = me->query("daoxing")-me->query_temp("temp/daoxing");
	exp = me->query("combat_exp")-me->query_temp("temp/combat_exp");
	mana = me->query("max_mana")-me->query_temp("temp/max_mana");
	force = me->query("max_force")-me->query_temp("temp/max_force");

	if (me->query_temp("quit"))
		return notify_fail("�����˳������У����Ժ�\n");
	link_ob = me->query_temp("link_ob");

	if(!force_quit) {
		if ( me->query_temp("no_move") )
			return notify_fail("�㱻��ס�ˣ������˵ó���Ϸ��\n");

		if(me->query_temp("quit_noway"))
			return notify_fail("�����ڲ����˳���Ϸ��\n");// xintai 1/29/2001

		if(!me->query_temp("suicide_countdown")) {
			if( me->is_busy() )
				return notify_fail("( ����һ��������û����ɣ������˳���)\n");
		} //to allow halt suicide :D by mon 9/9/97

		if( !wizardp(me) && environment(me) && 
		environment(me)->query("no_quit") && link_ob )
			return notify_fail("���ﲻ׼�˳���Ϸ��\n");
	}

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {
		// Are we possessing in others body ?
		if( link_ob->is_character() ) {
			write("��Ļ��ǻص�" + link_ob->name(1) + "�����ϡ�\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
	}
	if( me->is_busy()) return notify_fail("��������æ���������£������˳���Ϸ��\n");
	if (me->query_temp("sleeped")) me->set("marks/insleeping",1);

	if( me->over_encumbranced() )
		return notify_fail("���ϴ��Ķ���̫���ˣ��벻����Ϸ�ˡ�\n");

	if (interactive(me) && query_idle(me) < 10)
	{
		if( me->is_busy()) return notify_fail("��������æ���������£������˳���Ϸ��\n");
		if( me->is_fighting()) return notify_fail("����������ս���������˳���Ϸ��\n");
	} else flag = 1;

	me->set_temp("quit", 1);
	me->set_temp("no_kill", 1);
	me->set_temp("disable_inputs",1);

	CHANNEL_D->do_channel(this_object(), "sys", NOR + me->short() + HIR " ׼���뿪��Ϸ�ˡ�");
	if( dx>0 || exp>0 || mana>0 || force>0 )
	{
		CHANNEL_D->do_channel(this_object(), "sys",
			"\n��������"+dx+"��,��ѧ��������"+exp+"�㣬��������"+mana+"��,��������"+force+"��\n");
		write(HIR"\n\n�������ߣ����");
		if(dx>0) write("��������"+dx+"��.");
		if(exp>0) write("��ѧ��������"+exp+"��.");
		if(mana>0) write("��������"+mana+"��.");
		if(force>0) write("��������"+force+"��.");
		write("\n"NOR);
		if( (dx > 100000 || dx < -100000) && !wizardp(me))
			log_file("static/adddx",sprintf("%s(%s)����%d�����ֵ %s\n",  
				me->name(),me->query("id"),dx,ctime(time())));
		if( (exp > 100000 || exp < -100000) && !wizardp(me) )
			log_file("static/addexp",sprintf("%s(%s)����%d����ѧ����ֵ %s\n",  
				me->name(),me->query("id"),exp,ctime(time())));
		if( (mana > 1000 || mana < -100) && !wizardp(me) )
			log_file("static/addmana",sprintf("%s(%s)����%d������� %s\n",  
				me->name(),me->query("id"),mana,ctime(time())));   
		if( (force > 1000 || force < -100) && !wizardp(me) )
			log_file("static/addforce",sprintf("%s(%s)����%d��������� %s\n", 
				me->name(),me->query("id"),force,ctime(time())));
	}		
	if (!flag && !wizardp(me)) {
		write("�����˳���Ϸ ,����������......\n");
		me->set_temp("no_move", 1);
		call_out("do_quit", 2, me, link_ob);

	} else do_quit(me, link_ob);

	return 1;
}

void do_quit(object me, object link_ob)
{
	int i;
	object *inv;

	if (!me) return;
	if( !wizardp(me) ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				do_drop(me, inv[i]);
	}

	write(MAG"������̫��Ľ����������������Щ���ˡ�������,����������֮ǰ��Ҳ������,
����߳����Ĵ��ϱ�,���ڿ���ȥ����һƬ��ã���㲻����Ц�������ֵ�����
��������ģ�Ȼ�����Ȼ��ʧ,��Ȼ��ȥ ......��\n"NOR);
	me->set("lost_quit",time());
	if(!wizardp(me) || !me->query("env/invisibility"))
	tell_room(environment(me), me->query("name") + "�뿪������硣\n",me);

	if (link_ob) {
		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();
		destruct(link_ob);
	}

	if (me->query("mud_age") == me->query_temp("temp/mud_age"))
		me->add("mud_age", 1);

	CHANNEL_D->do_channel(this_object(), "sys",
		me->name() + "(" + capitalize(me->query("id")) + ")�뿪��Ϸ�ˡ�\n");
	me->delete_temp("quit");
	me->delete_temp("no_kill");
	me->delete_temp("disable_inputs");
	me->delete_temp("no_move");
	me->save();
	destruct(me);
}

int do_drop(object me, object obj)
{
    	//if obj is a self-made fabao, save first...
        //if( obj->query("series_no") && obj->query("fabao") ) obj->save();
           
        if( obj->query("no_drop") ){
                destruct(obj);
                return 0;
        }
        if (obj->move(environment(me))) {
                if( obj->is_character() )
                        message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
                else {
                        message_vision( sprintf("$N����һ%s$n��\n",     obj->query("unit")), me, obj );
                        if( !obj->query("value") && !obj->value() ) {
                                tell_object(me,"��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�\n");
                                destruct(obj);
                        }
                }
                return 1;
        }
        return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : quit

��������ʱ�뿪ʱ, �����ô�һָ�
HELP
    );
    return 1;
}
