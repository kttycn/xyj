// cmd : auto_create_area.c  ¸ù¾İ¼òµ¥ÉèÖÃÎÄ¼ş£¬Éú³ÉÇøÓò room file.
// by naihe 2:01 03-11-15 for huns@¾ªºèÂÛÌ³
// EM: lonely@163.com  or  lovesb@21cn.com
// PS: ÎÒµÄµ¥»úÊÇ xkx ÀàµÄ

// V1.1
// ĞŞÕıÁËÒ»¸öBUG
// ¸ü¸ÄÁË¼ÆËãµÄ·½Ê½£¬Ê¹Á÷³Ì¸üÇåÎú
// ¸ü¸ÄÁË½¨Á¢ÎÄ¼şµÄ·½Ê½£¬Ö»½¨Á¢ÔÚµØÍ¼ÀïµÄ¡¢²¢ÇÒÔÚÁĞ±íÀïµÄÎÄ¼şÃû
// ÎªÃ»ÓĞ setcolor(), delcolor() º¯ÊıµÄMUD¼Ó½øÁËÕâÁ½¸öº¯Êı

//v1.2
//¸Ä½øÁËÈİ´íĞÔ£¬ÖĞÎÄÃû³¤¶ÈËæÒâÁË.
//Ôö¼ÓÁËxÁ¬½Ó·û,¿ÉÒÔ½»²æÁ¬ÁË.
//Á¬½Ó·û¿ÉÒÔÁ¬ÓÃºÍ»¥Ïà´©Ô½ÁË£¬¾ßÌå¼ûÊ¾Àı¡£
//hunsĞŞ¸ÄÓÚ 2003.12.07

//v1.3
//Ôö¼ÓÁËA,<,>,V,v Á¬½Ó·û,¿ÉÒÔ¸ßµÍÁ¬ÁË£¬¼â¼âËùÖ¸ÊÇµØÊÆ½Ï¸ßµÄÎ»ÖÃ.
//   ¿ÉÒÔÕâÑùfilea>>>>>>fileb£¬Ò²¿ÉÒÔÕâÑùfilea>---->fileb,Ê×Î²Ò»Ñù¼´¿É
//Ôö¼ÓÁËE,! {  Á¬½Ó·û,¿ÉÒÔÁ¬ Â¥ÉÏ/Â¥ÏÂ ÉÏ/ÏÂ ÅÀÉÏ/ÅÀÏÂ Î»ÖÃ,EÈ¡ĞÎ×´±È½ÏÏñÂ¥Ìİ¡¢{ ÏñÉş×Ó.
//ĞŞÕıÁËÒ»¸öµØÍ¼Òì³£¸´ÔÓÊ±¿ÉÄÜ³öÏÖµÄBUG
//µØÍ¼ÖĞ¿ÉÒÔ³öÏÖÖØ¸´·¿¼äÁË£¬¿ÉÒÔÈç Ğ¡Â·-Ğ¡Â·---Ğ¡Â·
//ÕûÀíÁË½á¹¹£¬È¥µôÁËÒ»Ğ©²»±ØÒªµÄÑ­»·

//v1.4
//Ôö¼Ó¶àµØÍ¼¹¦ÄÜ£¬ĞŞ¸Ä¼¸¸ö³ö´íÌáÊ¾
//È¥µô¸ø·¿¼ä¼ÓÑÕÉ«¹¦ÄÜ£¬Ã»ÓÃ£¬ÑÕÉ«Ó¦¸ÃÊÇlookÀ´¾ö¶¨µÄ¡£
//huns ĞŞ¸ÄÓÚ 2006-7-10 22:36
//¿ÉÈÎÒâÑ¡ÔñÊÇ·ñÌí¼Ó³¤ÃèÊö£¬²¢¾ö¶¨Ìí¼ÓÁ¬½Ó³ö¿ÚµÄÃèÊö£¬¼ò»¯´ò×Ö¹ı³Ì
#include <ansi.h>
int sizeofmap , linelen , map_start_line ,map_number;// µØÍ¼ĞĞÊı ±¾ĞĞ³¤¶È µØÍ¼ÆğÊ¼ĞĞÊı µØÍ¼×ÜÊı
mapping all_exits = ([ ]);          //×Ü³ö¿Ú  ([·¿¼äÃû1  , ([·½Ïò ÖĞÎÄ·¿¼äÃû ])])
mapping all_dirs = ([ ]); //³ıÎÄ¼şÃûºÍ¶ÌÃèÊö¶ÔÕÕmapping ÒÔÍâµÄËùÓĞÊı¾İ¼¯ºÏ
/*
»ñµÃÄ¿Â¼ÖĞÎÄÃû³Æ all_dirs[/d/baihe/]["cname"] ===>°×ºÓ´å
»ñµÃÄ¿Â¼ÎÄ¼şÃû³Æ¶ÔÓ¦¶ÌÃèÊöĞÅÏ¢ all_dirs[/d/baihe/shulin]["short"] ===>Ê÷ÁÖ
»ñµÃÄ¿Â¼ÎÄ¼şÃû³Æ¶ÔÓ¦³¤ÃèÊöĞÅÏ¢ all_dirs[/d/baihe/shulin]["long"] ===>Ê÷ÁÖÊ÷ÁÖÊ÷ÁÖÊ÷ÁÖÊ÷ÁÖÊ÷ÁÖÊ÷ÁÖÊ÷ÁÖ  
»ñµÃÄ¿Â¼ÎÄ¼şÃû³Æ¶ÔÓ¦·¿¼äĞÅÏ¢ÉèÖÃ all_dirs[/d/baihe/shulin]["roomset"] ==>

*/

string filename , *allfile , *f_len  ,dir ;

string *map,*alldir=({}) ;       		   // ×ÜµØÍ¼
mapping filename_to_short = ([ ]);        // filename-->ÖĞÎÄ·¿¼äÃû

mapping short_to_long = ([ ]);        // short-->ÖĞÎÄ·¿¼ä³¤ÃèÊö
mapping short_to_filename = ([ ]);        // ÖĞÎÄ·¿¼äÃû-->filename
mapping xy2filename = ([ ]);        // µØÖ·-->filename

        // map[x][y]  xµÚ¼¸ĞĞ  £¬yµÚ¼¸ÁĞ ,xÏà¶ÔÆ«ÒÆ£¬  yÏà¶ÔÆ«ÒÆ
