#pragma once
#include "ILevel.h"


class SecondLevel : public ILevel
{
public:
	Field* generate_level() override;
};