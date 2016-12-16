// miscd.c
// by mon@xyj 10/19/98
// last modify by landis@myth 2001/08/28

string *dirs1 = ({
"/d/city",
"/d/westway",
"/d/kaifeng",
"/d/lingtai",
"/d/moon",
"/d/gao",
"/d/nanhai", 
"/d/eastway",
//"/d/myth/xuanyuan",
"/d/ourhome/honglou", 
});

string *dirs2 = ({
"/d/sea", 
"/d/xueshan",
//"/d/myth/suzhou",
"/d/shushan",
"/d/qujing/wuzhuang",
"/d/qujing/baotou", 
"/d/qujing/baoxiang", 
"/d/qujing/bibotan",
"/d/qujing/biqiu",
"/d/qujing/chechi",
"/d/qujing/dudi",
"/d/qujing/fengxian",
"/d/qujing/firemount",
"/d/qujing/jilei",
"/d/qujing/jindou",
"/d/qujing/jingjiling",
"/d/qujing/jinping",
"/d/qujing/jisaiguo",
"/d/qujing/maoying",
"/d/qujing/nverguo",
"/d/qujing/pingding",
"/d/qujing/pansi",
"/d/qujing/tongtian",
"/d/qujing/qilin",
"/d/qujing/qinfa",
"/d/qujing/qinglong",
"/d/qujing/tianzhu",
"/d/qujing/wudidong",
"/d/qujing/wuji",
"/d/qujing/xiaoxitian",
"/d/qujing/yinwu",
"/d/qujing/yuhua",
"/d/qujing/zhujie",
"/d/qujing/zhuzi",
});

string *dirs3 = ({
"/d/death",  
"/d/meishan",
"/d/qujing/lingshan",
"/d/penglai",
});

varargs mapping random_location(mixed flag)
{
        int i, j;
        string *dirs;
        string dir, tmp;
        object room;
        mapping location;
        mixed *exit, *file;

        location=allocate_mapping(4);
        switch(flag) {
                case 0:
                        dirs = dirs1;
                        break;
                case 1:
                        dirs = dirs1+dirs2;
                        break;
                case 2:
                        dirs = dirs1+dirs2+dirs3;
                        break;
        }

        i = random(sizeof(dirs));    // pick up one directory
        dir = dirs[i];
        file = get_dir( dir+"/*.c", -1 );

        do {
           j = random(sizeof(file));
           if( file[j][1] > 0 ) {
             tmp = file[j][0];
             room=find_object(dir+"/"+tmp);
           }
           if (!room) room=load_object(dir+"/"+tmp);
        } while ( !sizeof(file) ||
                  room->query("no_fight") ||
                  room->query("no_magic") ||
                  room->query("no_mieyao") ||
                  !room->query("short") ||
                  !(exit=room->query("exits")) ||
                  sizeof(exit)<2 );

        location["file"]=dir+"/"+tmp;
        location["room"]=room;
        return location;
}
