#include <stdio.h>
#include <string.h>

using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);
    int line1[ 10001 ], line2[ 10001 ], sum1, sum2, line1sum[ 10001 ], line2sum[ 10001 ];
    int a, b, x, y, res, tot1, tot2, lastl1, lastl2;
    bool mark;
    while(~scanf("%d", &a) && a)
    {
        mark = true; tot1 = 0; tot2 = 0;
        for(x = 0; x < a; x++) scanf("%d", &line1[ x ]), tot1 += line1[ x ], line1sum[ x ] = tot1;
        scanf("%d", &b);
        for(x = 0; x < b; x++) scanf("%d", &line2[ x ]), tot2 += line2[ x ], line2sum[ x ] = tot2;

        line1[ a ] = 10005;
        line2[ b ] = 10005;
        line1sum[ a ] = line1sum[a - 1] + 10005;
        line2sum[ b ] = line2sum[b - 1] + 10005;
        res = x = y = 0;
        lastl2 = lastl1 = 0;
        while( x <= a && y <= b )
        {
            if(line1[ x ] < line2[ y ]) x++;
            else if(line2[ y ] < line1[ x ]) y++;
            else
            {
                sum1 = line1sum[ x ] - lastl1;
                sum2 = line2sum[ y ] - lastl2;
                res += (sum1 > sum2) ? sum1 : sum2;
                lastl1 = line1sum[ x ];
                lastl2 = line2sum[ y ];
                mark = false;
                x++; y++;
            }
        }
        printf("%d\n", res - 10005);
    }
    return 0;
}
