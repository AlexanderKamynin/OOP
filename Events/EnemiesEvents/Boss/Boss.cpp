#include "Boss.h"

void Boss::React()
{
	std::cout << "����� ���� ������� ��������, ������ ��� ����..." << '\n';
	preview_battle();
	if (is_dead()) {
		std::cout << "������� �������������� ������..." << '\n';
	}
}

bool Boss::is_one_time()
{
	return this->is_dead();
}