// by snowcat jan 22 1998

#include <ansi.h>
#include "quest.c"

// the quest format is the following mapping:
// daoxing :     type     name     id            object         amount
//--------------------------------------------------------------------
//  1000   : ({ "find",  "秘笈",   "mi ji" ,     "",             "1" }), 
//  5000   : ({ "give",  "灾民",   "zai min" ,   "白银(silver)", "5" }), 
// 12000   : ({ "kill",  "白骨精", "baigu jing", "",             "3" });
 
//找一本秘笈，救济灾民五两银子，三打白骨精．．．．．．

mapping quests_ask = ([
       5 : ({ "ask", "孔方兄",       "kong fang",          "送经书",             "1" }),
      10 : ({ "ask", "疥顶小僧",     "jieding xiaoseng",   "取经之道",           "1" }),
      15 : ({ "ask", "李白",         "li bai",             "诗歌",               "1" }),
      20 : ({ "ask", "游方僧人",     "seng ren",           "佛道",               "1" }),
      25 : ({ "ask", "袁守诚",       "yuan shoucheng",     "算卦术",             "1" }),
      35 : ({ "ask", "杨中顺",       "yang zhongshun",     "讲授医术",           "1" }),
      40 : ({ "ask", "范青屏",       "fan qingping",       "讲拳法",             "1" }),
      45 : ({ "ask", "袁天罡",       "yuan tiangang",      "法术",               "1" }),
      50 : ({ "ask", "雾渊道长",     "wuyuan daozhang",    "讲玄道",             "1" }),
      55 : ({ "ask", "法明长老",     "faming zhanglao",    "呼风唤雨",           "1" }),
      65 : ({ "ask", "公孙大娘",     "gongsun daniang",    "歌艺舞艺",           "1" }),
      70 : ({ "ask", "贺知章",       "he zhizhang",        "国子监",             "1" }),
      75 : ({ "ask", "青鬏龟童",     "gui tong",           "讲授龟艺",           "1" }),
      80 : ({ "ask", "白髯鸡仙",     "ji xian",            "斗鸡术",             "1" }),
      85 : ({ "ask", "张果老",       "zhang guolao",       "太乙仙法",           "1" }),
      90 : ({ "ask", "铁算盘",       "tie suanpan",        "生财之道",           "1" }),
      95 : ({ "ask", "李玉娘",       "li yuniang",         "烹调术",             "1" }),

     100 : ({ "ask", "皤不分",       "bo bufen",           "移行换位术",         "1" }),
     120 : ({ "ask", "罗成",         "luo cheng",          "比武",               "1" }),
     140 : ({ "ask", "云阳真人",     "master yunyang",     "比武",               "1" }),
     160 : ({ "ask", "罗春",         "luo chun",           "比武",               "1" }),
     180 : ({ "ask", "卢生",         "lu sheng",           "黄梁一梦",           "1" }),
     200 : ({ "ask", "广筠子",       "guang yunzi",        "比武",               "1" }),
     220 : ({ "ask", "广羲子",       "guang xizi",         "比武",               "1" }),
     240 : ({ "ask", "黑熊怪",       "bear monster",       "比武",               "1" }),
     260 : ({ "ask", "吴刚",         "wu gang",            "砍树",               "1" }),
     280 : ({ "ask", "月下老人",     "yuexia laoren",      "姻缘术",             "1" }),
     300 : ({ "ask", "观音菩萨",     "guanyin pusa",       "大乘佛法",           "1" }),
     320 : ({ "ask", "惠岸行者",     "huian xingzhe",      "大乘佛法",           "1" }),
     340 : ({ "ask", "净瓶使者",     "shizhe",             "大乘佛法",           "1" }),
     360 : ({ "ask", "掌厨僧",       "zhangchu seng",      "烹调术",             "1" }),
     380 : ({ "ask", "掌禅僧",       "zhangchan seng",     "修禅",               "1" }),
     400 : ({ "ask", "知客僧",       "zhike seng",         "待客之方",           "1" }),

     430 : ({ "ask", "鳊提督",       "bian tidu",          "比武",               "1" }),
     460 : ({ "ask", "鲸无敌",       "jing wudi",          "比武",               "1" }),
     490 : ({ "ask", "龙表弟",       "long biaodi",        "比武",               "1" }),
     530 : ({ "ask", "鲤总兵",       "li zongbing",        "比武",               "1" }),
     560 : ({ "ask", "鲭都司",       "qing dusi",          "比武",               "1" }),
     590 : ({ "ask", "鲻太尉",       "zi taiwei",          "比武",               "1" }),
     630 : ({ "ask", "龟八斗",       "gui badou",          "军机",               "1" }),
     660 : ({ "ask", "龙少爷",       "long shaoye",        "比武",               "1" }),

     590 : ({ "ask", "青贝宫女",     "gong nu",            "采贝术",             "1" }),
     630 : ({ "ask", "黄贝宫女",     "gong nu",            "采贝术",             "1" }),
     660 : ({ "ask", "白贝宫女",     "gong nu",            "采贝术",             "1" }),
     690 : ({ "ask", "紫贝宫女",     "gong nu",            "采贝术",             "1" }),
     730 : ({ "ask", "银贝宫女",     "gong nu",            "采贝术",             "1" }),
     760 : ({ "ask", "金贝宫女",     "gong nu",            "采贝术",             "1" }),

     790 : ({ "ask", "青鳝力士",     "li shi",             "潜海术",             "1" }),
     830 : ({ "ask", "乌鳅力士",     "li shi",             "潜海术",             "1" }),
     860 : ({ "ask", "赤鲤力士",     "li shi",             "潜海术",             "1" }),
     890 : ({ "ask", "黄鲳力士",     "li shi",             "潜海术",             "1" }),
     930 : ({ "ask", "白鲨力士",     "li shi",             "潜海术",             "1" }),
     960 : ({ "ask", "紫鲭力士",     "li shi",             "潜海术",             "1" }),
     990 : ({ "ask", "金鳌力士",     "li shi",             "潜海术",             "1" }),
    1030 : ({ "ask", "银蛎力士",     "li shi",             "潜海术",             "1" }),

    1060 : ({ "ask", "蒲牢",         "pu lao",             "比武",               "1" }),
    1090 : ({ "ask", "狴犴",         "bi an",              "比武",               "1" }),
    1130 : ({ "ask", "睚眦",         "ya zi",              "比武",               "1" }),
    1160 : ({ "ask", "霸下",         "ba xia",             "比武",               "1" }),
    1190 : ({ "ask", "螭吻",         "chi wen",            "比武",               "1" }),
    1230 : ({ "ask", "饕餮",         "tao tie",            "比武",               "1" }),
    1260 : ({ "ask", "蚣蝮",         "gong fu",            "比武",               "1" }),
    1290 : ({ "ask", "金猊",         "jin ni",             "比武",               "1" }),
    1330 : ({ "ask", "椒图",         "shu tu",             "比武",               "1" }),
    1360 : ({ "ask", "敖广",         "ao guang",           "降雨",               "1" }),

    1400 : ({ "ask", "青髯老人",     "lao ren",            "西域",               "1" }),

    1500 : ({ "ask", "嫦娥",         "chang e",            "比武",               "1" }),
    1520 : ({ "ask", "抱琴",         "bao qin",            "舞技",               "1" }),
    1540 : ({ "ask", "茗烟",         "ming yan",           "舞技",               "1" }),
    1560 : ({ "ask", "锄药",         "chu yao",            "舞技",               "1" }),
    1580 : ({ "ask", "扫红",         "shao hong",          "舞技",               "1" }),
    1600 : ({ "ask", "蝶衣",         "butterfly",          "舞技",               "1" }),
    1620 : ({ "ask", "菊影",         "shade",              "舞技",               "1" }),
    1700 : ({ "ask", "西王母",       "xi wangmu",          "月宫参加水陆大会",   "1" }),

    1800 : ({ "ask", "秦琼",         "qin qiong",          "将军府参加水陆大会", "1" }),
    1900 : ({ "ask", "菩提祖师",     "master puti",        "方寸山参加水陆大会", "1" }),

    2100 : ({ "ask", "浣花",         "huan hua",           "下山比武",           "1" }),
    2200 : ({ "ask", "孔雀公主",     "kongque gongzhu",    "比武",               "1" }),
    2300 : ({ "ask", "乌鸦先生",     "wuya xiansheng",      "比武",               "1" }),
    2400 : ({ "ask", "鹦鹉将军",     "yingwu jiangjun",    "传授口技",           "1" }),
    2500 : ({ "ask", "白象尊者",     "baixiang zunzhe",    "比武",               "1" }),
    2600 : ({ "ask", "青狮老魔",     "qingshi laomo",      "比武",               "1" }),
    2700 : ({ "ask", "秃鹰尊者",     "tuying zunzhe",      "比武",               "1" }),

    3100 : ({ "ask", "国王",         "guo wang",           "派使来访",           "1" }),
    3200 : ({ "ask", "太监",         "tai jian",           "讲授宫政",           "1" }),
    3300 : ({ "ask", "宫妃",         "gong fei",           "宫中舞艺",           "1" }),
    3400 : ({ "ask", "宫女",         "girl",               "宫中舞艺",           "1" }),

    4100 : ({ "ask", "大使",         "da shi",             "来访水陆大会",       "1" }),
    4200 : ({ "ask", "黄门官",       "huangmen guan",      "来访水陆大会",       "1" }),
    4300 : ({ "ask", "梅鸳鸯",       "mei yuanyan",        "来访水陆大会",       "1" }),
    4400 : ({ "ask", "坊主",         "fang zhu",           "订购家什",           "1" }),
    4500 : ({ "ask", "锡匠",         "xi jiang",           "讲授锡艺",           "1" }),
    4600 : ({ "ask", "管家",         "guan jia",           "家政",               "1" }),
    4700 : ({ "ask", "小管家",       "guan jia",           "家政",               "1" }),
    4800 : ({ "ask", "叶大嫂",       "ye dasao",           "园艺",               "1" }),
    4900 : ({ "ask", "酒保",         "jiu bao",            "传授酿酒术",         "1" }),

    5000 : ({ "ask", "说书老",       "shuoshu lao",        "来大唐说书",         "1" }),
    5100 : ({ "ask", "戏子",         "xi zi",              "来大唐唱戏",         "1" }),
    5200 : ({ "ask", "元先生",       "yuan xiansheng",     "来大唐教外语",       "1" }),
    5300 : ({ "ask", "祭赛国武士",   "wu shi",             "交流武艺",           "1" }),
    5400 : ({ "ask", "小公主",       "xiliang princess",   "比武",               "1" }),
    5500 : ({ "ask", "皇宫伺卫",     "si wei",             "交流武艺",           "1" }),
    5600 : ({ "ask", "伺卫官",       "siwei guan",         "交流武艺",           "1" }),
    5700 : ({ "ask", "护宫卫士",     "wei shi",            "交流武艺",           "1" }),
    5800 : ({ "ask", "士兵",         "shi bing",           "交流武艺",           "1" }),
    5900 : ({ "ask", "校尉",         "xiao wei",           "交流武艺",           "1" }),

    8100 : ({ "ask", "仙官",         "xian",               "恭请光临",           "1" }),
    8200 : ({ "ask", "仙女",         "xian",               "邀请下凡",           "1" }),
    8300 : ({ "ask", "仙妃",         "xian",               "邀请下凡",           "1" }),
    8400 : ({ "ask", "仙子",         "xian",               "邀请下凡",           "1" }),
    8500 : ({ "ask", "仙将",         "xian",               "恭请光临",           "1" }),
    8600 : ({ "ask", "仙卿",         "xian",               "恭请光临",           "1" }),
    8700 : ({ "ask", "仙卿",         "xian",               "恭请光临",           "1" }),

    9100 : ({ "ask", "祭赛国国王",   "jisai guowang",      "派使来访",           "1" }),
    9200 : ({ "ask", "太白金星",     "tai bai",            "恭请光临",           "1" }),
    9300 : ({ "ask", "监斩官",       "jianzhan guan",      "讲授西域律法",       "1" }),
    9400 : ({ "ask", "道童",         "dao tong",           "清理道场",           "1" }),
    9500 : ({ "ask", "道士",         "dao shi",            "做道场",             "1" }),
    9600 : ({ "ask", "道人",         "dao ren",            "做道场",             "1" }),
    9700 : ({ "ask", "僧侣",         "seng lu",            "做法场",             "1" }),
    9800 : ({ "ask", "五福道长",     "dao zhang",          "传授道教",           "1" }),
    9900 : ({ "ask", "苦宿禅师",     "kusu chanshi",       "传授佛教",           "1" }),

   10000 : ({ "ask", "陈小二",       "chen xiaoer",        "宣传佛教",           "1" }),
   10100 : ({ "ask", "孙小二",       "sun xiaoer",         "宣传佛教",           "1" }),
   10200 : ({ "ask", "周小二",       "zhou xiaoer",        "宣传佛教",           "1" }),
   10300 : ({ "ask", "赵寡妇",       "zhao guafu",         "宣传佛教",           "1" }),
   10400 : ({ "ask", "李寡妇",       "li guafu",           "宣传佛教",           "1" }),
   10500 : ({ "ask", "钱寡妇",       "qian guafu",         "宣传佛教",           "1" }),
   10600 : ({ "ask", "郑寡妇",       "zheng guafu",        "宣传佛教",           "1" }),
   10700 : ({ "ask", "太子",         "tai zi",             "宫亭内政",           "1" }),
   10800 : ({ "ask", "王后",         "wang hou",           "宫事",               "1" }),
   10900 : ({ "ask", "公主",         "gong zhu",           "宫事",               "1" }),

   11100 : ({ "ask", "差官",         "chai guan",          "西域国政",           "1" }),
   11200 : ({ "ask", "殿官",         "dian guan",          "西域国政",           "1" }),
   11300 : ({ "ask", "文官",         "wen guan",           "西域国政",           "1" }),
   11400 : ({ "ask", "官客",         "guan ke",            "官僚术",             "1" }),
   11500 : ({ "ask", "臣子",         "chen zi",            "官僚术",             "1" }),
   11600 : ({ "ask", "碧奴慕伊",     "binu muyi",          "插花艺",             "1" }),
   11700 : ({ "ask", "坎都力",       "kan duli",           "烹饪术",             "1" }),
   11800 : ({ "ask", "库司库司",     "kusi kusi",          "烹饪术",             "1" }),
   11900 : ({ "ask", "拉苏律司",     "lasu lusi",          "金银匠艺",           "1" }),
   12000 : ({ "ask", "索哈娜",       "suo hana",           "西域语",             "1" }),
   12100 : ({ "ask", "阿依娜",       "a yina",             "金银匠艺",           "1" }),
   12200 : ({ "ask", "柳妙手",       "liu miaoshou",       "医术",               "1" }),
   12300 : ({ "ask", "刘老板",       "liu laoban",         "西域商事",           "1" }),
   12400 : ({ "ask", "萨米儿大叔",   "uncle samui",        "烹饪术",             "1" }),
   12500 : ({ "ask", "陈长老",       "chen zhanglao",      "祭祀术",             "1" }),

   13000 : ({ "ask", "日值功曹",     "rizhi gongcao",      "传授武功",           "1" }),
   13100 : ({ "ask", "年值功曹",     "nianzhi gongcao",    "传授武功",           "1" }),
   13200 : ({ "ask", "月值功曹",     "yuezhi gongcao",     "传授武功",           "1" }),
   13300 : ({ "ask", "时值功曹",     "shizhi gongcao",     "传授武功",           "1" }),
   13400 : ({ "ask", "魔礼海",       "moli hai",           "传授武功",           "1" }),
   13500 : ({ "ask", "魔礼青",       "moli qing",          "传授武功",           "1" }),
   13600 : ({ "ask", "风婆",         "feng po",            "起风",               "1" }),
   13700 : ({ "ask", "云童",         "yun tong",           "布云",               "1" }),
   13800 : ({ "ask", "雷公",         "lei gong",           "打雷",               "1" }),
   13900 : ({ "ask", "电母",         "dian mu",            "闪电",               "1" }),
    

   15100 : ({ "ask", "黄衣仙女",     "huangyi xiannu",            "邀请下凡",           "1" }),
   15200 : ({ "ask", "紫衣仙女",     "ziyi xiannu",            "邀请下凡",           "1" }),
   15300 : ({ "ask", "绿衣仙女",     "luyi xiannu",            "邀请下凡",           "1" }),
   15400 : ({ "ask", "红衣仙女",     "hongyi xiannu",            "邀请下凡",           "1" }),
   15500 : ({ "ask", "青衣仙女",     "qingyi xiannu",            "邀请下凡",           "1" }),
   15600 : ({ "ask", "皂衣仙女",     "zaoyi xiannu",            "邀请下凡",           "1" }),
   15700 : ({ "ask", "素衣仙女",     "suyi xiannu",            "邀请下凡",           "1" }),
   16100 : ({ "ask", "运水力士",     "li shi",             "邀请观礼水陆大会",   "1" }),
   16200 : ({ "ask", "修桃力士",     "li shi",             "邀请观礼水陆大会",   "1" }),
   16300 : ({ "ask", "打扫力士",     "li shi",             "邀请观礼水陆大会",   "1" }),
   16400 : ({ "ask", "剪枝力士",     "li shi",             "邀请观礼水陆大会",   "1" }),
   16500 : ({ "ask", "施肥力士",     "li shi",             "邀请观礼水陆大会",   "1" }),
   16600 : ({ "ask", "培土力士",     "li shi",             "邀请观礼水陆大会",   "1" }),
   16700 : ({ "ask", "锄树力士",     "li shi",             "邀请观礼水陆大会",   "1" }),

   20100 : ({ "ask", "黛姐",         "dai jie",            "花艺",               "1" }),
   20200 : ({ "ask", "方丈",         "fang zhang",         "传授佛学",           "1" }),
   20300 : ({ "ask", "福嫂",         "fu sao",             "烹饪术",             "1" }),
   20400 : ({ "ask", "柳光头",       "liu guangtou",       "烹饪术",             "1" }),
   20500 : ({ "ask", "万口福",       "wan koufu",          "烹饪术",             "1" }),
   20600 : ({ "ask", "辛儿娘",       "xiner niang",        "烹饪术",             "1" }),
   20700 : ({ "ask", "侯郎中",       "hou langzhong",      "西域药理",           "1" }),
   20800 : ({ "ask", "张妈",         "zhang ma",           "烹饪术",             "1" }),
   20900 : ({ "ask", "甜妞",         "tian niu",           "西域服装",           "1" }),
   21000 : ({ "ask", "歌女",         "ge nu",              "来唐唱歌",           "1" }),

   30100 : ({ "ask", "郭三娘",       "guo sanniang",       "西域服装",           "1" }),
   30200 : ({ "ask", "魏大嫂",       "wei dasao",          "种植园艺",           "1" }),
   30300 : ({ "ask", "季梅儿",       "ji meier",           "西域服装",           "1" }),
   30400 : ({ "ask", "陶娘子",       "tao niangzi",        "西域服装",           "1" }),
   30500 : ({ "ask", "侯郎中",       "hou langzhong",      "西域药理",           "1" }),
   30600 : ({ "ask", "黄汤",         "huang tang",         "酿酒术",             "1" }),
   30700 : ({ "ask", "醉方休",       "zui fangxiu",        "酿酒术",             "1" }),
   30800 : ({ "ask", "胖店主",       "pang dianzhu",       "商务",               "1" }),
   30900 : ({ "ask", "瘦店娘",       "shou dianniang",     "商务",               "1" }),

   40100 : ({ "ask", "米老板",       "mi laoban",          "商务",               "1" }),
   40200 : ({ "ask", "乐老板",       "le laoban",          "商务",               "1" }),
   40300 : ({ "ask", "吴老板",       "wu laoban",          "商务",               "1" }),
   40400 : ({ "ask", "马老板",       "ma laoban",          "马术",               "1" }),
   40500 : ({ "ask", "乔老板",       "qiao laoban",        "商务",               "1" }),
   40600 : ({ "ask", "史老板",       "shi laoban",         "竹器编制工艺",       "1" }),
   40700 : ({ "ask", "舒老板",       "shu laoban",         "西域服装",           "1" }),
   40800 : ({ "ask", "司徒晋宝",     "situ jinbao",        "商务",               "1" }),
   40900 : ({ "ask", "知书和尚",     "he shang",           "佛学",              "1" }),
   41000 : ({ "ask", "尚礼和尚",     "he shang",           "佛学",              "1" }),
   41100 : ({ "ask", "俗家和尚",     "he shang",           "佛学",              "1" }),
   41200 : ({ "ask", "书院和尚",     "he shang",           "佛学",              "1" }),
   41300 : ({ "ask", "客家和尚",     "he shang",           "佛学",              "1" }),
   41400 : ({ "ask", "修行和尚",     "he shang",           "佛学",              "1" }),
   41500 : ({ "ask", "穷和尚",       "he shang",           "佛学",              "1" }),
   41600 : ({ "ask", "瘦和尚",       "he shang",           "佛学",              "1" }),
   41700 : ({ "ask", "胖和尚",       "he shang",           "佛学",              "1" }),
   41800 : ({ "ask", "老和尚",       "heshang",            "佛学",              "1" }),
   41900 : ({ "ask", "笑和尚",       "he shang",           "佛学",              "1" }),
   42000 : ({ "ask", "诵经僧人",     "he shang",           "佛学",              "1" }),
   42100 : ({ "ask", "出勤僧人",     "he shang",           "佛学",              "1" }),
   42200 : ({ "ask", "俗家僧人",     "he shang",           "佛学",              "1" }),
   42300 : ({ "ask", "修禅僧人",     "he shang",           "佛学",              "1" }),
   42400 : ({ "ask", "传法僧人",     "he shang",           "佛学",              "1" }),

   50100 : ({ "ask", "陈康",         "chen",               "捕鱼术",          "1" }),
   50200 : ({ "ask", "陈禄",         "chen",               "捕鱼术",          "1" }),
   50300 : ({ "ask", "陈溯",         "chen",               "捕鱼术",          "1" }),
   50400 : ({ "ask", "陈鸠",         "chen",               "捕鱼术",          "1" }),
   50500 : ({ "ask", "陈蜀",         "chen",               "捕鱼术",          "1" }),
   50600 : ({ "ask", "陈焘",         "chen",               "捕鱼术",          "1" }),
   50700 : ({ "ask", "陈戛",         "chen",               "捕鱼术",          "1" }),
   50800 : ({ "ask", "陈笮",         "chen",               "捕鱼术",          "1" }),
   50900 : ({ "ask", "陈子虬",       "chen",               "捕鱼术",          "1" }),
   51000 : ({ "ask", "陈龙大",       "chen",               "捕鱼术",          "1" }),
   51100 : ({ "ask", "陈大头",       "chen",               "捕鱼术",          "1" }),
   51200 : ({ "ask", "陈小个",       "chen",               "捕鱼术",          "1" }),
   51300 : ({ "ask", "陈老大",       "chen",               "捕鱼术",          "1" }),
   51400 : ({ "ask", "陈老二",       "chen",               "捕鱼术",          "1" }),
   51500 : ({ "ask", "陈老三",       "chen",               "捕鱼术",          "1" }),
   51600 : ({ "ask", "陈老四",       "chen",               "捕鱼术",          "1" }),
   51700 : ({ "ask", "陈大伯",       "chen",               "捕鱼术",          "1" }),
   51800 : ({ "ask", "陈大叔",       "chen",               "捕鱼术",          "1" }),
   51900 : ({ "ask", "陈大舅",       "chen",               "捕鱼术",          "1" }),
   52000 : ({ "ask", "陈大哥",       "chen",               "捕鱼术",          "1" }),
   52100 : ({ "ask", "陈大爷",       "chen",               "捕鱼术",          "1" }),
   52200 : ({ "ask", "陈二伯",       "chen",               "捕鱼术",          "1" }),
   52300 : ({ "ask", "陈二叔",       "chen",               "捕鱼术",          "1" }),
   52400 : ({ "ask", "陈二舅",       "chen",               "捕鱼术",          "1" }),
   52500 : ({ "ask", "陈二哥",       "chen",               "捕鱼术",          "1" }),
   52600 : ({ "ask", "陈二爷",       "chen",               "捕鱼术",          "1" }),
   52700 : ({ "ask", "陈三伯",       "chen",               "捕鱼术",          "1" }),
   52800 : ({ "ask", "陈三叔",       "chen",               "捕鱼术",          "1" }),
   52900 : ({ "ask", "陈三舅",       "chen",               "捕鱼术",          "1" }),
   53000 : ({ "ask", "陈三哥",       "chen",               "捕鱼术",          "1" }),
   53100 : ({ "ask", "陈三爷",       "chen",               "捕鱼术",          "1" }),
   53200 : ({ "ask", "陈四伯",       "chen",               "捕鱼术",          "1" }),
   53300 : ({ "ask", "陈四叔",       "chen",               "捕鱼术",          "1" }),
   54400 : ({ "ask", "陈四舅",       "chen",               "捕鱼术",          "1" }),
   54500 : ({ "ask", "陈四哥",       "chen",               "捕鱼术",          "1" }),
   54600 : ({ "ask", "陈娘",         "chen",               "烹鱼技艺",        "1" }),
   54700 : ({ "ask", "陈氏",         "chen",               "烹鱼技艺",        "1" }),
   54800 : ({ "ask", "陈婆",         "chen",               "烹鱼技艺",        "1" }),
   54900 : ({ "ask", "陈妈",         "chen",               "烹鱼技艺",        "1" }),
   55000 : ({ "ask", "陈嫂",         "chen",               "烹鱼技艺",        "1" }),
   55100 : ({ "ask", "陈婶",         "chen",               "烹鱼技艺",        "1" }),
   55200 : ({ "ask", "陈大娘",       "chen",               "烹鱼技艺",        "1" }),
   55300 : ({ "ask", "陈大婆",       "chen",               "烹鱼技艺",        "1" }),
   55400 : ({ "ask", "陈大妈",       "chen",               "烹鱼技艺",        "1" }),
   55500 : ({ "ask", "陈大嫂",       "chen",               "烹鱼技艺",        "1" }),
   55600 : ({ "ask", "陈大婶",       "chen",               "烹鱼技艺",        "1" }),
   55700 : ({ "ask", "陈二娘",       "chen",               "烹鱼技艺",        "1" }),
   55800 : ({ "ask", "陈二婆",       "chen",               "烹鱼技艺",        "1" }),
   55900 : ({ "ask", "陈二妈",       "chen",               "烹鱼技艺",        "1" }),
   55600 : ({ "ask", "陈二嫂",       "chen",               "烹鱼技艺",        "1" }),
   55700 : ({ "ask", "陈二婶",       "chen",               "烹鱼技艺",        "1" }),
   55800 : ({ "ask", "陈三娘",       "chen",               "烹鱼技艺",        "1" }),
   55900 : ({ "ask", "陈三婆",       "chen",               "烹鱼技艺",        "1" }),
   56000 : ({ "ask", "陈三妈",       "chen",               "烹鱼技艺",        "1" }),
   56100 : ({ "ask", "陈三嫂",       "chen",               "烹鱼技艺",        "1" }),
   56200 : ({ "ask", "陈三婶",       "chen",               "烹鱼技艺",        "1" }),
   56300 : ({ "ask", "陈四娘",       "chen",               "烹鱼技艺",        "1" }),
   56400 : ({ "ask", "陈四婆",       "chen",               "烹鱼技艺",        "1" }),
   56500 : ({ "ask", "陈四妈",       "chen",               "烹鱼技艺",        "1" }),
   56600 : ({ "ask", "陈四嫂",       "chen",               "烹鱼技艺",        "1" }),
   56700 : ({ "ask", "陈四婶",       "chen",               "烹鱼技艺",        "1" }),

   60000 : ({ "ask", "官人",         "guan ren",           "互访",              "1" }),
   60100 : ({ "ask", "大姑奶",       "da gunai",           "捐助水陆大会",      "1" }),
   60200 : ({ "ask", "二姑奶",       "er gunai",           "捐助水陆大会",      "1" }),
   60300 : ({ "ask", "小姑奶",       "xiao gunai",         "捐助水陆大会",      "1" }),
   60400 : ({ "ask", "大嫂子",       "da saozi",           "捐助水陆大会",      "1" }),
   60500 : ({ "ask", "小嫂子",       "xiao saozi",         "捐助水陆大会",      "1" }),
   60600 : ({ "ask", "小妾",         "xiao qie",           "捐助水陆大会",      "1" }),
   60700 : ({ "ask", "二妾",         "er qie",             "捐助水陆大会",      "1" }),
   60800 : ({ "ask", "大小姐",       "da xiaojie",         "捐助水陆大会",      "1" }),
   60900 : ({ "ask", "二小姐",       "er xiaojie",         "捐助水陆大会",      "1" }),
   61000 : ({ "ask", "花姐儿",       "hua jieer",          "捐助水陆大会",      "1" }),
   61200 : ({ "ask", "小姐",         "xiaojie",            "捐助水陆大会",      "1" }),

   70000 : ({ "ask", "大少爷",       "da shaoye",          "捐助水陆大会",      "1" }),
   70100 : ({ "ask", "二少爷",       "er shaoye",          "捐助水陆大会",      "1" }),
   70200 : ({ "ask", "小少爷",       "xiao shaoye",        "捐助水陆大会",      "1" }),
   70300 : ({ "ask", "大痞子",       "da pizi",            "捐助水陆大会",      "1" }),
   70400 : ({ "ask", "小痞子",       "xiao pizi",          "捐助水陆大会",      "1" }),
   70500 : ({ "ask", "小官人",       "xiao guanren",       "捐助水陆大会",      "1" }),
   70600 : ({ "ask", "大公子",       "da gongzi",          "捐助水陆大会",      "1" }),
   70700 : ({ "ask", "二公子",       "er gongzi",          "捐助水陆大会",      "1" }),
   70800 : ({ "ask", "少公子",       "shao gongzi",        "捐助水陆大会",      "1" }),
   70900 : ({ "ask", "花公子",       "hua gongzi",         "捐助水陆大会",      "1" }),
   71000 : ({ "ask", "浪公子",       "lang gongzi",        "捐助水陆大会",      "1" }),
   71100 : ({ "ask", "公子",         "gongzi",             "捐助水陆大会",      "1" }),
   71200 : ({ "ask", "王孙",         "wang sun",           "捐助水陆大会",      "1" }),

   72000 : ({ "ask", "灵宝道君",     "lingbao daojun",     "主持道场",           "1" }),
   72100 : ({ "ask", "太上老君",     "taishang laojun",    "主持道场",           "1" }),
   72200 : ({ "ask", "元始天尊",     "yuanshi tianzun",    "主持道场",           "1" }),

   75000 : ({ "ask", "布道法师",     "budao fashi",        "来唐布道",           "1" }),
   75100 : ({ "ask", "祭官",         "ji guan",            "祭祀术",             "1" }),
   75200 : ({ "ask", "慈悲和尚",     "cibei heshang",      "佛法",               "1" }),
   75300 : ({ "ask", "灯官",         "deng guan",          "制灯术",             "1" }),
   75400 : ({ "ask", "店主",         "dian zhu",           "烹调术",             "1" }),
   75500 : ({ "ask", "府令",         "fu ling",            "西域民法",           "1" }),
   75600 : ({ "ask", "府官",         "fu guan",            "西域民法",           "1" }),
   75700 : ({ "ask", "上官郡主",     "shangguan junzhu",   "祈雨术",             "1" }),
   75800 : ({ "ask", "上官仪",       "shangguan yi",       "祈雨术",             "1" }),
   75900 : ({ "ask", "上官阿人",     "shangguan aren",     "祈雨术",             "1" }),
   76000 : ({ "ask", "上官申尜",     "shangguan shenga",   "祈雨术",             "1" }),
   76100 : ({ "ask", "上官曲岸",     "shangguan quan",     "祈雨术",             "1" }),
   76200 : ({ "ask", "老王爷",       "lao wangye",         "来访大唐国",         "1" }),
   76300 : ({ "ask", "大王子",       "da wangzi",          "来访大唐国",         "1" }),
   76400 : ({ "ask", "二王子",       "er wangzi",          "来访大唐国",         "1" }),
   76500 : ({ "ask", "小王子",       "xiao wangzi",        "来访大唐国",         "1" }),
   76600 : ({ "ask", "老者",         "oldman",             "避火法",             "1" }),
   76700 : ({ "ask", "土地",         "tudi",               "火焰山",             "1" }),
   76800 : ({ "ask", "张铁臂",       "blacksmith",         "锻铁术",             "1" }),
   76900 : ({ "ask", "茶花娘子",     "chahua niangzi",     "茶道",               "1" }),
   77000 : ({ "ask", "鹤发老童",     "hefa laotong",       "西域药理",           "1" }),

   80000 : ({ "ask", "金顶大仙",     "jinding daxian",     "取经",               "1" }),
   80100 : ({ "ask", "阿傩尊者",     "anuo zunzhe",        "取经",               "1" }),
   80200 : ({ "ask", "迦叶尊者",     "jiaye zunzhe",       "取经",               "1" }),
   80300 : ({ "ask", "接引佛祖",     "jieyin fuzu",        "取经",               "1" }),
   80400 : ({ "ask", "优婆塞",       "youpo sai",          "取经",               "1" }),
   80500 : ({ "ask", "优婆夷",       "youpo yi",           "取经",               "1" }),
//   80600 : ({ "ask", "比丘僧",       "biqiu seng",         "取经",               "1" }),
//   80700 : ({ "ask", "比丘尼",       "biqiu ni",           "取经",               "1" }),
//   80800 : ({ "ask", "金刚",         "jin gang",           "取经",               "1" }),
//   80900 : ({ "ask", "菩萨",         "pu sa",              "取经",               "1" }),
   81000 : ({ "ask", "白髯土地",     "tu di",              "西域民俗",           "1" }),

  100000 : ({ "ask", "白无常",       "bai wuchang",        "比武",               "1" }),
  100500 : ({ "ask", "黑无常",       "hei wuchang",        "比武",               "1" }),
  101000 : ({ "ask", "王方平",       "wang fangping",      "比武",               "1" }),
  101500 : ({ "ask", "阴长生",       "yin changsheng",     "比武",               "1" }),
  102000 : ({ "ask", "郁垒",         "yu lei",             "比武",               "1" }),
  102500 : ({ "ask", "神荼",         "shen tu",            "比武",               "1" }),
  103000 : ({ "ask", "桥梁使者",     "bridge guard",       "奈何桥",             "1" }),
  103500 : ({ "ask", "断足鬼",       "duanzu gui",         "可怜人",             "1" }),
  104000 : ({ "ask", "牛头鬼",       "niutou gui",         "比武",               "1" }),
  104500 : ({ "ask", "马面鬼",       "mamian gui",         "比武",               "1" }),

  150000 : ({ "ask", "阎罗王",       "yanluo wang",        "生死",               "1" }),
  151000 : ({ "ask", "轮转王",       "lunzhuan wang",      "生死",               "1" }),
  152000 : ({ "ask", "卞城王",       "biancheng wang",     "生死",               "1" }),
  153000 : ({ "ask", "都市王",       "dushi wang",         "生死",               "1" }),
  154000 : ({ "ask", "泰山王",       "taishan wang",       "生死",               "1" }),
  155000 : ({ "ask", "仵官王",       "chuguan wang",       "生死",               "1" }),
  156000 : ({ "ask", "平等王",       "pingdeng wang",      "生死",               "1" }),
  157000 : ({ "ask", "宋帝王",       "songdi wang",        "生死",               "1" }),
  158000 : ({ "ask", "楚江王",       "chujiang wang",      "生死",               "1" }),
  159000 : ({ "ask", "秦广王",       "qinguang wang",      "生死",               "1" }),
  160000 : ({ "ask", "地藏王菩萨",   "dizang pusa",        "生死",               "1" }),

  170000 : ({ "ask", "孤直公",       "guzhi gong",         "诗歌",               "1" }),
  175000 : ({ "ask", "凌空子",       "lingkong zi",        "诗歌",               "1" }),
  180000 : ({ "ask", "十八公",       "shiba gong",         "诗歌",               "1" }),
  185000 : ({ "ask", "拂云叟",       "fuyun sou",          "诗歌",               "1" }),
  190000 : ({ "ask", "杏仙",         "xing xian",          "讲习成精法术",       "1" }),

  200000 : ({ "ask", "康安裕",       "kang anyu",          "比武",               "1" }),
  210000 : ({ "ask", "张伯时",       "zhang boshi",        "比武",               "1" }),
  220000 : ({ "ask", "姚公麟",       "yao gonglin",        "比武",               "1" }), 
  230000 : ({ "ask", "李焕章",       "li huanzhang",       "比武",               "1" }),
  240000 : ({ "ask", "直健",         "zhi jian",           "拳法",               "1" }),
  250000 : ({ "ask", "郭申",         "guo shen",           "拳法",               "1" }),

  260000 : ({ "ask", "福星",         "fu xing",            "来访大唐国",         "1" }),
  270000 : ({ "ask", "寿星",         "shou xing",          "来访大唐国",         "1" }),
  280000 : ({ "ask", "禄星",         "lu xing",            "来访大唐国",         "1" }),
  290000 : ({ "ask", "军机大臣",     "jun ji",             "访问大唐国",         "1" }),
  300000 : ({ "ask", "井龙王",       "jing longwang",      "治水术",             "1" }),

//  810000 : ({ "ask", "仙童",         "xian tong",          "佛学",               "1" }),
//  820000 : ({ "ask", "阿罗",         "a luo",              "佛学",               "1" }),
//  830000 : ({ "ask", "揭谛",         "jie di",             "佛学",               "1" }),
//  840000 : ({ "ask", "白雄尊者",     "baixiong zunzhe",    "取经",               "1" }),
//  850000 : ({ "ask", "燃灯古佛",     "randeng gufo",       "取经",               "1" }),
//  860000 : ({ "ask", "如来佛",       "rulai fo",           "取经",               "1" }),

  900000 : ({ "ask", "二郎真君",     "erlang zhenjun",     "得道秘法",           "1" }),
  910000 : ({ "ask", "金圣宫",       "jinsheng gong",      "避妖术",             "1" }),
  920000 : ({ "ask", "毗蓝婆",       "pilan po",           "讲授佛学",           "1" }),
  930000 : ({ "ask", "圆清",         "yuan qing",          "讲授佛学",           "1" }),
 1000000 : ({ "ask", "大鹏明王",     "dapeng mingwang",    "大雪山参加水陆大会", "1" }),

]);


