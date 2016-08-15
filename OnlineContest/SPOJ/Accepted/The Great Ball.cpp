/************************************

    Shuvo
    Problem name :
    Problem ID   :
    Problem algo :
    Note         :

*************************************/

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

struct X
{
    int lazy;
};

void init(int node, int b, int e);
void lazyreset(X &p);
void update(int node, int b, int e);
void propogat(X &p, X &l, X &r);
void lazyupdate(X &p);
void query(int node, int b, int e);

int ee[ 110 ][ 2 ], ans, x, y;
X stree[ 10000000 * 4 ];

int main()
{
    //#ifdef localhost
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    input();

    return 0;
}
void input()
{
    int maxval, n, T;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n);
        maxval = -1;
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &ee[ i ][ 0 ], &ee[ i ][ 1 ]);
            maxval = maxval < ee[ i ][ 1 ] ? ee[ i ][ 1 ] : maxval;
        }

        init(1, 1, maxval);

        for(int i = 0; i < n; i++)
        {
            x = ee[ i ][ 0 ];
            y = ee[ i ][ 1 ];
            update(1, 1, maxval);
        }
        ans = 0;
        query(1, 1, maxval);
        printf("%d\n", ans);
    }
}
void init(int node, int b, int e)
{
    lazyreset(stree[ node ]);

    if(b == e) return ;

    int left = node << 1, right = left + 1, mid = (b + e) >> 1;

    init(left, b, mid);
    init(right, mid + 1, e);
}
void lazyreset(X &p)
{
    p.lazy = 0;
}
void update(int node, int b, int e)
{
    int left = node << 1, right = left + 1, mid = (b + e) >> 1;

    if(b > y || e < x)
    {
        if(b != e)
        {
            propogat(stree[ node ], stree[ left ], stree[ right ]);
            lazyreset(stree[ node ]);
        }
        return ;
    }

    if(b >= x && e <= y)
    {
        lazyupdate(stree[ node ]);
        if(b != e)
        {
            propogat(stree[ node ], stree[ left ], stree[ right ]);
            lazyreset(stree[ node ]);
        }
        return;
    }

    propogat(stree[ node ], stree[ left ], stree[ right ]);
    lazyreset(stree[ node ]);

    update(left, b, mid);
    update(right, mid + 1, e);
}
void propogat(X &p, X &l, X &r)
{
    l.lazy += p.lazy;
    r.lazy += p.lazy;
}
void lazyupdate(X &p)
{
    p.lazy++;
}
void query(int node, int b, int e)
{
    int left = node << 1, right = left + 1, mid = (b + e) >> 1;

    if(b == e)
    {
        ans = ans < stree[ node ].lazy ? stree[ node ].lazy : ans;
        return ;
    }

    propogat(stree[ node ], stree[ left ], stree[ right ]);
    lazyreset(stree[ node ]);

    query(left, b, mid);
    query(right, mid + 1, e);
}

