// channeld.c
// modified by tool on 96/10/05
// modified by mon@xyj on 10/97 to add support for
//          intermud emote.

#include <ansi.h>
#include <net/dns.h>
#include <net/macros.h>
inherit F_DBASE;

#define REMOTE_Q    "/adm/daemons/network/services/remote_q.c"

mapping channels = ([
	"sys":  ([      "msg_speak": HIG "��ϵͳ��%s��%s\n" NOR, "wiz_only": 1 ]),
	"wiz":  ([      "msg_speak": HIY "����ʦ��%s��%s\n" NOR,
					"msg_emote": HIY "����ʦ��%s\n" NOR,
					"wiz_only": 1
			]),
	"new":	([	"msg_speak": HIG "�����֡�"HIW"%s��%s\n" NOR,
				"msg_emote": HIG "�����֡�"HIW"%s\n" NOR,
				"newbie":1,
			 ]),
	"gwiz": ([      "msg_speak": HIG "��������ʦ��%s��%s\n" NOR,
					"msg_emote": HIG "��������ʦ��%s\n" NOR,
					"wiz_only": 1, "intermud": GWIZ, "channel": "CREATOR",
					"filter": 1,
					"intermud_emote": 1 ]),
	"moon":  ([      "msg_speak": HIB "���¹ⱦ�С�%s��%s\n" NOR,
					"msg_emote": HIB "���¹ⱦ�С�%s\n" NOR,
					"intermud": GCHANNEL, "channel": "xyj",
					"filter": (:$1["MUDLIB"]=="A Journey to the West" :) ]),
	"es":   ([      "msg_speak": HIG "��̶�����ġ�%s��%s\n" NOR,
					"msg_emote": HIG "��̶�����ġ�%s\n" NOR,
					"intermud": GCHANNEL, "channel": "es",
					"filter": 1 ]), //keep the channel name
                                //as "es" to be compatible with other
                                //ES2 type muds.
	"sldh": ([      "msg_speak": HIC "��ˮ½��᡿%s��%s\n" NOR,
					"msg_emote": HIC "��ˮ½��᡿%s\n" NOR,
	]),
	"chat": ([      "msg_speak": HIC "�����ġ�%s��%s\n" NOR,
					"msg_emote": HIC "�����ġ�%s\n" NOR,
			]),
	"rumor":([      "msg_speak": HIM "��ҥ������%s��%s\n" NOR,
					"msg_emote": HIM "��ҥ������%s\n" NOR,
					"anonymous": "ĳ��",
	]),
    "yyqy": ([  "msg_speak": NOR+HIC+"����Ӱ��Ե��"+HIW+"%s��%s\n" NOR,
            "msg_emote": HIC"����Ӱ��Ե��"HIW"%s\n" NOR,
            "intermud": GCHANNEL,
            "channel": "yyqy",
            "filter": 1,
        ]),
    "jy": ([  "msg_speak": NOR+HIB+"�����ס�"+HIW+"%s��%s\n" NOR,
            "msg_emote": HIB"�����ס�"HIW"%s\n" NOR,
        ]),
	"music":([      "msg_speak": MAG "�������ָ���%s���ţ�%s\n" NOR,
	]),
    "club":([  "msg_speak": HIW "�����ɡ�%s��%s\n" NOR,
				"msg_emote": HIW "�����ɡ�%s" NOR,
				"msg_color": HIW,
				"party_only": 1 ]), 
	"mp":([     "msg_speak": HIY "�����ɡ�"+HIG"%s: %s\n" NOR,
				"msg_emote": HIY "�����ɡ�"+HIG"%s" NOR,
				"msg_color": NOR+HIY,
				"menpai_only": 1 ]),
//	"news":([ "msg_speak": HIG "�����Ų�����%s��%s\n"NOR, ]),
	"ftpd":([ "msg_speak": HIW "�����λ�Ӱ��%s��%s\n"NOR, ]),
]);

string party;
string menpai;
void add_rumor(object me,string msg);
void create()
{
	seteuid(getuid());      // This is required to pass intermud access check.
	set("channel_id", "Ƶ������");
	this_object()->set("rumor_point",0);
}

