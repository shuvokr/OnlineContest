#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int DP(int pos, int part);
int point, mamo[ 50010 ][ 4 ], n, k, in[ 50010 ];

int main()
{
    int T, sum = 0;
    scanf("%d", &T);
    while( T-- )
    {
        in[ 0 ] = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &in[ i ]), in[ i ] += in[i - 1];
        scanf("%d", &k);

        memset(mamo, -1, sizeof mamo);
        printf("%d\n", DP(1, 3));
    }
    return 0;
}

/******Input*******
1
8
2 5 3 1 4 6 1 7
3
Output: 24
******************/

int DP(int pos, int part)
{
    if(part == 0 || pos + k - 1 > n) return 0;
    int &ret = mamo[ pos ][ part ];
    if(ret != -1) return ret;

    int a, b;
    if(pos + k - 1 <= n) a = in[ pos + k - 1 ] - in[pos - 1] + DP(pos + k, part - 1);
    b = DP(pos + 1, part);
    //printf("%d %d %d %d\n", a, b , pos, part);
    return ret = max(a, b);
}

