#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>

using namespace std;
template <class T> T power ( T a, T p ) { int res = 1, x = a; while ( p ) { if ( p & 1 ) res = res * x; x = x * x; p >>= 1; } return res;}
int main()
{
    long long N, neww, res;
    map <long long, bool> mp;
    while(~scanf("%lld", &N))
    {
        res = 0; mp.clear(); neww = N;

        while( !mp[ neww ] && neww != 1 )
        {
            //printf("%lld ", neww);
            N = neww;
            mp[ N ] = true; neww = 0ll;
            while( N )
            {
                neww += power(N % 10, 2ll);
                N /= 10;
            }
            res++;
        }

        if(neww != 1) puts("-1");
        else printf("%lld\n", res);
    }
    return 0;
}
