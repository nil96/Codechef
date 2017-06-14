#include<stdio.h>
#define lli long long int
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    lli n,i;
    scanf("%lld",&n);
    lli flag=2*n;
    lli sum=0;
    lli min=1000000000000;
    for(i=0;i<n;i++)
    {
       lli temp;
       scanf("%lld",&temp);
       if(temp<min)
         min=temp;
       sum=sum+temp;
       if(temp<2)
        flag=-1;
    }
    if(flag==-1)
     printf("%lld\n",flag);
    else
    {
       sum=sum-min+2;
       printf("%lld\n",sum);
    }
  }
  return 0;
}
 