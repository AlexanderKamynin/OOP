#include "CeilingCollapse.h"


void CeilingCollapse::React()
{
	std::cout << "�� ��������� �� �������� �����. ������� ������������..." << '\n';
	for (int i = 0; i < this->cells_to_change.size(); i++) {
		if (cells_to_change[i]->get_event() == nullptr) {
			cells_to_change[i]->set_passability(false);
		}
	}
}
