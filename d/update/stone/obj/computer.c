inherit ITEM;

void init();

void init()
{
	if (!wizardp(this_player())) {
                set("no_get","就你的体格想拿"+this_object()->query("name")+"，这可是全内置的配置，重得很。\n");
		set("no_give","这可是顶级的电脑笔记本，哪能随便送人呀？值好几万呢\n");
		set("no_drop","你是大款吗？顶级的电脑笔记本说扔就扔了？浪费啊！\n");
		set("no_sell","古人哪里知道"+this_object()->query("name")+"的价值？也用不来啊，还是自己留着吧。\n");
	}                                 
}

void create()
{
 set_name("[1;35m【IBM原装电脑笔记本】[2;37;0m", ({ "computer","pc"}));
        set("long",
"\n[1;40mP4的顶级配置，装有所有最新的软硬件，[2;37;0m\n"
"\n[1;40m专门为玩泥巴和写泥巴用的！可惜的少了一根网线！[2;37;0m\n"
"\n[1;40m我FAINT!![2;37;0m\n");
//"\n[1;40m底上有一个标签:巫师专用！[2;37;0m\n"
set_weight(100);
set("value", 200000);
setup();
}
