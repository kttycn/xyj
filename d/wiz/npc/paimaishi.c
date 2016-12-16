// ÅÄÂôÊ¦
//stone modify

inherit NPC;
#include <ansi.h>;
int begin_paimai(string name,int value ,int paimai_count,int m);
int go_paimai(string id,string name,int value,int num,int m);
int report_paimai(object buyer,int money,int num);
int finish_paimai(int num,int sign);
int pay_back(string id, int amount);
int delete_ob(int num);
void create()
{
        set_name("ÅÄÂôÊ¦", ({ "paimai shi", "ji", "shi" }) );
                set("nickname", HIW "ÌìÏÂµÚÒ»´¸" NOR);
        set("gender", "ÄĞĞÔ");
        set("age", 45);
        set("no_get", 1);
        set("long",
                "ÕâÊÇÒ»Î»Êİ¸ßµÄÖĞÄêÈË£¬ÒòÎª¹«ÕıÎŞË½¶ø±»ÍÆÎªÌìÏÂµÚÒ»ÅÄÂôÊ¦¡£\n");
        set("combat_exp",600000);
//        set("shen", 0);
        set("attitude", "friendly");
        set("apply/attack", 100);
        set("apply/defense", 100);

        set("max_kee", 800);
        set("max_gin", 800);
        set("max_sen", 800);
        set("max_force", 8000);
        set("eff_force",8000);
        set("force",8000);

        set_skill("force", 300);
        set_skill("unarmed", 300);
        set_skill("sword",300);
        set_skill("parry",300);
        set_skill("dodge", 300);

            setup();
            
	carry_object("/d/obj/cloth/choupao")->wear(); 
}


