#include<stdio.h>
#include<stdlib.h>
#define lli long long int
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    lli x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld\n",x+y-1);
  }
  return 0;
}
 