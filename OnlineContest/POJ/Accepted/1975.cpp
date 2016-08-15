#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

typedef vector <int> vi;

int BFS(int s);
int BFS2(int s);

vector <vi> graph, graph2;
int node, edge;
bool mark[ 100 ], ck[ 100 ];

int main()
{
    int T;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &node, &edge);
        graph.assign(node + 2, vi());
        graph2.assign(node + 2, vi());
        for(int i = 0, u, v; i < edge; i++)
        {
            scanf("%d %d", &u, &v);
            graph[ u ].push_back( v );
            graph2[ v ].push_back( u );
        }

        int res = 0, cmp = (node + 1) >> 1;
        memset(ck, true, sizeof ck);

        for(int i = 1; i <= node; i++)
        {
            int ret = BFS( i ); //printf("%d %d\n", i, ret);
            if(ret >= cmp)
            {
                ck[ i ] = false;
                res++;
            }
        }
        for(int i = 1; i <= node; i++)
        {
            if(ck[ i ])
            {
                int ret = BFS2( i ); //printf("%d %d\n", i, ret);
                if(ret >= cmp)
                {
                    ck[ i ] = false;
                    res++;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
int BFS(int s)
{
    memset(mark, true, sizeof mark);
    queue <int> q; q.push( s ); mark[ s ] = false; int ret = 0;
    while(!q.empty())
    {
        s = q.front(); q.pop();
        for(int i = 0; i < graph[ s ].size(); i++)
        {
            int d = graph[ s ][ i ];
            if(mark[ d ])
            {
                mark[ d ] = false;
                ret++; q.push( d );
            }
        }
    }
    return ret;
}
int BFS2(int s)
{
    memset(mark, true, sizeof mark);
    queue <int> q; q.push( s ); mark[ s ] = false; int ret = 0;
    while(!q.empty())
    {
        s = q.front(); q.pop();
        for(int i = 0; i < graph2[ s ].size(); i++)
        {
            int d = graph2[ s ][ i ];
            if(mark[ d ])
            {
                mark[ d ] = false;
                ret++; q.push( d );
            }
        }
    }
    return ret;
}
