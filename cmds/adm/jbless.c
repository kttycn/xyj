
// ����ף��
// write by guoth
// 2001.2.14

#include <ansi.h>

inherit F_CLEAN_UP;

string *color = ({
    RED, GRN, YEL, MAG, BLU, CYN, WHT,
    HIR, HIG, HIY, HIB, HIM, HIC, HIW, });

string *holiday = ({
    "Ԫ��","����","���˽�","���˽�","��ͯ��","�����","ʥ����",
    });

string *holiday_pic = ({
@TEXT
         ______     __  ._    )z  ee     .____zz     ab
         ~~~~~~     @@~~-@   ]U@z_aL_,   ]@~==~"     @[
        zzzzzzzz    @L__d@   ]M[~~][]P   ]@_a@_      ][
        ~ ][@       ]L  ][   ]~Lzza@abz, ~~~-@~~~'   ][
          a[@L      `~~~~'    ][~ aUC~~   z@]@]b_    ][
       __d@'`@z_a[zzzd@@bzzz, d[_dr`@L  _a~Ld@ ~@b,  "'
       "~~   "-@~ ~~    "~~~  qr~~  `~,    `@'  "~   ze
                                                     ~"
TEXT,
@TEXT

           ]L        ._ __     z  )L           __
       .___aL__z,    ]' ]'._  ][  ]'      zs--~~"    __
          ]P ._   ~~~@~~@~~~  dL--@-4[   ]P )z       @P
       `~~@~~~ _    `' `'_   sa],][ a'   a' ][      .@'
      ---%--z--~  "~~@~~][  ]M[" ][.[   ]L__aL_ze   ][
       _a'  ]L      .@  d[  ~dL__@_]-'  `',.[_      d'
     .s'a~~~[~@-    ]P  a    a' ]M[     .a'][]L     "
       .C__][       ]'z_[   .[ )r`[    .%" a' @[   e@
       ][  a'       @  ~'   ][_F  @L  ]~  .@  `'   `'
       a~~~@       ]'       au~   `@'    "@'
TEXT,
@TEXT
     ._   _,        _        _   _     e   _
     ][)--a[--,     @     .__L___@__,  [   @      zzr-=~~"
    )d@L__aL__      @     `~~[~~~@~~ ),[e--@--L  ][  _             ab
    ]M@[  ][        @,       '   ~   ][[@  @ ][  ][  @             @[
    ]H[@~~~~~~"    .@b     =~~-@~~~e ][[`  @ ][  ]'  @             ][
    ]H[ %~~~~@     ][a        ][   [ ]'[___@_]L_ qzzz@zzzz,        ][
    `][ @zzzz@    .% ]L       ][   [ ~ [   [L     ., @ e,          ][
     ][ [    @    d'  @,      ][  .[   [  ][],    a' @ `L          "'
     ][ [~~~~@   d'   `@,     ][z_][   [ .@ `L   ]P  @  qL         ze
     ][ [ ._.@ .d'     `@,    ][`~~    [_@'  `L_.@ _,@  `a         ~"
     `" '  ~~" "'       `"    `'       '~     `"`' "~"   "
TEXT,
@TEXT
                 .,                  _  .,
    ]r-z-]b      ]@        ][ ][     @' ][      e___z=-
    ]L_@_][      ]@     )--]K-]K-~,  @._]L_z,   ][ __            ]K
    ]L_@_][      ]@        ]P ]P     @-,][ ]    @  ][            ][
   .=' @ `uL     ]H[     ----r--@, .%@`'][ ]    @  ][ .e         ][
   ][~~@]C][     a'[        ][  @  `'@  ][ ]z, `~~~][~~~         ][
   ][z-~~~][    .@ ],       ][  @    @"~]M~~'    a,][b,          `'
   ]Pz,z,"@'    d' `L       ][_ @    @  a~b     ]r ][`@L         ]L
   ][] `'e-L   ]'   ]L,     ][`~~    @ ]P qL   ]~  ][ ][         q@
  .a']L__a,@, s'     ]@-    ][       @]~   -b `"  -a[
             "'             "        ~"     "      "
TEXT,
@TEXT
                  __          ._
       )z         ""_      qb ][__   ]L `@         .ab           _,
     -e @       -z~@[    __]K-@~~~   ][  @       z=~"            ][
     ][ [        q,aLzz, `' [ 6      ]L._@]b     @ ],            ][
     ][ [     ez-~~~L,    ___z--L   e]M'.[]P    .[_ab=-,         ][
     ][ [       ]F]C]P    `~`@ ][   @][ ]L]bzL  ]@~][            ][
     a' [  ][   ][]C%'       [ dP  `~][~]@,     ._ ]L_,          ]
    ]r  L  ]b   `~]""        [`@'    d[.%`L     dP ][`@L
   ]~   `@d@'   )-a~"        [ "     ][d' ]@_   @'_a[ `'         @b
   "           __z=-~~-      [       ]K'   ~~"    `@
               `'            '
