#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int fun(int a)
{
  if(a<0)
    return 0;
  return a;
}
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      lli d,c,l;
      lli flag=0;
      scanf("%lld%lld%lld",&c,&d,&l);
      lli max1=(d+c)*4;
      lli min1=d*4+(c-min(c,2*d)) *4;
      if((l>=min1 && l<=max1) && l%4==0)
       flag=1;
      if(flag==0)
       printf("no\n");
      else
       printf("yes\n");
   }
} 