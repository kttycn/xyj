inherit ROOM;

void create ()
{
	set ("short", "��");
	set ("long", @LONG
������ӻ����ˣ�û��һ����������㲻���е㷢ë�ˡ���
�㿴�˿����ܣ����ֵ����и���ֵ�ͼ����tuan����
LONG);

	set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"maze1",
	"south" : __DIR__"sl4",
]));	
	set("objects", ([
	]));
	set("item_desc", ([
	"tuan" : "

	--------
	/	|		| \\
	/	|		|	\\
		|--------------|
		|	 |		|	 |
		|--------------|
	\\	|		|	/
	\\ |		| /
	--------

",
	]) );
	setup();
}								
