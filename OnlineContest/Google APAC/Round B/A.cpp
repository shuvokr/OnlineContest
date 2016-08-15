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

void Input();
const int INF = 2147483647;
const long long LINF = 9223372036854775807ll;
/**************************Templet end*********************************/

struct data
{
    int nod, time, now;
    data() {}
    data(int a, int b, int c):nod(a), time(b), now(c) {}
    bool operator<(const data &x) const
    {
        return time < x.time;
    }
};

void Dijkstra(int s, int e, int nw, int ts);

vector <vi> graph;
int cost[ 505 ][ 505 ][ 24 ], n, m, k, rcost[ 510 ], fans[ 505 ][ 505 ][ 24 ];
vector <int> ans;
bool mark[ 24 ];

int main()
{
    //#ifdef monkey
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    //#endif
    Input();

    return 0;
    /// Not use cin/cout without necessity. This a causes of TLE :p
}
void Input()
{
	int T, kag = 0;
	si1( T );
	while( T-- )
	{
		CLR(cost, 0);
		si3(n, m, k);
		graph.assign(n + 5, vi());
		for(int i = 0, a, b; i < m; i++)
		{
			si2(a, b);
			graph[a].push_back(b);
			graph[b].push_back(a);
			
			for(int j = 0; j < 24; j++) si1(cost[a][b][j]), cost[b][a][j] = cost[a][b][j];
		}
		
		ans.clear(); CLR(mark, false);
		for(int i = 0, D, S; i < k; i++)
		{
			si2(D, S);
			for(int i = 1; i <= n; i++) rcost[ i ] = INF;
			if(mark[ S ]) ans.push_back(fans[ 1 ][ D ][ S ]);
			else mark[ S ] = true, Dijkstra(1, D, S, S), ans.push_back(fans[1][D][S]);;
		}
		
		pf("Case #%d:", ++kag);
		for(int i = 0; i < ans.size(); i++) pf(" %d", ans[ i ]); puts("");
	}
}
void Dijkstra(int s, int e, int nw, int ts)
{
    priority_queue <data> pq;
    rcost[ s ] = 0;
    data tmp;
    int nd, tm;
    pq.push(data(s, 0, nw));
    while(!pq.empty())
    {
        tmp = pq.top(); pq.pop();
        nd = tmp.nod; tm = tmp.time; int nww = tmp.now;
        if(rcost[ nd ] == tm)
        {
            for(int i = 0; i < graph[ nd ].size(); i++)
            {
                int pr = graph[ nd ][ i ];
                int cst = cost[nd][pr][nww];
                if(rcost[ nd ] + cst < rcost[ pr ])
                {
                    rcost[ pr ] = rcost[ nd ] + cst;
                    nw = nww + (cst % 24);
                    nw = nw < 24 ? nw : nw - 24;
                    //pf("%d ", rcost[ pr ]); pi3(nd, pr, nw);
					pq.push(data(pr, rcost[ pr ], nw));
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
		int val = rcost[ i ] == INF ? -1 : rcost[ i ];
		fans[ 1 ][ i ][ ts ] = val;	
	}
}
