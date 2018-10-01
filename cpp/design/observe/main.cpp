#include "RoomMate.h"
#include "QQGroup.h"

int main(void)
{
    RoomMate *A = new RoomMate("A", "Sleeping", "sleep");
    RoomMate *B = new RoomMate("B", "Playing", "play");
    RoomMate *D = new RoomMate("D", "Papa", "pp");

    QQGroup *group = new QQGroup();
    group->registerObserver(A);
    group->registerObserver(B);
    group->registerObserver(D);
    group->notifyObservers("Quickly");

    std::cout << "=======================" << std::endl;


    group->removeObserver(A);
    group->notifyObservers("GG");

    return 0;
}
