#include<stdio.h>
#include<stdlib.h>
#define lli long long int
lli arr[100];
lli hash[1000010];
lli min(lli a,lli b)
{
  if(a<b)
   return a;
  return b;
}
int main()
{
  lli n,i,j;
  scanf("%lld",&n);
  for(i=0;i<n;i++)
  {
    scanf("%lld",&arr[i]);
  }
  for(i=0;i<=1000000;i++)
   hash[i]=0;
 
  for(i=0;i<n;i++)
  {
    lli y=arr[i];
    for(j=i;j<n;j++)
    {
      y=min(arr[j],y);
      hash[y]++;
    }
  }
  lli q;
  scanf("%lld",&q);
  lli z;
  while(q--)
  {
    scanf("%lld",&z);
    printf("%lld\n",hash[z]);
  }
  return 0;
}