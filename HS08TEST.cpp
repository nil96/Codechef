#include<stdio.h>
#include<stdlib.h>
#define lli long long int
int main()
{
  lli out;
  float amount;
  scanf("%lld%f",&out,&amount);
  if((out%5)!=0)
    printf("%.2f\n",amount);
  else if(amount-out-0.5<0)
    printf("%.2f\n",amount);
  else
  {
    amount=amount-out-0.5;
    printf("%.2f\n",amount);
  }
  return 0;
}