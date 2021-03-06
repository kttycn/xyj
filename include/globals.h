//
// file: globals.h
//
// This file is #included in all objects automatically by the driver.
// (See config file of driver)

//#pragma save_binary

//#define private protected 

#define JOB_OB(x)		("/d/job/"+x+"/job")
#define CITY_OB(city,room)   ("/d/"+city+"/"+room)
// Directories

#define COMMAND_DIR		"/cmds/"
#define CONFIG_DIR		"/adm/etc/"
#define DATA_DIR		"/data/"
#define HELP_DIR		"/doc/"
#define LOG_DIR			"/log/"

// Daemons

#define BR_D			"/adm/daemons/brd"
#define ALIAS_D			"/adm/daemons/aliasd"
#define BAN_D     	        "/adm/daemons/band.c"
#define CHANNEL_D		"/adm/daemons/channeld"
#define CHAR_D			"/adm/daemons/chard"
#define CHINESE_D		"/adm/daemons/chinesed"
#define COMBAT_D		"/adm/daemons/combatd"
#define COMMAND_D		"/adm/daemons/cmd_d"
#define CONVERT_D		"/adm/daemons/convertd"
#define CRON_D          "/adm/daemons/cron"
#define D_D					"/adm/daemons/dd"
#define EMOTE_D			"/adm/daemons/emoted"
#define FINGER_D		"/adm/daemons/fingerd"
#define INQUIRY_D		"/adm/daemons/inquiryd"
#define LOGIN_D			"/adm/daemons/logind"
#define EVENT_D	        "/adm/daemons/eventd"
#define CLUB_D			"/adm/daemons/clubd"
#define LANGUAGE_D      "/adm/daemons/languaged.c"
#define MISC_D		    "/adm/daemons/miscd"
#define MONITOR_D		"/adm/daemons/monitord"
#define MONEY_D	        "/adm/daemons/moneyd"
#define NATURE_D		"/adm/daemons/natured"
#define OBSTACLE_D      "/adm/daemons/obstacled"
#define PROFILE_D		"/adm/daemons/profiled"
#define RANK_D			"/adm/daemons/rankd"
#define SECURITY_D		"/adm/daemons/securityd"
#define SPELL_D		    "/adm/daemons/spelld"
#define STORY_D	        "/adm/daemons/storyd.c"
#define TASK_D          "/adm/daemons/questd"
#define TOPTEN_D	    "/adm/daemons/toptend"
#define UPDATE_D		"/adm/daemons/updated"
#define VIRTUAL_D		"/adm/daemons/virtuald"
#define WEAPON_D		"/adm/daemons/weapond"
// added by stone 20020607
#define LOCATION_D      "/adm/daemons/locationd"

#define MASTER_OB		"/adm/obj/master"
#define SIMUL_EFUN_OB	"/adm/obj/simul_efun"

#define CLASS_D(x)		("/daemon/class/" + x)
#define SKILL_D(x)		("/daemon/skill/" + x)
#define CONDITION_D(x)	("/daemon/condition/" + x)

// Clonable/Non-inheritable Standard Objects

#define CORPSE_OB		"/obj/corpse"
#define LOGIN_OB		"/obj/login"
#define MAILBOX_OB		"/obj/mailbox"
#define JINBI_OB		"/obj/money/gold-coin"
#define RMB_OB			"/obj/money/rmb"
#define GOLD_OB			"/obj/money/gold"
#define SILVER_OB		"/obj/money/silver"
#define COIN_OB			"/obj/money/coin"
#define USER_OB			"/obj/user"
#define VOID_OB			"/obj/void"
#define STORY_DIR       "/obj/story/"

// Inheritable Standard Objects

#define BANK			"/std/room/bank"
#define BULLETIN_BOARD	"/std/bboard"
#define BBS_BOARD		"/std/bbsboard"
#define BULLE_BOARD     "/std/bbsboard_b"
#define CHARACTER		"/std/char"
#define CLASS_GUILD		"/std/room/class_guild"
#define COMBINED_ITEM	"/std/item/combined"
#define EQUIP			"/std/equip"
#define FORCE			"/std/force"
#define CITY			"/std/city"
#define HOCKSHOP		"/std/room/hockshop"
#define ITEM			"/std/item"
#define LIQUID			"/std/liquid"
#define MONEY			"/std/money"
#define NPC			    "/std/char/npc"
#define NPC_SAVE		"/std/char/npcsave"
#define POWDER			"/std/medicine/powder"
#define QUEST			"/std/quest"
#define ROOM			"/std/room"
#define SKILL			"/std/skill"
#define SSERVER			"/std/sserver"
#define SKILL_MODEL_UNARMED    "/std/skill_model_unarmed.c"
#define SKILL_MODEL_WEAPON     "/std/skill_model_weapon.c"
#define SKILL_MODEL_DEFAULT    "/std/skill_model_default.c"

