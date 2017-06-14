#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define lli long long int
using namespace std;
char arr[10000];
lli fun()
{
   lli l=strlen(arr);
   char x=arr[0];
   char y=arr[1];
    if(x==y)
      return 0;
   for(lli i=2;i<l;i++)
   {
      if(i%2==0)
      {
         if(x!=arr[i])
           return 0;
      }
      else
      {
           if(y!=arr[i])
           return 0;
      }
   }
   return 1;
}
int main()
{
   lli t;
   scanf("%lld",&t);
   getchar_unlocked();
   while(t--)
   {
       scanf("%s",arr);
       getchar_unlocked();
       lli z=fun();
       if(z==1)
         printf("YES\n");
       else
         printf("NO\n");
   }
   return 0;
}