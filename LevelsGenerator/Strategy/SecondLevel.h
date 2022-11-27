#pragma once
#include "ILevelStrategy.h"


class SecondLevel : public ILevelStrategy
{
public:
	Field* generate_level() override;
};