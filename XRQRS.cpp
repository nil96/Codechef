#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define lli long long int
using namespace std;
vector<lli> v;
void fun0()
{
  lli x;
  scanf("%lld",&x);
  v.push_back(x);
}
void fun1()
{
  lli l,r,x;
  scanf("%lld%lld%lld",&l,&r,&x);
  l--;
  r--;
  lli max1=-2000,temp,learn;
   //for(lli i=l;i<=r;i++)
     // printf("v=%lld\n",v[i]);
  for(lli i=l;i<=r;i++)
  {
    temp=v[i]^x;
    if(temp>max1)
    {
       max1=temp;
       learn=v[i];
    }
  }
  printf("%lld\n",learn);
}
void fun2()
{
  vector<lli> :: iterator p=v.end();
  lli x;
  scanf("%lld",&x);
  v.erase(p-x,p);
}
void fun3()
{
  lli l,r,x;
  scanf("%lld%lld%lld",&l,&r,&x);
  l--;
  r--;
  lli count1=0;
  for(lli i=l;i<=r;i++)
  {
    if(v[i]<=x)
      count1++;
  }
  printf("%lld\n",count1);
}
void fun4()
{
  vector<lli> temp;
    lli l,r,x;
  scanf("%lld%lld%lld",&l,&r,&x);
  l--;
  r--;
  vector<lli> :: iterator it;
  it=v.begin();
  for(lli i=l;i<=r;i++)
    temp.push_back(v[i]);
  sort(temp.begin(),temp.end());
  printf("%lld\n",temp[x-1]);
}
int main()
{
  lli m;
  v.clear();
  scanf("%lld",&m);
  lli flag;
  lli x;
  while(m--)
  {
    scanf("%lld",&flag);
    switch(flag)
    {
      case 0:
             fun0();
             break;
      case 1:
             fun1();
             break;
      case 2:
             fun2();
             break;
      case 3:
             fun3();
             break;
      case 4:
             fun4();
             break;
    }
  }
}