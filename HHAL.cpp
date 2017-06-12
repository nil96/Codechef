#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define li long int
char a[100050];
int check_pal(char *c)
{
  li a;
  a=strlen(c);
  li i=0,j=a-1;
  while(i<=j)
  {
    if(c[i]!=c[j])
    {
     return 2;
    }
    i++;
    j--;
  }
  return 1;
}
int main()
{
  li t;
  scanf("%ld",&t);
  while(t--)
  {
    scanf("%s",a);
    int ans=check_pal(a);
    printf("%d\n",ans);
  }
  return 0;
}