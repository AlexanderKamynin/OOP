#include "Boss.h"

void Boss::React()
{
	Message msg(EnumClass::LOG_GAME, "Boss::React()");
	this->notify(msg);
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