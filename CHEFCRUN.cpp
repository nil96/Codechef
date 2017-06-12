#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli arr[1000040];
int main()
{
    lli t;
    scanf("%lld",&t);
    while(t--)
    {
        lli n;
        scanf("%lld",&n);
        for(lli i=1;i<=n;i++)
        {
          scanf("%lld",&arr[i]);
        }
        lli s,e;
        scanf("%lld%lld",&s,&e);
        lli sumc=0,suma=0,curr=0,mc=0,ma=0;
        for(lli i=s;i<e;i++)
        {
           curr=max(arr[i],curr+arr[i]);
           mc=max(curr,mc);
           sumc=sumc+arr[i];
        }
        curr=0;
        for(lli i=e;i<=n;i++)
        {
           curr=max(arr[i],arr[i]+curr);
           ma=max(curr,ma);
           suma=suma+arr[i];
        }
        for(lli i=1;i<s;i++)
        {
           curr=max(arr[i],arr[i]+curr);
           ma=max(curr,ma);
           suma=suma+arr[i];
 
        }
        //printf("sumc==%lld mc==%lld\n",sumc,mc);
        //printf("suma==%lld  ma==%lld\n",suma,ma);
        lli ans=min(suma+2*(sumc-mc),sumc+2*(suma-ma));
        printf("%lld\n",ans);
    }
}