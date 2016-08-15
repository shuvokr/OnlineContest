#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    long long a, b, T;
    int k, i;
    scanf("%lld", &T);
    while( T-- )
    {
        scanf("%lld %lld", &a, &b);
        if((!a && !b) || !b) {puts("1"); continue;}
        if( !a ) {puts("0"); continue;}
        k = b % 4; b = !k ? 4 : k; a = pow(a, b);
        printf("%lld\n", a % 10);
    }
    return 0;
}
