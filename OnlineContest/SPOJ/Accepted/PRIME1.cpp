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
template <class T> T power ( T a, T p ) { int res = 1, x = a; while ( p ) { if ( p & 1 ) res = res * x; x = x * x; p >>= 1; } return res;}
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


const long long pr = 32000;
long long prime[ 3500 ], ind;
bool mark[ pr ];
void primelist()
{
    for(long long i = 4; i < pr; i += 2) mark[ i ] = false;
    for(long long i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
    for(long long i = 3, sq = sqrt( pr ); i < sq; i += 2)
        if(mark[ i ])
            for(long long j = i * i; j < pr; j += i + i) mark[ j ] = false;
    prime[ 0 ] = 2; ind = 1;
    for(long long i = 3; i < pr; i += 2)
        if(mark[ i ]) prime [ ind++ ] = i; //printf("%d\n", ind);
}

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

void input();

/**************************Templet end*********************************/

long long start(long long n, long long p);

bool vis[ 100010 ];

int main()
{
    primelist();
    //#ifdef monkey
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    input();

    return 0;
}
void input()
{
    long long T, a, b;
    bool space = false;
    scanf("%lld", &T);
    while( T-- )
    {
        if( space ) puts("");
        else space = true;
        scanf("%lld %lld", &a, &b);
        if(a == 1) a++;
        if(a <= b && a == 2) puts("2");
        if(a == 2) a++;
        if(a > b) continue;
        memset(vis, true, sizeof vis);

        for(long long i = 1; sq(prime[ i ]) <= b; i++)
        {
            long long k = start(a, prime[ i ]);
            for(long long j = k; j <= b; j += prime[ i ])
                if(j != prime[ i ]) vis[j - a] = false;
        }

        for(long long i = 0; i <= b - a; i++)
            if(vis[ i ] && (a + i) % 2) printf("%lld\n", a + i);
    }
}
long long start(long long n, long long p)
{
    //printf("%d %d\n", n, p);
    if(n < p) return p;
    long long ret = n / p;
    ret *= p;
    if(ret < n) ret += p;
    if(ret % 2 == 0) ret += p;
    return ret;
}
