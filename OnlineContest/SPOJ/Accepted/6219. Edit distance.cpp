#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp(int pos, int mk);

char mke[ 2010 ], in[ 2010 ], fs[ 2010 ], sn[ 2010 ];
int p, len, ln, l, memo[ 2010 ][ 2010 ];

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%s %s", fs, sn);
        len = strlen( sn );
        ln = strlen( fs );
        l = len < ln ? ln : len;
        memset(memo, -1, sizeof memo);
        printf("%d\n", dp( 0, 0 ));
        //for(int i = 0; i < ); i++) printf("%d ", res[ i ]); puts("");
    }
    return 0;
}
int dp(int pos, int mk)
{
    if( mk == l && pos == l) return 0;
    if(pos == l || mk == l) return 1 << 29;
    if(memo[ pos ][ mk ] != -1) return memo[ pos ][ mk ];
    int a, b, c;
    a = 1 + dp(pos + 1, mk + 1); // change
    b = 1 + dp(pos, mk + 1); // insert
    c = 1 + dp(pos + 1, mk); // Delet
    if(fs[ pos ] == sn[ mk ]) return dp(pos + 1, mk + 1);
    return memo[ pos ][ mk ] = min(a, min(b, c));
}

