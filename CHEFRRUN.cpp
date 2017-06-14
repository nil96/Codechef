#include<bits/stdc++.h>
using namespace std;
#define lli long long int
struct node
{
   lli data,chain,vis;
};
struct node arr[2000000];
lli cum_mag(lli ind,lli n,lli nx)
{
  lli i=ind;
  lli x=0;
  lli prev=ind;
  while(arr[i].vis==-1)
  {
     //printf("%lld(%lld)  ",i,nx);
     arr[i].vis=nx;
     arr[i].chain=x++;
     prev=i;
     i=(i+arr[i].data+1)%n;
  }
  //printf("\n");
  if(arr[i].vis!=arr[prev].vis)
   return 0;
  return abs(arr[i].chain-arr[prev].chain)+1;
}
 
lli oprtn(lli n)
{
  lli x=0;
  lli nx=0;
  for(lli i=0;i<n;i++)
  {
     if(arr[i].vis==-1)
     {
         x=x+cum_mag(i,n,++nx);
     }
  }
  return x;
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
      scanf("%lld",&arr[i].data);
      arr[i].vis=-1;
      arr[i].chain=-1;
    }
    lli x=oprtn(n);
    printf("%lld\n",x);
  }
}