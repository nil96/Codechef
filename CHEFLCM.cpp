#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define lli long long int
using namespace std;
lli prime[100011];
vector<lli> v;
lli prime_number()
{
   for(lli i=0;i<=100010;i++)
   {
     prime[i]=1;
   }
   prime[1]=prime[0]=0;
   for(lli i=2;i<=320;i++)
   {
     if(prime[i]==1)
     {
       for(lli j=i*i;j<=100000;j=j+i)
       {
         prime[j]=0;
       }
     }
   }
   v.clear();
   for(lli i=0;i<=100000;i++)
   {
      if(prime[i]==1)
      {
         v.push_back(i);
      }
   }
}
 
int main()
{
  prime_number();
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
     lli n,i=0,sum=1;
     scanf("%lld",&n);
     if(n==1)
     {
       printf("1\n");
       continue;
     }
 
 
 
     while(i<v.size())
     {
        if(n%v[i]==0)
        {
           lli x=v[i];
           lli m=1;
           while(n%x==0)
           {
             n=n/x;
             m=x*m;
           }
           lli x1=(m*x-1)/(x-1);
           sum=sum*x1;
           //printf("x1==%lld\n",x1);
        }
        i++;
     }
     if(n>1)
     {
       n=(n*n-1)/(n-1);
       sum=sum*n;
     }
     printf("%lld\n",sum);
  }
  return 0;
}
 