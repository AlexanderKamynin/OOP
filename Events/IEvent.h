﻿#pragma once
#include "../Logging/Subject.h"


class IEvent : public Subject { //интерфейс событий
public:
    virtual void React() = 0;
    virtual bool is_one_time() = 0; //определяет, одноразовое событие или нет
    virtual ~IEvent() = 0 {};
};

