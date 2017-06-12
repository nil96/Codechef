#include<stdio.h>
#include<stdlib.h>
#define lli long long int
int main()
{
  lli n,x;
  scanf("%lld",&n);
  lli count1=0,count2=-2;
  while(n--)
  {
    scanf("%lld",&x);
    if(x!=0)
    {
      count1++;
    }
    else if(x==0)
    {
       if(count2<count1)
         count2=count1;
      count1=0;
    }
  }
   if(count2<count1)
      count2=count1;
  printf("%lld\n",count2);
  return 0;
}
 