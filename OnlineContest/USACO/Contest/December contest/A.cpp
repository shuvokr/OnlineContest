#include <stdio.h>
#include <algorithm>
using namespace std;
struct data
{
    long long x, y;
}in[ 100010 ];
int main()
{
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    int N;
    long long minn, res, sum, tot, p, tmp;
    while(~scanf("%d", &N))
    {
        sum = 0; minn = -100000000000000ll;
        scanf("%lld %lld", &in[0].x, &in[0].y);
        for(int i = 1; i < N; i++)
        {
            scanf("%lld %lld", &in[i].x, &in[i].y);
            tot = abs(in[ i ].x - in[i - 1].x);
            tot += abs(in[ i ].y - in[i - 1].y);
            sum += tot;
        }

        res = sum + 100; //printf("%lld\n", sum);
        for(p = 1; p < N - 1; p++)
        {
            tmp = sum;
            tot = abs(in[ p ].x - in[p - 1].x);
            tot += abs(in[ p ].y - in[p - 1].y);
            tmp -= tot;

            tot = abs(in[ p ].x - in[p + 1].x);
            tot += abs(in[ p ].y - in[p + 1].y);
            tmp -= tot;

            tot = abs(in[p - 1].x - in[p + 1].x);
            tot += abs(in[p - 1].y - in[p + 1].y);
            tmp += tot;
            //printf(" %lld\n", tmp);
            res = min(res, tmp);
        }

        printf("%lld\n", res);
    }
    return 0;
}

