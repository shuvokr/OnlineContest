#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;
#define pb push_back
void input();
void prime();
int countDivisor(int n);
bool isok(int n);

const int MAX = 1000001;
int prlim;
bool mark[ MAX ];
vector <int> primes;

int main()
{
    prime();
    input();

    return 0;
}
void input()
{
    int cou = 0, dv;
    for(int i = 1; i < MAX; i++)
    {
        dv = countDivisor( i );
        if(isok( dv )) cou++;
        if(cou == 9) cou = 0, printf("%d\n", i);
    }
}
void prime()
{
    mark[ 0 ] = mark[ 1 ] = false; mark[ 2 ] = true;
    for(int i = 4; i < MAX; i += 2) mark[ i ] = false;
    for(int i = 3; i < MAX; i += 2) mark[ i ] = true;
    int srt = sqrt( MAX ) + 1;
    for(int i = 3; i < srt; i += 2)
        if(mark[ i ])
            for(int j = i << 1; j < MAX; j += i) mark[ j ] = false;
    primes.pb( 2 );
    for(int i = 3; i < MAX; i += 2)
        if(mark[ i ]) primes.pb( i );
    prlim = primes.size();
}
int countDivisor(int n)
{
    if(mark[ n ]) return 2;
    int divisor = 1, sr = sqrt( n ) + 1;
    for (int i = 0; i < sr; i++)
    {
        if (n % primes[i] == 0)
        {
            int cnt = 1;
            while (n % primes[i] == 0)
            {
                n /= primes[i];
                cnt++;
            }
            divisor *= cnt;
        }
        if(mark[ n ]) divisor *= 2, i = prlim;
    }
    return divisor;
}
bool isok(int n)
{
    int srt = sqrt( n ) + 1;
    for(int i = 0; primes[ i ] < srt; i++)
    {
        if(n % primes[ i ] == 0)
        {
            if(n / primes[ i ] != primes[ i ])
            if(mark[n / primes[ i ]]) return true;
            else return false;
        }
    }
    return false;
}
