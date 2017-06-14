#include<bits/stdc++.h>
#define lli long long int
#define gc() getchar_unlocked()
using namespace std;
lli arr[1000000];
lli arr1[1000000];
lli get_max1(lli *a,lli n,lli *ind)
{
   lli max1=-1;
   for(lli i=0;i<n;i++)
   {
      if(max1<abs(a[i]))
      {
        max1=abs(a[i]);
        *ind=i;
      }
   }
   return max1;
}
lli max1(lli a,lli b,lli c,lli d)
{
  lli z=max(max(a,b),c);
  return max(z,d);
}
int main()
{
  lli t,n,k;
  scanf("%lld",&t);
  while(t--)
  {
     scanf("%lld%lld",&n,&k);
     for(lli i=0;i<n;i++)
     {
       scanf("%lld",&arr[i]);
     }
     for(lli i=0;i<n;i++)
     {
       scanf("%lld",&arr1[i]);
     }
     lli mx;
     lli z=get_max1(arr1,n,&mx);
     z=abs(z*k);
     lli sum=0;
     for(lli i=0;i<n;i++)
     {
       sum=sum+arr[i]*arr1[i];
     }
     printf("%lld\n",sum+z);
  }
  return 0;
}
 