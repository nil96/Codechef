
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define lli long long int
using namespace std;
vector<lli> v;
vector<lli> fac;
void learn(lli m)
{
  fac.clear();
  fac.resize(m+10);
  fac[0]=1;
  for(lli i=1;i<=m+3;i++)
  {
    fac[i]=(fac[i-1]*i)%m;
  }
}
lli cal_fac(lli temp,lli m)
{
  if(temp+1>=m)
  {
  //  printf
    return 0;
  }
  else
    return fac[temp+1];
}
lli bumbae(lli temp,lli m)
{
  lli temp1;
  if(temp%2==0)
  {
    lli z1=(temp/2)%m;
    lli z2=temp%m;
    lli z3=(temp+1)%m;
    temp1= ( (z1*z2)%m ) *z3;
  }
  else
  {
    lli z1=(temp+1)/2;
    z1=z1%m;
    lli z2=temp%m;
    temp1=( (z2*z2)%m )*(z1);
  }
  return temp1%m;
}
int main()
{
  lli n,m,temp;
  cin>>n>>m;
  learn(m);
  lli ans=0,factr1,factr2;
  for(lli i=0;i<n;i++)
  {
    cin>>temp;
    factr1=cal_fac(temp,m);
    factr2=bumbae(temp,m);
 //   printf("%lld %lld f[%lld]==%lld\n",factr1,factr2,i+1,factr1+factr2-1);
    ans=(ans+factr1+factr2-1)%m;
  }
  printf("%lld\n",ans);
  return 0;
}