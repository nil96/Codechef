#include<stdio.h>
#include<stdlib.h>
char c[100005];
void intilise(char *c)
{
  long long int i;
  for(i=0;i<=100004;i++)
  {
    c[i]='0';
  }
}
void mark(long long int temp)
{
  if(c[temp]=='0')
  {
     c[temp]='1';
  }
}
long long int operation(long long int a)
{
  long long int i,count=0;
  for(i=1;i<=a;i++)
  {
    if(c[i]=='1')
     count++;
  }
  return count;
}
int main()
{
  long long int t,N,temp,l,ans;
  scanf("%lld",&t);
  while(t--)
  {
     intilise(c);
     scanf("%lld",&N);
     l=N;
     while(N--)
     {
       scanf("%lld",&temp);
       mark(temp);
     }
     ans=operation(l);
     printf("%lld\n",ans);
  }
}
 
Comments 
