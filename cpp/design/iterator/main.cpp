#include <iostream>
#include "Aggregate.h"
#include "Iterator.h"
#include "ConcreteAggregate.h"
#include "ListAggregate.h"

int main(void)
{
    Aggregate *aggregate = new ConcreteAggregate();
    if ( NULL != aggregate )
    {
        aggregate->Push("Hello");
        aggregate->Push("Come On");
        aggregate->Push("World");
    }
    std::cout << " count : " << aggregate->Count() << std::endl;

    Iterator *iter = aggregate->CreateIterator();
    if ( NULL != iter )
    {
        std::cout << " first : " << iter->First() << std::endl;
        while ( !iter->isEnd())
        {
            std::cout << "get value is : " << iter->getCur() << std::endl;
            iter->Next();
        }
    }

    Aggregate *listagate = new ListAggregate();
    if ( NULL != listagate )
    {
        listagate->Push("Come on");
        listagate->Push("Good");
    }
    std::cout << " list count : " << listagate->Count() << std::endl;

    Iterator *liter = listagate->CreateIterator();
    if ( NULL != liter)
    {
        std::cout << " list first : " << liter->First() << std::endl;
        while ( !liter->isEnd())
        {
            std::cout << "list get value is : " << liter->getCur() << std::endl;
            liter->Next();
        }
    }

    return 0;
}
