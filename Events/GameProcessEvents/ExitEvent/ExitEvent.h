#pragma once
#include "../GameProcessEvents.h"
#include <iostream>


class ExitEvent : public GameProcessEvents
{
public:
	ExitEvent() : GameProcessEvents(nullptr) {};

	void React() override;

	bool is_activate() override;

	bool is_show();

	void boss_is_defeat();

private:
	bool boss_defeat = false;
	bool show_exit = false;
};

