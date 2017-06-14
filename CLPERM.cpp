#include<stdio.h>
#include<stdlib.h>
#define lli long long int
int main()
{
  lli t,i;
  scanf("%lld",&t);
  while(t--)
  {
    lli n,k;
    scanf("%lld%lld",&n,&k);
    lli val=(n*n+n)/2;
    lli sum=0,temp;
    for(i=0;i<k;i++)
    {
       scanf("%lld",&temp);
       sum=sum+temp;
    }
    //printf("z===%lld\n",val-sum);
    if((val-sum)%2==0)
    {
      printf("Chef\n");
    }
    else
    {
      printf("Mom\n");
    }
  }
  return 0;
}
 