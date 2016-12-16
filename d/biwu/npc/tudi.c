// rewritten by snowcat on 4.12.1997

inherit NPC;

int give_fajian();

void create()
{
  set_name("���ع���", ({"tu di", "tu", "di"}));
  set("gender", "����");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 250000);
  set("daoxing", 300000);

  set("per", 25);
  set_skill("dodge", 60);
  set("max_sen",600);
  set("max_gee",600);
  set("max_gin",600);
  set("force",800);
  set("max_force",800);
  set("max_mana",800);
  set("force_factor",25);
  set_skill("spells",60);
  set_skill("stick",60);
  setup();

  set("inquiry", ([
       "here": "����Ƿ���¥�������������档\n",
       "name": "��������Ҳ���Ϸ�������ֻ��һЩ��������\n",
      ]));
  carry_object("/d/obj/cloth/choupao")->wear();

}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_yao","want");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	tell_object(ob,"���ع���Ц��������˵����
    �����ڿ�ʼ���㽫Ҫ�������Ŀ��顣������Ҫͨ��һ���Թ���Ȼ����ᵽ���
��¥����һ�����ڻ��������ʮһ����֣������������ս���ڷ���¥��û�л�ͷ��
·����ֻ�еȴ�һ���Ӻ��Զ��ͻ᳤��ʮ�ֽ�ͷ��
    ˳����һ�£�����Ҫ(want)��ͷ��ˮ����\n\n");
        ob->set_temp("comehere",1);
}

int do_yao()
{
	object ob,kele,hbb;
	ob = this_player();

	if (ob || interactive(ob))
		if ( ob->query_temp("comehere") )
		{
			tell_object(ob, "���ع���������һ�ۣ���ͷ��ˮ�����˹��������������԰ɡ���\n");
			kele = new("/d/biwu/obj/kele");
			hbb = new("/d/biwu/obj/hbb");
			kele->move(ob);
			hbb->move(ob);
        	ob->delete_temp("comehere");
        	return 1;
        }
	return 0;
}
