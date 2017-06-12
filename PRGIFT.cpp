#include<stdio.h>
#include<stdlib.h>
int main()
{
long long signed int t,n,k,count=0,i;
long long signed int a;
scanf("%lld",&t);
while(t--)
{
count=0;
scanf("%lld",&n);
scanf("%lld",&k);
for(i=0;i<n;i++)
{
scanf("%lld",&a);
if(a%2==0)
count++;
}
if(k==0)
{
  if(count==n)
  {
    printf("NO\n");
  }
  else
  {
    printf("YES\n");
  }
}
else
{
if(count>=k)
printf("YES\n");
else
printf("NO\n");
}
}
}