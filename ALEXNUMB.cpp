#include<stdio.h>
#include<stdlib.h>
int main()
{
  int t;
  scanf("%d",&t);
  long long unsigned int a,b,n,ans;
  while(t--)
  {
     scanf("%llu",&a);
     n=a;
     while(a--)
     {
        scanf("%llu",&b);
     }
     ans=n*(n-1);
     ans=ans/2;
     printf("%llu\n",ans);
  }
  return 0;
}