inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
�������������������ϵ�һ���������Ĵ����Ǵ��СС��
�Ҷ�����֪ͨ��������溣����ӿ��һ��һ��������
�ߵĽ�ʯ��������������������ǵأ��·�Ҫ������Ȼ��
����������������ǰ��
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"haitan1",
]));

        set("outdoors", "xihai");

  setup();
}

