#include "FirstLevel.h"

Field* FirstLevel::generate_level()
{
	FieldGenerator<
		RuleFieldSize<10, 10>,
		RulePlayerSpawn<3, 6>,
		RuleExitSpawn<7, 8>,
		RuleMapEventSpawn<MapEventFactory::MapEventToCreate::TrapEvent, 4>,
		RuleMapEventSpawn<MapEventFactory::MapEventToCreate::CeilingCollapseEvent, 2>,
		RuleEnemiesSpawn<EnemiesEventFactory::EnemyToCreate::RatEnemy,
			std::make_pair(10,20), std::make_pair(1,3), std::make_pair(5,50), 5>,
		RuleEnemiesSpawn<EnemiesEventFactory::EnemyToCreate::WarrionEnemy,
			std::make_pair(30, 40), std::make_pair(5, 7), std::make_pair(51, 100), 3>,
		RuleEnemiesSpawn<EnemiesEventFactory::EnemyToCreate::BossEnemy,
			std::make_pair(30, 50), std::make_pair(7, 10), std::make_pair(5, 500), 1>,
		RuleObjectSpawn<GameObjectEventFactory::GameObjectToCreate::AltarObject, 1>,
		RuleObjectSpawn<GameObjectEventFactory::GameObjectToCreate::LockedTreasureObject, 3>,
		RuleObjectSpawn<GameObjectEventFactory::GameObjectToCreate::UnlockedTreasureObject, 3>
	> generator;
	return generator.generate();
}