string xy_to_filename( int x,   int y ,   int x1  ,     int y1 ) ;

int add_exit( string n1, string exit, string n2 );

/*******************************************************************
 '-','<','>',        //Î÷-¶«£¬Î÷¸ß-¶«µÍ£¬Î÷µÍ-¶«¸ß£¬

 '|','V','A',    // ±±       ±±µÍ      ±±µÍ      ±±¸ß
                     // |         v         V         A
                     // ÄÏ  £¬   ÄÏ¸ß  £¬  ÄÏ¸ß  £¬  ÄÏµÍ

 '/','\','X',    //     ¶«±±  Î÷±±       ½»²æÁ¬½Ó£¬ ½»²æÁ¬½Ó
                       //    /          \          x          X
                       //Î÷ÄÏ     £¬     ¶«ÄÏ£¬

¼¸¸öÌØÊâµÄ
 'E','!'  '{'      // Â¥ÉÏ  ÉÏ   ¸ß ÅÀÉÏ/ÅÀÏÂ
                   //  E     !   {  Éş×Ó
                   // Â¥ÏÂ£¬ÏÂ   µÍ
********************************************************************/

//ËùÓĞÁ¬½Ó·û
mixed *all_foos=({ '-','<','>', '|', 'V','A', '/','\\', 'X', 'E','!','{'  }) ;

int test_file(string filename);
int read_dir( int n);
int read_room_list();
int read_map( int n);
int get_exit( mixed foo ,int x  ,int y );
int total_map_n();

// ÓÃÓÚ¼ì²âÎÄ¼şÃû(Ó¢ÎÄÃû)ÊÇ·ñÓĞĞ§
// Èç¹ûÏ£ÍûÓÃÒ»Ğ©ÌØ±ğµÄ×Ö·û£¨Èçºº×ÖµÈ£©×÷Îª write_file() µÄ
// ÎÄ¼şÃû£¬£¬Çë¸ü¸Ä±¾º¯Êı£¬»òÊ¹±¾º¯ÊıÖ±½Ó return 1 .
int valid( string n )
{
	string l = "1234567890abcdefghijklmnopqrstuvwxyz-_";
	mixed t;
	if( !n ) return 0;
	foreach( t in l )
		if( n[0] == t ) return 1;
	return 0;
}

//Ö»ÁôÏÂÎÄ¼şÃû£¬ÆäËû×ª¿Õ¸ñ
string replace_nouse_to_blank( string s )
{
	string temp , *all_foo= ({"-","|","/","\\",  "X" ,"A","V", "<",">" ,"E" ,"!" ,"{"}) ;
	foreach( temp in all_foo )
	     s = replace_string( s, temp, " " );

	return s;
}

int read_file_msg( string filename)
{
 	return  test_file(filename)
	        &&  read_room_list();
}

//ÑéÖ¤ÎÄ¼şÊÇ·ñ¿ÉÓÃ
int test_file(string filename)
{
	string   file ,*temp_f_len;
	map_number=0;
	if( !filename ) return notify_fail("ÇëÖ¸¶¨ÎÄ¼ş¡£\n");
	
	if(file_size( filename )==-1) return notify_fail("ÎÄ¼ş²»´æÔÚ¡£\n");
	
	//write("------ ok>>>>\n"+file_size( filename ));
	
	if( !file = read_file( filename )  )	return notify_fail("ÎŞ·¨¶ÁÈ¡¸ÃÎÄ¼ş£º"+filename+"\n");

	if(strsrch( file, "	" ) != -1)
	return notify_fail("¸ÃÎÄ¼şº¬ÓĞTABÌø¸ñ,ÒòÎªÃ¿¸öÈËµÄ³¤¶È¶¨Òå¿ÉÄÜ²»Ò»ÖÂ£¬»áµ¼ÖÂ³ö´í,ÇëÈ«²¿Ìæ»»Îª¿Õ¸ñ\n");

	file=replace_string( file, "\t", "        " );
//tab×ª8¿Õ¸ñ,»­µØÍ¼Ê±±ğÓÃTAB¼üÌø¸ñ£¬ÎÒµÄ±à¼­Æ÷ÓÃTABÊ±ÏÔÊ¾³¤¶Ì²»Ò»£º( ¡£

	if( strlen( file ) < 10 ) return notify_fail("¸ÃÎÄ¼şÄÚÈİÌ«ÉÙ£¬ÎŞ·¨×÷ÎªÓĞĞ§×ÊÁÏ¡£\n");

	if( strsrch( file, "#create area file#" ) == -1
	 || strsrch( file, "#dir#" ) == -1
	 || strsrch( file, "#list#" ) == -1
	// || strsrch( file, "#list_end#" ) == -1
	 || strsrch( file, "#map#" ) == -1
	 || strsrch( file, "#map_end#" ) == -1 )
		return notify_fail("¸ÃÎÄ¼ş×ÊÁÏ²»×ã£¬ÎŞ·¨½¨Á¢ÎÄ¼ş¡£"
			"Çë²ÎÔÄ help auto_create_area »ñµÃ¸ñÊ½¹æ·¶ËµÃ÷¡£\n");

	f_len = explode( file, "\n" );
		
	temp_f_len =f_len - ({ "", " ", "  ", "¡¡", "	", }); //È¥µô¿ÕĞĞ,¼Ó¿ìËÙ¶È
	if( sizeof(temp_f_len) < 10 )
		return notify_fail("¸ÃÎÄ¼şÄÚÈİÌ«ÉÙ£¬»ò¿ÕĞĞ·ûºÅÌ«ÉÙ£¬ÎŞ·¨×÷ÎªÓĞĞ§×ÊÁÏ¡£\n");

	//¹²ÓĞ¶àÉÙ·ùµØÍ¼
	map_number = sizeof( filter_array( f_len, (: strsrch( $1, "#map#" ) != -1 :) )  );


	return 1;
}

