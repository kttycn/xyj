// �����硤���μǡ��汾(����)
 

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("��ƹ�", ({"jiuguan", "pot","guan"}));
  set_weight(800);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
     set("long", "һ������װ�ƵĴ�ƹ��ӣ�һ����֪����ũ����õġ�\n");
     set("unit", "��");
     set("value", 100);
     set("max_liquid", 15);
  }

  set("liquid", ([
        "type": "alcohol",
        "name": "�ƾ�",
        "remaining": 35,
        "drunk_supply": 35,
      ]));
}