varargs int do_channel(object me, string verb, string arg, int emote,int allow_chat)
{
	object *ob;
	string *tuned_ch, who, arg1;
	int time,count,count1,last_chat,len;

	if(sizeof(verb)>0)
		if( verb[sizeof(verb)-1] == '*' ) {
			emote = 1;
			verb = verb[0..<2];
		}

	if(arg && strlen(arg)>240) return 0;

	if( !mapp(channels) || undefinedp(channels[verb]) )
		return 0;

	if( userp(me) && !allow_chat ) {
		if(channels[verb]["wiz_only"] && !wizardp(me) )
			return 0;
		if(channels[verb]["party_only"] && !me->query("club"))
			return notify_fail("�㻹���ȼ���һ��������˵�ɡ�\n");

		if (channels[verb]["party_only"]) {
			party = me->query("club");
			channels[verb]["msg_speak"] = HIY "��"+party+"��%s��%s\n" NOR;
			channels[verb]["msg_emote"] = HIY "��"+party+"��%s\n" NOR;
		}

		if (channels[verb]["menpai_only"] && !me->query("family/family_name"))
			return notify_fail("�����ĸ����ɵġ�\n");

		if (channels[verb]["menpai_only"]) {
			menpai = me->query("family/family_name");
			channels[verb]["msg_speak"] = HIG "��"HIR+menpai+HIG"��%s��%s\n" NOR;
			channels[verb]["msg_emote"] = HIG "��"HIR+menpai+HIG"��%s\n" NOR;
		}
		if( emote && undefinedp(channels[verb]["msg_emote"])  ) {
			write("�Բ������Ƶ����֧�� emote ��\n");
			return 1;
		}

		time=time();
		if(me->query("channel/chat_block") &&
		(time-me->query("channel/chat_block"))<0 )
			return notify_fail("��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");

		count=me->query("channel/chat_count");
		count1=sizeof(explode(" "+arg,"\n"))/3+1;
		count1+=sizeof(arg)/200;
		count+=count1;
		last_chat=me->query("channel/last_chat");
		if (count>2) {
			count=0;
			me->set("channel/last_chat",time);
			if (time==last_chat || count1>2) {
				me->set("channel/chat_block",time+180);
				return notify_fail("��Ϊһ�ν���̫�࣬��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");
			}
		}
		me->set("channel/chat_count",count);

		if( channels[verb]["newbie"]==1 && me->query("age")>15
		&& !wizardp(me) && userp(me) )
			return notify_fail("�������Ѿ������ˣ���������ʹ������Ƶ��˵����\n");

		if( arg==(string)me->query_temp("last_channel_msg") )
			return notify_fail("�ý�̸Ƶ��˵���벻Ҫ�ظ���ͬ��ѶϢ��\n");

		tuned_ch = me->query("channels");
		if( !pointerp(tuned_ch) )
			me->set("channels", ({ verb }) );
		else if( member_array(verb, tuned_ch)==-1 )
			me->set("channels", tuned_ch + ({ verb }) );

		if( emote && !channels[verb]["intermud_emote"])
		{
			string vb, emote_arg;

			if( nullp(arg) ) return 0;
			if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 )
			{
				vb = arg;
				emote_arg = "";
			}
			if( channels[verb]["anonymous"] )
				arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 1);
			else
			{
				arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 0,
					!undefinedp(channels[verb]["intermud"]));
				if(!arg)
				{
					string id, site;
					if(sscanf(emote_arg, "%s@%s", id, site)==2)
					{
						int age=me->query("mud_age");
						if(!wizardp(me))
						{
							if(age<3600)
								return notify_fail("�����ڻ�����ʹ�����Ƶ����\n");
							else if(age<86400)
							{
								if((int)me->query("sen")<30)
									return notify_fail("�����ھ����㣬����ʹ�����Ƶ����\n");
								me->add("sen",-5);
							}
						}
						REMOTE_Q->send_remote_q(site, verb, me->query("id"), id, vb);
						write("��·ѶϢ���ͳ������Ժ�\n");
						return 1;
					}
				}
			}
			if( !arg ) return 0;
		}
	}

	if( channels[verb]["anonymous"] )
	{
		who = channels[verb]["anonymous"];
		if (userp(me))
		{
			if((int)me->query("sen")<50)
				return notify_fail("���Ѿ�û�о���ɢ��ҥ���ˡ�\n");
			me->add("sen",-5);
			do_channel( this_object(), "sys", 
			sprintf("ҥ�ԣ�%s(%s)��", me->name(1),me->query("id")));
		}
	}
	else if( userp(me) || !stringp(who = me->query("channel_id")) )
	{
		who = me->query("name");
		if(me->query("id")) 
			who=who+"(" + capitalize(me->query("id")) + ")";
	}

	ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );
	if( !arg ) arg = "������";

	len=strlen(arg);
	while(len>1 && arg[len-1]=='\n')
		arg=arg[0..((len--)-2)];

	if(userp(me)) arg1=replace_string(arg, "$N", me->name());
	else arg1=arg;

	if( emote )
	{
		if( channels[verb]["intermud_emote"] ) arg1 = who + " " + arg;
	}

	if( arrayp(channels[verb]["extra_listener"]) )
	{
		channels[verb]["extra_listener"] -= ({ 0 });
		if( sizeof(channels[verb]["extra_listener"]) )
			channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
	}

	if( !undefinedp(channels[verb]["intermud"])
	&& base_name(me) != channels[verb]["intermud"] )
	{
		if(userp(me))
		{
			int age=me->query("mud_age");
			arg=replace_string(arg, "$N", me->name()+"("+
			capitalize(me->query("id"))+"@"+Mud_name()+")",1);
			arg=replace_string(arg, "$N", me->name());

            if(!wizardp(me)) {
				if(age<3600)
					return notify_fail("�����ڻ�����ʹ�����Ƶ����\n");
				else if(age<86400) {
					if((int)me->query("sen")<30)
						return notify_fail("�����ھ����㣬����ʹ�����Ƶ����\n");
					me->add("sen",-5);
				}
			}
		}
		channels[verb]["intermud"]->send_msg(
			channels[verb]["channel"], me->query("id"), 
		me->name(1), arg, emote, channels[verb]["filter"] );
	}

	if( emote ) {
		message( "channel:" + verb,sprintf( channels[verb]["msg_emote"], arg1 ), ob );
	} else
		message( "channel:" + verb,sprintf( channels[verb]["msg_speak"], who, arg1 ), ob );

	if( userp(me) ) 
		me->set_temp("last_channel_msg", arg);
	if( channels[verb]["anonymous"] ) add_rumor(me,arg); 
	return 1;
}

