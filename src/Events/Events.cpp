#include "Events.h"

#include "Loot.h"

namespace Events
{
	void CrosshairRefManager::Evaluate(RE::TESObjectREFRPtr a_ref)
	{
		auto& loot = Loot::GetSingleton();
		if (CanOpen(std::move(a_ref))) {
			loot.SetContainer(_cachedAshPile ? _cachedAshPile : _cachedRef);
		} else {
			loot.Close();
		}
	}

	void CombatManager::Close()
	{
		auto& loot = Loot::GetSingleton();
		loot.Close();
	}
}
