// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create ()
{
  set ("short", "�ڵ�");
  set ("long", @LONG

    ������һ���������������ƣ�᣽Ƕ��ˡ����Ϲ����������
���а��������Ľ�գ���ٰ��ޣ���ǧ���У�ʮһ���ף�ʮ��٤������
�����������������ĵȡ�ֱ�������ۻ����ҡ������߸�����һ��������
ۼ�Ĵ�ƿ���ϲ�̴����֦������һƬ���֮����
LONG);

  set("exits", ([
  "southdown" : "/d/xuyi/taijie",
  "west" : __DIR__"zoulang",
]));

  setup();
  replace_program(ROOM);
}