TEXT,
@TEXT
                   -_        _  e,    )L  -,          .,
     a___z--@   ),  @ .,     ][ ]'     [  ][      .,__%'          __
     ]      [    K--C~~~  .__ab-@-='   L  ][._    ][~z            ][
     ] -@[~'[    [  ]'       q[]'     [[az]@M[    ][ @            ][
     ]  ]L_ [    [  @ _,     _L__a,  ][[" ][][    ]' @___         qP
     ] ~]C~ [   )[-~C~~"   `~~]  a   `'[  ]LaUz   ~~~@"           ][
     ]  ][[.[   ][ ]ML        ]  @     ["~]a       a'@)L          ][
     ]hr=-=M[   ]' %'b,       ]`L[     [  %`L     ]' @ `@_
     ][  __][  .[ d' `L       ] `'     [ d' ],   _'.,@  `'        ]K
     ][~~~'][  d'/"   qb_     a       )[]P  `@_ `"  ]@
     `'        "`'            `        '~            "
TEXT,
@TEXT
                            _,  .,    ],  .,
    `-@~~~~@   ]b)zz__z=' __aL__dL_,  a'  d'     _zz--~~~
      @,  d'    @ ]r )[   ~~[~~~@~~'),[e--a--e  )P  _             a[
      ]L.d'   _, .r [d[    `'  )'   a][[ )[ d[  a' .[            )@[
      .@C     ~@ az][aze `~~~@~~~- .[]~' d[ a  )P  ][            ]@
  ._z/~'"-z_  .[  ]@'[      ]P   @ d'@___a__L_ qbzzabzzzc        ][
  `~  .[  `~' ][][@@][      ]'  ]P "]P  )Mb     _  [ z           a'
   ezzdbzzz   a ]UMPa       @   ]'  ]' .%`[    ]r ][ ][          "
      a'     .[dO@/~~~'    )Pe__r   % .%' @   ]r  ]' ][         ze
 _____C____, `~>r`az__     d'`~~   )P_r'  ]L,]r._.@  `[         ~'
 "~~~~~~~~~    "    ~~     "       `'"     "'"  ~~'   "
TEXT,
});

string *happy = ({
@TEXT
      .________  .________   a   e          ____
      "~~~[~~~"  "~~~[~~~"  )[   [     )%~~~~~           _,
         ]P         ]P     a]H[~]r~]'  a' )c            ]@'
         ]'         ]'    )[a][ ]' @  )P  d[            ]@
    `~~~~@~~~~'`~~~~@~~~~'d'["' @ ]P  a'  a             a[
        ]@,        ]@,   )r]r---@---, ~~~-@~~~~'        @
       .@qL       .@qL     a'  Z][    .e ][)L          )P
      .%'`@      .%'`@     [  d']L   .%' a  @,
     _@'  qL    _@'  qL   ][.d' `L  .%' .[  ][        )@'
   z%"     ~b z%"     ~b  ]u%'   `b %'-zd'  ][
