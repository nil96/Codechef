#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define lli long long int
vector<lli> v;
bool cmp(lli i,lli j)
{
  return i<j;
}
lli fsum(lli i,lli j)
{
  if(i>j)
    return 0;
  lli n=j-i+1;
  lli sum=(n*(2*i+(n-1)))/2;
  return sum;
}
int main()
{
  lli t,temp,i;
  scanf("%lld",&t);
  while(t--)
  {
    v.clear();
    lli n,k;
    scanf("%lld%lld",&n,&k);
    v.push_back(n+1);
    for(i=0;i<k;i++)
    {
      scanf("%lld",&temp);
      v.push_back(temp);
    }
    sort(v.begin(),v.end(),cmp);
    lli sum=fsum(1,v[0]-1);
    for(i=0;i<v.size()-1;i++)
    {
      if(v[i]>sum)
      {
         break;
      }
      else
      {
       // if(v[i+1]-v[i]>1)
          sum=sum+fsum(v[i]+1,v[i+1]-1);
      }
    }
    sum=sum+1;
    if(sum%2==0)
      printf("Mom\n");
    else
      printf("Chef\n");
  }
  return 0;
}
 
Submission Info: