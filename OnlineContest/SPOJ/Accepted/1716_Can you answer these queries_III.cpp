
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

const int MAX = 100005;

void input();

/**************************Templet end*********************************/

struct X
{
    int sum;
    int prefix;
    int sufix;
    int maxsum;
};

/**************All Function**************/

void init(int node, int b, int e);
void marge(X &root, X &left, X &right);
void update(int node, int b, int e);
void query(int node, int b, int e);

/****************************************/

int in[ MAX ], x, y, tmpp;
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
            if(ch[ 0 ] == '0') in[ x ] = y, update(1, 0, n - 1);
            else
            {
                y--;
                ans.maxsum = ans.sum = ans.prefix = ans.sufix = -111111111;
                query(1, 0, n - 1);
                int res = ans.maxsum;
                printf("%d\n", res);
            }
        }
    }
}
void init(int node, int b, int e)
{
    if(b == e)
    {
        stree[ node ].prefix = stree[ node ].sufix = stree[ node ].sum = stree[ node ].maxsum = in[ b ];
        return ;
    }
    int left = node << 1, right = left + 1, mid = (b + e) >> 1;

    init(left, b, mid);
    init(right, mid + 1, e);

    marge(stree[ node ], stree[ left ], stree[ right ]);
}
void marge(X &root, X &l, X &r)
{
    root.sum = l.sum + r.sum;
    int mxs = l.maxsum < r.maxsum ? r.maxsum : l.maxsum;
    int k = l.sufix + r.prefix;
    mxs = mxs < k ? k : mxs;
    root.maxsum = mxs;
    k = l.sum + r.prefix;
    root.prefix = l.prefix < k ? k : l.prefix;
    k = l.sufix + r.sum;
    root.sufix = r.sufix < k ? k : r.sufix;
}
void update(int node, int b, int e)
{
    if(x >= b && x <= e)
    {
        if(b == e)
            if(x == b)
            {
                stree[ node ].prefix = stree[ node ].sufix = stree[ node ].sum = stree[ node ].maxsum = in[ b ];
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
        if(b > y || e < x)
        {
            return ;
        }
        if(b >= x && e <= y)
        {
            marge(ans, ans, stree[ node ]);
            return ;
        }
        int left = node << 1, right = left + 1, mid = (b + e) >> 1;

        query(left, b, mid);
        query(right, mid + 1, e);
}