//¶ÁÈ¡ ·¿¼äÃû³ÆÁĞ±í
int read_room_list()
{
	mixed temp;
	string  *temp_arr , checking ;
	int m;
	// ok, make a file_name list for all rooms.
	write("------ ÕıÔÚ¶ÁÈ¡ ·¿¼äÃû³ÆÁĞ±í >>>>\n");
	temp = ({ });
	m = 0;

	// get rooms list
	foreach( checking in f_len )
	{
	//	if( strsrch( checking , "#list_end#" ) != -1 )
	//		break; Ò»Ö±¶Áµ½ÎÄ¼şÎ²£¬¹ÊÎŞĞèÅĞ¶Ï½áÊøĞĞ±ê¼Ç
		if( m ) temp += ({ checking });
		if( !m && strsrch( checking , "#list#" ) != -1 )
			m = 1;
	}
	if( !temp || !sizeof(temp) )
		return notify_fail("ÎŞ·¨¶ÁÈ¡ÓĞĞ§µÄ·¿¼äÃû³ÆÁĞ±í£¬Çë²éÕıÔÙÊÔ¡£\n");

	m = sizeof(temp) ;

	write("¹²¶ÁÈ¡ "+ m +" ¸ö·¿¼äÃû³Æ¡£\n------ ÕıÔÚÑéÖ¤·¿¼äÃû³ÆÊÇ·ñÓĞĞ§ >>>\n");

	short_to_filename = ([ ]);// ÖĞÎÄ·¿¼äÃû-->filename
	filename_to_short = ([ ]);// filename-->ÖĞÎÄ·¿¼äÃû
	//short_to_long = ([ ]);// ÖĞÎÄ·¿¼äÃû-->ÖĞÎÄ·¿¼ä³¤ÃèÊö
	// ½øĞĞÓĞĞ§ÅĞ¶Ï£¬²¢Éú³É2¸ö¶ÔÓ¦µÄ map £¬·½±ãµ÷ÓÃ
	foreach( checking in temp )
	{
	
		if(sizeof(temp_arr = explode( checking, ":" ))!=2)
			return notify_fail("·¿¼äÃû³ÆÁĞ±íÓĞµÄÈ±:»òÌ«¶à£º£¬Çë²éÕıÔÙÊÔ¡£\n");
	
	//	if( sizeof(temp_arr) =2) //³¤ÃèÊöÖĞº¬ÓĞ£º
	        
			sscanf( checking, "%s:%s",temp_arr[0] ,temp_arr[1] );//,temp_arr[2]
		
		temp_arr[0]= replace_string( temp_arr[0], " ", "" );
		temp_arr[1]= replace_string( temp_arr[1], " ", "" );	
		
		if( sizeof(temp_arr) >1 && valid(temp_arr[1]) )   //Ôö¼ÓÉèÖÃ·¿¼äµÄ³¤ÃèÊö...
		{
			if( !undefinedp( short_to_filename[ temp_arr[0]] ) )
				return notify_fail( "·¿¼äÃû³ÆÁĞ±í" + temp_arr[0] +"ÖØ¸´¶¨Òå£¬Çë²éÕıÔÙÊÔ¡£\n");

			short_to_filename[ temp_arr[0] ] = temp_arr[1];

			if( !undefinedp( filename_to_short[ temp_arr[1] ] ) )
				return notify_fail( "ÎÄ¼şÃû³ÆÁĞ±í"+temp_arr[1]+ "ÖØ¸´¶¨Òå£¬Çë²éÕıÔÙÊÔ¡£\n");

			filename_to_short[ temp_arr[1] ] = temp_arr[0];
			}
	}
  	//ÓĞĞ©ÎŞÁÄ£¬²»¹ı»¹ÊÇ¼ÓÉÏ£¬·ÀÖ¹Ã»¿¼ÂÇµ½µÄÎÊÌâ
	if( !filename_to_short || !short_to_filename )
	return notify_fail("ÎŞ·¨»ñµÃÓĞĞ§µÄ·¿¼äÃû³ÆÁĞ±í£¬Çë²éÕıÔÙÊÔ¡£\n");

	if( sizeof(filename_to_short) < m)
	return notify_fail("·¿¼äÃû³ÆÁĞ±íÓ¢ÎÄÎÄ¼şÃûÓĞÖØ¸´£¬Çë²éÕıÔÙÊÔ¡£\n");

	if( sizeof(short_to_filename) < m )
	return notify_fail("·¿¼äÃû³ÆÁĞ±íÖĞÎÄ¶ÌÃèÊöÓĞÖØ¸´£¬Çë²éÕıÔÙÊÔ¡£\n");

	write("¹²¶ÁÈ¡ÓĞĞ§·¿¼äÃû³Æ "+sizeof(short_to_filename)+" ¸ö¡£\n");
	
	
	return 1;
}
/*
int sort(string a,string b)
{
	return (sizeof(a)>sizeof(b))?-1:0;	
}
*/
//¶ÁÈ¡µÚn Ä¿Â¼ÉèÖÃ
int read_dir( int n)
{
//	function f = (: sort :);
	// ok. get "dir" first
	int i;
	
	write("----------------------------------------------\n- ÕıÔÚ¶ÁÈ¡ Ä¿Â¼ÉèÖÃ\n");

	if( !sizeof(alldir) )//Èç¹ûÃ»ÓĞËùÓĞÄ¿Â¼//alldirÎ´¶¨Òå£¬ÄÇÃ´¾Í³õÊ¼»¯Ëü
	{
		alldir= filter_array( f_len, (: strsrch( $1, "#dir#" ) != -1 :) );
		if( !alldir || !arrayp(alldir) || !sizeof(alldir) )
			return notify_fail("ÎŞ·¨¶ÁÈ¡ÓĞĞ§µÄ ¡°ÇøÓòÄ¿Â¼¡± ÉèÖÃ£¬Çë²éÕıÔÙÊÔ¡£\n");
				
		for(i=0;i<sizeof(alldir);i++ )
		{
		alldir[i]=  replace_string(alldir[i],"#dir#" ,"");
		alldir[i]=  replace_string(alldir[i]," " ,"");
		}
		
		write_file( "/test/alldir", implode( alldir, "\n" ), 1 );//Êä³öËùÓĞÇøÓòÄ¿Â¼£¬·½±ãºóĞø±à³ÌÓÃ
	}
	dir = replace_string( alldir[n-1], " ", "" );//°üº¬ÇøÓòÄ¿Â¼
	
	//dir = replace_string( checking, "#dir#", "");
	if( !dir ) return notify_fail("ÎŞ·¨¶ÁÈ¡ÓĞĞ§µÄ ¡°ÇøÓòÄ¿Â¼¡± ÉèÖÃ£¬Çë²éÕıÔÙÊÔ¡£\n");
	if( dir[0] != '/' || dir[strlen(dir)-1] != '/' )
		return notify_fail("Ä¿Â¼Îª£º"+dir+"£¬Ëü²¢²»ÊÇÒ»¸ö¾ø¶ÔÂ·¾¶Ãû£¬Çë²éÕıÔÙÊÔ¡£\n");
	write("µ±Ç°Ä¿Â¼Éè¶¨Îª£º"+dir+"-- ÕıÔÚ»ñµÃµØÍ¼ÉèÖÃ...\n");
		return 1;
}





