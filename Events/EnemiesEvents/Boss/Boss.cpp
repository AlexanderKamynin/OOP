#include "Boss.h"

void Boss::React()
{
	this->notify(Message("log_game", "react from boss\n"));
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