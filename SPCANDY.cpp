#include<stdio.h>
#include<stdlib.h>
int main()
{
  long long int t;
  long long int N,K,div,rem;
  scanf("%lld",&t);
  while(t--)
  {
    scanf("%lld",&N);
    scanf("%lld",&K);
    if(K!=0 && N!=0)
    {
     div=N/K;
     rem=N%K;
    printf("%lld ",div);
    printf("%lld\n",rem);
    }
    else if(N==0)
    {
      printf("0 ");
      printf("0\n");
    }
    else if(N!=0 && K==0)
    {
      printf("0 ");
      printf("%lld\n",N);
    }
  }
  return 0;
}
 