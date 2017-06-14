#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#define lli long long int
using namespace std;
lli cosx[100];
void calculate_root()
{
   cosx[0]=2;
   for(lli i=1;i<=51;i++)
   {
      cosx[i]=cosx[i-1]*2;
   }
}
lli s_arr[100];
lli c_arr[100];
void my_memset()
{
   for(lli i=0;i<=52;i++)
   {
     s_arr[i]=0;
     c_arr[i]=0;
   }
}
int main()
{
  lli t;
  scanf("%lld",&t);
  calculate_root();
  while(t--)
  {
     lli s,c,k;
     scanf("%lld%lld%lld",&s,&c,&k);
     lli count1=1;
     my_memset();
     for(lli i=s-2;i>=0;i--)
     {
        s_arr[i]=count1;
        count1++;
     }
     for(lli i=0;i<c;i++)
     {
         c_arr[i]=1;
     }
     lli sum=0;
     for(lli i=0;i<=50;i++)
     {
        if(s_arr[i]+c_arr[i]>=k)
        {
           sum=sum+cosx[i];
        }
     }
     if(s>=k)
     sum=sum+3;
     printf("%lld\n",sum);
 
  }
  return 0;
}
 