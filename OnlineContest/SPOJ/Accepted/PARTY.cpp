#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dp(int pnum, int tcost);

struct data
{
    int cost, fun;
}in[ 110 ];

bool cmp(const data a, const data b)
{
    if(a.cost < b.cost) return true;
    if(a.cost == b.cost)
    {
        if(a.fun > b.fun) return true;
        return false;
    }
    return false;
}

int rcost, rfun, party, mamo[ 110 ][ 510 ], amount;

int main()
{
    while(scanf("%d %d", &amount, &party) && (amount || party))
    {
        for(int i = 0; i < party; i++) scanf("%d %d", &in[ i ].cost, &in[ i ].fun);
        sort(in, in + party, cmp);
        memset(mamo, -1, sizeof mamo);
        rfun = dp(0, 0);
        if(!rfun)
        {
            printf("%d 0\n", in[ 0 ].cost);
            continue;
        }
        int left = 0, right = amount, mid;
        while(left < right)
        {
            mid = (left + right) >> 1;
            amount = mid;
            memset(mamo, -1, sizeof mamo);
            if(dp(0, 0) < rfun) left = mid + 1;
            else right = mid;
        }
        printf("%d %d\n", left, rfun);
    }
    return 0;
}
int dp(int pnum, int tcost)
{
    if(pnum >= party) return 0;
    if(mamo[ pnum ][ tcost ] != -1) return mamo[ pnum ][ tcost ];
    //int &ret = mamo[ pnum ][ tcost ];
    int a = 0, b = 0;
    if(tcost + in[ pnum ].cost <= amount)
        a = in[ pnum ].fun + dp(pnum + 1, tcost + in[ pnum ].cost);

    b = 0 + dp(pnum + 1, tcost);
    return mamo[ pnum ][ tcost ] = a < b ? b : a;
}
