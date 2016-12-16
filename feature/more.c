//more.c

#include <ansi.h>

void more(string cmd, string *text, int line)
{
	int i, t_size;
	switch(cmd)
	{
		case "b":
			line = line - 46;
			if(line<-22) line=-23;
			for(i=line + 23; line < i;line++)
				write(text[line]+"\n");
			break;
		case "q":
			return;
		default:
			t_size = sizeof(text);
			for(i=line + 23; line<t_size && line<i; line++)
				write(text[line] + "\n");
			if(line >= t_size) return;
			break;
	}
	printf(BRED HIG"== 未完继续 " HIY "%d%%" NOR
		BRED HIG" == (ENTER 继续下一页，q 离开，b 前一页"NOR")"NOR,
		(line*100/sizeof(text)) );
	input_to("more", text, line);
}

void start_more(string msg)
{
	if(!msg || strlen(msg)<1)
		return;
	more("", explode(msg, "\n"), 0);
}
