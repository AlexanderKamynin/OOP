#include "Subject.h"

void Subject::attach(IObserver* observer)
{
	this->observers.push_back(observer);
}

void Subject::detach(IObserver* observer)
{
	observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify(Message &msg)
{
	for (auto elem : this->observers) {
		elem->update(msg);
	}
}
