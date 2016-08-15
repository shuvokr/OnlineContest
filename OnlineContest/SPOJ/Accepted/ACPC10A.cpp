#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    long long a, b, c, d;
    while(scanf("%lld %lld %lld", &a, &b, &c) && (a || b || c))
    {
        if(b - a == c - b && b - a != 0) printf("AP %lld\n", c + b - a);
        else
        {
            long long tmp = b / a;
            printf("GP %lld\n", c * tmp);
        }
    }
    return 0;
}
