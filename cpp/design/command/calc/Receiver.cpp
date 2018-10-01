#include "Receiver.h"
#include <iostream>

Receiver::Receiver(int m1, int m2)
    :m_param1(m1), m_param2(m2)
{}

void Receiver::ExecAdd()
{
    std::cout << "+ : " << m_param1 + m_param2 << std::endl;
}

void Receiver::ExecSub()
{
    std::cout << "- : " << m_param1 - m_param2 << std::endl;
}

void Receiver::ExecMul()
{
    std::cout << "* :" << m_param1 * m_param2 << std::endl;
}

void Receiver::ExecDiv()
{
    if (0 == this->m_param2)
    {
        std::cout << "param 2 not zero" << std::endl;
        return;
    }

    std::cout << "/ :" << m_param1 / m_param2 << std::endl;
}
