#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define lli long long int
#define gc() getchar_unlocked()
using namespace std;
lli arr[100000000];
lli fil(lli n,lli k,lli *temp,lli x)
{
   lli count1=0;
   lli y=0;
   if(x==0)
     y=1;
   for(lli i=0;i<n;i++)
   {
     if(i%2==0)
      temp[i]=x;
     else
      temp[i]=y;
   }
  /* printf("tempi\n   ");
   for(lli i=0;i<n;i++)
   {
      printf("%lld ",temp[i]);
   }
   printf("\narri\n");
   for(lli i=0;i<n;i++)
   {
      printf("%lld ",arr[i]);
   }*/
   for(lli i=0;i<n;i++)
   {
      if(arr[i]!=temp[i])
        count1++;
   }
   return count1;
}
lli flip(lli x)
{
  if(x==0)
    return 1;
  return 0;
}
void copy1(lli *arr,lli *temp,lli n)
{
  for(lli i=0;i<n;i++)
  {
    arr[i]=temp[i];
  }
}
 
lli fun1(lli n,lli k)
{
  lli temp[100005];
  lli temp1[100005];
  lli x0=fil(n,k,temp,0);
  //printf("x0===%lld ",x0);
  lli x1=fil(n,k,temp1,1);
  //printf("x1===%lld ",x1);
  if(x0<x1)
  {
     copy1(arr,temp,n);
     return x0;
  }
  else
  {
     copy1(arr,temp1,n);
     return x1;
  }
}
lli fun2(lli n,lli k)
{
  lli old_state=arr[0];
  lli x=k-1;
  lli count1=0;
  for(lli i=1;i<n;i++)
  {
     if(old_state==arr[i])
     {
       x--;
         if(x<0)
         {
             if(i+1<n)
             {
               if(arr[i]==arr[i+1])
               {
                  arr[i]=flip(arr[i]);
                  count1++;
                }
                else
                {
                    arr[i-1]=flip(arr[i-1]);
                    count1++;
                }
             }
             else if(i==n-1)
             {
                   arr[i]=flip(arr[i]);
                   count1++;
            }
            x=k-1;
            old_state=arr[i];
         }
     }
     else
     {
        old_state=arr[i];
        x=k-1;
     }
  }
  return count1;
}
 
 
int main()
{
  lli t;
  scanf("%lld",&t);
  gc();
  while(t--)
  {
     lli n,k;
     scanf("%lld%lld",&n,&k);
     gc();
     for(lli i=0;i<n;i++)
     {
       char x=gc();
       if(x=='0')
         arr[i]=0;
       else
         arr[i]=1;
     }
     lli ans=0;
     if(k==1)
     {
       ans=fun1(n,k);
     }
     else
     {
       ans=fun2(n,k);
     }
     printf("%lld\n",ans);
     for(lli i=0;i<n;i++)
     {
        printf("%lld",arr[i]);
     }
     printf("\n");
  }
  return 0;
}
 