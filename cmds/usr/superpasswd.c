//Cracked by Roath
// superpasswd.c
#include <ansi.h>
#include <command.h>
#include <login.h>
inherit F_CLEAN_UP;
inherit F_DBASE;
int check_legal_superpasswd(object ob,string arg);
private void get_new_superpasswd(string superpasswd, object ob);
private void get_old_superpasswd(string superpasswd, object ob);
int main(object me, string arg)
{
	object ob;

	if( me != this_player(1) ) return 0;

	ob = me->query_temp("link_ob");
	if( !ob ) return 0;
	while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

	write("Ϊ�˰�ȫ�������������������ݱ�ʶ��");
	input_to("get_old_superpasswd", 1, ob);
	return 1;
}
int check_legal_superpasswd(object ob,string superpasswd)
{
	int i;
	int bigletter=0;
	int smlletter=0;
	int number=0;
	string id;
	i = strlen(superpasswd);
	if( strlen(superpasswd) <= 5)   {
		write(WHT"�Բ��������ݱ�ʶ��������"BLINK HIY"��"WHT"���ַ���\n"NOR);
		return 0;
	}
	while(i--) {
		if( superpasswd[i]<='Z' && superpasswd[i] >='A' ) bigletter++;
		if( superpasswd[i]<='z' && superpasswd[i] >='a' ) smlletter++;
	}
	if( bigletter == 0 || smlletter == 0 || bigletter+smlletter == strlen(superpasswd)){
        write(WHT"������ݱ�ʶ�������"HIY"��д" NOR HIR"��" + HIY"СдӢ����ĸ" NOR HIR"��" + WHT"����"HIY"������ţ����֣���㣩"NOR WHT"��\n"NOR);
		return 0;
	}
	return 1;
}
private void get_old_superpasswd(string superpasswd, object ob)
{
       string old_superpasswd;
       write("\n");
       old_superpasswd = ob->query("superpasswd");
       if( crypt(superpasswd, old_superpasswd)!=old_superpasswd ) {
              write("��ݱ�ʶ����\n");
              return;
       }
       write("�������µ���ݱ�ʶ��");
       input_to("get_new_superpasswd", 1, ob );
}
private void get_new_superpasswd(string superpasswd, object ob)
{
	if( !check_legal_superpasswd(ob,superpasswd)) {
		write("���趨������ݱ�ʶ"HIM"[ "HIC"SuperPassWord"HIM" ]"NOR"��");
		input_to("get_new_superpasswd", 1, ob);
		return;
	}
	write("\n��������һ���µ���ݱ�ʶ��");
	input_to("confirm_new_superpasswd", 1, ob, crypt(superpasswd,0));
}

private void confirm_new_superpasswd(string superpasswd, object ob, string new_superpasswd)
{
	write("\n");
	if( crypt(superpasswd, new_superpasswd)!=new_superpasswd ) {
		write("�Բ������������ݱ�ʶ������ͬ������ʹ��ԭ������ݱ�ʶ��\n");
		return;
	}
	seteuid(getuid());
	if( !ob->set("superpasswd", new_superpasswd) ) {
		write("��ݱ�ʶ���ʧ�ܣ�\n");
		return;
	}

	ob->save();
	write("��ݱ�ʶ����ɹ���\n");
}

int help(object me)
{
	write(@HELP
ָ���ʽ : superpasswd
 
���ָ������޸������ݱ�ʶ��
 
HELP
    );
    return 1;
}
 
