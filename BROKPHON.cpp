#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define lli long long int
using namespace std;
lli arr[1000000];
int main()
{
   lli t;
   scanf("%lld",&t);
   while(t--)
   {
     lli n;
     scanf("%lld",&n);
     for(lli i=0;i<n;i++)
     {
       scanf("%lld",&arr[i]);
     }
     lli m=0;
     for(lli i=1;i<n-1;i++)
     {
       if(arr[i]!=arr[i+1])
       {
         if(arr[i]==arr[i-1])
           m=m+2;
         else
           m=m+1;
       }
     }
     //printf("m========%lld\n",m);
     m=m+2*(arr[0]!=arr[1]);
     printf("%lld\n",m);
   }
}