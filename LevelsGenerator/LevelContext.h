#pragma once
#include "../Background/Field.h"
#include "../Player/Player.h"
#include "Levels/ILevel.h"
#include "Levels/FirstLevel.h"
#include "Levels/SecondLevel.h"


class LevelContext
{
public:
	LevelContext(int level);

	Field* get_field();
private:
	Field* field;
	ILevel* level;
};

