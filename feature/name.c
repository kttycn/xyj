// name.c

#include <ansi.h>
#include <dbase.h>
#include <condition.h>

nosave string *my_id;

string *query_my_id()
{
  return my_id;
}

void set_name(string name, string *id)
{
  set("name", name);
  set("id", id[0]);
  my_id = id;
}

int id(string str)
{
  string *applied_id;

  if( this_player() && !this_player()->visible(this_object()) ) return 0;

  if( pointerp(applied_id = query_temp("apply/id")) 
  &&  sizeof(applied_id) ) 
   if( member_array(str, applied_id)!=-1 )
    return 1;
   else
    return 0;
    
  // If apply/id exists, this object is "pretending" something, don't
  // recognize original id to prevent breaking the pretending with "id"
  // command.

  if( pointerp(my_id) && member_array(str, my_id)!=-1 )
   return 1;
  else
   return 0;
}

string *parse_command_id_list()
{
  string *applied_id;

  if( pointerp(applied_id = query_temp("apply/id")) 
  &&  sizeof(applied_id) )
   return applied_id;
  else
   return my_id;
}

varargs string name(int raw)
{
  string str, *mask;
  
  if( !raw && sizeof(mask = query_temp("apply/name")) )
   return mask[sizeof(mask)-1];
  else {
   if( stringp(str = query("name")) )
    return str;
   else
    return file_name(this_object());
  }
}

varargs string short(int raw)
{
	string job_title, title,  nick, str, *mask, nickname;//party_title, degree,
	int fadai;

	if( !stringp(str = query("short")) )
		str = name(raw) + "(" + capitalize(query("id")) + ")";

	if( !this_object()->is_character() ) return str;

	if( !raw && sizeof(mask = query_temp("apply/short")) )
		str = (string)mask[sizeof(mask)-1];
	else {
		if( stringp(nick = query("nickname")) )
			str = sprintf("��%s��%s", nick, str);

//		if ( stringp(degree = query("degree")) ) 
//			str = sprintf("%s%s%s%s%s",degree,(party_title?"":""),
//			(title?"":""),(nick?"":" "), str);

		if( stringp(job_title = query("job_title")) )
			str = sprintf("%s %s",job_title, str); 

		if( !raw && sizeof(mask = query_temp("apply/title")) )
			title = (string)mask[sizeof(mask)-1];
		else
			title = query("title");
		nickname = query("nick");
		if( stringp(nickname) )
			str = sprintf("%s%s%s", nickname, (nick?"":" "), str);
		else if( stringp(title) )
			str = sprintf("%s%s%s", title,(nick?"":" "), str);

	}

	if( !raw ) {
//		if (userp(this_object())){//By waiwai@2001/02/17 ����npc������ͨ����״̬
		if( this_object()->is_ghost() ) str = HIB "(����) " NOR + str;
		if( query_temp("netdead") ) str += HIG " <������>" NOR;
		if(query_temp("pending/exercising") ) str += HIY " <ڤ˼������> "NOR;
		if( query_temp("doing_xiudao") ) str += HIY " <�޵���>" NOR;
		if( in_input() ) str += HIC " <����������>" NOR;
		if( in_edit() ) str += HIY " <�༭������>" NOR;
		if (userp(this_object())) {
			if( this_object()->query("thief") ) str += HIG " <����>" NOR;
			if( this_object()->query("PKS")>0 ) str += HIR " <ɱ��ɱ��>"NOR;
		}
		if( interactive(this_object())
		&&  query_idle( this_object() ) > 240 )
		{
           	fadai = 16-(int)this_object()->query("int")/2;
			if (fadai<0) fadai = 0;
			this_object()->improve_skill("idle-force",fadai);
			str += HIM " <����"+chinese_number((query_idle(this_object())-60)/60)+"����>" NOR;
		}

		if ( this_object()->is_fighting() ) str += HIW " <ս����>" NOR;

		if( !living(this_object()) ) str += HIR + query("disable_type") + NOR;
	}
	return str;
}

varargs string long(int raw)
{
  string str, extra, *mask;
  
  if( !raw && sizeof(mask = query_temp("apply/long")) )
   str = mask[sizeof(mask)-1];
  else if( !stringp(str = query("long")) )
   str = short(raw) + "��\n";

  if( stringp(extra = this_object()->extra_long()) )
   str += extra;

  return str;
}