//¶ÁÈ¡µÚn·ùµØÍ¼ ,ÉèÖÃµØÍ¼ ,Ìí¼Ó ×ø±ê--¡µÎÄ¼şÃû
int read_map( int n)
{
	mapping counter = ([ ]);        // ¼ÆÊıÆ÷,Í³¼ÆÖØ¸´·¿¼ä´ÎÊı
	
	string  s1,s2 ,line,checking ,temp_name1,temp_name2 ;
	int  m ,x=0 ,y ,left ,right,i=0,c=0,a;
	

	map = ({ }); m = 0;

	foreach( checking in f_len )//Ã¿´Î¶¼´ÓÍ·¶ÁÆğ£¬ËÆºõ¿ÉÒÔÓÅ»¯Ò»ÏÂ
	{
		i++;
		if( strsrch( checking , "#map_end#" ) != -1 )
		{
			if(sizeof(map))	break;
		}
		if( m ) map += ({ checking });
		if( strsrch( checking , "#map#" ) != -1 )
		{
			c ++;    //ÕÒµ½µÚc·ùµØÍ¼
			if(c==n)
			{
				m=1;
			map_start_line=i;}

		}
	}
	sizeofmap = sizeof(map);
	if( !map || !sizeofmap )
		return notify_fail("ÎŞ·¨¶ÁÈ¡µÚ"+n+"·ùµØÍ¼ÉèÖÃ£¬Çë²éÕıÔÙÊÔ¡£\n");

	write("µÚ"+n+"·ùµØÍ¼¶ÁÈ¡³É¹¦£¡ÕıÔÚ½øĞĞµØµãÉèÖÃ>>\n");

	//Ìí¼Ó±¾µØÌØÉ«ÃèÊö
	while(strsrch( map[x] , ":" ) != -1)  //ÓĞµ±Ç°·¿¼äµÄÌØ±ğµÄ³¤ÃèÊö
	{
		sscanf(  map[x], "%s:%s",s1 ,s2 );//s1ÎÄ¼şÃû  s2³¤ÃèÊö
		
		s1= replace_string( s1, " ", "" ); 
		short_to_long[s1]=s2;		
		x++;
	}
	
	// ½«»ñµÃµÄ map ĞÅÏ¢²ğ·Ö£¬»ñµÃ×ø±ê-¡µÎÄ¼şÃû
	allfile = ({ });
	//for(x=0;x<sizeofmap;x++)
	for(x=x;x<sizeofmap;x++)
	
	{
		line = map[x];				//Ò»ĞĞĞĞÀ´
		if( !line|| !sizeof(line)) continue;	//	Ğ
		linelen=sizeof(line);	

		while((a=strsrch( line , "/d/" )) != -1)
		{
		  while(strsrch(  "1234567890abcdefghijklmnopqrstuvwxyz_/"  , line[a]) != -1 
		  			&& strsrch(  "1234567890abcdefghijklmnopqrstuvwxyz_/"  ,line[a+1]) != -1) //·ÀÖ¹Ì«½ôÃÜµØÍ¼ÖĞ¿¿½ü±ğµÄ /ÒıÆğ³ö´í
		  {
		  if(line[a]=='/') line[a]='*';
		  
		  a++;
		  if(a+1==linelen)break;
		  
		  }
		  	
		}
		
		
		map[x] = line;
	 
		line = replace_nouse_to_blank( line );  //Ö»ÁôÏÂÎÄ¼şÃû£¬ÆäËû×ª¿Õ¸ñ
		
		xy2filename[x]=([]);                    //¸ñÊ½ ({ x:({ y : filename})})
		for(y=0;y<linelen;y++)
		{
			if(line[y]==' ') continue;

			//Óöµ½ÎÄ¼şÀïµÄshortÁË
			right=y; left=y;
			while((right!=(linelen-1))&&line[right+1]!=' ') y=++right;
			checking = line[left..right];       //ÎÄ¼şÀïµÄshort
			
			checking=replace_string(checking, ".", "");//È¥µôÎªÑÓ³¤ÎÄ¼şÃû¶øÌí¼ÓµÄ ^·ûºÅ
			
			if(checking[0]=='*') //°ÑÁ¬½ÓµÄÆäËûÄ¿Â¼ÏÂµÄÂ·¾¶»Ö¸´Õı³£
			{
				checking=replace_string(checking, "*", "/");
				short_to_filename[checking]=checking;
				filename_to_short[checking]=filename_to_short[checking[strsrch(checking,"/",-1)+1..]];				
			}

		
			if( !short_to_filename[checking] )  // ¼ì²éÃ¿¸öµÄÓĞĞ§ĞÔ
			 return	notify_fail("µØÍ¼ÉèÖÃµØµã"+checking+"ÎŞ¶ÔÓ¦ÎÄ¼şÃû ...ÇëÌí¼ÓºóÔÙÔËĞĞ±¾³ÌĞò\n");
			 
			 if(undefinedp(counter[checking]))  //ÖĞÎÄ¶ÌÃèÊöµÚÒ»´Î³öÏÖ
			{
			counter[checking]=0; 					  //¿ªÊ¼Í³¼Æ...
			xy2filename[ x][left]=short_to_filename[checking] ;	//Ìí¼Ó ×ø±ê--¡µÎÄ¼şÃû
			
			if(checking[0]!='/')                                   //°ÑÁ¬½ÓµÄÆäËûÄ¿Â¼ÏÂµÄÎÄ¼şÃûÈ¥µô
			allfile += ({ xy2filename[x][left] });			//Ìí¼ÓÎÄ¼şÃû
			}
			else		//·¿¼äÃû³ÆµÚn´Î³öÏÖ£¬ÒÀ´Î½Ğ×öfile file1 file2¡£¡£¡£

			{
			counter[checking]=counter[checking]+1;   		  //Í³¼Æ´ÎÊı
			temp_name1=short_to_filename[checking];	  		 //ÉèÖÃÖØ¸´·¿¼äµÄmapping ,
			temp_name2=short_to_filename[checking]+counter[checking];//Ó¢ÎÄÎÄ¼şÃûºóÃæ¼ÓÁËÊı×Ö£¬

			filename_to_short[temp_name2]=filename_to_short[temp_name1];//µ«ÖĞÎÄÃû³Æ²»±ä

			xy2filename[x][left] =temp_name2   ;			//Ìí¼Ó ×ø±ê--¡µÎÄ¼şÃû
			
			allfile += ({temp_name2 });				//Ìí¼ÓÎÄ¼şÃû

			}
		}
	}

	if( !allfile || !sizeof(allfile) ) return notify_fail("ÎŞ·¨¶ÁÈ¡µØÍ¼µØµã£¬Çë²éÕıÔÙÊÔ¡£\n");

	write("µØÍ¼ÉèÖÃ³É¹¦£¡ÔÚµØÍ¼Àï£¬¹²ÓĞ "+sizeof(allfile)+" ¸öµØµã¡£¿ªÊ¼¼ÆËã·½Ïò ...\n");

	return 1;
}


 //ÉèÖÃËùÓĞ³ö¿Ú
