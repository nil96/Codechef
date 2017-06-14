#include<bits/stdc++.h>
#define lli long long int
#define gc() getchar_unlocked()
using namespace std;
vector<lli> v;
vector<lli> m;
char ans[100000];
char ans1[100000];
int main()
{
   lli t;
   scanf("%lld",&t);
   while(t--)
   {
      lli n,temp;
      v.clear();
      m.clear();
      scanf("%lld",&n);
      gc();
      scanf("%s",ans);
      gc();
      scanf("%s",ans1);
      gc();
      for(lli i=0;i<=n;i++)
      {
         scanf("%lld",&temp);
         v.push_back(temp);
      }
      lli count1=0;
      lli max1=0;
      lli i=0,j=0;
      for(lli i=0;i<n;i++)
      {
        lli flag=0;
        if(ans[i]==ans1[i])
          flag++;
        count1=count1+flag;
      }
      if(count1==n)
        printf("%lld\n",v[n]);
      else
      {
        lli max11=-1;
        for(lli i=0;i<=count1;i++)
        {
            if(max11<v[i])
             max11=v[i];
        }
        printf("%lld\n",max11);
      }
   }
   return 0;
}
 
