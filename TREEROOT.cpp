#include<stdio.h>
#include<stdlib.h>
#define lli long long int
struct node
{
  lli a;
  lli b;
};
struct node n[10000];
int main()
{
  lli t,N,n1;
  scanf("%lld",&t);
  while(t--)
  {
    scanf("%lld",&N);
    lli i=0;
    n1=N;
    while(N--)
    {
      scanf("%lld%lld",&n[i].a,&n[i].b);
      i++;
    }
    N=n1;
   // for(i=0;i<N;i++)
   //  printf("(%lld,%lld)\n",n[i].a,n[i].b);
    lli count=0,l;
    i=0;
    while(i<N)
    {
      l=(n[i].a-n[i].b);
    //  printf("l===%lld\n",l);
      count=count+l;
      i++;
    }
    printf("%lld\n",count);
  }
}