/**********************************Templet start***********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

#define phl puts("Hello")
#define sf scanf
#define pf printf
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define CLR(n, v) memset(n, v, sizeof( n ))
#define INF 1 << 30
#define pb push_back
#define maxn 200+2
#define lim(v) v.begin(), v.end()
#define sz(v) ((int)v,size())
#define equals(a, b) (fabs(a-b)<eps)

#define white 0
#define black 1

const double PI = 2 * acos ( 0.0 );
const double eps = 1e-9;

typedef long long lld;
typedef unsigned long long llu;
typedef pair<int, int> pi;
typedef  vector<int> vi;
typedef vector<pi> vpi;

template <class T> T jog(T a, T b) { return a + b; }
template <class T> T bog(T a, T b) { return a - b; }
template <class T> T gon(T a, T b) { return a * b; }
template <class T> T sq(T x) {return x * x;}
template <class T> T gcd( T a, T b ) { return b == 0 ? a : gcd(b, a % b); }
template <class T> T lcm ( T a, T b ) { return ( a / gcd ( a, b ) ) * b; }
template <class T> T power ( T a, T p ) { int res = 1, x = a; while ( p ) { if ( p & 1 ) res = res * x; x = x * x; p >>= 1; } return res;}
template <class T> T cordinatlenth(T a, T b, T c, T d) { return sqrt( sq(a - c) + sq(b - d) ); }
lld bigmod ( lld a, lld p, lld mod )
{
    lld res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % mod;
        x = ( x * x ) % mod;
        p >>= 1;
    }
    return res;
}


int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

void input();

/**************************Templet end*********************************/

int in[ 4 ][ 4 ], fr[ 4 ], sr[ 4 ], rnum, T, kag;

int main()
{
    #ifdef monkey
        freopen("input.txt", "r", stdin);
        freopen("A-small-attempt0.txt", "w", stdout);
    #endif
    input();

    return 0;
}
void input()
{
    kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &rnum);
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++) scanf("%d", &in[ i ][ j ]);
        for(int i = 0; i < 4; i++) fr[ i ] = in[rnum - 1][ i ];

        scanf("%d", &rnum);
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++) scanf("%d", &in[ i ][ j ]);
        for(int i = 0; i < 4; i++) sr[ i ] = in[rnum - 1][ i ];

        int tmp = 100, cou = 0, ze = 0, one = 0;
        for(int i = 0, j; i < 4; i++)
        {
            cou = 0;
            for(j = 0; j < 4; j++)
            {
                if(fr[ i ] == sr[ j ]) cou++;
            }
            if(cou == 1) {tmp = 1; rnum = fr[ i ]; one++;}
            if(!cou) ze++;
        }

        if(one == 1) printf("Case #%d: %d\n", ++kag, rnum);
        else if(ze == 4) printf("Case #%d: Volunteer cheated!\n", ++kag);
        else printf("Case #%d: Bad magician!\n", ++kag);
    }
}
