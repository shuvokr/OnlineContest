#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    char number[ 1000000 ];
    int i, len, test, res;
    scanf("%d", &test); getchar();
    while( test-- )
    {
        gets( number );
        res = 0; len = strlen( number );
        for(i = 0; i < len; i++)
        {
            res += number[ i ] == '1' ? 2 :
                number[ i ] == '2' || number[ i ] == '3' || number[ i ] == '5' ? 5 :
                    number[ i ] == '4' ? 4 :
                        number[ i ] == '6' || number[ i ] == '9' || number[ i ] == '0' ? 6 :
                            number[ i ] == '7' ? 3 : 7;
        }
        printf("%d leds\n", res);
    }
    return 0;
}
