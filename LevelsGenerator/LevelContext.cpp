#include "LevelContext.h"


LevelContext::LevelContext(int level)
{
	switch (level)
	{
	case 1:
		this->level = new FirstLevel();
		break;
	case 2:
		this->level = new SecondLevel();
		break;
	default:
		break;
	}
    this->field = this->level->generate_level();
}

Field* LevelContext::get_field()
{
    return this->field;
}
