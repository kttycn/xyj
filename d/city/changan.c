inherit "/std/city.c";

void create ()
{
reload("����");
set ("short", "������");
set ("long", @LONG

����һ�����ϵĳ��С�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"jiuguan1",
]));
  set("no_clean_up", 1);

  setup();
}

int clean_up()
{
      return 0;
}

