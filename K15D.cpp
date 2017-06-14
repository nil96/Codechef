#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#define lli long long int
using namespace std;
lli prime_number[10002];
lli p1[10002];
lli n1;
lli find_prime_number()
{
    for(lli i=2;i<=10001;i++)
    {
       prime_number[i]=1;
    }
 
    prime_number[0]=0;
    prime_number[1]=0;
    for(lli i=2;i<=101;i++)
    {
       if(prime_number[i]==1)
       {
         for(lli j=i*i;j<=10001;j=j+i)
         {
           prime_number[j]=0;
        }
      }
   }
 
 
   lli j=0;
   for(lli i=2;i<=10001;i++)
   {
    if(prime_number[i]==1)
    {
      p1[j]=i;
      j++;
    }
   }
 
   n1=j;
   //printf("n1===%lld %lld\n",n1,p1[n1-1]);
}
lli oprtn(lli n)
{
 
  lli zum=n;
  lli latest=1;
  for(lli i=0;i<n1;i++)
  {
    if(n<p1[i])
      break;
    if(n%p1[i]==0)
    {
       latest=p1[i];
       while(n%p1[i]==0)
       {
         n=n/p1[i];
       }
    }
  }
  //printf("latest==%lld n==%lld\n",latest,n);
  latest=max(n,latest);
  return zum/latest;
}
int main()
{
  lli t;
  find_prime_number();
  scanf("%lld",&t);
  //getchar_unlocked();
  while(t--)
  {
     lli n;
     scanf("%lld",&n);
    // getchar_unlocked();
     lli ans=oprtn(n);
     printf("%lld\n",ans);
  }
  return 0;
}
 
 