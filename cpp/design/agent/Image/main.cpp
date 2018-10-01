#include "BigImageProxy.h"

int main(void)
{
    BigImageProxy *proxy = new BigImageProxy("xxx.png", 400);
    proxy->Show();

    BigImageProxy *proxy1 = new BigImageProxy("ppp.png", 800);
    proxy1->Show();
    return 0;
}
