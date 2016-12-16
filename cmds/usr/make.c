//make.c
//by happ@YSZZ

#include <ansi.h>

int do_bian(object me);

void done(object me);
void over(object me, object yao);

int main(object me, string arg)
{
	object ob;
	int lv;
	lv=me->query_skill("medical",1);
	seteuid(getuid());

	if( me->is_busy() )
		return notify_fail("����æ���ء�\n");

	if( !arg )
		return notify_fail("��Ҫ��ʲôҩ��\n");

	if( me->is_fighting() )
		return notify_fail("������ս������ʲôҩ����\n");
	if( me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("����æ���أ�ûʱ����ҩ��\n");

	switch (arg)
	{
		case "hugu":
			if( ! present("herb_hugu", me) || ! present("herb_duhuo", me) || 
			! present("herb_fangfeng", me) || ! present("herb_danggui", me) )
				return notify_fail("���ҩ�Ĳ���ȫ��\n");
			if( lv < 30 )
				return notify_fail("���ҽ�������Ƴ����Ǿơ�\n");
			done(me);
			ob=new("/d/obj/medicine/hugu.c");
			break;
		case "jinyinhua":
			if( ! present("herb_jyhua", me) )
				return notify_fail("���ҩ�Ĳ���ȫ��\n");
			if( lv < 30 )
				return notify_fail("���ҽ�������Ƴ�������¶��\n");
			done(me);
			ob=new("/d/obj/medicine/jyhua.c");
			break;
		case "meirandan":
			if( ! present("herb_slg", me) || ! present("herb_xuejie",me) ||
	    	! present("herb_lurong",me) || ! present("herb_hafen", me) ||
			! present("herb_honghua",me) || ! present("herb_heshouwu",me) ||
			! present("herb_renshen",me) || ! present("herb_fuzi", me) )
				return notify_fail("���ҩ�Ĳ���ȫ��\n");
			if( lv < 150 )
				return notify_fail("���ҽ�������Ƴ��߱����׵���\n");
			done(me);
			ob=new("/d/obj/medicine/qibao.c");
			break;
		case "tongmai":
			if( ! present("herb_chuanwu", me) || ! present("herb_chenpi", me) ||
			! present("herb_moyao", me) || ! present("herb_danggui", me) )
				return notify_fail("���ҩ�Ĳ���ȫ��\n");
			if( lv < 100 )
				return notify_fail("���ҽ�������Ƴ�����ͨ������\n");
			done(me);
			ob=new("/d/obj/medicine/tongmai.c");
			break;
		case "huojin":
			if( ! present("herb_chuanwu", me) || ! present("herb_honghua", me) ||
			! present("herb_shengdi", me) )
				return notify_fail("���ҩ�Ĳ���ȫ��\n");
			if( lv < 80 )
				return notify_fail("���ҽ�������Ƴ������Ѫ�衣\n");
			done(me);
			ob=new("/d/obj/medicine/huojin.c");
			break;
		case "wuchangdan":
			if( ! present("herb_tianqi", me) || ! present("herb_xiongdan",me) ||
			! present("herb_xuelian",me) || ! present("herb_renshen",me))
				return notify_fail("���ҩ�Ĳ���ȫ��\n");
			if( lv < 80 )
				return notify_fail("���ҽ�������Ƴ��޳�����\n");
			done(me);
			ob=new("/d/obj/medicine/wuchang.c");
			break;
		case "baoming":
			if( ! present("herb_heshouwu", me) || ! present("herb_xuelian",me) ||
			! present("herb_lurong",me) || ! present("herb_renshen",me)  ||
			! present("herb_honghua",me) || ! present("herb_chenpi",me ))
				return notify_fail("���ҩ�Ĳ���ȫ��\n");
			if( lv < 150 )
				return notify_fail("���ҽ�������Ƴ����������衣\n");
			done(me);
			ob=new("/d/obj/medicine/baoming.c");
			break;
		case "liushen":
			if( ! present("herb_niuhuang", me) || ! present("herb_xiongdan",me) ||
			! present("herb_bingpian",me) || ! present("herb_chansu",me ))
				return notify_fail("���ҩ�Ĳ���ȫ��\n");
			if( lv < 50 )
				return notify_fail("���ҽ�������Ƴ������衣\n");
			done(me);
			ob=new("/d/obj/medicine/liushen.c");
			break;
		case "sancai":
			if( ! present("herb_tiandong", me) || ! present("herb_gancao",me) ||
			! present("herb_huangbo",me) || ! present("herb_guiwei",me ) ||
			! present("herb_renshen",me ) )
				return notify_fail("���ҩ�Ĳ���ȫ��\n");
			if( lv < 190 )
				return notify_fail("���ҽ�������Ƴ����ŷ��赤��\n");
			done(me);
			ob=new("/d/obj/medicine/sancai.c");
			break;
		case "zaizao":
			if( ! present("herb_renshen", me) || ! present("herb_xuejie",me) ||
			! present("herb_juhua",me) || ! present("herb_dahuang",me ) ||
			! present("herb_shanjia",me ) )
				return notify_fail("���ҩ�Ĳ���ȫ��\n");
			if( lv < 150 )
				return notify_fail("���ҽ�������Ƴ��˲������衣\n");
			done(me);
			ob=new("/d/obj/medicine/zaizao.c");
			break;
		case "duomei":
			if( ! present("herb_hupo", me) || ! present("herb_gsliu",me) ||
			! present("herb_hafen",me ) )
				return notify_fail("���ҩ�Ĳ���ȫ��\n");
			if( lv < 170 )
				return notify_fail("���ҽ�������Ƴ���������衣\n");
			done(me);
			ob=new("/d/obj/medicine/hpdm.c");
			break;
/*		case "zhengqi":
			if( ! present("huo zao", me) || ! present("herb_lingzhi",me) ||
			! present("herb_gancao",me ) )
				return notify_fail("���ҩ�Ĳ���ȫ��\n");
			if( lv < 220 )
				return notify_fail("���ҽ�������Ƴ�����ˮ��\n");
			done(me);
			ob=new("/d/obj/medicine/zhengqi.c");
			me->start_busy(3);
			ob->move(me);
			break;*/
		case "qingxin":
			if( ! present("herb_chuanwu", me) || ! present("herb_gsliu",me) ||
			! present("herb_shancha",me ) )
				return notify_fail("���ҩ�Ĳ���ȫ��\n");
			if( lv < 180 )
				return notify_fail("���ҽ�������Ƴ����Ľⶾ�衣\n");
			done(me);
			ob=new("/d/obj/medicine/qingxin.c");
			ob->move(me);
			break;
		case "sanhua":
			if( ! present("herb_honghua",me) || ! present("herb_zihua",me) ||
			! present("herb_lanhua",me ) || ! present("jiuzi_hupo",me) )
				return notify_fail("���ҩ�Ĳ���ȫ��\n");
			if( lv < 110 )
				return notify_fail("���ҽ�������Ƴ��������Ӹࡣ\n");
			done(me);
			ob=new("/d/obj/medicine/sanhua.c");
			break;
		default: return notify_fail("��û������������ҩ��\n");
	}
	me->start_busy(6);
	call_out("over", 6, me, ob);
	return 1;
}


void done(object me)
{
	int i;
	object *inv; 
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("done"))
			destruct(inv[i]);
	}
	message_vision( HIY "ֻ��$N��������ҩ��֮�ϣ������ҩ�ı���ʧ�ˡ�\n\n" NOR,me);
	me->start_busy(6);
	return;
}

void over(object me, object yao)
{
	yao->move(me);
	message_vision( CYN"���Σ�$Nվ����������Ȼ�Ƴ���һ"+yao->query("unit")+
	"��"+yao->query("name")+CYN"����\n"NOR, me);
}
