#include <stdio.h>
int main()
{
    int h1, h2, m1, m2;
    while(~scanf("%d %d %d %d", &h1, &m1, &h2, &m2) && (h1 || h2 || m1 || m2))
    {
        int res = 0;
        if(h1 == h2 && m1 == m2)
        {
            puts("0");
            continue;
        }
        if(h1 == h2 && m1 < m2)
        {
            printf("%d\n", m2 - m1);
            continue;
        }
        else
        {
            res = 1, h1++;
            if(h1 == 24) h1 = 0;
        }
        while(h1 != h2)
        {
            res++; h1++;
            if(h1 == 24) h1 = 0;
        }
        //printf("  %d\n", res);
        res *= 60;
        if(m1 < m2) res += (m2 - m1);
        else res -= (m1 - m2);
        printf("%d\n", res);
    }

    return 0;
}

