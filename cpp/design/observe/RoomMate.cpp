#include "RoomMate.h"

void RoomMate::Update(const std::string &msg)
{
    std::cout << this->name << " " << this->action << " " << this->now << " " << msg << std::endl;
}

std::string RoomMate::getName()
{
    return this->name;
}
