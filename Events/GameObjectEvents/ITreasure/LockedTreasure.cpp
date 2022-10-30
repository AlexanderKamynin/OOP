#include "LockedTreasure.h"

void LockedTreasure::set_gold_in_treasure(int gold)
{
	this->gold = gold;
}

void LockedTreasure::React()
{
    Message msg(EnumClass::LOG_GAME, "LockedTreasure::React()");
    this->notify(msg);
	std::cout << "������ ������� ������? [yes/no]" << '\n';
    std::string agree = "";
    while (agree != "yes" and agree != "no") {
        std::cin >> agree;
        if (agree == "yes") {
            if (this->check_passkey()) {
                player->take_passkey();
                std::cout << "�� ������� ������ � " << gold << " ������!" << '\n';
                player->add_gold(gold);
                this->unlock = true;
            }
            else {
                std::cout << "� ��� ��� ������ �������" << '\n';
            }
        }
        else if (agree == "no") {
            std::cout << "�� ������ �� ��������� ������" << '\n';
        }
        else {
            std::cout << "������� yes ��� no..." << '\n';
        }
    }

}

bool LockedTreasure::is_one_time()
{
    if (this->is_unlock()) {
        return true;
    }
    return false;
}

bool LockedTreasure::is_unlock()
{
    return this->unlock;
}

bool LockedTreasure::check_passkey()
{
    if (player->get_passkey() >= 1) {
        return true;
    }
    return false;
}
