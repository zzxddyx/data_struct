#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <iostream>
#include <string>
using namespace std;

class Screen
{
    public:
        typedef string::size_type pos;

    public:

    private:
        pos cursor = 0;
        pos height = 0;
        pos width = 0;
        string contents = '';
};

#endif _SCREEN_H_
