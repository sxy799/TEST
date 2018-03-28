#include <stdio.h>
#include <math.h>
#include <unit.h>
#ifdef TEXT_RUN
#include "testcase1.h"
#endif
int main()
{
    double n;
while(scanf("%lf", &n) != EOF)
{
    printf("%lf\n", newton_sqrt(n));
}
    return 0;
}