// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

//created by night 7/24/2000
 
inherit ROOM;

string look_picture();

void create ()
{
	set ("short", "飞月轩");
	set ("long", @LONG

说这里是兵器铺，倒不如说是个兵器陈列室。偌大的一个房间，四壁挂着
各种制作精良的兵刃。整个房间彩梁画栋，连顶棚也用彩漆绘满了各种美
丽而诗意的图形，每幅画似乎都在诉说一个娓娓动人的爱情故事。在内堂
有一幅巨大的画（ＰＩＣＴＵＲＥ），似乎述说了主人淡泊的心志。这座
飞月轩的主人高翔曾经是叱咤一时的江湖人物，遭遇了一段浪漫美丽的爱
情，可是，后来因为种种原因，不得不远离中原，含恨与爱妻别离。他引
以为生平最大憾事，终于淡出江湖，筑了这座飞月轩，怀念着他的妻子，
凭着他精湛的武器铸造术，平淡度日。
LONG);

	set("exits", ([
		"north"   : __DIR__"jiedao4",
	]));
	set("objects", ([
        __DIR__"npc/gao"   : 1,
//        __DIR__"npc/worker"   : 1,
	]));
	set("item_desc",([
		"picture" : (: look_picture :),
	]));

	setup();
}


string look_picture()
{
	return
        "\n"
        "    ※※※※※※※※※※※※※※※※※※※※※※※※※※\n"
        "    ※※※※※※※※※※※※※※※※※※※※※※※※※※\n"
        "    ※※※※※※※+----------------------+※※※※※※※\n"
        "    ※※※※※※※|::::        **     :: |※※※※※※※\n"
        "    ※※※※※※※|::        ***       : |※※※※※※※\n"
        "    ※※※※※※※|:        ***｜*  ** : |※※※※※※※\n"
        "    ※※※※※※※|:          *｜*,*     |※※※※※※※\n"
        "    ※※※※※※※|  *** * *   ｜/* **   |※※※※※※※\n"
        "    ※※※※※※※|   *＼'** * ｜        |※※※　※※※\n"
        "    ※※※※※※※|   ***＼**  ｜        |※※　修　※※\n"
        "    ※※※※※※※|     * *＼ *┃  ***   |※※　身　※※\n"
        "    ※※※※※※※|#         ＼┃**,*    |※※　如　※※\n"
        "    ※※※※※※※|:           ┃／      |※※　竹　※※\n"
        "    ※※※※※※※|:           ┃        |※※※　※※※\n"
        "    ※※※※※※※|.                 ..@ |※※※※※※※\n"
        "    ※※※※※※※+----------------------+※※※※※※※\n"
        "    ※※※※※※※※※※※※※※※※※※※※※※※※※※\n"
        "    ※※※※※※※※※※※※※※※※※※※※※※※※※※\n";
}

