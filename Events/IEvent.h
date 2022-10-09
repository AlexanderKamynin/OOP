#pragma once


class IEvent { //интерфейс событий
public:
    virtual void React() = 0;

    virtual ~IEvent() = 0;
};

