string* guainame=({
	"Ò°Ã¨¹Ö","yemao guai",
	"Ò°¼¦¹Ö","yeji guai",
	"Ò°¹·¹Ö","yegou guai",
	"Ò°ÍÃ¹Ö","yetu guai",
	"Ò°Ïó¹Ö","yexiang guai",
	"Ò°ĞÜ¹Ö","yexiong guai",
	"Ò°Öí¹Ö","yezhu guai",
	"Ğ«×Ó¹Ö","xiezi guai",
	"Ò°ºï¹Ö","yehou guai",
	"ÒÎÑı","yizi yao",
	"¹íÆÅ","gui po",
	"·çÑı","feng yao",
	"Ñ©¾«","xue jing",
	"¸òó¡¹Ö","hama guai",
	"±Ú»¢¹Ö","bihu guai",
	"Ë®Éß¾«","shuishe jing",
	"½©Ê¬","jiang shi",
	"Ê÷Ñı","shu yao",
	"ºüÀê¾«","huli jing",
	"»±Ê÷¾«","huaishu jing",
	"ÎüÑª¹í","xixie gui",
	"ÑîÊ÷¾«","yangshu jing",
	"µõËÀ¹í","diaosi gui",
	"ºÚÎŞ³£","heiwu chang",
	"°×ÎŞ³£","baiwu chang",
	"ºûµû¾«","hudie jing",
	"ĞÌÌì","xing tian",
	"Ùç","kui",
	"ò¿ÓÈ","chi you",
	"Ë®Ä§ÊŞ","shui moshou",
	"ÍÁÄ§ÊŞ","tu moshou",
	"»ğÄ§ÊŞ","huo moshou",
	"òÔ¹Ö","jiao guai",
	"ÉßÑı","she yao",
	"Ê¯í¶ÄïÄï","shiji niangniang",
	"ºÚÉ½ÀÏÑı","heishan laoyao",
	"òÚò¼¾«","wugong jing",
	"°×¹Ç¾«","baigu jing",
	"Ö©Öë¾«","zhizhu jing",
	"·äÑı","feng yao",
	"µÆÁı¹Ö","denglong guai",
	"Ì³×Ó¾«","tanzi guai",
	"É¨°Ñ¾«","saoba jing",
});
        
void create()
{
	int i;

	set_name(guainame[i=random(sizeof(guainame)/2)*2],({guainame[i+1]}));
	set("age",20+random(80));
	set("attitude","heroism");
	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :)
	}) );

	setup();
}