void init()
{
        ::init();
        add_action("do_paimai", "paimai");
        add_action("do_paimailist", "paimailist");
        add_action("do_yao", "yao");

}
int do_paimai(string arg)
{
        object who,ob;
        int money,clone_number,paimai_count,i,value,sale_price;
        string id,file_name;
        mapping fpaimai,vpaimai,ipaimai,npaimai,lpaimai,opaimai,spaimai;
        string* terms;

        fpaimai = query("fpaimai");
        vpaimai = query("vpaimai");
        ipaimai = query("ipaimai");
        npaimai = query("npaimai");
        lpaimai = query("lpaimai");
        opaimai = query("opaimai");
        spaimai = query("opaimai");

        who=this_player();

        if( who->is_busy() )
         return notify_fail("ÄãµÄ¶¯×÷»¹Ã»ÓĞÍê³É£¬²»ÄÜÌá½»ÎïÆ·½øĞĞÅÄÂô¡£\n");
    if( !arg || sscanf(arg, "%s with %d",id, money)!=2 )
                return notify_fail("Ö¸Áî¸ñÊ½£ºpaimai <ÎïÆ·id> with <µ×¼Û(silverÎªµ¥Î»)> \n");
        if( !ob=present(id, who))
                return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷¡£\n");
        if( ob->query("money_id") )
                return notify_fail("ÄãÒªÅÄÂô¡¸Ç®¡¹£¿\n");

        if (ob->query("value")==0 || money==0)
                return notify_fail("²»ÖµÇ®£¬Äã¾Í±ğÂôÁË£¡\n");
        if (ob->query("no_paimai"))
                return notify_fail("ÕâÑù¶«Î÷²»ÄÜÅÄÂôÁË£¡\n");
        if (who->query("balance")<100)
                return notify_fail("ÄãÕËºÅÀïµÄÇ®²»¹»Ö§¸¶ÊÖĞø·Ñ£¡\n");
        who->add("balance",-100);

        command("jy "+"ÓĞÈËÌá½»"+NOR+ob->query("name")+HIW+"½øĞĞÅÄÂô¡£"NOR);
        sscanf(file_name(ob),"%s#%d",file_name,clone_number);

        if( mapp(fpaimai) &&  sizeof(fpaimai) )
                add("total_number",1);
        else
                set("total_number",0);

        value = ob->query("value");
        sale_price= ob->query_temp("sale_price");
        if (sale_price>0)
                sale_price= sale_price>value?value:sale_price;

        set("fpaimai/"+ sprintf("%d",query("total_number")),file_name);
        set("vpaimai/"+sprintf("%d",query("total_number")), money);
        set("ipaimai/"+sprintf("%d",query("total_number")), who->query("id"));
        set("npaimai/"+sprintf("%d",query("total_number")), ob->query("name"));
        set("lpaimai/"+sprintf("%d",query("total_number")), 1);
        set("opaimai/"+sprintf("%d",query("total_number")), who->query("id"));
        set("spaimai/"+sprintf("%d",query("total_number")), sale_price);

        if (query("total_number")==0 || query("lpaimai/"+sprintf("%d",query("number")))==0)
        {
                set("value",money);
                set("pnum",0);
                set("number",query("total_number")>0?query("number")+1:0);
                call_out("begin_paimai",15,ob->query("name"),money,query("number"),0);
        }
        destruct(ob);
        return 1;
}
int begin_paimai(string name,int money,int num,int m)
{
        m+=1;
        if (m==1)
        {
                command("jy "+"ÏÖÔÚ¿ªÊ¼ÅÄÂô "NOR+name+HIW+" µÄËùÓĞÈ¨¡£"+NOR);
        }
        set("on_paimai",1);
        command("jy  "+NOR+name+HIW+" µ×¼Û "+chinese_number(money)+"Á½Òø×Ó µÚ"+chinese_number(m)+"´Î");
        if (!(m==3))
                call_out("begin_paimai",20,name,money,num,m);
        else
                call_out("finish_paimai",2,num,0);
}
int finish_paimai(int num,int sign)
{
        string id,owner_id;
        object buyer,owner;
        int i;


        id=query("ipaimai/" + sprintf("%d", num));
        owner_id=query("opaimai/" + sprintf("%d", num));
        set("lpaimai/"+sprintf("%d",num), 0);

        buyer=find_player(id);
        owner=find_player(owner_id);
        if (sign==0)
        {
                if(owner)
                        tell_object(owner,HIR"ÄãµÄ¶«Î÷Ã»ÓĞÂô³öÈ¥£¬ÇëÔÚÊ®·ÖÖÓÄÚÀ´ÄÏ³Ç¿ÍÕ»¶şÂ¥Õä±¦Õ«È¡»Ø×Ô¼ºµÄÎïÆ·¡£\n"NOR);
        }
        else
        {
                command("jy  ³É½»!"+buyer->query("id")+"»ñµÃÁË "+NOR+query("npaimai/" + sprintf("%d", num))+HIW+" µÄËùÓĞÈ¨¡£"+NOR);
                if (buyer)
                        tell_object(buyer,HIR"Äã»ñµÃÁË "+NOR+query("npaimai/" +sprintf("%d", num))+HIR+" µÄËùÓĞÈ¨£¬ÇëÔÚÊ®·ÖÖÓÄÚÀ´ÄÏ³Ç¿ÍÕ»¶şÂ¥Õä±¦Õ«È¡»ØÄãÂòµÄ¶«Î÷¡£\n"NOR);
                if (owner)
                        tell_object(owner,HIR"ÄãµÄ"+NOR+query("npaimai/" + sprintf("%d", num))+HIR+"ÂôÁË"
                        +chinese_number(query("vpaimai/" + sprintf("%d", num)))+"Á½Òø×Ó£¬¿Û³ı5%ÊÖĞø·Ñ£¬ÆäÓàµÄÒÑ¾­¼ÓÈëÄãµÄ»§Í·ÁË¡£\n"NOR);
        }
        set("on_paimai",0);

        pay_back(owner_id,query("vpaimai/" + sprintf("%d", num))*95);

        call_out("delete_ob",36000,num);

        num=num+1;
        if (query("lpaimai/" + sprintf("%d", num))==1)
        {
                set("value",query("vpaimai/" + sprintf("%d", num)));
                set("number",num);
                set("pnum",0);
                call_out("begin_paimai",5,query("npaimai/" + sprintf("%d", num)),query("vpaimai/" + sprintf("%d", num)),num,0);
        }
        return 1;
}
int report_paimai(object buyer,int money,int num)
{
        remove_call_out("begin_paimai");
        remove_call_out("finish_paimai");
        remove_call_out("go_paimai");

        if (query("pnum"))
        {
                pay_back(query("ipaimai/" + sprintf("%d", num)),query("vpaimai/" + sprintf("%d", num))*100);
        }
        add("pnum",1);
        buyer->add("balance",(0-money*100));
        set("vpaimai/"+sprintf("%d",num), money);
        set("ipaimai/"+sprintf("%d",num), buyer->query("id"));
        set("value",money);
        command("jy  "+buyer->query("id")+" ³ö¼Û "+chinese_number(money)+"Á½Òø×Ó ¹ºÈë"+NOR+query("npaimai/" + sprintf("%d", num))+HIW"µÄËùÓĞÈ¨¡£");
        call_out("go_paimai",5,buyer->query("id"),query("npaimai/" + sprintf("%d", num)),money,num,0);
        return 1;
}
int pay_back(string id, int amount)
{
    object who;

    who=find_player(id);
    if(who)
        {
                who->add("balance",amount);
                if(!who->save(1))
                {
                        log_file("paimai_log","Failed to return "+amount+
                                " coin to "+id+"\n");
                        return 0;
                }
        log_file("paimai_log","pay "+amount+" to "+id+"\n");
        return 1;
    }
        else
        {
                who=new(USER_OB);
                who->set("id",id);
                if(!who->restore())
                {
                        log_file("paimai_log","Failed to return "+amount+
                                " coin to "+id+"\n");
                        destruct(who);
                        return 0;
                }
                else
                {
                        who->add("balance",amount);
                        if(!who->save(1))
                        { // save(1) will not erase autoload.
                                log_file("paimai_log","Failed to return "+amount+" coin to "+id+"\n");
       				destruct(who);
                                return 0;
                        }
                        log_file("paimai_log","pay "+amount+" to "+id+"\n");
                        destruct(who);
                        return 1;
                }
    }
}
int go_paimai(string id,string name,int money,int num,int m)
{
        m+=1;
        command("jy  "+id+" ³ö¼Û "+chinese_number(money)+"Á½Òø×Ó ¹ºÈë "+NOR+name+HIW+" µÄËùÓĞÈ¨£
¬µÚ"+chinese_number(m)+"´Î");
        if (!(m==3))
                call_out("go_paimai",20,id,name,money,num,m);
        else
                call_out("finish_paimai",5,num,1);
}
int do_paimailist()
{
        int i;

        for(i=query("number")+1;;i++)
        {
                if (query("lpaimai/" + sprintf("%d", i))==1)
                {
                        printf("%-10s£º µ×¼Û %-3d Á½Òø×Ó \n",query("npaimai/" +sprintf("%d", i)),query("vpaimai/" + sprintf("%d", i)));
                }
                else
                        return 1;
        }
        return 1;
}
int do_yao()
{
        mapping fpaimai,vpaimai,ipaimai,npaimai,lpaimai,spaimai;
        string* terms;
        string id;
        object ob;
        int i;

        fpaimai = query("fpaimai");
        vpaimai = query("vpaimai");
        ipaimai = query("ipaimai");
        npaimai = query("npaimai");
        lpaimai = query("lpaimai");
        spaimai = query("spaimai");

        if( mapp(fpaimai) &&  sizeof(fpaimai) )
        {
                terms=keys(fpaimai);

                for(i=0;i<sizeof(terms);i++)
                {
                        if (ipaimai[terms[i]]==this_player()->query("id") && lpaimai[terms[i]]==0)
                        {
                                ob=new(fpaimai[terms[i]]);
                                if (spaimai[terms[i]]>0)
                                        ob->set_temp("sale_price",spaimai[terms[i]]);
                                ob->move(this_player());
                                ipaimai[terms[i]]="paimai shi";
                                message_vision(CYN+"ÅÄÂôÊ¦½«"+NOR+npaimai[terms[i]]+CYN+"½»¸ø$N¡£\n", this_player(),this_object());
                                return 1;
                        }
                }
        }
        tell_object(this_player(),"ÕâÀïÃ»ÓĞÊôÓÚÄãµÄÎïÆ·¡£\n");
        return 1;
}
int delete_ob(int num)
{
        delete("npaimai/"+sprintf("%d",num));
        delete("ipaimai/"+sprintf("%d",num));
        delete("vpaimai/"+sprintf("%d",num));
        delete("lpaimai/"+sprintf("%d",num));
        delete("fpaimai/"+sprintf("%d",num));
        delete("spaimai/"+sprintf("%d",num));

        return 1;
}
