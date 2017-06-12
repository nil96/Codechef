#include<stdio.h>
#include<stdlib.h>
char c[1000005];
void operation()
{
  long long int i,ans,ans1;
  long long int k=1000000;
  int num=103993,num1=33102;
  for(i=0;i<=k;i++)
  {
    ans=num/num1;
    num=num%num1;
    num=num*10;
    c[i]=(char)(ans+'0');
    while(num<num1)
    {
      num=num*10;
      c[++i]='0';
    }
  }
}
void print(long long int l)
{
  long long int i;
  for(i=1;i<=l;i++)
  {
    printf("%c",c[i]);
  }
}
int main()
{
   int t;
   long long int N;
   scanf("%d",&t);
   operation();
   while(t--)
   {
      scanf("%lld",&N);
      if(N==0)
      {
        printf("3\n");
        continue;
      }
      else
      {
        printf("3.");
        print(N);
      }
      printf("\n");
   }
}