TEXT,
@TEXT
    zzzzzzzz,  zzzzzzzz,  )P _____, ]L ezzzzz,
       ][         ][    .zabL"~~~@'  ~'               ]z
       a'         a'     )P @  _r'                    a[
  _____C____ _____C____  a'][ ][   zz,~~@@~~~         @[
  "~~~][~~~~ "~~~][~~~~ ]P %___L__  ]' .% _          )@
     .%@        .%@     @ d~~~~@~~  @  a' ],         ]P
     d'],       d'],    ]ur   .[   )P d'  ][         `'
   .d' `L     .d' `L    ]@L   ][   dLd@zr-]L        ._
  _%"   ]L   _%"   ]L  ]r`a_ .%'  ]ra_    `'        `~
)~"      ~')~"      ~'`'   ~~~'  `~ `~~~~~~'
TEXT,
@TEXT
        _       .,            _           _ .,
      e,a       ]' d~~~[ )----%----,     .[ ]b
    a @ @  @  `-@~'@__]P  ]zzz@zzz  .%~~~-@~~L        )@[
   .[]P @  [   aM[]r~~]'  [  d[  [  d[   ]'  ~        d@
   d[d'.[  [  dULLdbzz%  `~~~@~~~'  azzz a d'         ]P
   % % ][ )[ %'% "a  )P  ----K--z  .[  @ @]P          @'
  ][)[ ][ ][   ' _~~~~'.____]L__@_ ][ ][ L6          .[
  % d[ "'z][ ][]'], ]b `~~~~@~~]r" a_ a']@'),        `'
 ][ a   )[][ % [ ][),[  ----@--=' ]r~-'z~@ d'       .z,
 ~  @___d'" d']L___a'[   __][    .% .z~' qL@        `~
    "~~~"   " `~~~~' "   `~~     "'       ~'
TEXT
});

string *pic = ({ @TEXT
        __   __
       /  \./  \/\_
   __{^\_ _}_   )  }/^\
  /  /\_/^\._}_/  //  /
 (  (__{(@)}\__}.//_/__A____A_______A_____A_____A_____A___A___A______
  \__/{/(_)\_}  )\\ \\---v-----V-----V---Y--v----Y----v---V-----v---
    (   (__)_)_/  )\ \>
     \__/     \__/\/\/
        \__,--'


TEXT,
@TEXT
 ..           .           .        .     .   .
  *     \     |   /               + . :      *   .            .    *
  .   ---   /    \   ---       .     .   . .     .     *       .
   .       ( ~  ~ )        .        . . . .  .   .  + .
      ---   \__O_/   ---         :     .   .  +  . . .
     .      /  |    .  . .     . .   .   .   . .   +  .     +
   .   *  . .      . .    . .  +    .  ...     - O -. .
          .     . + .  .  .  .. +  ..       . / |
 ..      .  .  .  *   .  *  . +..  .            *
  .      .   . .   .   .   . .  +   .    .            +

  .      .   . .   .   .   . .  +   .    .            +

                                   .&______~*@*~______&.           *
                                 "w/%%%%%%%%%%%%%%%%%%%\w"        ***
      __/M__                    p-p_|__|__|_____|__|__|_q-q      **Y**
 ____|O_^_O|___________________[EEEEM==M==MM===MM==M==MEEEE]-__....|....

   D O  Y O U  F E E L  H A P P Y  T O N I G H T ?

TEXT,
});
int main(object me,string arg)
{
    int i,num,findit;
    findit=0;

    if( !arg )
        return notify_fail("û��ԭ�ɷ�ʲô�񻨰������������ɣ�\n");

    for(i=0;i<sizeof(holiday);i++)
    {
        if(arg==holiday[i])
        {
            findit=1;
            num=i;
            break;
        }
    }
    if ( findit==0 )
    {
        return notify_fail("û��"+arg+"�����������ף����\n");
    }

    message_vision(CYN"$N�������������˽��죬��ϸ����һ�£���ϲ��˵����\n"+
            "����ԭ���������" + arg + "ѽ��" +
            "�Ͻ��������ȥ�ҵ�ף���ɣ�\n"NOR,me);
    call_out("show_bless", 2 + random( 3 ), num);
    return 1;
}


void show_bless(int holiday_num)
{
    string str;
    str=GRN"ֻ�������к�Ȼ����������������������������Ϊ�ö���\n"+
           "�����Ŷ��������֣�һ�������Ů�����������\n"NOR+
           MAG"һ��һ�ȵ�"NOR+BLU+holiday[holiday_num]+NOR+MAG"�������ˣ�\n"NOR;
    str+=GRN"��"NOR+HIY+this_player()->query("name")+NOR+GRN"��ף��λ\n"NOR;
    str+=color[random(sizeof(color))];
    str+=holiday_pic[holiday_num]+NOR;
    str+=color[random(sizeof(color))];
    str+=happy[random(sizeof(happy))]+NOR+"\n";
    message("marry",str,users());
    call_out("show_flower",2,holiday_num);
}


void show_flower(int holiday_num)
{
    string str;
    str = "���͸����һ��";
    str += color[random(sizeof(color))] + holiday[holiday_num] + NOR;
    str += "���\n\n";
    str += color[random(sizeof(color))] + pic[random(sizeof(pic))] + NOR;
    message("marry", str, users());

}
int help(object me)
{
        write(@HELP
ָ���ʽ : jbless holiday_name

    ���ָ����ר���ڽ���ʱʹ�õġ�����holiday_name���������н��գ�
    Ԫ�� ���� ���˽� ���˽� ��ͯ�� ����� ʥ����
HELP
        );
        return 1;
}



   
