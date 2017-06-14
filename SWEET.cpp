#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define lli long long int
using namespace std;
vector<lli> v;
lli oprtn(lli n)
{
  lli curr_max=0;
  lli max1=0;
  for(lli i=0;i<n;i++)
  {
    curr_max=curr_max+v[i];
    if(curr_max<0)
      curr_max=0;
    if(max1<curr_max)
    {
      max1=curr_max;
    }
  }
  return max1;
}
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    v.clear();
    lli n,x;
    scanf("%lld%lld",&n,&x);
    for(lli i=0;i<n;i++)
    {
      lli temp;
      scanf("%lld",&temp);
      v.push_back(temp-x);
    }
    lli ans=oprtn(n);
    printf("%lld\n",ans);
  }
  return 0;
}
 
Comments 