int set_exits( string *map )
{
	int x, y;
	mixed foo;
	string line;

	all_exits = ([ ]);

	// ÒÔÃ¿Ò»¸öÁ¬½Ó·ûÎªµ¥Î»£¬¿ªÊ¼¼ÆËã·½Ïò
	for(x=0;x<sizeofmap;x++)
	{	line = map[x];
		
	 	if(strsrch( line , ":" ) != -1) continue;//·ÀÖ¹³¤ÃèÊöÀïÃæÓĞÁ¬½Ó·ûºÅ,µØÍ¼ÄÚ±¾Éí²»ÄÜ³öÏÖ:
		linelen = sizeof(map[x]);
		for(y=0;y<linelen;y++)
		{
			foo = map[x][y];

			if(member_array(foo ,all_foos)==-1) continue;

			if(foo=='-'||foo=='<'||foo=='>')
			{
				if(y==0||y==linelen-1)
				return notify_fail("ÎÄ¼şµÚ"+(x+1+map_start_line)+"ĞĞ £¬"+(y+1)+"ÁĞ  - ,< ,> Á¬½Ó´íÎó\n");

			}
			if(foo=='|'||foo=='A'||foo=='V'||foo=='E'||foo=='!'||foo=='{')
			{
				if(x==0||x==sizeofmap||(y+1)>sizeof(map[x-1])||(y+1)>sizeof(map[x+1]))
		 		return notify_fail("ÎÄ¼şµÚ"+(x+1+map_start_line)+"ĞĞ ,"+(y+1)+"ÁĞ | ,A ,V ,E ,! { Á¬½Ó´íÎó\n");

			}
			if(foo=='/')
			{
				if(x==0||x==sizeofmap||y==0||(y+2)>sizeof(map[x-1])||y>sizeof(map[x+1]))
				return notify_fail("ÎÄ¼şµÚ"+(x+1+map_start_line)+"ĞĞ ,"+(y+1)+"ÁĞ  /  Á¬½Ó´íÎó\n");
			}
			if(foo=='\\')
			{
				if(x==0||x==sizeofmap||y==0||y>sizeof(map[x-1])||(y+2)>sizeof(map[x+1]))
				return notify_fail("ÎÄ¼şµÚ"+(x+1+map_start_line)+"ĞĞ ,"+(y+1)+"ÁĞ  \\  Á¬½Ó´íÎó\n");
			}

			if(foo=='X')
			{
				if(x==0||x==sizeofmap||y==0||(y+2)>sizeof(map[x-1])||(y+2)>sizeof(map[x+1]))
					return notify_fail("ÎÄ¼şµÚ"+(x+1+map_start_line)+"ĞĞ ,"+(y+1)+"ÁĞ   x  Á¬½Ó´íÎó\n");
			}
			 //¹ıÂËµô¶à·ûÏàÁ¬Ê±µÄÖĞ¼äµÄ·û,¿ÉÄÜ»¹ÓĞ½»²æ  aaa-----bbbµÈ,Ö»¼ì²é×ó±ß»òÉÏ±ß
			 //Èç¹ûÊÇÄ³¸öÁ¬½Ó·û£¬ÇÒ×ó±ß»òÉÏ±ßÑÓÉì·½ÏòÉÏ²»ÊÇÕâ¸ö·û£¬¾ÍÁ¬½Ó·¿¼ä
			if((member_array(foo,({'-','<','>'}))!=-1&&map[x][y-1]!=foo)
			||(member_array(foo,({'|','A','V','E','!','{'}))!=-1&&map[x-1][y]!=foo)
			||(foo=='/' &&map[x-1][y+1]!=foo)
			||(foo=='\\'&&map[x-1][y-1]!=foo)
			||foo=='X'
			 )
			if(!get_exit( foo,x ,y )) return  notify_fail( "ÎŞ·¨ÉèÖÃ³ö¿Ú1\n"  );

		}
	}
	if( !all_exits || !sizeof(all_exits) ) return notify_fail( "ÎŞ·¨ÉèÖÃ³ö¿Ú2\n"  );
	write("·½Ïò¶ÁÈ¡Íê±Ï£¡½¨Á¢ÎÄ¼ş£º\n");
	return 1;
}

