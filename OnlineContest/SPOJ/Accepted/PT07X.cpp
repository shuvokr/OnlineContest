#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;

int dp(int u, int flag);

vector <vi> graph;
int node, par[ 100010 ], mamo[ 100010 ][ 2 ];

int main()
{
    int u, v;
    while(~scanf("%d", &node))
    {
        graph.assign(node + 2, vi());
        for(int i = 1; i < node; i++)
        {
            scanf("%d %d", &u, &v);
            graph[ u ].push_back( v );
            graph[ v ].push_back( u );
        }
        memset(mamo, -1, sizeof mamo);
        printf("%d\n", min(dp(1, 0), dp(1, 1)));
    }
    return 0;
}
int dp(int u, int flag)
{
    if(graph[ u ].size() == 0) return 0;
    if(mamo[ u ][ flag ] != -1) return mamo[ u ][ flag ];
    int sum = 0;
    for(int i = 0; i < graph[ u ].size(); i++)
    {
        int v = graph[ u ][ i ];
        if(v != par[ u ])
        {
            par[ v ] = u;
            if( !flag ) sum += dp(v, 1);
            else sum += min(dp(v, 0), dp(v, 1));
        }
    }
    return mamo[ u ][ flag ] = sum + flag;
}
