#include "LookNBA.h"
#include "Mishu.h"

#include "Observer.h"

int main(void)
{
    LookNBA *A = new LookNBA("A", "NBA");
    LookNBA *B = new LookNBA("B", "NBA");

    Mishu *mishu = new Mishu();
    mishu->registerObserver(A);
    mishu->registerObserver(B);
    mishu->notifyObserver("Work");

    return 0;
}
