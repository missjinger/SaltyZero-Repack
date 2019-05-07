// authorized by saltyzero@foxmail.com

#include "world_chat.h" 

class world_chat : public PlayerScript
{
public:
	world_chat() : PlayerScript("world_chat") {}

	void OnChat(Player* player, uint32 type, uint32 lang, std::string& msg, Guild* guild)
	{
		// if (guild == NULL) return;

		const char * clsclr[11] =
		{
			"|cffC79C6E[", //WARRIOR
			"|cffF58CBA[", //PLADIN
			"|cffABD473[", //HUNTER
			"|cffFFF569[", //ROGUE
			"|cffFFFFFB[", //PRIEST
			"|cffC41F3B[", //DEADKNINGHT
			"|cff0070DE[", //SHAMAN
			"|cff69CCF0[", //MAGE
			"|cff9482C9[", //WARLOCK
			"|cffFFFFFF[",
			"|cffFF7D0A["  //DRUID
		};

		const char * race[11] =
		{
			"Human",
			"Orc",
			"Dwarf",
			"Nightelf",
			"Undead",
			"Tauren",
			"Gnome",
			"Troll",
			"Goblin",
			"Bloodelf",
			"Draenei"
		};

		const char * gender[2] = { "Male", "Female" };

		//std::string _faction = ((sFactionTemplateStore.LookupEntry(player->getFaction()))->ourMask == 3) ? "|cff0000FF[联盟]|r" : "|cffFF0000[部落]|r";
		std::string _faction = (player->GetTeamId() == TEAM_ALLIANCE) ? "|cff3399FF[|TInterface/pvpframe/pvp-currency-alliance:15|t联盟]|r" : "|cffFF0000[|TInterface/pvpframe/pvp-currency-horde:15|t部落]|r";
		std::string _icon = std::string("") + "|TInterface/ICONS/Achievement_Character_" + race[player->getRace() - 1] + "_" + gender[player->getGender()] + ":14|t";
		std::string _class = clsclr[player->getClass() - 1];

		//|Hplayer:%s|h%s|h
		std::string message = _faction + _class + _icon + "|Hplayer:" + player->GetName() + "|h" + player->GetName() + "]|h|r: |cffADD8E6" + msg + "|r";
		sWorld->SendGlobalText((message).c_str(), NULL);
	}
};

_module void AddSC_world_chat()
{
	new world_chat();
}