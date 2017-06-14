#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define lli long long int
#define f(i,n) for(lli i=0;i<n;i++)
using namespace std;
lli find1(lli x)
{
   lli index=1;
   lli z=1;
   while(x-z>=0)
   {
     x=x-z;
     index++;
     z++;
   }
   return index;
}
int main()
{
  lli t;
  cin>>t;
  while(t--)
  {
    lli n,s;
    cin>>n>>s;
    lli ans=find1(s-n);
    printf("%lld\n",n-ans);
  }
}
 