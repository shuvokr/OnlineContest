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
#define CLR(n, v, x) memset(n, v, x)
#define INF 1 << 30
#define pb push_back
#define maxn 200+2
#define lim(v) v.begin(), v.end()
#define sz(v) ((int)v,size())
#define equals(a, b) (fabs(a-b)<eps)
#define pcase(n) printf("Test %d:\n", n);

#define white 0
#define black 1

const double PI = 2 * acos ( 0.0 );
const double eps = 1e-9;
const int MAX = 30010;

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
    int open, close;
};

/**************All Function**************/

void init(int node, int b, int e);
void marge(X &root, X &left, X &right);
void update(int node, int b, int e);

/****************************************/

X stree[ MAX * 4 ];
char in[ MAX ];
int pos, len;

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
    int q, T, kag = 0;
    while( ~scanf("%d", &len) )
    {
        pcase( ++kag );
        getchar(); gets( in );
        if(len % 2)
        {
            scanf("%d", &q);
            while(q--)
            {
                scanf("%d", &pos);
                if( !pos ) puts("NO");
            }
            continue;
        }

        len--;
        init(1, 0, len);

        scanf("%d", &q);
        while( q-- )
        {
            scanf("%d", &pos);
            if( !pos ) puts(!stree[ 1 ].open && !stree[ 1 ].close ? "YES" : "NO");
            else pos--, update(1, 0, len);
        }
    }
}
void init(int node, int b, int e)
{
    if(b == e)
    {
        if(in[ b ] == '(')
        {
            stree[ node ].open = 1;
            stree[ node ].close = 0;
        }
        else
        {
            stree[ node ].open = 0;
            stree[ node ].close = 1;
        }
    }
    else
    {
        int left = node << 1, right = left + 1, mid = (b + e) >> 1;
        init(left, b, mid);
        init(right, mid + 1, e);

        marge(stree[ node ], stree[ left ], stree[ right ]);
    }
}
void marge(X &root, X &left, X &right)
{
    int mini = left.open < right.close ? left.open : right.close;
    root.open = left.open - mini + right.open;
    root.close = left.close - mini + right.close;
}
void update(int node, int b, int e)
{
    if(b == e)
    {
        if(in[ pos ] == '(')
        {
            in[ pos ] = ')';
            stree[ node ].open--;
            stree[ node ].close++;
        }
        else
        {
            in[ pos ] = '(';
            stree[ node ].open++;
            stree[ node ].close--;
        }
    }
    else
    {
        int left = node << 1, right = left + 1, mid = (b + e) >> 1;

        if(pos <= mid) update(left, b, mid);
        else update(right, mid + 1, e);

        marge(stree[ node ], stree[ left ], stree[ right ]);
    }
}

