// cp.c
// creator:	 Fan@falling-sun.chinesemud.net
// creat time:  1999/04/05

inherit F_CLEAN_UP;
 
protected string get_path(string str);
protected string get_file(string str);
protected int cp_file(object me, string from, string to, int rflag, int iflag, int silent);
int help(object ob);

int directory_exists(string dirname)
{
	return (file_size(dirname) == -2);
}
int file_exists(string filename)
{
	return (file_size(filename) > -1 );
}


varargs string extract( string str, int from, int to )
{
	if( !stringp( str ) ) return ""; // syntax error
	if( nullp( from ) ) return str;
	if( nullp( to ) ) to = strlen( str );
	return str[from..to];
}

//
 
int main(object me, string arg)
{
	mixed *files;
	string str,flags, tpath, fpath, from, to, tmp1, tmp2;
	int loop, rflag, iflag, silent;

	if (me!=this_player(1))	return 0;
	seteuid( getuid(me) );

	if(!arg || arg == "")  return help(me);

	if(sscanf(arg, "-%s %s", flags, str) == 2
	|| sscanf(arg, "%s -%s", str, flags) == 2) {
		if(sscanf(" " + flags + " ", "%sr%s", tmp1, tmp2) == 2)  rflag = 1;
		if(sscanf(" " + flags + " ", "%si%s", tmp1, tmp2) == 2)  iflag = 1;
		if(sscanf(" " + flags + " ", "%sf%s", tmp1, tmp2) == 2)  iflag = 0;
		if(sscanf(" " + flags + " ", "%ss%s", tmp1, tmp2) == 2)  silent = 1;
	}else str=arg;
 
	if(sscanf(str, "%s to %s", from, to) != 2 &&
	sscanf(str, "%s %s", from, to) !=2)
		return help(me);

	if(to == ".")  to = (string)this_player()->query("cwd");
 
	from = resolve_path(me->query("cwd"), from);
	to   = resolve_path(me->query("cwd"), to);

	if(directory_exists(from))
		if(from[strlen(from)-1] == '/')  from += "*";
	else from += "/*";

	fpath = get_path(from);
	tpath = get_path(to);

	if(!directory_exists(fpath)) {
		write("Cp: û�����Ŀ¼ : " + fpath + "\n");
		return 1; 
	}
 
	if(!directory_exists(tpath)) {
		write("Cp: û�����Ŀ¼ : " + tpath + "\n");
		return 1; 
	}

	if((int)master()->valid_read(fpath, me, "cp") == 0) {
		printf("Cp: Ȩ�޲������%s.\n",(fpath == "" ? "��Ŀ¼" : fpath));
		return 1;
	}

	if((int)master()->valid_write(tpath, me, "cp") == 0) {
		printf("Cp: Ȩ�޲�����д%s.\n",(tpath == "" ? "��Ŀ¼" : tpath));
		return 1; 
	}

	files = get_dir(from);
	files -= ({ "." });
	files -= ({ ".." });
 
	if(!files || !sizeof(files)) {
		write("Cp:  û���������÷� : " + from + "\n");
		return 1;
	}
//   ������ƶ���ļ������"to"��Ϊһ��Ŀ��Ŀ¼

	if(sizeof(files) > 1) {
		if(tpath != "")   tpath = to + "/";

		if(!directory_exists(tpath)) {
			if (!rflag){
				write("Cp: û�����Ŀ¼ : " + tpath + "\n");
				return 1; 
			}else mkdir(tpath);
		}

		if(tpath == fpath) {
			write("Cp: �ⲻ��Ϲ������\n");
			return 1; 
		}
	}
 
	if(sscanf(tpath, fpath + "%s", tmp1) == 1 && tmp1 != "" && rflag) {
		write("Cp: ���ܵݹ鸴�ơ�\n");
		return 1; 
	}

	if(sizeof(files) == 1) {
		if(!file_exists(fpath + files[0]) &&
		!directory_exists(fpath + files[0])) {
			write("Cp: " + fpath + files[0] + " �ļ�������.\n");
			return 1;
		}

		if(directory_exists(to)) 
			to += (tpath == "" ? "" : "/") + get_file(files[0]);

		cp_file(me, fpath + files[0], to, rflag, iflag, 0);

		this_player()->set("cwf", to);
		return 1;
	}

	for(loop=0; loop<sizeof(files); loop++) 
		cp_file(me, fpath + files[loop], tpath + files[loop], rflag, iflag, silent);

	if(silent)  write("Cp: �ļ�������ɡ�\n");

	return 1;
}
 
