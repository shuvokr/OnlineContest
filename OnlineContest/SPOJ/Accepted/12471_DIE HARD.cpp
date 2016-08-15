#include <stdio.h>
#include <string.h>

using namespace std;

int dp(int helth, int amor, int live);

int mamo[ 1003 ][ 1003 ], final_res;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int Helth, amor, T, live;
    scanf("%d", &T);
    while( T-- )
    {
        memset(mamo, -1, sizeof mamo);
        scanf("%d %d", &Helth, &amor);
        final_res = -1;
        live = dp(Helth, amor, 0);
        final_res--;
        printf("%d\n", final_res);
    }
    return 0;
}
int dp(int helth, int amor, int live)
{
    int maxi = 1e-7;
    if(helth < 1 || amor < 1) return 0;
    if(mamo[ helth ][ amor ] != -1) return mamo[ helth ][ amor ];
    int a = 0, b = 0, c = 0;

    if( !live )
    {
        a = 1 + dp(helth + 3, amor + 2, 1); //air
        b = 1 + dp(helth - 5, amor - 10, 2); //weter
        c = 1 + dp(helth - 20, amor + 5, 3); //fire
//        if(a == b && a == c) final_res = a;
//        else if(a == b || a == c) final_res = a;
//        else if(b == c) final_res = b;
//        else final_res = b;
        final_res = a > b ? a : b;
        final_res = final_res > c ? final_res : c;
        //printf("%d %d %d\n", a, b, c);
    }
    else if(live == 1)
    {
        b = 1 + dp(helth - 5, amor - 10, 2); //weter
        c = 1 + dp(helth - 20, amor + 5, 3); //fire
    }
    else if(live == 2)
    {
        a = 1 + dp(helth + 3, amor + 2, 1); //air
        c = 1 + dp(helth - 20, amor + 5, 3); //fire
    }
    else
    {
        a = 1 + dp(helth + 3, amor + 2, 1); //air
        b = 1 + dp(helth - 5, amor - 10, 2); //weter
    }
    maxi = a > b ? a :
        b = b > c ? b : c;
    mamo[ helth ][ amor ] = maxi;
    return maxi;
}
