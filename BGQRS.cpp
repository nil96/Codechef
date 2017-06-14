#include<bits/stdc++.h>
#define lli long long int
using namespace std;
vector<lli> v;
lli count1(lli a,lli b)
{
   lli c=0;
   while(a%b==0)
   {
      a=a/b;
      c++;
   }
   return c;
}
int main()
{
   lli ans=0;
   lli n,m,t;
   scanf("%lld",&t);
   while(t--){ ans=0;
   scanf("%lld%lld",&n,&m);
   v.clear();
   for(lli i=0;i<n;i++)
   {
      lli temp;
      scanf("%lld",&temp);
      v.push_back(temp);
   }
   while(m--)
   {
      lli type,l,r;
      scanf("%lld%lld%lld",&type,&l,&r);
      l--,r--;
      if(type==1)
      {
        lli x;
        scanf("%lld",&x);
        for(lli i=l;i<=r;i++)
          v[i]*=x;
      }
      else if(type==2)
      {
        lli x;
        scanf("%lld",&x);
        for(lli i=l,j=1;i<=r;i++,j++)
          v[i]=x*j;
      }
      else
      {
        lli c2=0,c5=0;
        for(lli i=l;i<=r;i++)
        {
          //printf("v[%lld]==%lld\n",i,v[i]);
          c2+=count1(v[i],2);
          c5+=count1(v[i],5);
        }
        ans+=min(c2,c5);
      }
   }
   printf("%lld\n",ans);
   }
   return 0;
}