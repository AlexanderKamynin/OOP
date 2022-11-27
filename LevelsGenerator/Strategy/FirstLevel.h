#pragma once
#include "ILevelStrategy.h"


class FirstLevel : public ILevelStrategy
{
public:
	Field* generate_level() override;
};