int filter_listener(object ppl, mapping ch)
{
        // Don't bother those in the login limbo.
	if( !environment(ppl) ) return 0;

	if( ch["wiz_only"] ) return wizardp(ppl);
        //as followed add by vikee,only belong to the party & wizard can see these message
	if (ch["party_only"])
		return (wizardp(ppl)
			&& (!ppl->query("env/party") || ppl->query("env/party")==party))
			|| party == ppl->query("club"); 
         //as followed add by yesi,only belong to the menpai & wizard can see these message
	if (ch["menpai_only"])
		return (wizardp(ppl)
		|| ppl->query("family/family_name")==menpai); 
	return 1;
}

void register_relay_channel(string channel)
{
	object ob;

	ob = previous_object();
	if( undefinedp(channels[channel]) || !ob) return;
	if( arrayp(channels[channel]["extra_listener"]) ) {
		if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
		channels[channel]["extra_listener"] += ({ ob });
	} else
		channels[channel]["extra_listener"] = ({ ob });
}

void add_rumor(object me,string msg)
{
	object ob=this_object();
	string msg_id;
	int i;
	int detect_chance;
	int rumor_point=ob->query("rumor_point");
	rumor_point++;
	if (rumor_point>10) rumor_point-=10;
	i=sizeof(msg_id);
	msg_id="rumor_msg_0";
	i=sizeof(msg_id);
	msg_id[i-1]+=rumor_point;
	ob->set(msg_id,msg);
	msg_id="rumor_id_0";
	i=sizeof(msg_id);
	msg_id[i-1]+=rumor_point;
	ob->set("rumor_point",rumor_point);
	detect_chance=31-(int)(me->query("daoxing")/33333);
	if (!userp(me) || wizardp(me) || random(100)>detect_chance)
	{
		ob->set(msg_id,"none");
		return;
	}
	ob->set(msg_id,me->query("name")+"("+me->query("id")+")");
	return;                 
}

string query_rumor_msg(int num)
{
	string msg_id;
//	string msg;
	int i;
	msg_id="rumor_msg_0";
	i=sizeof(msg_id);
	msg_id[i-1]+=num;
	return this_object()->query(msg_id);
}
string query_rumor_id(int num)
{
	string msg_id;
//	string msg;
	int i;
	msg_id="rumor_id_0";
	i=sizeof(msg_id);
	msg_id[i-1]+=num;
	return this_object()->query(msg_id);
}
