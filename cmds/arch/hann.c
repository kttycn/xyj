//Cracked by Roath
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        string old_status, new_status;
        int my_level, ob_level, level;

        if( me!=this_player(1) ) return 0;

        if( !arg || sscanf(arg, "%s %s", arg, new_status)!=2 )
                return notify_fail("����Ҫ���ʲô��\n");

        if( wiz_level(new_status) < 0 ) return notify_fail("ʲô?\n");

        if( !objectp(ob = present(arg, environment(me))) 
        ||      !userp(ob) )
                return notify_fail("ʲô?\n");

        old_status = wizhood(ob);

        seteuid(getuid());
        if( !(SECURITY_D->set_status(ob, new_status)) )
                return notify_fail("ʲô?\n");
                
        write( HIR BLINK "Ok.\n" NOR);
        seteuid(getuid());
        ob->setup();

        return 1;
}

int help(object me)
{
write(@HELP
ʲô?
HELP
    );
    return 1;
}
