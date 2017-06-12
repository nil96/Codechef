#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define lli long long int
using namespace std;
lli arr[1000009];
lli par[1000009];
lli sum[1000009];
int main()
{
   lli t;
   scanf("%lld",&t);
   while(t--)
   {
   	 lli n,h;
     scanf("%lld%lld",&n,&h);
     for(lli i=0;i<=n;i++)
     {
     	arr[i]=n;
     	par[i]=0;
     }
     for(lli i=0;i<n;i++)
     {
     	lli x,y;
     	scanf("%lld%lld",&x,&y);
     	par[x]=par[x]-1;
     	par[y+1]=par[y+1]+1;
     }
     for(lli i=1;i<n;i++)
     {
         par[i]=par[i]+par[i-1];
     }
     for(lli i=0;i<n;i++)
     {
     	arr[i]=arr[i]+par[i];
     }
    // for(lli i=0;i<n;i++)
     //{
     //	printf("%lld ",arr[i]);
    // }
     sum[0]=arr[0];
     for(lli i=1;i<n;i++)
     {
        sum[i]=sum[i-1]+arr[i];
     }
     lli max1=sum[h-1];
     for(lli i=1,j=h;i<n && j<n;i++,j++)
     {
        lli z=sum[j]-sum[i-1];
        if(z<max1)
          max1=z;
     }
     printf("%lld\n",max1);
   }
   return 0;
}
 