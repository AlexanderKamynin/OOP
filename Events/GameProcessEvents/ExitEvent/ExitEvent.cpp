#include "ExitEvent.h"

void ExitEvent::React()
{
	Message msg(EnumClass::LOG_GAME, "ExitEvent::React()");
	this->notify(msg);
	if (show_exit == false) {
		this->show_exit = true;
		if (boss_defeat) {
			this->activate = true;
			std::cout << "�� ����� �����..." << '\n';
			std::cout << "�����������! �� �������� :)" << '\n';
		}
		else {
			std::cout << "�� ������� �������������� ������. �������� �����, ����� ������� �����..." << '\n';
		}
	}
	else if (boss_defeat) {
		this->activate = true;
		std::cout << "�����������! �� �������� :)" << '\n';
	}
	else {
		std::cout << "���� ��� �� ��������..." << '\n';
	}
}

bool ExitEvent::is_one_time()
{
	return false;
}

bool ExitEvent::is_activate()
{
	return this->activate;
}

bool ExitEvent::is_show()
{
	return this->show_exit;
}

void ExitEvent::boss_is_defeat()
{
	boss_defeat = true;
}
