#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#define lli long long int
#define greater 1
#define lesser 0
using namespace std;
struct node
{
  lli x;
  lli y;
};
struct node arr[1000000];
lli matrix[510][510];
lli mod(lli x)
{
  if(x<0)
    return -x;
  return x;
}
 
lli fun(lli x)
{
  lli k=0;
  for(lli i=0;i<x;i++)
  {
    for(lli j=0;j<x;j++)
    {
       arr[matrix[i][j]].x=i;
       arr[matrix[i][j]].y=j;
    }
  }
  lli sum=0;
  for(lli i=1,j=i+1;j<=x*x;i++,j++)
  {
    sum=sum+mod(arr[i].x-arr[j].x)+mod(arr[i].y-arr[j].y);
  }
  return sum;
}
 
int main() 
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    lli n;
    scanf("%lld",&n);
    for(lli i=0;i<n;i++)
    {
      for(lli j=0;j<n;j++)
      {
        scanf("%lld",&matrix[i][j]);
      }
    }
    lli sum=fun(n);
    printf("%lld\n",sum);
  }
} 