
mapping* quests=({    
	(["quest_type" : "sweep", "location" : "СԺ",]),
	(["quest_type" : "sweep", "location" : "��Ժ",]),
	(["quest_type" : "sweep", "location" : "��Ժ",]),
	(["quest_type" : "sweep", "location" : "�᷿",]),
	(["quest_type" : "sweep", "location" : "������",]),
	(["quest_type" : "sweep", "location" : "����",]),
	(["quest_type" : "sweep", "location" : "������",]),
	(["quest_type" : "sweep", "location" : "����",]),
	(["quest_type" : "sweep", "location" : "����",]),
	(["quest_type" : "sweep", "location" : "С��",]),
	(["quest_type" : "write",]),
	(["quest_type" : "carry",]),
	(["quest_type" : "dig",]),
});
  
void create()
{
	seteuid(getuid());
}

mapping query_quest()
{
	return quests[random(sizeof(quests))];
}
