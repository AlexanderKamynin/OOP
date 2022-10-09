#include "Background/Field.h"
#include "Background/Cell.h"
#include "Player/Player.h"
#include "Background/CellView.h"
#include "Background/FieldView.h"
#include "Control/CommandReader.h"
#include "Control/Controller.h"
#include "Control/Mediator.h"
#include "Events/IEvent.h"


int main()
{
    setlocale(LC_ALL, "RU");
    Mediator mediator;
    mediator.start_game();
    return 0;
}