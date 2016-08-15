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
#include <deque>
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
template <class T> T power ( T a, T p ) { T res = 1, x = a; while ( p ) { if ( p & 1 ) res = res * x; x = x * x; p >>= 1; } return res;}
template <class T> T cordinatlenth(T a, T b, T c, T d) { return sqrt( sq(a - c) + sq(b - d) ); }
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
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

/*
#define M 1000005
int phi[M];

void calculatePhi()
{
    for (int i = 1; i < M; i++) phi[i] = i;
    for (int p = 2; p < M; p++)
        if (phi[p] == p) // p is a prime
            for (int k = p; k < M; k += p) phi[k] -= phi[k] / p;
}
*/

/*
const int pr = 500001;
int prime[ 41539 ], ind;
bool mark[ pr ];
void primelist()
{
    for(int i = 4; i < pr; i += 2) mark[ i ] = false;
    for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
    for(int i = 3, sq = sqrt( pr ); i < sq; i += 2)
        if(mark[ i ])
            for(int j = i * i; j < pr; j += i + i) mark[ j ] = false;
    prime[ 0 ] = 2; ind = 1;
    for(int i = 3; i < pr; i += 2)
        if(mark[ i ]) ind++; printf("%d\n", ind);
}
*/

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

#define check(n, pos) (n & (1<<(pos)))
#define biton(n, pos) (n | (1<<(pos)))
#define bitoff(n, pos) (n & ~(1<<(pos)))

void input();

/**************************Templet end*********************************/

int in[ 100100 ];

int main()
{
//    #ifdef monkey
//        freopen("spacialInput.txt", "r", stdin);
//        freopen("spacialOutput.txt", "w", stdout);
//    #endif
    input();

    return 0;
}
void input()
{
    int T, n, kag = 0;
    sf("%d", &T);
    while( T-- )
    {
        CLR(in, 0);
        sf("%d", &n);
        for(int i = 0; i < n; i++) sf("%d", &in[ i ]);

        int i = 0, x, y, z, res = 3;
        in[ n ] = 1000000010;

        if(n < 3)
        {
            pf("Case %d: -1\n", ++kag);
            continue;
        }

        res = 3;
        i = x = y = z = 0;
        int cou = 0;

        while( i < n )
        {
            //cout << "start = " << i << endl;

            int flag = 1, k = 1;
            if( !x ) while(in[ i ] < in[i + 1] && i < n) i++, x++, flag = 0, k = 0;
            if(!cou) if((i < n && i - 1 > -1 && in[ i ] > in[i - 1]) || flag) i++;
            if(i >= n) break;

            //cout << "start = " << i << endl;
            flag = 1;
            while(in[ i ] > in[i + 1] && i < n) i++, y++, flag = 0;
            if((i < n && i - 1 > -1 && in[ i ] < in[i - 1]) || flag) i++;
            if(i >= n) break;

            if(in[ i ] > in[i - 1]) y--, i--;

            //cout << "start = " << i << endl;
            flag = 1;
            while(in[ i ] < in[i + 1] && i < n)
            {
                i++, z++, flag = 0;
                if(i == n - 1) break;
            }
            if((i < n && i - 1 > -1 && in[ i ] > in[i - 1]) || flag) i++;

            x++; y++; z++;

            //cout << x << " " << y << " " << z << " " << i << endl;

            res = max(res, x + y + z);
            x = z - 1; y = z = 0;
            cou++;
        }

        pf("Case %d: %d\n", ++kag, res);
    }
}
/*

1
10
21 15 5 16 19 13 7 17 18 20
10
26777 15573 5097 16512 23986 13290 9161 18636 22355 24767

*/
