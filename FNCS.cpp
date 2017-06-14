#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#define lli long long int
using namespace std;
lli input[100080];
lli sum_input[100080];
lli f[100080];
lli sum_f[100080];
struct range
{
  lli low;
  lli high;
};
struct range r[100080];
int main()
{
   lli t,i;
   scanf("%lld",&t);
   input[0]=0;
   t=t+1;
   for(i=1;i<t;i++)
     scanf("%lld",&input[i]);
   sum_input[0]=0;
   sum_input[1]=input[1];
   for(i=2;i<t;i++)
   {
     sum_input[i]=sum_input[i-1]+input[i];
   }
   for(i=1;i<t;i++)
   {
     scanf("%lld%lld",&r[i].low,&r[i].high);
   }
 
   f[0]=0;
   for(i=1;i<t;i++)
   {
     f[i]=sum_input[r[i].high]-sum_input[r[i].low-1];
   }
   sum_f[0]=0;
   sum_f[1]=f[1];
   for(i=2;i<t;i++)
   {
     sum_f[i]=sum_f[i-1]+f[i];
   }
   lli q;
   scanf("%lld",&q);
   while(q--)
   {
     lli flag,x,y;
     scanf("%lld%lld%lld",&flag,&x,&y);
     if(flag==2)
     {
        printf("%lld\n",sum_f[y]-sum_f[x-1]);
 
     }
     else
     {
        input[x]=y;
        sum_input[0]=0;
        sum_input[1]=input[1];
        for(i=2;i<t;i++)
        {
         sum_input[i]=sum_input[i-1]+input[i];
        }
       f[0]=0;
       for(i=1;i<t;i++)
       {
        f[i]=sum_input[r[i].high]-sum_input[r[i].low-1];
       }
       sum_f[0]=0;
       sum_f[1]=f[1];
       for(i=2;i<t;i++)
       {
          sum_f[i]=sum_f[i-1]+f[i];
       }
     }
   }
   return 0;
}
 