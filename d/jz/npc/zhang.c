inherit F_VENDOR_SALE;

void create()
{
	set_name("��ʥ��", ({"zhang shengshou", "zhang", "boss"}));
	set("title", "[1;32m���ֻش�[m");
	set("gender", "����");
	set("age", 37);
	set("long","��ʥ�ֳ��������ҩ�ĵķ�����ҽ��Ҳ���˵á�\n");
	set("kee", 300); 
	set("max_kee", 300);
	set("sen", 200);
	set("max_sen", 200);
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("vendor_goods", ([
		"jiuzi"         : "/d/jz/herb/jiuzi",
		"baishu"        : "/d/jz/herb/baishu",
		"beimu"         : "/d/jz/herb/beimu",
		"bingpian"      : "/d/jz/herb/bingpian",
		"bohe"          : "/d/jz/herb/bohe",
		"caizi"         : "/d/jz/herb/caizi",
		"chaihu"        : "/d/jz/herb/chaihu",
		"chansu"        : "/d/jz/herb/chansu",
		"chenpi"        : "/d/jz/herb/chenpi",
		"chuanwu"       : "/d/jz/herb/chuanwu",
		"dahuang"       : "/d/jz/herb/dahuang",
		"danggui"       : "/d/jz/herb/dangui",
		"dingxiang"     : "/d/jz/herb/dingxiang",
		"duanxu"        : "/d/jz/herb/duanxu",
		"duhuo"         : "/d/jz/herb/duhuo",
		"erhua"         : "/d/jz/herb/ercha",
		"fangfeng"      : "/d/jz/herb/fangfeng",
		"fuzi"          : "/d/jz/herb/fuzi",
		"gancao"        : "/d/jz/herb/gancao",
		"goujuzi"       : "/d/jz/herb/goujuzi",
		"gsliu"         : "/d/jz/herb/gsliu",
		"guiwei"        : "/d/jz/herb/guiwei",		
		"hafem"         : "/d/jz/herb/hafen",
		"honghua"       : "/d/jz/herb/honghua",
		"huajiao"       : "/d/jz/herb/huajiao",        
		"huangbo"       : "/d/jz/herb/huangbo",
		"huanglian"     : "/d/jz/herb/huanglian",
		"hugu"          : "/d/jz/herb/hugu",   
		"hupo"          : "/d/jz/herb/hupo",
		"jinying"       : "/d/jz/herb/jinying",
		"juhua"         : "/d/jz/herb/juhua",
		"lanhua"        : "/d/jz/herb/lanhua",
		"lianqiao"      : "/d/jz/herb/lianqiao",
		"lianzi"        : "/d/jz/herb/lianzi",
		"lurong"        : "/d/jz/herb/lurong",
		"moyao"         : "/d/jz/herb/moyao",
		"niuhuang"      : "/d/jz/herb/niuhuang",
		"niuxi"         : "/d/jz/herb/niuxi",
		"qianjinzi"     : "/d/jz/herb/qianjinzi",
		"ruxiang"       : "/d/jz/herb/ruxiang",
		"shancha"       : "/d/jz/herb/shancha",
		"shengdi"       : "/d/jz/herb/shengdi",
		"shenglg"       : "/d/jz/herb/shenglg",
		"shexiang"      : "/d/jz/herb/shexiang",
		"sumu"          : "/d/jz/herb/sumu",
		"chuanshanjia"  : "/d/jz/herb/shanjia",
		"qingdai"       : "/d/jz/herb/qingdai",
		"taoxian"       : "/d/jz/herb/taoxian",
		"tiandong"      : "/d/jz/herb/tiandong",
		"tianqi"        : "/d/jz/herb/tianqi",
		"tugou"         : "/d/jz/herb/tugou",
		"water"         : "/d/jz/herb/water",
		"wulingzhi"     : "/d/jz/herb/wulingzhi",   
		"xiefen"        : "/d/jz/herb/xiefen",
		"xingren"       : "/d/jz/herb/xingren",
		"xiongdan"      : "/d/jz/herb/xiongdan",
		"xuejie"        : "/d/jz/herb/xuejie",
		"yanghuo"       : "/d/jz/herb/yanghuo",
		"yjhua"         : "/d/jz/herb/yjhua",
		"yuanzhi"       : "/d/jz/herb/yuanzhi",
		"zhusha"        : "/d/jz/herb/zhusha",
		"zihua"         : "/d/jz/herb/zihua",
		"zzfen"         : "/d/jz/herb/zzfen",
		"jifang"        : "/d/obj/book/m-book1",
		"yuyicao"       : "/d/obj/book/m-book2",
		"sangangshilue" : "/d/obj/book/m-book3",
		"kejinjijie"    : "/d/obj/book/m-book4",
		"douzhendinglun": "/d/obj/book/m-book5",
		"bojixidoufang" : "/d/obj/book/m-book6",
		"bencaogangmu"  : "/d/obj/book/m-book7",
		"bencaojizhu"   : "/d/obj/book/m-book8",
		"xinxiubencao"  : "/d/obj/book/m-book9",
		"qianjinyaofang": "/d/obj/book/m-book10",
		"qianjinyifang" : "/d/obj/book/m-book11",
		"waitaimiyao"   : "/d/obj/book/m-book12",
		"longshulun"    : "/d/obj/book/m-book13",
	]) );

	set_skill("literate", 70);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);

	setup();
	carry_object("/d/obj/cloth/choupao")->wear();
}



void init()
{
        object ob;

        ::init();
        add_action("do_vendor_list", "list");
}

