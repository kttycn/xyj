inherit ITEM;

void init();

void init()
{
	if (!wizardp(this_player())) {
                set("no_get","������������"+this_object()->query("name")+"�������ȫ���õ����ã��صúܡ�\n");
		set("no_give","����Ƕ����ĵ��ԱʼǱ��������������ѽ��ֵ�ü�����\n");
		set("no_drop","���Ǵ���𣿶����ĵ��ԱʼǱ�˵�Ӿ����ˣ��˷Ѱ���\n");
		set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ��Ҳ�ò������������Լ����Űɡ�\n");
	}                                 
}

void create()
{
 set_name("[1;35m��IBMԭװ���ԱʼǱ���[2;37;0m", ({ "computer","pc"}));
        set("long",
"\n[1;40mP4�Ķ������ã�װ���������µ���Ӳ����[2;37;0m\n"
"\n[1;40mר��Ϊ����ͺ�д����õģ���ϧ������һ�����ߣ�[2;37;0m\n"
"\n[1;40m��FAINT!![2;37;0m\n");
//"\n[1;40m������һ����ǩ:��ʦר�ã�[2;37;0m\n"
set_weight(100);
set("value", 200000);
setup();
}
