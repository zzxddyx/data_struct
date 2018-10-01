#include "LookNBA.h"

std::string LookNBA::getName()
{
    return this->name;
}

std::string LookNBA::getType()
{
    return this->type;
}

void LookNBA::Update(const std::string &msg)
{
    std::cout << "name : " << this->getName() << "\t" << "type : " << this->getType() << "\t" << "action : " << msg << std::endl;
}
