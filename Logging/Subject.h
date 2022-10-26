#pragma once
#include "ISubject.h"
#include "Message.h"
#include <vector>


class Subject : public ISubject
{
public:
	void attach(IObserver* observer) override;
	void detach(IObserver* observer) override;
	void notify(Message &msg) override;
	~Subject() = default;
private:
	std::vector<IObserver*> observers;
};

