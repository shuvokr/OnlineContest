
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
#define pcase(n) printf("Case %d:\n", n);

#define white 0
#define black 1

const double PI = 2 * acos ( 0.0 );
const double eps = 1e-9;
const int MAX = 100005;

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
    int sum;
    int maxval;
};

/**************All Function**************/

void init(int node, int b, int e);
void lazyreset(X &p);
void marge(X &root, X &left, X &right);
void update(int node, int b, int e);
void lazyupdate(X &p);
void calculate(X &p, int len);
void propagate(X &p, X &u, X &v);
void query(int node, int b, int e);

/****************************************/

int in[ MAX ], x, y, first, second;
X stree[ MAX * 4 ], ans;
bool mark;

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
    int n, q;
    char ch[ 3 ];
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &in[ i ]);
        }

        init(1, 0, n - 1);

        scanf("%d", &q);
        while( q-- )
        {
            scanf("%s %d %d", ch, &x, &y); x--;
            if(ch[ 0 ] == 'U') in[ x ] = y, update(1, 0, n - 1);
            else
            {
                y--;
                first = second = ans.sum = -11111111;
                mark = true;
                query(1, 0, n - 1);
                //printf("  %d %d\n", first, second);
                first += second;
                second = ans.sum;
                if(first > second)
                    printf("%d\n", first);
                else printf("%d\n", second);
            }
        }
    }
}
void init(int node, int b, int e)
{
    if(b == e)
    {
        stree[ node ].sum = in[ b ];
        stree[ node ].maxval = in[ b ];
        return ;
    }
    int left = node << 1, right = left + 1, mid = (b + e) >> 1;

    init(left, b, mid);
    init(right, mid + 1, e);

    marge(stree[ node ], stree[ left ], stree[ right ]);
}
void marge(X &root, X &l, X &r)
{
    int mxi = l.sum < r.sum ? r.sum : l.sum;
    root.sum = l.maxval + r.maxval;
    root.sum = root.sum < mxi ? mxi : root.sum;
    root.maxval = l.maxval < r.maxval ? r.maxval : l.maxval;
}
void update(int node, int b, int e)
{
    if(x >= b && x <= e)
    {
        if(b == e)
            if(x == b)
            {
                stree[ node ].sum = y;
                stree[ node ].maxval = y;
                return ;
            }
            else return;

        int left = node << 1, right = left + 1, mid = (b + e) >> 1;

        update(left, b, mid);
        update(right, mid + 1, e);

        marge(stree[ node ], stree[ left ], stree[ right ]);
    }
}
void query(int node, int b, int e)
{
    if(mark){
    if(b > y || e < x)
    {
        return ;
    }

    int left = node << 1, right = left + 1, mid = (b + e) >> 1;

    if(b >= x && e <= y)
    {
        if(b == x && e == y) mark = false;
        ans.sum = stree[ node ].sum < ans.sum ? ans.sum : stree[ node ].sum;
        if(b == e)
        {
            if(first == -11111111) first = stree[ node ].sum;
            else if(second == -11111111) second = stree[ node ].sum;
            else
            {
                int tmp = stree[ node ].maxval;
                if(first < tmp)
                {
                    int k = tmp;
                    tmp = first;
                    first = k;
                }
                if(second < tmp)
                {
                    second = tmp;
                }
            }
            return;
        }
    }

    query(left, b, mid);
    query(right, mid + 1, e);
    }
}

