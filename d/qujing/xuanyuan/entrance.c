// ��Ĺ���
#include <login.h>
#include <room.h>

inherit ROOM;
void create()
{
set("short","���");
set("long",@LONG

	��Ҳ��֪���Լ�������ʲô�ط���˵�����ϣ������Լ��ղ�
��������ת�ģ��㲻���ж�һ��Ī���Ŀ־壬���û�е����Ļ�
���㻹�ǻ�ȥΪ�ã����ﲻ�ǻ���ס�ĵط���

LONG);
set("exits", ([
	"up" : "/d/eastway/bingma",
	"in" : __DIR__"road1",
]));
set("valid_startroom",1);
setup();

}

