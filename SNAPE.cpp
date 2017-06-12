#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
  float b,ls,mzx,min,max;
  int t;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%f",&b);
    scanf("%f",&ls);
    max=sqrt(b*b+ls*ls);
    min=sqrt(ls*ls-b*b);
    printf("%f %f\n",min,max);
  }
  return 0;
}