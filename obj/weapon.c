//��ʦ�����ŵı���
#include <ansi.h>
#include <weapon.h>

inherit EQUIP;

mapping wp_type=([
	"axe"	 : "/d/obj/weapon/axe/bigaxe",
	"blade" : "/d/obj/weapon/blade/blade",
	"fork"	: "/d/obj/weapon/fork/gangcha",
	"hammer": "/d/obj/weapon/hammer/hammer",
	"mace"	: "/d/obj/weapon/mace/ironmace",
	"spear" : "/d/obj/weapon/spear/gangqiang",
	"staff" : "/d/obj/weapon/staff/muzhang",
	"stick" : "/d/obj/weapon/stick/qimeigun",
	"sword" : "/d/obj/weapon/sword/changjian",
	"whip"	: "/d/obj/weapon/whip/pibian",
	"halberd":"/d/obj/weapon/halberd/sanchaji",
	"needle": "/d/qujing/xuanyuan/obj/needle",
]);

void create()
{
	object own;
	mapping wp;
	string* idlist;
	string wpid;
	
	seteuid(0);
	set_name("ʦ�ű���",({"bing qi"}));
	set("value", 1);			 
	set("no_get", 1);		 
	set("no_give", 1);		
	set("no_sell", 1);		
	set("no_drop", 1);		
	set("no_put", 1);
	set("flag", TWO_HANDED);
	set("weight_mp", 1);
	set("family",1);			
	set("weapon_prop/damage", 10);
	set("skill_type","unarmed");
}

void set_value(object me)
{
	mapping wp;
	string* idlist;
	string wpid;
	object ob;

	if(query("owner_id")==me->query("id")){
		wp=me->query("family_wp");
		set_default_object(wp_type[wp["type"]]);
		set("default_file",wp_type[wp["type"]]);
		ob=find_object(wp_type[wp["type"]]);
		wpid=ob->query("id");
		idlist=explode(wpid," ");
		idlist=({wpid})+idlist;
		set_name(HIW"ʦ��"+ob->query("name")+NOR,idlist);
		me->set("family_wp/name","ʦ��"+ob->query("name"));
		me->set("family_wp/id",wpid);
		set("weapon_prop/damage",wp["damage"]);
		set("weapon_prop/exp",wp["exp"]);
		set("skill_type",wp["type"]);
	}
}

void improve_exp(object me)
{
	int exp,lvl;

	if(me->query("id")!=query("owner_id"))return;
	exp=me->query("family_wp/exp");
	lvl=me->query("family_wp/damage")-10;
	if(lvl > 300) return;
	exp++;
	if(exp>=(lvl+1)*(lvl+1)){
		exp=0;
		lvl++;
		set("weapon_prop/damage",10+lvl);
		set("weapon_prop/exp",0);
		me->set("family_wp/damage",lvl+10);	
		me->set("family_wp/exp",0);
		tell_object(me,"���"HIC+query("name")+NOR"����������ˣ�\n");
		return;
	}
	set("weapon_prop/exp",exp);
	me->set("family_wp/exp",exp);
//	me->set("apply/damage",10+lvl);
}