//              Á¬½Ó·ûºÅ Î»ÖÃx  Î»ÖÃy
int get_exit( mixed foo ,int x  ,int y )
{
	// Á¬½Ó·ûÁªµÄÁ½¸öÎÄ¼şÃû name1:½Ï×ó»ò½ÏÉÏµÄ  name2:½ÏÓÒ»ò½ÏÏÂµÄ
	string name1 , name2;

	//-------------ºáÏòÁ¬½Ó·û--------------------
	if(foo=='-'||foo=='<'||foo=='>')
	{
		name1 = xy_to_filename( x, y ,0,-1 );
		name2 = xy_to_filename( x, y ,0,1 );

		if(foo=='-')
		return add_exit( name1, "east", name2 )&&add_exit( name2 , "west", name1 );

		if(foo=='<')
		return add_exit( name1, "eastdown", name2 )&&add_exit( name2 , "westup", name1 );

		if(foo=='>')
		return add_exit( name1, "eastup", name2 )&&add_exit( name2 , "westdown", name1 );

	}
	//-------------×İÏòÁ¬½Ó·û--------------------
	if(foo=='|'||foo=='A'||foo=='V'||foo=='E'||foo=='!'||foo=='{')
	{
		name1 = xy_to_filename( x, y ,-1,0 );
		name2 = xy_to_filename( x, y  ,1,0 );

		if(foo=='|')
		return add_exit( name1, "south", name2 )&&add_exit( name2, "north", name1 );

		if(foo=='A')
		return add_exit( name1, "southdown", name2 )&&add_exit( name2, "northup", name1 );

		if(foo=='V')
		return add_exit( name1, "southup", name2 )&&add_exit( name2, "northdown", name1 );

		if(foo=='E')
		return add_exit( name1, "downstairs", name2 )&&add_exit( name2, "upstairs", name1 );
		                       //ÏÂÂ¥                                    ÉÏÂ¥

		if(foo=='!')
		return add_exit( name1, "down", name2 )&&add_exit( name2, "up", name1 );

		if(foo=='{')
		return add_exit( name1, "climbdown", name2 )&&add_exit( name2, "climbup", name1 );


	}

	//-----Î÷ÄÏ-¶«±±-------------------------
	if(foo=='/')
	{
		name1 = xy_to_filename( x, y ,-1,1 );
		name2 = xy_to_filename( x, y ,1,-1 );

		return add_exit( name1, "southwest", name2 )&&add_exit( name2, "northeast", name1 );

	}
	//-----Î÷±±-¶«ÄÏ-------------------------
	if(foo=='\\')
	{
		name1 = xy_to_filename( x, y ,-1,-1 );
		name2 = xy_to_filename( x, y ,1,1 );

		return  add_exit( name1, "southeast", name2 )&&add_exit( name2, "northwest", name1 );
	}

	//---------½»²æÁ¬½Ó-------------------------
	if(foo=='X')
	{
	// x Ïàµ±ÓÚ /£¬\ Á½ÕßÔÚÒ»¸öÎ»ÖÃÉÏ,µİ¹éµ÷ÓÃÁ½´Î
		if(!get_exit( '/' , x  , y )) return 0;
		if(!get_exit( '\\' , x  , y )) return 0;
		return 1;
	}

}

 //ÓÉµØÖ·µÃµ½ÎÄ¼şÃû x1 y1ÊÇÓÃÀ´½â¾ö¹ıÂËµô¶à·ûÏàÁ¬
 // map[x][y]        xµÚ¼¸ĞĞ  £¬yµÚ¼¸ÁĞ , xÏà¶ÔÆ«ÒÆ£¬    yÏà¶ÔÆ«ÒÆ
string xy_to_filename( int x ,   int y  ,  int x1  ,    int y1 )
{
	int  left,linelen ;
	string  line ;
	//¹ıÂËµôÖØ¸´µÄÁ¬½Ó·û£¬Èç aaaa-------bbbb Ö»¼ì²éÓÒ±ß»òÏÂ±ß
	do{
		x+=x1 ; y+=y1 ;
		line = map[x];
		linelen =sizeof( line );
		if(( (y+1)>linelen)||line[y]==' ')
		{	write("µØÍ¼µÚ"+(x+1+map_start_line)+"ĞĞ,µÚ"+(y+1)+"ÁĞ´¦ÎŞÎÄ¼şÃûÎÄ×Ö£¬¸½½üÁ¬½Ó·ûÁ¬½Ó´íÎó¡£\n");
			return 0;
		}
		if( member_array( line[y] ,all_foos )==-1 )  break;    //ÕÒµ½ ·¿¼äÃû³Æ ÁË
	  }while(1);

	left = y;

	//»ñµÃÎÄ¼şÃûÆğÊ¼×ø±ê
	if(left>0)
	{
						 //³öÏÖ......   ÒâÎ¶×ÅÒÑ¾­µ½ÁË·¿¼äÃû³Æ×î×ó±ß
		while(member_array(line[left-1] ,({' '})+all_foos)==-1)
		{
	 	left--;
	 	if(left==0) 	break;
	 	}
	}

	//»ñµÃÎÄ¼şÃû
	return xy2filename[x][left];
}

//ÉèÖÃ³ö¿Ú        ·¿¼ä1----¡µ³ö¿Ú-------·¿¼ä2
int add_exit( string n1, string exit, string n2 )
{
	if((!n1)||(!n2)) return 0;
	if( undefinedp( all_exits[n1] ) )
		all_exits[n1] = ([ ]);
	all_exits[n1][exit] = n2;
	return 1;
}

