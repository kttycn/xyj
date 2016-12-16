// miscd.c
// by mon@xyj 10/19/98

#pragma optimize

#include <ansi.h>

inherit F_DBASE;

mapping maps=([]);

string *dirs1 = ({
"/d/city",
"/d/westway",
"/d/jjf",
"/d/kaifeng",
"/d/lingtai",
"/d/moon",
"/d/gao",
"/d/nanhai", 
"/d/eastway",
"/d/qujing/xuanyuan",
"/d/ourhome/honglou", 
});

string *dirs2 = ({
"/d/sea", 
"/d/xueshan",
//"/d/myth/suzhou",
"/d/shushan",
"/d/wusheng",
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

void create()
{
   string filename=__DIR__"find.map";
   string buf, *buf1;
   string dir, name;
   int size, i;

   seteuid(getuid());
   set("name", "��ؾ���");
   set("id", "miscd");

   maps=([]);

   buf=read_file(filename);
   if(!buf) return; //no data available.

   buf1=explode(buf,"\n");
  
   if(!(size=sizeof(buf1))) return;

   for(i=0;i<size;i++) {
     if(sscanf(buf1[i],"%s %s",dir,name)==2) {
       name=replace_string(name," ","");
       if(strlen(dir)>2 && strlen(name)>2) {
         maps+=([dir:name]);
       }
     }
   }
}
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

int random_capture(object me,int chance,int silent)
{
        if(!me) return 0;
        if(!chance) chance=5000;
//	if(wizardp(me)) chance=1;

        if(random(chance)==0) {
	    if(silent)
                tell_object(me,"\n��Ȼһ��Ʒ��Х�����������ɼ�"+
                    "�����˽�ȥ��\n");
	    else
                message_vision("\n��Ȼһ��Ʒ��Х������$N���ɼ�"+
                    "�����˽�ȥ��\n",me);
            tell_object(me,"\n��֪���˶�ã�����\n\n");
            me->set_temp("old_place",environment(me));
            me->move("/d/qujing/baihuling/jail",1);
            message_vision("$N���ص�һ��ˤ�ڵ��ϣ�\n",me);
            return 1;
        }
	return 0;
}


string find_place(object where)
{
	string fail, filename, filename1, answer; //msg,
	int len;

	fail=""; // default fail message

        filename=file_name(where);
	len=strlen(filename);
	if(len<2) return fail;

        len--;
        while(filename[len]!='/' && len>0) {
	  len--;
	}
	if(len<2) return fail;

	filename1=filename[1..(len-1)];

        if(sscanf(filename,"/d/changan/bed#%*s")==1) {
	//this need check first.
	  answer="����";
        } else if(!undefinedp(maps[filename1])) {
	  answer=maps[filename1];
	} else if(where->is_character()) {
	  answer=where->query("name")+"����";
        } else if(sscanf(filename,"/obj/home#%*s")==1) {
          answer="ס����";
        } else { 
          answer=undefinedp(where->query("short"))?
		  where->short():
		  where->query("short");
        }

	return answer;
}


	
