// for autosave players data file.
#include <ansi.h>

inherit F_DBASE;
#define FEI_D "/obj/feizei/feizei.c"
void auto_fei();
void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "�ڴ澫��");
        CHANNEL_D->do_channel( this_object(), "sys", "\n��������ϵͳ�Ѿ�������\n");
        call_out("auto_fei", 4);
}

void auto_fei()
{
        FEI_D->choose_npc();
        remove_call_out("auto_fei");
        call_out("auto_fei", 720);
}
