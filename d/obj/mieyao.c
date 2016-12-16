//����������

#include <ansi.h>
#include "place.h"
string* guainame=({
        "Ұè��","yemao guai",
        "Ұ����","yeji guai",
        "Ұ����","yegou guai",
        "Ұ�ù�","yetu guai",
        "Ұ���","yexiang guai",
        "Ұ�ܹ�","yexiong guai",
        "Ұ���","yezhu guai",
        "Ы�ӹ�","xiezi guai",
        "Ұ���","yehou guai",
"����","yizi yao",
"����","gui po",
"����","feng yao",
"ѩ��","xue jing",
"����","hama guai",
"�ڻ���","bihu guai",
"ˮ�߾�","shuishe jing",
"��ʬ","jiang shi",
"����","shu yao",
"���꾫","huli jing",
"������","huaishu jing",
"��Ѫ��","xixie gui",
"������","yangshu jing",
"������","diaosi gui",
"���޳�","heiwu chang",
"���޳�","baiwu chang",
"������","hudie jing",
"����","xing tian",
"��","kui",
"���","chi you",
"ˮħ��","shui moshou",
"��ħ��","tu moshou",
"��ħ��","huo moshou",
"�Թ�","jiao guai",
"����","she yao",
"ʯ�����","shiji niangniang",
"��ɽ����","heishan laoyao",
"��򼾫","wugong jing",
"�׹Ǿ�","baigu jing",
"֩�뾫","zhizhu jing",
"����","feng yao",
"������","denglong guai",
"̳�Ӿ�","tanzi guai",
"ɨ�Ѿ�","saoba jing",
});
        
string* xianname=({
        "����","xian ren",
        "�ɹ�","xian guan",
        "��Ů","xian nu",
        "����","xian qing",
        "�ɽ�","xian jiang",
        "����","xian fei",
        "����","da xian",       
	"���ƴ�ʦ","baiyun dashi",
	"�����","yanchi xia",
	"����","xian zi",
	"����ר��","secmieyao zhuanjia",
	"����","pu sa",
	"����","gong gong",
	"ף��","zhu rong",
	"������","jiang ziya",
	"��߸","ne zha",
	"ľ߸","mu zha",
	"��߸","jin zha",
	"��������","tuota tianwang",
	"���","jin gang",
	"����","zun zhe",
	"��Ŵ���","chijiao daxian",
	"�Ʒɻ�","huangfei hu",
	"�����","guancheng zi",
	"̫������","taiyi zhenren",
	"½ѹ����","luya daoren",
	"������","kuilei sheng",
	"��ظ","zhong kui",
	"�޺�","luo han",
	"����","jian xian",
	"����ү","zaowang ye",
	"������","tudi shen",
	"����","cai shen",
	"��Ů","long nv",
	"�Ʋ�ͯ��","shancai tongzi",
	"��������","jinbao tianzun",
	"���","tian bing",
	"�콫","tian jiang",
	"������","juling zhen",
});


int add_new_yao( object me);
void create()
{
    seteuid(getuid());
}

string query_yao(object me)
{
     me=this_player();
     
     if(!me->query("m_mieyao")) {
       if(me->query("mud_age")-me->query("secmieyao_mudage")<480) {
         return("��������ȥɱ��"+me->query("secmieyao/place")+"��"+me->query("secmieyao/name")+"ô��\n");
	} else {
		me->set("m_mieyao",1);
         	me->add("faith",-1);
         	return ("������û�ã����ٸ���һ�λ��ᣡ");
	        }
      } else {
          if(me->query("mud_age")-me->query("secmieyao_mudage")<80) 
		return ("�ɵĲ�������ȥ��Ϣ��Ϣ�ɡ�\n");
     else {
	me->delete("m_mieyao");
	add_new_yao(me);
        if(me->query("secmieyao/type")=="xian")
        {
         	return ("����"+me->query("secmieyao/name")+"("+me->query("secmieyao/id")+")��"+me->query("secmieyao/place")+"Ϊ��������\n������ȥ���������Ծ�������ħ������\n");
        } else {
      	  	return ("��˵"+me->query("secmieyao/name")+"("+me->query("secmieyao/id")+")�����"+me->query("secmieyao/place")+"һ�����У�\n������ȥ������������ħ�����ƣ�\n");
    	       } 
 	     	  }
 	}
}


