#include <stdio.h>
#include <math.h>
int main()
{
    int T, n;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n);
        if(n % 2)
        {
            puts("0");
            continue;
        }
        int res = 1, len = sqrt( n ) + 1;
        for(int i = 2; i < len; i++)
        {
            if(!(n % i))
            {
                int tmp = n / i;
                res += !(i % 2) ? 1 : 0;
                res += !(tmp % 2) ? 1 : 0;
                res -= tmp == i && !(tmp % 2) ? 1 : 0;
            }
        }
        printf("%d\n", res);
    }

    return 0;
}
