#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define lli long long int
#define mod 1000000007
using namespace std;
vector<lli> v;
vector<lli> v1;
lli arr[100006];
bool cmp(lli x,lli y)
{
  return x<y;
}
void calculate_power()
{
   arr[0]=1;
   for(lli i=1;i<100002;i++)
   {
     arr[i]=(arr[i-1]*2)%mod;
   }
}
int main()
{
   lli t;
   scanf("%lld",&t);
   calculate_power();
   while(t--)
   {
      lli n;
      v.clear();v1.clear();
      scanf("%lld",&n);
      for(lli i=0;i<n;i++)
      {
         lli temp;
         scanf("%lld",&temp);
         v.push_back(temp);
      }
      sort(v.begin(),v.end(),cmp);
      for(lli i=n-1;i>=0;i--)
      {
        v1.push_back(v[i]);
      }
      lli sum=0,j;
      for(lli i=0,j=n-1;i<n;i++,j--)
      {
         lli x=((v1[i]-v[i]+mod)*(arr[j]))%mod;
         sum=(sum+x)%mod;
      }
      printf("%lld\n",sum%mod);
   }
   return 0;
}