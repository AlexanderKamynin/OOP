#pragma once
#include "../../Background/Field.h"
#include "../../Player/Player.h"
#include "ILevelStrategy.h"
#include "FirstLevel.h"
#include "SecondLevel.h"


class LevelContext
{
public:
	LevelContext(int level);

	Field* get_field();
private:
	Field* field;
	ILevelStrategy* level;
};

