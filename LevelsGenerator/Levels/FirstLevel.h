#pragma once
#include "ILevel.h"


class FirstLevel : public ILevel
{
public:
	Field* generate_level() override;
};

