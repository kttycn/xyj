//By waiwai@mszj 2000/11/03 �Ż�look.c
 
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
   if (arg=="n") me->set("look","n");
   else if (arg=="y") me->set("look","y");
   else	return help();
   write("ok!!\n");
   return 1;
}
 
int help()
{
	write(@TEXT

ָ���ʽ�� lookset <y/n> 
 
���ָ�������趨lookʱ�Ƿ�ɿ�������Ļ���״����

���磺 lookset y   �ɿ���
       lookset n   ȥ������
 
TEXT
	);
	return 1;
}
