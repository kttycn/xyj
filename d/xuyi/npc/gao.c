// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

//created by night 7/24/2000

inherit NPC;
string zhuzao(object me);

void create()
{
        set_name("����", ({"gao xiang", "gao"}));
        set("gender", "����" );
        set("title", "������ʦ");
        set("age", 33);
        set("long", "����ɽ���Ƕ��ڶ��������еĽܳ���������������졣\n");
        set("combat_exp", 60000);
        set("attitude", "friendly");
        set("int", 40);
        set("str", 40);
        set("spi", 40);
        set("per", 40);
        set("kar", 40);
        set("cps", 40);
        set("con", 40);
        set("cor", 40);
        set("class", "taoist");

        set("eff_dx", 40000);
        set("nkgain", 300);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("spells", 20);  
        set_skill("dao", 20);
        set_skill("literate", 20);
        set_skill("stick", 20);  
        set_skill("qianjun-bang", 20);
        set_skill("puti-zhi", 20);  
        set_skill("jindouyun", 20);
        set_skill("dodge", 20);
        set_skill("force", 20);   
        set_skill("wuxiangforce", 20);

        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");

        set("max_kee", 300);
        set("max_gin", 300);
        set("max_sen", 200);
        set("force", 200);
        set("max_force", 100);
        set("force_factor", 10);
        set("mana", 400);
        set("max_mana", 200);
        set("mana_factor", 10);
        
        set("inquiry", ([
                "name" : "�����ո����裬ƫ���ڴˡ�\n",
                "here" : "����������ɽ�������ڡ�\n", 
            "����" : (: zhuzao :),
            "����" : (: zhuzao :),            
            "weapon" : (: zhuzao :),
         ]) );
        
        setup();
//        carry_object("/d/lingtai/obj/daoguan")->wear();
        carry_object("/d/lingtai/obj/cloth")->wear();
//        carry_object("/d/obj/weapon/stick/xiangmo")->wield();
}

string zhuzao(object me)
{
        object ob;
        me = this_player();

        if(me->query_temp("add_damage"))
        {
                message_vision("�����Թ��Ե�������ǽ�ϵ�ī�񻭣�����$N�ˡ�\n", me);
                return RANK_D->query_respect(me)+"�Ѿ���������ذɡ�\n";
        }       
        if( !me->query_temp("zhuzao/paid") )
        {
                if( me->query_temp("zhuzao/asked") ) 
                {
                        message_vision("�����Թ��Ե�������ǽ�ϵ�ī�񻭣�����$N�ˡ�\n", me);
                        return RANK_D->query_respect(me)+"��ء�\n";
                }
                else
                {
                        me->set_temp("zhuzao/asked", 1);
                        message_vision("���迴��$Nһ�ۣ�ҡ��ҡͷ��\n", me);
                        return "���ѵ������ɣ�������š�\n";
                }
        }
        else
        {
                me->delete_temp("zhuzao");
                message_vision("����̾�˿�������$N����"+RANK_D->query_respect(me)+"��Ȼ��˿��������£�����������\n", me);
                if (!(ob = me->query_temp("weapon")))
                        return "��û�ñ��У����������죿\n";
                else
                {
                message_vision("����ӹ�"+ob->name()+"����ĥ����������һ�ᣬ�ֽ�����$N��\n",me);
                message_vision("ֻ������һ����"+ob->name()+"�ķ������ǰ��ʤһ�\n",me);                
                me->add_temp("apply/damage",random(8)+5);
                me->set_temp("add_damage",1);                
                return "�����Ѿ����ã���ذɡ�\n";
                }
        }
}

int accept_object(object me, object ob)
{
        if( ob->value() >= 200000 )
        {
                message_vision("�����$N����"+RANK_D->query_respect(me)+"�����ؽ𣬿�����������\n", me);
                me->set_temp("zhuzao/paid", 1);
                return 1;
        }
        else
        {
            command("say ���ҵ����ҵ�������̫�����ˡ�");
            return 1;
        }
}

