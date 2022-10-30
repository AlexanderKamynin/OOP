#include "CeilingCollapse.h"


void CeilingCollapse::React()
{
	Message msg(EnumClass::LOG_GAME, "CeilingCollapse::React()");
	this->notify(msg);
	std::cout << "Вы наступили на нажимную плиту. Потолок обваливается..." << '\n';
	for (int i = 0; i < this->cells_to_change.size(); i++) {
		if (cells_to_change[i]->get_event() == nullptr) {
			cells_to_change[i]->set_passability(false);
		}
	}
}

bool CeilingCollapse::is_one_time()
{
	return true;
}
