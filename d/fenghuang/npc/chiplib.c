// chiplib.c                    
// ���ֳ��ڳ����Ӧ�ú�ʽ
int Game_chip_count(int flag, object me)
{
        int total;
        object gamechip;
        gamechip = present("game_money",me);
        if(!gamechip) return 0; 
        total = 0;
        total += gamechip->value();
        if(flag && gamechip)    
                destruct(gamechip);
        return total;
}

int Game_can_afford(int amount, object me)
{
        int total;
        total = Game_chip_count(0,me);
        if( total >= amount )
        {
                return 1;       
        }
        else
        {
                return 0;       
        }
}

int Game_receive_chip(int amount, object me)
{
        int total;
        object chip;
        
        total = Game_chip_count(0,me);
        total += amount;
        if( total < 0 ) return 0;
        Game_chip_count(1,me);  
        chip = new("/d/obj/misc/gamechip.c");
        chip -> set_amount( total );
        chip -> move(me);
        return 1;
        
}

