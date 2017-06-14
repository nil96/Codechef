#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define lli long long int
using namespace std;
int main()
{
   lli arr[101];
   lli t;
   scanf("%lld",&t);
   while(t--)
   {
      lli n;
      scanf("%lld",&n);
      for(lli i=0;i<101;i++)
        arr[i]=0;
      for(lli i=0;i<n;i++)
      {
         lli z;
         scanf("%lld",&z);
         if(arr[z]==0)
           arr[z]++;
      }
      lli sum=0;
      for(lli i=0;i<101;i++)
        sum=sum+arr[i];
      printf("%lld\n",sum);
   }
   return 0;
}
 