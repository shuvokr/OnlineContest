/***************** Shuvo *****************/
/****************** DIU *****************/

#pragma comment(linker, "/stack:64000000")

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
#define pb push_back
#define lim(v) v.begin(), v.end()
#define sz(v) ((int)v,size())
#define equals(a, b) (fabs(a-b)<eps)
#define si1(a) scanf("%d", &a)
#define pi1(a) printf("%d\n", a)
#define si2(a, b) scanf("%d %d", &a, &b)
#define pi2(a, b) printf("%d %d\n", a, b)
#define si3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pi3(a, b, c) printf("%d %d %d\n", a, b, c)

#define white 0
#define black 1

const double PI = 2 * acos ( 0.0 );
const double eps = 1e-9;

typedef long long lld;
typedef unsigned long long llu;
//typedef pair<int, int> pi;
typedef  vector<int> vi;
//typedef vector<pi> vpi;

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

void Input();
const int INF = 2147483647;
const long long LINF = 9223372036854775800ll;
/**************************Templet end*********************************/

lld DP(lld pos, lld remain);
lld DP2(lld pos, lld remain);

lld n, m, q, in[ 10010 ], posi[ 110 ], neg[ 110 ], pi, ni, mamo[ 110 ][ 10010 ], vis[ 110 ][ 10010 ], ck;
lld posip[ 110 ], negp[ 110 ];

int main()
{
    //#ifdef monkey
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    Input();

    return 0;
    /// Not use cin/cout without necessity. This a causes of TLE :p
}
void Input()
{
	int T, kag = 0;
	si1( T ); CLR(vis, 0); ck = 1;
	while( T-- )
	{
		sf("%lld %lld %lld", &n, &m, &q);
		for(int i = 0; i < m; i++) sf("%lld", &in[ i ]);
		pi = ni = 0;
		for(int i = 0, a, b; i < n; i++)
		{
			sf("%d %d", &a, &b);
			if(a < 0) neg[ ni ] = b, negp[ ni++ ] = a;
			else posi[ pi ] = b, posip[ pi++ ] = a;
		}
		
		//cout << "***********" << ni << endl;
		
		lld ans = DP(0, q); ck++;
		lld ans2 = DP2(0, q); ck++;
		
		//cout << ans << " " << ans2 << endl;
		
		pf("Case #%d: ", ++kag);
		
		if(ans < 0 || ans2 < 0) puts("IMPOSSIBLE");
		else pf("%lld\n", max(ans, ans2));
		//cout << ans << endl;
	}
}
lld DP(lld pos, lld remain)
{
	if(pos == pi) return 0;
	lld &ret = mamo[ pos ][ remain ];
	if(vis[ pos ][ remain ] == ck) return ret;
	vis[ pos ][ remain ] = ck;
	ret = -INF;
	for(int i = 0; i <= remain; i++)
	{
		if(i == 0)
		{
			lld x = posi[ pos ];
			if(in[ x ] < 0)
			{
				lld tmp = in[ x ] * (-1);
				if(tmp == 0) ret = max(0ll, DP(pos + 1, remain - i));
				else{
				lld z = posip[ pos ] / tmp;
				z += (bool)(posip[ pos ] % tmp);
				ret = max(z, DP(pos + 1, remain - i));
				}
			}
		}
		else
		{
			lld x = posi[ pos ] + i;
			lld y = posi[ pos ] - i;
			
			if(x < m && in[ x ] < 0)
			{
				lld tmp = in[ x ] * (-1);
				if(tmp == 0) ret = max(0ll, DP(pos + 1, remain - i));
				else{
				lld z = posip[ pos ] / tmp;
				z += (bool)(posip[ pos ] % tmp);
				ret = max(z, DP(pos + 1, remain - i));
				}
			}
			
			if(y > -1 && in[ y ] < 0)
			{
				lld tmp = in[ y ] * (-1);
				if(tmp == 0) ret = max(0ll, DP(pos + 1, remain - i));
				else{
				lld z = posip[ pos ] / tmp;
				z += (bool)(posip[ pos ] % tmp);
				ret = max(z, DP(pos + 1, remain - i));
				}
			}
		}
	}
	return ret;
}
lld DP2(lld pos, lld remain)
{
	if(pos == ni) return 0;
	lld &ret = mamo[ pos ][ remain ];
	if(vis[ pos ][ remain ] == ck) return ret;
	vis[ pos ][ remain ] = ck;
	ret = -INF;
	
	for(int i = 0; i <= remain; i++)
	{
		if(i == 0)
		{
			lld x = neg[ pos ];
			if(in[ x ] > -1)
			{
				lld tmp = in[ x ];
				if(tmp == 0) ret = max(0ll, DP2(pos + 1, remain - i));
				else{
				lld z = negp[ pos ] / tmp;
				z += (bool)(negp[ pos ] % tmp);
				ret = max(z, DP2(pos + 1, remain - i));
				}
			}
		}
		else
		{
			lld x = neg[ pos ] + i;
			lld y = neg[ pos ] - i;
			
			if(x < m && in[ x ] > -1)
			{
				lld tmp = in[ x ];
				if(tmp == 0) ret = max(0ll, DP2(pos + 1, remain - i));
				else{
				lld z = negp[ pos ] / tmp;
				z += (bool)(negp[ pos ] % tmp);
				ret = max(z, DP2(pos + 1, remain - i));
				}
			}
			
			if(y > -1 && in[ y ] > -1)
			{
				lld tmp = in[ y ];
				if(tmp == 0) ret = max(0ll, DP2(pos + 1, remain - i));
				else{
				lld z = negp[ pos ] / tmp;
				z += (bool)(negp[ pos ] % tmp);
				ret = max(z, DP2(pos + 1, remain - i));
				}
			}
		}
	}
	return ret;
}