// User IDs

#define ROOT_UID		"Root"
#define BACKBONE_UID	"Backbone"

// Features

#define F_ACTION		"/feature/action.c"
#define F_ALIAS			"/feature/alias.c"
#define F_APPRENTICE	"/feature/apprentice.c"
#define F_ATTACK		"/feature/attack.c"
#define F_ATTRIBUTE		"/feature/attribute.c"
#define F_AUTOLOAD		"/feature/autoload.c"
#define F_BANKER		"/feature/banker.c"
#define F_CLEAN_UP		"/feature/clean_up.c"
#define F_COMMAND		"/feature/command.c"
#define F_CONDITION		"/feature/condition.c"
#define F_DAMAGE		"/feature/damage.c"
#define F_DBASE			"/feature/dbase.c"
#define F_EDIT			"/feature/edit.c"
#define F_ENCODING		"/feature/encoding.c"
#define F_EQUIP			"/feature/equip.c"
#define F_FINANCE		"/feature/finance.c"
#define F_FOOD			"/feature/food.c"
#define F_LIQUID		"/feature/liquid.c"
#define F_MASTER		"/std/char/master.c"
#define F_MESSAGE		"/feature/message.c"
#define F_MORE			"/feature/more.c"
#define F_MOVE			"/feature/move.c"
#define F_NAME			"/feature/name.c"
#define F_ONEOWNER		"/feature/oneowner.c"
#define F_SAVE			"/feature/save.c"
#define F_BACKUP		"/feature/backup.c"
#define F_SKILL			"/feature/skill.c"
#define F_TEAM			"/feature/team.c"
#define F_TREEMAP		"/feature/treemap.c"
#define F_UNIQUE		"/feature/unique.c"
#define F_VENDOR		"/feature/vendor.c"
#define F_VENDOR_SALE   "/feature/vendor_sale.c"
#define F_FROZEN        "/feature/frozen.c"
// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

//topten
#define TOPTEN_RICH 	"/data/topten/rich.o"
#define TOPTEN_PKER 	"/data/topten/pker.o"
#define TOPTEN_EXP  	"/data/topten/exp.o"
#define TOPTEN_DX   	"/data/topten/dx.o"
#define TOPTEN_KILL		"/data/topten/killer.o"
#define TOPTEN_QUESTS	"/data/topten/quests.o"
#define TOPTEN_SPELLS	"/data/topten/spells.o"
#define TOPTEN_TASK		"/data/topten/task.o"
#define TOPTEN_FORCE	"/data/topten/force.o"
#define TOPTEN_PER1 	"/data/topten/per1.o"
#define TOPTEN_PER2 	"/data/topten/per2.o"
#define TOPTEN_AGE  	"/data/topten/age.o"
#define TOPTEN_MASTER  	"/data/topten/master.o"

#define RICH_B 		"TOP TEN 【 月影奇缘十大富豪　　 】排行榜"
#define PKER_B 		"TOP TEN 【 月影奇缘十大狂魔　　 】排行榜"
#define EXP_B  		"TOP TEN 【 月影奇缘十大武学高手 】排行榜"
#define DX_B  		"TOP TEN 【 月影奇缘十大道行高手 】排行榜"
#define KILL_B 		"TOP TEN 【 月影奇缘十大魔头　　 】排行榜"
#define QUESTS_B    "TOP TEN 【 月影奇缘十大解迷高手 】排行榜"
#define TASK_B      "TOP TEN 【 月影奇缘十大TASK高手 】排行榜"
#define SPELLS_B 	"TOP TEN 【 月影奇缘十大魔法高手 】排行榜"
#define FORCE_B		"TOP TEN 【 月影奇缘十大内力高手 】排行榜"
#define PER1_B		"TOP TEN 【 月影奇缘十大白马王子 】排行榜"
#define PER2_B		"TOP TEN 【 月影奇缘十大梦中情人 】排行榜"
#define AGE_B		"TOP TEN 【 月影奇缘十大老不死　 】排行榜"
#define MASTER_B	"TOP TEN 【 月影奇缘十大高手　　 】排行榜"

#define PROFILE_COMMANDS
#undef PROFILE_COMMANDS