//»ñµÃ³ö¿ÚĞÅÏ¢
string get_exit_msg( string file )
{
	string longexitmsg="", msg = "" , exit , *exits=({"east", "eastup", "eastdown", "west", "westup", "westdown",
			    "north", "northup", "northdown","south", "southup", "southdown",
			    "northeast", "northwest", "southeast", "southwest" ,
			    "upstairs","downstairs",  "up","down" ,"climbup","climbdown"

			});
	mapping exit2long=([
	"east":"¶«±ßÈ¥¾ÍÊÇ",
	 "eastup":"¶«±ß¹ıÈ¥¸ß´¦¾ÍÊÇ",
	  "eastdown":"¶«±ßµÍ´¦ÍùÏÂ¾ÍÊÇ", 
	 
	 "west":"Î÷Ãæ×ß¾ÍÊÇÈ¥", 
	  "westup":"Î÷Ãæ¹ıÈ¥¸ß´¦¾ÍÊÇÈ¥",
	   "westdown":"Î÷ÃæµÍ´¦ÍùÏÂ¾ÍÊÇÈ¥",
	   
	 "north":"±±±ß×ß¾Íµ½ÁË",
	  "northup":"±±±ß¸ß´¦×ß¾Íµ½ÁË",
	   "northdown":"±±±ßµÍ´¦ÍùÏÂ¾Íµ½ÁË",
	  
	 "south":"ÄÏÃæ¾ÍÊÇ", 
	  "southup":"ÄÏÃæ¹ıÈ¥¸ß´¦¾ÍÊÇ", 
	   "southdown":"ÄÏÃæµÍ´¦ÏòÏÂ¾ÍÊÇ",
	   
	 "northeast":"¶«±±·½Ïò¿ÉÒÔµ½",
	  "northwest":"Î÷±±·½ÏòÈ¥Íù",
	   "southeast":"¶«ÄÏ·½Ïòµ½´ï", 
	   "southwest" :"Î÷ÄÏ·½ÏòÁ¬×Å",
	
	 "upstairs":"ÑØÂ¥ÌİÍùÉÏ¾ÍÊÇ",
	 "downstairs":"ÏÂÂ¥¾Íµ½ÁË",  
	   "up":"ÏòÉÏËÆºõÊÇÍ¨Íù",
	   "down" :"³¯ÏÂËÆºõ¿ÉÒÔµ½", 
	 "climbup":"ÑØ×ÅÉş×ÓÍùÉÏÅÀËÆºõ¿ÉÒÔµ½",
	 "climbdown":"ÑØ×ÅÉş×ÓÏòÏÂËÆºõ¿ÉÒÔµ½´ï"
	
	]);
	longexitmsg="";
	if(undefinedp( all_exits[file] ) )
	{
		all_exits[file]=([]);
		 all_exits[file]["long"]="";//Ã»ÓĞ³ö¿ÚÃèÊö
		  return "";
	} 
	 
	foreach( exit in exits)  //ÖğÒ»²éÑ¯ ,Ìí¼Ó
	{
		if( !undefinedp( all_exits[file][exit] ) )
		{			

			if( all_exits[file][exit][0]=='/')//ÆäËüÄ¿Â¼Á¬½Ó
		 		msg += sprintf("%-16s","\n		\""+ exit +"\"")+":\""+all_exits[file][exit]+"\",";			
			else
				msg += sprintf("%-16s","\n		\""+ exit +"\"")+": __DIR__\""+all_exits[file][exit]+"\",";	
							 
				longexitmsg+= exit2long[exit]+filename_to_short[all_exits[file][exit]]+",";		
		}
	}
	
	longexitmsg+=",";
	longexitmsg=replace_string( longexitmsg, ",,","¡£" );
	
	all_exits[file]["long"] = longexitmsg;
	
	msg+=",";
	return replace_string( msg, ",,","" ) + "\n";
}

