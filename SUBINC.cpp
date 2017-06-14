#include<bits/stdc++.h>
#define lli long long int
using namespace std;
vector<lli> v;
int main()
{
   lli t;
   scanf("%lld",&t);
   while(t--)
   {
      lli n,temp;
      v.clear();
      scanf("%lld",&n);
      for(lli i=0;i<n;i++)
      {
          scanf("%lld",&temp);
          v.push_back(temp);
      }
      lli count1=1,ans=0;
      for(lli i=0;i+1<n;i++)
      {
          if(v[i]<=v[i+1])
          {
             count1++;
             //printf("%lld >%lld c1===%lld\n",v[i],v[i+1],count1);
          }
          else
          {
             ans=ans+(count1*(count1+1))/2;
            // printf("ans==%lld\n",ans);
             count1=1;
          }
      }
      ans=ans+(count1*(count1+1))/2;
      printf("%lld\n",ans);
   }
   return 0;
}
 