#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define lli long long int
#define gc() getchar_unlocked()
#include<string.h>
using namespace std;
char arr[500];
lli get()
{
  lli n=strlen(arr);
  lli count1=0;
  for(lli i=0;i<n;i++)
  {
    if(arr[i]=='T')
      count1=count1+2;
    else
      count1++;
  }
  return count1;
}
lli get1(lli l,lli z)
{
   lli m=l/z;
   if(m*z<=l)
    return m;
   return m-1;
}
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    gc();
    scanf("%s",arr);
    lli z=get();
    lli x;
    scanf("%lld",&x);
    lli n=get1(12*x,z);
    lli ans=12*x*n-((n*(n+1))/2)*z;
    printf("%lld\n",ans);
  }
  return 0;
}