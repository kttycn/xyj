//shushan2 by yushu@SHXY 2000.12
inherit ITEM;
void create()
{
  set_name("��¯", ({ "jin danlu", "danlu" }) );
  set_weight(300000);
  set_max_encumbrance(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "����һ���������������Ĵ��¯��\n");
    set("value", 2000);
  }
}
