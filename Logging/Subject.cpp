#include "Subject.h"

void Subject::attach(IObserver* observer)
{
	this->observers.push_back(observer);
}

void Subject::detach(IObserver* observer)
{
	std::remove(observers.begin(), observers.end(), observer);
}

void Subject::notify(const Message &msg)
{
	for (auto elem : this->observers) {
		elem->update(msg);
	}
}
