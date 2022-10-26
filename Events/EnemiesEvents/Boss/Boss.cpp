#include "Boss.h"

void Boss::React()
{
	Message msg("log_game", "react from boss\n");
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