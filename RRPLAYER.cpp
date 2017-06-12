#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define lli long long int
using namespace std;
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    lli n;
    scanf("%lld",&n);
    //printf("n===%lld\n",n);
    float ans=0.0f,x=5.0f;
    lli i;
    for(i=1;i<=n;i++)
    {
       x=1.0f/i;
      // printf("x==%f\n",x);
       ans=ans+x;
    }
    //printf("ans===%f\n",ans);
    float z=n*ans;
     printf("%.1f\n",z);
  }
  return 0;
}
 