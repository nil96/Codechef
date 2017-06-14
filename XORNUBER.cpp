#include<bits/stdc++.h>
#define lli long long int
using namespace std;
lli arr[1000000];
lli check(lli n)
{
   lli flag=0;
   for(lli i=0;i<=30;i++)
   {
     if(arr[i]==0)
       flag=1;
     if(flag==1 && arr[i]==1)
       return -1;
   }
   return 1;
}
lli convertor(lli n)
{
   lli z;
   if(n==1)
     return 2;
   for(lli i=0;i<=30;i++)
   {
      z=1<<i;
      lli x=z&n;
      if(x!=0)
        arr[i]=1;
      else
        arr[i]=0;
    }
    lli x=check(n);
    lli i;
    for(i=0;i<=30;i++)
    {
      if(arr[i]==0)
        break;
    }
    arr[i-1]=0;
    if(x==-1)
     return -1;
    lli no=0;
    lli x1=1;
    for(lli i=0;i<=30;i++)
    {
       no=no+x1*arr[i];
       x1=x1*2;
    }
    return no;
}
int main()
{
   lli t;
   scanf("%lld",&t);
   while(t--)
   {
      lli n;
      scanf("%lld",&n);
      lli z=convertor(n);
      printf("%lld\n",z);
 
   }
}
 