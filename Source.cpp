/*
  _____                        ____               
 |  ___| __ ___ _______ _ __  / ___|___  _ __ ___ 
 | |_ | '__/ _ \_  / _ \ '_ \| |   / _ \| '__/ _ \
 |  _|| | | (_) / /  __/ | | | |__| (_) | | |  __/
 |_|  |_|  \___/___\___|_| |_|\____\___/|_|  \___|
	 Lightning speed and strength
		 conjured directly from the depths of logic!   
			Infusion-WoW 2011 - 2013 (C)
<--------------------------------------------------------------------------->
 - Developer(s): Cyphric, (Styler)
 - Complete: 100%
 - ScriptName: 'Vendor'
 - Comment: N/A
<--------------------------------------------------------------------------->
*/

#include "ScriptPCH.h"

class vendor : public CreatureScript
{
	public:
vendor() : CreatureScript("vendor") { }


	bool OnGossipHello(Player * player, Creature * creature)
	{
		if(player->isInCombat)
			return false;

		if(player->GetSession()->GetSecurity() >= 0)
		{
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Buy something", GOSSIP_SENDER_MAIN, 0);
		} 
		else
		{
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "No Access!", GOSSIP_SENDER_MAIN, 1);
		}
		player->PlayerTalkClass->SendGossipMenu(9000, creature->GetGUID());
	}
	
	bool OnGossipSelect(Player * player, Creature * creature, uint32 sender, uint32 action, ChatHandler *handler)
	{
		Player* me = handler->GetSession()->GetPlayer();
		switch(action)
		{
		case 0:
			{
			player->GetSession()->SendListInventory(creature->GetGUID());
			}break;

		case 1:
			{
				handler->PSendSysMessage(" %s you son of a bitch, you're a %s"), player->GetName, player->getGender();
				player->GetSession()->KickPlayer();
				player->CLOSE_GOSSIP_MENU();
			}break;
		}
	}


};

void AddSC_vendor()
{
	new vendor();
}