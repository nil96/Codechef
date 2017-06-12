#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define lli long long int
lli b[100000];
lli check(lli a)
{
  char buffer[15];
  sprintf(buffer,"%lld",a);
  int i=-1;
  while(buffer[i]!='\0')
  {
    i++;
    if(buffer[i]=='2' || buffer[i]=='3' || buffer[i]=='5' ||
      buffer[i]=='6' || buffer[i]=='7' || buffer[i]=='8')
       return 0;
  }
  //printf("%s\n",buffer);
  return 1;
}
 
 
lli calculate()
{
  lli i,l,m=0,k;
  for(i=1;i<=100000;i++)
  {
    k=i*i;
    l=check(k);
    if(l==0)
     continue;
    else
    {
      b[++m]=k;
    }
  }
  return m;
}
 
lli answer(lli n1,lli n2,lli m)
{
  lli i=0,count=0;
  while(1)
  {
    if(b[i]>=n1 && b[i]<=n2)
      count++;
      i++;
    if(b[i]>n2)
     break;
    if(i>m)
     break;
  }
  return count;
}
void intilize()
{
  lli i;
  for(i=0;i<=100000;i++)
   b[i]=3;
}
int main()
{
  lli t,n1,n2,m,n;
  scanf("%lld",&t);
  m=calculate();
  //printf("m========%lld",m);
  while(t--)
  {
    scanf("%lld%lld",&n1,&n2);
    n=answer(n1,n2,m);
    printf("%lld\n",n);
  }
}
 