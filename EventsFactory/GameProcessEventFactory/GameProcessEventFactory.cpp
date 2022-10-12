#include "GameProcessEventFactory.h"


IEvent* GameProcessEventFactory::createExitEvent() {
	return new ExitEvent();
}

IEvent* GameProcessEventFactory::createDefeatEvent() {
	return new DefeatEvent(this->player);
}