#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define lli long long int
using namespace std;
int main()
{
   lli t;
   scanf("%lld",&t);
   while(t--)
   {
     lli n,psize;
     scanf("%lld%lld",&n,&psize);
     lli carry=0,ans=0,x=0,lans=0;
     lli req;
     for(lli i=0;i<n;i++)
     {
       scanf("%lld",&req);lans=0;
       if(carry<0)
        carry=0;
       if(carry>=req)
        carry=carry-req;
       else
       {
         lli z=req/psize;
         if((z-1)*psize+carry>=req)
         {
            lans=z-1;
         }
         else if(z*psize+carry>=req)
         {
           lans=z;
         }
         else if((z+1)*psize+carry>=req)
         {
           lans=z+1;
         }
         carry=lans*psize+carry-req;
       }
       //printf("lans==%lld\n",lans);
       ans=ans+lans;
       carry=carry-1;
       lans=0;
     }
     printf("%lld\n",ans);
   }
}
 