//½¨Á¢ÎÄ¼ş            Ä¿Â¼      ÎÄ¼şÃû
void create_it( string dir, string file )
{
//	int t;
	string alltext,exit_msg; 
	
	if( !filename_to_short[file] )
	{
		write("ÎŞ·¨½¨Á¢ "+file+" ¡£\n");
		return;
	}
	write(">> "+filename_to_short[file]+": "+dir+file+".c ½¨Á¢ÖĞ.....");
	
	exit_msg =get_exit_msg(file);//±ØĞëÏÈÔËĞĞº¯Êı£¬·ñÔò³ö¿ÚÁ¬½ÓÎÄ×ÖÎ´ÉèÖÃ
	
	alltext = "//Created by command: \"auto_create_area.c\" v1.5
// File: "+ dir + file + ".c   "+ctime(time())+
"\n//#include <ansi.h>
inherit ROOM;
void create()
{
	set(\"short\", \""+filename_to_short[file]+"\");
	set(\"long\",@LONG\n"+short_to_long[filename_to_short[file]]
	+ all_exits[file]["long"]
	+"\nLONG\n);
	set(\"exits\", ([ /* sizeof() == "+(sizeof( all_exits[file])-1)+" */"+exit_msg+" ]));
/*	set(\"objects\", ([ // sizeof() ==
  		__DIR__\"npc/...\" : 1,
		]));
*/
        set(\"outdoors\", __DIR__);
	setup();
	//replace_program(ROOM);
}
";
	write(   write_buffer("/test"+dir + file + ".c" , 0 ,alltext )  ? "³É¹¦\n":"Ê§°Ü\n" );
}

int help(object me)
{
	string msg = "
===========================================
    auto_create_area ÎÄ¼şÃû
    ÀıÈç auto_create_area /d/xj/abc
½«¸ù¾İ¸ÃabcÎÄ¼şÉèÖÃ£¬Éú³ÉÒ»Æ¬¼òµ¥ÇøÓòÔ´ÎÄ¼ş£¬
Ê£ÏÂµÄ¹¤×÷¾ÍÊÇ¾ßÌåĞŞ¸Ä·¿¼äµÄ¶¨Òå ¡£
Çë×¢Òâ£¬¸÷²¿·Ö±Ø²»¿ÉÉÙ£¬¶ø¿ÕĞĞ»á±»Ê¡ÂÔ¡£
  ***** ÒÔÏÂÊÇÊ¾·¶ÎÄ¼ş¸ñÊ½ ******

#create area file#
//
#list#
´óÌü:dating
ÎÔÊÒ:woshi
³ø·¿:chufang:ÕâÀïÊÇÒ»¸öÑÌÑ¬»ğÁÇ£¬ÏãÆøËÄÒçµÄ³ø·¿
ÑôÌ¨:yangtai
´óÃÅ¿Ú:damenkou
ÃÅÍâ:menwai
Ğ¡Â·:xiaolu
#list_end#

#dir#	/d/area1/
//ÎÄ¼şÉú³ÉÎ»ÖÃÊµ¼ÊÔÚ/test/d/area1/
#map#
´óÌü-ÎÔÊÒ-³ø^^^·¿
     |  \\  |  \\
   ÑôÌ¨-´óÃÅ¿Ú-ÃÅÍâ-----Ğ¡Â·
#map_end#
//Î»ÖÃ¿ÉÒÔĞ´ÈÎÒâĞĞ×¢ÊÍÄÚÈİ£¬²»»á±»¶ÁÈ¡¡£
  ********************************\n";

string msg1="
Çë×¢Òâ£¬ÎªÁËÊ¹¸ñÊ½¹æ·¶£¬Çë×ñÊØÒÔÏÂ¹æÔò£º

1¡¢Ä¿Â¼ÇëÊ¹ÓÃ¾ø¶ÔÂ·¾¶£¬¼´¿ªÍ·¼°½áÎ²¶¼ĞèÒª / ·ûºÅ¡£
2¡¢·¿¼äÖĞÎÄÃû£¬ÇëÎğÊ¹ÓÃ¿Õ¸ñ¼°
   - ,| ,/ ,\\ ,E, A, v ,V ,! ,{ ,< ,> ,x ,X.
3¡¢·¿¼äÖĞÎÄÃû¼°ÎÄ¼şÃû¶ÔÕÕÁĞ±íÄÚµÄËùÓĞ¿Õ¸ñ½«±»ºöÂÔ£¬
   ²¢ÇëÊ¹ÓÃ \":\" ·ûºÅÁ¬½Ó
4¡¢·½ÏòÎª£ºÉÏ±±ÏÂÄÏ×óÎ÷ÓÒ¶«
5¡¢ºáÏò·¿¼äÁ¬½Ó£¬Ê¹ÓÃ \"-\" \"<\" \">\" £¬·¿¼äÃûÖ®¼äÎŞ¿Õ¸ñ¡£
6¡¢×İÏò·¿¼äÁ¬½Ó£¬Ê¹ÓÃ \"|\" \"A\" \"v\" \"V\" ¡£.
7¡¢Î÷Ğ±Ïò·¿¼äÁ¬½Ó£¬Ê¹ÓÃ \"/\"¡£
8¡¢¶«Ğ±Ïò·¿¼äÁ¬½Ó£¬Ê¹ÓÃ \"\\\"¡£
9¡¢½»²æÁ¬½ÓÓÃ x»ò X.
10¡¢A,v»òV,< ,>,¼â¼âËùÖ¸ÊÇµØÊÆ½Ï¸ßµÄÎ»ÖÃ.
11¡¢Á¬½Ó·û¿ÉÒÔÁ¬ĞøÊ¹ÓÃ£¬Ò²¿ÉÒÔÏà»¥´©Ô½,·¿¼äÃû³ÆÖĞ¼ä\n¿ÉÓÃ^^^·ûºÅÀ´ÑÓ³¤ÒÔ±ãÓĞ×ã¹»Î»ÖÃºÍÆäËü·¿¼äÏàÁ¬";


string msg2="\n
   7,8 Àı×Ó                       9 Àı×Ó
      abc  c,f Î»ÖÃ±ØĞëÓĞÖĞÎÄÃû×Ö   aa bb
      d/e                             x
      fgh                           cc dd
                ±íÊ¾aa ddÏàÁ¬£¬bb ccÏàÁ¬,ÃÔ¹¬ÀïÓĞÊ±ÓÃµ½

   11Àı×Ó   ·¿¼ä1
             |
    ·¿¼ä3--------- ·¿¼ä4    ±íÊ¾ 1 2 ÏàÁ¬£¬3 4 ÏàÁ¬
             |
          ·¿¼ä2

Èç²»Ã÷°×£¬Çë¶ÔÕÕÉÏÎÄÊ¾·¶¸ñÊ½¡£ÈÔ²»Ã÷°×»òÓĞ´íÎó£¬
ÇëÓèwww.mudbuilder.comÂÛÌ³ ÁôÑÔ¡£

    Ğ´ºÃ¸ÃÎÄ¼şºó£¬ÊäÈë±¾Ö¸Áî¼´¿É¡£
==========\n";

	me->start_more( msg );
	me->start_more( msg1);
	me->start_more( msg2);
	return 1;
}

int main( object me, string arg )
{
	int map_i; // µÚ¼¸·ùµØÍ¼
	if(!arg) return help(me);
		assure_file( "/test/ " );
		if( file_size( "/test" ) != -2 )
			return notify_fail("ÎŞ·¨½¨Á¢¸ÃÄ¿Â¼£º/test\n");
	if(!read_file_msg( arg )) return 0;
	alldir=({}) ;
	for( map_i=1;map_i<=map_number;	map_i++)
	{
	//	short_to_long = short_to_long_bk+([]);
		reset_eval_cost();
		if(!read_dir(map_i ) || !read_map( map_i))
			return 0;
		
		assure_file( "/test"+dir+" " );
		if( file_size( "/test"+dir ) != -2 )
		return notify_fail("ÎŞ·¨½¨Á¢¸ÃÄ¿Â¼£º/test"+dir+"---\n");
		//write("\nok1\n");²âÊÔÓÃµÄ

		if(!set_exits( map)) 	return 0 ;
		//write("\nok2\n");²âÊÔÓÃµÄ

	// ½¨Á¢ÔÚµØÍ¼ÄÚµÄ·¿¼ä
		foreach( filename in allfile ) create_it( dir, filename );

		write("\n½¨Á¢Íê±Ï£¡¹²Éú³É /test"+dir+" ÏÂ "+sizeof(allfile)+" ¸öÎÄ¼ş¡£\n");
		
	}
	write("\nËùÓĞÎÄ¼ş½¨Á¢Íê±Ï£¡\n");
	return 1;
}

