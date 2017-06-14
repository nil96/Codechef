#include<bits/stdc++.h>
#define lli long long int
using namespace std;
char arr[1000000];
int main()
{
    lli t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%s",&arr);
        lli l=strlen(arr);
        lli count0=0,count1=0;
        for(lli i=0;i<l;i++)
        {
            if(arr[i]=='1')
                 count1++;
            else
                count0++;
        }
        if(count1==1 || count0==1)
            printf("Yes\n");
        else
            printf("No\n");
 
    }
}
 