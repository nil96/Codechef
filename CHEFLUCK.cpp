#include<stdio.h>
#include<stdlib.h>
#define lli long long int
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    lli n;
    scanf("%lld",&n);
    lli q=n/7;
    lli rem=n%7;
    lli flag=0;
    while(1)
    {
      if(rem%4==0)
      {
        printf("%lld\n",q*7);
        flag=1;
        break;
      }
      else
      {
        q=q-1;
        rem=n-7*q;
      }
      if(q<0)
        break;
    }
    if(flag==0)
     printf("-1\n");
  }
}