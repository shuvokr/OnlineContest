/*************************************Templet start*************************************/
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
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define long long lld
#define llu unsigned long long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n, v) memset(n, v, sizeof( n ))
#define eps 1e-8
#define INF 5000
#define pb push_back
#define maxn 200+2

#define white 0
#define black 1

typedef pair<int, int> pii;
typedef  vector<int> vi;
typedef vector<pii> vii;


int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

/********************************Templet end********************************************/
void input();

char grid[ 22 ][ 22 ];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tmp, T, kag = 0, c, r, N, i, j, row, col, counter;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &N); getchar();
        for(i = 0; i < N; i++) gets( grid[ i ] );
        for(i = 0; i < N; i++)
            for(j = 0; j < N; j++)
                if(grid[ i ][ j ] == '#') r = i, c = j, i = j = N;
        col = 0; tmp = c;
        while(grid[ r ][ c ] == '#' && c < N) c++, col++;
        row = 1; r++;
        for(i = r; i < N; i++)
        {
            counter = 0; j = tmp;
            while(grid[ i ][ j ] == '#' && j < N) j++, counter++;
            (counter != col) ? i = N : row++;
        }
        printf("Case #%d: ", ++kag);
        if(row != col) puts("NO");
        else
        {
            counter = 0; tmp = row * col;
            for(i = 0; i < N; i++)
                for(j = 0; j < N; j++)
                    if(grid[ i ][ j ] == '#') counter++;
            puts(counter == tmp ? "YES" : "NO");
        }
    }
    return 0;
}
