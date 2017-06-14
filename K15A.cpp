#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#define lli long long int
using namespace std;
lli arr[10010];
lli oprtn(lli n)
{
  for(lli i=0;i<=1001;i++)
  {
    arr[i]=0;
  }
  lli temp,count1=0;
  for(lli i=0;i<n;i++)
  {
    scanf("%lld",&temp);
    arr[temp]++;
    if(arr[temp]==2)
    {
      count1++;
    }
  }
  return count1;
}
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    lli n;
    scanf("%lld",&n);
    lli ans=oprtn(n);
    printf("%lld\n",ans);
  }
  return 0;
}
 
Comments 
