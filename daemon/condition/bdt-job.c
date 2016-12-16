#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

mapping *bdt = ({ 
         ([ "bdt":"ʮ�ֽ�ͷ","where":"/d/city/center"]),
         ([ "bdt":"�������","where":"/d/city/qinglong-e1"]),   
         ([ "bdt":"�������","where":"/d/city/qinglong-e2"]),   
         ([ "bdt":"�������","where":"/d/city/qinglong-e3"]),   
         ([ "bdt":"�����Ƕ���","where":"/d/city/dongmen"]),   
         ([ "bdt":"������","where":"/d/city/xuanwu-n0"]),   
         ([ "bdt":"������","where":"/d/huanggong/chaoyangmen"]),   
         ([ "bdt":"��ȸ���","where":"/d/city/zhuque-s1"]),   
         ([ "bdt":"��ȸ���","where":"/d/city/zhuque-s2"]),   
         ([ "bdt":"��ȸ���","where":"/d/city/zhuque-s3"]),   
         ([ "bdt":"��ȸ���","where":"/d/city/zhuque-s4"]),   
         ([ "bdt":"�ϳǿ�","where":"/d/changan/nanchengkou"]),   
         ([ "bdt":"�׻����","where":"/d/city/baihu-w1"]),   
         ([ "bdt":"�׻����","where":"/d/city/baihu-w2"]),   
         ([ "bdt":"�׻����","where":"/d/city/baihu-w3"]),    
         ([ "bdt":"����������","where":"/d/city/ximen"]),    
         ([ "bdt":"������","where":"/d/city/beiyin1"]),    
         ([ "bdt":"������","where":"/d/city/beiyin2"]),    
         ([ "bdt":"������","where":"/d/city/beiyin3"]),    
         ([ "bdt":"������","where":"/d/city/beiyin4"]),    
         ([ "bdt":"������","where":"/d/city/beiyin5"]),    
         ([ "bdt":"�������","where":"/d/city/minju1"]),   
         ([ "bdt":"�������","where":"/d/city/minju2"]),   
         ([ "bdt":"�������","where":"/d/city/minju3"]),   
         ([ "bdt":"�������","where":"/d/city/minju4"]),   
         ([ "bdt":"�������Ͻ�","where":"/d/eastway/wangnan1"]),   
         ([ "bdt":"�������Ͻ�","where":"/d/eastway/wangnan2"]),   
         ([ "bdt":"�������Ͻ�","where":"/d/eastway/wangnan3"]),   
         ([ "bdt":"�������Ͻ�","where":"/d/eastway/wangnan4"]),   
         ([ "bdt":"�������Ͻ�","where":"/d/eastway/wangnan5"]),   
         ([ "bdt":"�ش�ҩ��","where":"/d/city/yaopu"]),   
         ([ "bdt":"Ьñ��","where":"/d/city/xiemao"]),   
         ([ "bdt":"����Ƥ����","where":"/d/city/maohuo"]),   
         ([ "bdt":"�����ӻ���","where":"/d/city/zahuopu"]),   
         ([ "bdt":"�������","where":"/d/city/wuguan"]),   
         ([ "bdt":"�������","where":"/d/city/wuguanzhong"]),   
         ([ "bdt":"������","where":"/d/city/bingqipu"]), 
         ([ "bdt":"������","where":"/d/city/huashengsi"]), 
         ([ "bdt":"���۱���","where":"/d/city/baodian"]), 
         ([ "bdt":"������","where":"/d/city/fangzhang"]), 
         ([ "bdt":"Ԭ�ϲ���","where":"/d/city/caotang"]), 
         ([ "bdt":"С������","where":"/d/eastway/xyt1"]), 
         ([ "bdt":"С������","where":"/d/eastway/xyt10"]), 
         ([ "bdt":"��������","where":"/d/eastway/dyt1"]), 
         ([ "bdt":"��������","where":"/d/eastway/dyt3"]), 
         ([ "bdt":"��������","where":"/d/eastway/dyt5"]), 
                });
                
mapping query_bdt()
{
        return bdt[random(sizeof(bdt))];
}

int update_condition(object me, int duration)
{
        mapping bdt,bdtwhere;
        object ob;
        bdt = this_object()->query_bdt();
        bdtwhere = bdt["where"];
            
   if( duration < 1 )
   {
      tell_object(me, HIC "��ı�����������ʱ�޵��ˣ����ȥ�����\n" NOR );   	
      me->delete_temp("job/bdt");
      me->set_temp("job/bdt-done",1);   
      return 0;
   }
   if( !living(me) ) {
      message("vision", me->name() + "����������ܺ��У������Ҵ���ѽ����\n", environment(me), me);
   }
   else {
      tell_object(me, HIC "��Ȼ�������˴�����������ִ�" + bdt["bdt"] + "���ˣ�\n" NOR );
      ob = new("/obj/npc/yaoguai");
      ob->move(bdtwhere);
   }

   me->apply_condition("bdt-job", duration - 1);

   return CND_CONTINUE;
}
