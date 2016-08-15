#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

int main()
{
    char braket[ 2002 ];
    int len, i, tmp, kag = 0;
    stack < char > st;
    while( ~scanf("%s", braket) )
    {
        if(braket[ 0 ] == '-') break;
        while(!st.empty()) st.pop();
        len = strlen( braket ); tmp = 0;
        for(i = 0; i < len; i++)
        {
            if(braket[ i ] == '{')
            {
                st.push( braket[ i ] );
            }
            else if(braket[ i ] == '}')
            {
                if( !st.empty() )
                {
                    st.pop();
                }
                else
                {
                    st.push('{');
                    tmp++;
                }
            }
        }
        len = st.size();
        if( !len ) printf("%d. %d\n", ++kag, tmp);
        else printf("%d. %d\n", ++kag, len / 2 + tmp);
    }
    return 0;
}
