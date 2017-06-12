#include<stdio.h>
#include<stdlib.h>
int main()
{
  long long signed int t,N,C,Q,L,R,dis;
  scanf("%lld",&t);
  while(t--)
  {
    scanf("%lld",&N);
    scanf("%lld",&C);
    scanf("%lld",&Q);
    while(Q--)
    {
      scanf("%lld",&L);
      scanf("%lld",&R);
      if(C<=R && C>=L)
      C=R+L-C;
    }
    printf("%lld\n",C);
  }
}
 