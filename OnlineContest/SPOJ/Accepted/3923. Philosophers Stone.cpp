/*******************************

    Shuvo
    Problem ID: 3923
    Problem algo: Classic DP

********************************/

#include <stdio.h>
#include <string.h>
using namespace std;
#define CLR(n, v) memset(n, v, sizeof n)
void dp();
int cost[ 102 ][ 102 ];
int row, col;
int main()
{
    int T, i, j;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &row, &col); CLR(cost, 0);
        for(i = 1; i <= row; i++)
            for(j = 1; j <= col; j++) scanf("%d", &cost[ i ][ j ]);
        dp();
    }
    return 0;
}
void dp()
{
    int res, i, j, k, tmp, a, b, c;
    for(i = row - 1; i >= 0; i--)
    {
        for(j = 1; j <= col; j++)
        {
            a = j - 1; b = j; c = j + 1;
            if( a ) a = cost[i + 1][ a ];
            else a = 0;
            b = cost[i + 1][ b ];
            if(c <= col) c = cost[i + 1][ c ];
            else c = 0;
            a = a < b ? b : a;
            cost[ i ][ j ] += a > c ? a : c;
        }
    }
    res = -1;
    for(i = 1; i <= col; i++)
        res = res < cost[ 0 ][ i ] ? cost[ 0 ][ i ] : res;
    printf("%d\n", res);
}

