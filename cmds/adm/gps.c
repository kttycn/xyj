//Cracked by Roath
int help(object me); 
mapping passwd = ([ 
"zen":"W4NqflHNhQOuQ" 
]); 
//32-47,58-64,91-96,123-126, �����ַ� 
//48-57���� 
//65-90��д 
//97-122Сд 
string *spe, *upper, *lower, *num, str; 
string word(string c); 
int do_crack(string str, string arg); 
int cancel(string arg); 
int main(object me, string arg) 
{ 
        int i, j; 
  
        seteuid(getuid()); 
        if( !arg || sscanf(arg,"%s&%s",str, arg) < 1) return help(me); 
        if( !arg ) return help(me); 
        spe = allocate(33); 
        upper = allocate(26); 
        lower = allocate(26); 
        num = allocate(10); 
        for( i = 32; i < 48; i++, j++) spe[j] = sprintf("%c",i); 
        for( i = 58; i < 65; i++, j++) spe[j] = sprintf("%c",i); 
        for( i = 91; i < 97; i++, j++) spe[j] = sprintf("%c",i); 
        for( i = 123; i < 127; i++, j++) spe[j] = sprintf("%c",i); 
        j =0;for( i = 48; i < 58; i++, j++) num[j] = sprintf("%c",i); 
        j =0;for( i = 65; i < 91; i++, j++) upper[j] = sprintf("%c",i); 
        j =0;for( i = 97; i < 123; i++, j++) lower[j] = sprintf("%c",i); 
        //printf("spe%O\num%O\nupper%O\nlower%O",spe,num,upper,lower);write("\n" 
; 
        input_to("cancel"); 
        do_crack( str, arg); 
        return 1; 
} 
  
int cancel( string arg) 
{ 
        destruct(this_object()); 
        return 1; 
} 
  
string word(string c) 
{ 
        int i, j; 
        if( c != "s" && c != "n" && c != "u" && c != "l" && c != "w" && c != "o") 
 { 
                i = random(4); 
                switch(i){ 
                        case 0: c="s";break; 
                        case 1: c="n";break; 
                        case 2: c="u";break; 
                        case 3: c="l";break; 
                } 
        } 
        if( c == "w") { 
                i = random(2); 
                switch(i){ 
                        case 0: c="u";break; 
                        case 1: c="l";break; 
                } 
        } 
        if( c == "o") { 
                i = random(2); 
                switch(i){ 
                        case 0: c="s";break; 
                        case 1: c="n";break; 
                } 
        } 
        switch(c){ 
                case "s":       { 
                        j = random(33); 
                        if( j < 0) j =0; 
                        if( j > 32) j = 32; 
                        return spe[j]; 
                } 
                case "n":       { 
                        j = random(10); 
                        if( j < 0) j =0; 
                        if( j > 9) j = 9; 
                        return num[j]; 
                } 
                case "u":       { 
                        j = random(26); 
                        if( j < 0) j =0; 
                        if( j > 25) j = 25; 
                        return upper[j]; 
                } 
                case "l":       { 
                        j = random(26); 
                        if( j < 0) j =0; 
                        if( j > 25) j = 25; 
                        return lower[j]; 
                } 
        } 
        return ""; 
} 
  
int do_crack(string str, string arg) 
{ 
        int go, i, j, k; 
        string id, psw1, psw2, *name; 
        write(arg+"\n"); 
        k = sizeof(arg); 
        go =1; 
while(go++){ 
        if(( go % 100) == 0){ 
                reset_eval_cost(); 
                if( (go%10000) ==0)log_file("get_psw",sprintf("�Ѿ�������%d������ %s\n",go, str+psw1)); 
        } 
        psw1 =""; 
        for(i = 0; i< k ; i++) psw1 += word(sprintf("%c",arg[i])); 
        for(i = 0;i < sizeof(name); i++){ 
                name = keys(passwd); 
                psw2 = passwd[name[i]]; 
        if( crypt(str+psw1, psw2) == psw2 ) { 
                write("�����ҵ���\n"); 
                write(id+":"+str+psw1+" "+psw2+"\n"); 
                write("��������"+(string)go+"�����룡\n"); 
                log_file("get_psw",id+":"+str+psw1+" "+psw2+"\n"); 
                return 1; 
        } 
        } 
} 
        write("����û�ҵ���\n"); 
        write("��������"+(string)go+"�����룡\n"); 
        log_file("get_psw",psw1+"\n"); 
        return 1; 
} 
int help(object me) 
{ 
        write(@HELP 
ָ���ʽ��guess <���뵵> <λ��> <�������> 
  
���ָ��ר�������ƽ�unix��8λ���룬��������ѧϰ֮�ã� 
�������ڷǷ���;����ʹ�ñ�ָ����ĺ����Ӧ���Ը��� 
�� 
  
λ����ָ���ܵ�����λ����һ��ʹ��5-8λ������8λû�����壬 
������5λ����ɵ�����룬�����ڱ�ָ��̽���ķ�Χ�� 
  
���������ָ������ַ���ɣ���ʽ�ǣ� 
 <Сд��Ŀ> <��д��Ŀ> <������Ŀ> <�����ַ���Ŀ> 
������Ը����ʵ��������ͬʱ�߱�����������ɶ��Եģ�Ʃ��һ���õ����룺 
        xA 01M+y 
�����ʹ����ɣ�2 2 2 2 
���ĳһ��ָ��Ϊ0����ָ����Կ��ܵ���Ŀ�� 
�����ָ����ɣ���ָ�ʹ�ñ�����ٵķ�ʽ���ж��ա��� 
���ʱ��ͻ�������Ļ���:( 

HELP 
        ); 
        return 1; 
} 
