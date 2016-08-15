#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stack>
#include <iostream>
using namespace std;
int main()
{
    char expration[ 405 ], ch;
    stack <char> st;
    int T, i, len;
    scanf("%d", &T); getchar();
    while( T-- )
    {
        gets( expration );
        len = strlen( expration );
        while( !st.empty() ) st.pop();
        for(i = 0; i < len; i++)
        {
            if(expration[ i ] == '(') st.push( expration[ i ] );
            else if(expration[ i ] == ')')
            {
                ch = st.top();
                while( !st.empty() && ch != '(' )
                {
                    printf("%c", ch);
                    st.pop();
                    ch = st.top();
                }
                st.pop();
            }
            else if(islower(expration[ i ]))printf("%c", expration[ i ]);
            else st.push(expration[ i ]);
        }
        puts("");
    }
    return 0;
}