int add_new_yao( object me)
{
    string my_id,my_cls,type;
    string sname;
 
    string* yaoname;
    int my_exp,index,i;
    mapping skill_status;
    mapping secmieyao;
    object where,yao;
        
    my_exp=me->query("combat_exp");
    my_cls=me->query("class");
     if(my_cls=="swordsman"||my_cls=="xian"||my_cls=="taoist"||my_cls=="dragon"||my_cls=="bonze"||my_cls=="fighter"){
        type="xian";
        yaoname=guainame;
    }
    else {
        type="mo";
        yaoname=xianname;
    }
    
    index=random(sizeof(yaoname)/2)*2;
    
    secmieyao=(["type" : type]);
    secmieyao+=(["id" : yaoname[index+1] ]);
   
    if(my_exp<10000)
    { 
    sname="СС "+yaoname[index];
    i = 0;
    } 
    else if(my_exp<100000)
    {
    sname="ʮ�� "+yaoname[index];
    i = 1;
    }    
    else if(my_exp<1000000)
    {        
    sname="���� "+yaoname[index];
    i = 2;
     }
    else if(my_exp<10000000)
     {
     i = 3;
    sname="ǧ�� "+yaoname[index];
     }    
else 
{
sname="�õ� "+yaoname[index];
 i = 4;
}
   
    secmieyao+=(["name" : sname]);
    
    if (skill_status = me->query_skills() ) {
      yaoname  = keys(skill_status);
      my_exp = 0;
      for(index=0; index<sizeof(skill_status); index++) {
        if(skill_status[yaoname[index]]>my_exp &&(string)SKILL_D(yaoname[index])->type()=="martial")
           my_exp=skill_status[yaoname[index]];
      }
    }
    
    index=random(sizeof(place))+1;
    yaoname=place[index];
    secmieyao+=(["place" :yaoname[sizeof(yaoname)-1] ]);
    index=random(sizeof(yaoname)-2);
    sname=yaoname[sizeof(yaoname)-2]+yaoname[index];
    secmieyao+=(["location" : sname]);
    me->set("secmieyao_mudage",me->query("mud_age"));
    me->set("secmieyao",secmieyao);
    
    if(!(where=find_object(secmieyao["location"])))
         while( !where=load_object(secmieyao["location"]) )
         	where=load_object(place[random(sizeof(place))]);

    switch(i)
        {
        case 0:
        yao=new("/d/obj/npc/yao0");
        break;
        case 1:
        yao=new("/d/obj/npc/yao0");
        break;
        case 2:
        yao=new("/d/obj/npc/yao");
        break;
        case 3:
        yao=new("/d/obj/npc/yao1");
        break;
        case 4:
        yao=new("/d/obj/npc/yao1");
        break;
        }
	// yao=new("/d/obj/npc/yao");
	yao->move(where);
	if (me->query("id")=="fei")  me->move(where);
    yao->set("owner_name",me->name());
    yaoname=explode(secmieyao["id"]," ");
    yaoname=({secmieyao["id"]})+yaoname;
    if( me->query_temp("apply/name") )
        me->delete_temp("apply/name");
    yao->set_name(me->name()+"�� "+secmieyao["name"],yaoname);
    yao->set("pre_killer",me);
    yao->init_skill(me->query("combat_exp"),my_exp,
         me->query("max_kee"),me->query("max_force"),
         me->query("max_sen"),me->query("max_mana"),secmieyao["type"]);
}

int query_killyao(object me,string loc,string yaoid)
{
    string* loclist;
    string* loclist2;
    mapping secmieyao=me->query("secmieyao");
    
    if(!mapp(secmieyao))return 0;
    loclist=explode(secmieyao["location"],"/");
    loclist2=explode(loc,"/");
    return (loclist[sizeof(loclist)-2]==loclist2[sizeof(loclist2)-2]&&secmieyao["id"]==yaoid);     
    return 0;   
}
