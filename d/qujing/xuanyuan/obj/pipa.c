inherit ITEM;

string *names = ({
        "��ʯ����",
        "��ͭ����",
        "��������",
        });

void create()
{
        set_name(names[random(sizeof(names))], ({"pi pa"}));
        set_weight(100);
           set("unit", "ö");
           set("long", "ԭ������һ����ʯ�������ɵľ���\n");
           set("no_sell", 1);
           set("value", 5000);
   setup();
}

