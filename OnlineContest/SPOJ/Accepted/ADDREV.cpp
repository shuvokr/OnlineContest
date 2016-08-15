#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char m[202] = {0},n[202] = {0};
        scanf("%s%s",m,n);

        int i,lenm,r,lenn,cry=0,k,len,kk,j,res;
        int c[2000];
        lenm=strlen(m);
        lenn=strlen(n);
        if(lenm >= lenn)
        {
            cry = 0;
            for(i=0; i<lenn; i++)
            {
                int a = m[i] - 48, b = n[i] - 48;
                k = a + b + cry;
                len = log10(k);
                if(len == 0)
                {
                    c[i] = k;
                    cry = 0;
                }
                else
                {
                    c[i] = k % 10;
                    cry = k / 10;
                }
            }
            k = 0;
            for(i = lenn; i < lenm; i++)
            {
                k = (m[i] - 48) + cry;
                len = log10(k);
                if(len == 0)
                {
                    c[i] = k;
                    cry = 0;
                }
                else
                {
                    c[i] = k % 10;
                    cry = k / 10;
                }
            }
            int count = 0;
            for(i = 0; i < lenm; i++)
            {
                if(c[i] == 0)
                    count++;
                else break;
            }
            for(i = count; i < lenm; i++)
                printf("%d",c[i]);
            if(cry != 0)
                printf("%d",cry);
            printf("\n");
        }
        else
        {
            cry = 0;
            for(i=0; i<lenm; i++)
            {
                int a = n[i] - 48, b = m[i] - 48;
                k = a + b + cry;
                len = log10(k);
                if(len == 0)
                {
                    c[i] = k;
                    cry = 0;
                }
                else
                {
                    c[i] = k % 10;
                    cry = k / 10;
                }
            }
            k = 0;
            for(i = lenm; i < lenn; i++)
            {
                k = (n[i] - 48) + cry;
                len = log10(k);
                if(len == 0)
                {
                    c[i] = k;
                    cry = 0;
                }
                else
                {
                    c[i] = k % 10;
                    cry = k / 10;
                }
            }
            int count = 0;
            for(i = 0; i < lenn; i++)
            {
                if(c[i] == 0)
                    count++;
                else break;
            }
            for(i = count; i < lenn; i++)
                printf("%d",c[i]);
            if(cry != 0)
                printf("%d",cry);
            printf("\n");
        }
    }
    return 0;
}