protected int cp_file(object me, string from, string to, int rflag, int iflag, int silent)
{
	mixed *tmp;
	int loop;
 
	if(from == to) {
		write("Cp: Ϲ����...\n");
		return 1;
	}

	if(file_size(from) == -1) {
		write("Cp: " + from + " �ļ�������.\n");
		return 1;
	}

	if(directory_exists(from)) {
		from += "/";  to += "/";

		if(rflag) {
			tmp = get_dir(from);
			if(!directory_exists(to))   
				mkdir( to[0..strlen(to)-2] );
 
			for(loop=0; loop<sizeof(tmp); loop++)
				cp_file(me, from + tmp[loop], to + tmp[loop], rflag, iflag, silent);
		}

		else {
			if(!silent)  write("���ܸ���: " + from + " ��һ��Ŀ¼��\n");
			return 1;
		}

		rmdir( from[0..strlen(from)-2] );

		if(!silent)
			write("����Ŀ¼�ṹ: " + from + " --> " + to + "\n");
		return 1;
	}

	if(iflag && file_exists(to)) {
		if(!silent) write("Ŀ���ļ�: " + to + " �Ѿ����ڡ�\n");
		return 1;
	}
	if (cp(from,to))
	{
		if(!silent)  write("" + from + " ---> " + to + "...ok.\n");
		log_file("cmds/cp",	sprintf("%s(%s) cpһ��(%s) �� (%s) on %s\n",
		me->name(),  //��¼ʹ�����������
		geteuid(me), //��¼ʹ�������ID
		from,   //��¼Դ�ļ�
		to,  //��¼Ŀ���ļ�
		ctime(time()) ) ); //��¼ʹ�������ʱ��
	}
	else
		if(!silent)  write("" + from + " ---> " + to + "ʧ�ܣ�\n");

	return 1; 
}

protected string get_path(string str)
{
	mixed *tmp;
	string path;

	if(str == "/") return "";

	if(str[strlen(str)-1] == '/') return str;
	else if(directory_exists(str)) return str+"/";

	tmp = explode(str, "/") - ({ 0 });
	if (sizeof(tmp)>=2)
		path = "/" + implode( tmp[0..sizeof(tmp)-2], "/")+"/";
	else
		path="";
	if(path == "//") path = "";

	return path;
}
 
protected string get_file(string str)
{
	mixed *tmp;
	tmp = explode(str, "/");

	return tmp[sizeof(tmp)-1]; 
}
  
int help(object me)
{
  write(@HELP
ָ���ʽ: cp [-rsfi] <Դ�ļ�> <Ŀ���ļ�>
 
	��ָ����Ը����ļ���
	
	
	���ָ������ʹ��ͨ���*��?���Ƹ�����ļ�������ʹ�����²�����
	
	-r : ���ư�����Ŀ¼���ļ������Ը��ǵ���ʽ��д�Ѿ����ڵ�Ŀ���ļ���
	-i : ����ʹ�ø��Ƿ�ʽ��дĿ���ļ���
	-f : ǿ��ʹ�ø��Ƿ�ʽ��д�Ѿ����ڵ��ļ���
	-s : ʹ�üž���ʽ�����ļ���
	

HELP
	);
	return 1;
}
 
