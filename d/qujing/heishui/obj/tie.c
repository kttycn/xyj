inherit ITEM;

void create()
{
        set_name("����", ({"letter", "xin tie"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"����������Ͻ�˿��֯����������������ϼ��˿���ż����֣�\n"
"\n"

"     ��������ż�ö���ɮ����ɮ��������ʮ������֮�壬\n" 
"     ʳ�����߿ɳ������ϣ��޲��Ҷ�������˸�����\n" 
"     ���ٺ��ᣬͬϯ�ٱ�����������\n" 
"\n"
"                                          ��������\n");
                set("material", "paper");
        }
  set("is_monitored",1);
  setup();
}

