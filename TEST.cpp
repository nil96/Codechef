#include<stdio.h>
#include<stdlib.h>
int main()
{
  int num;
  scanf("%d",&num);
  while(num!=42)
  {
    printf("%d\n",num);
    scanf("%d",&num);
  }
}
 