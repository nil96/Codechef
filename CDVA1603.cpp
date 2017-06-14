#include <bits/stdc++.h>
using namespace std;
#define lli long long int
vector<double> v;
vector<double> :: iterator it;
lli cmp(double a,double b)
{
	return a<b;
}
int main()
{
   lli t;
   scanf("%lld",&t);
   while(t--)
   {
     lli n,q;
     scanf("%lld%lld",&n,&q);
     v.clear();
     for(lli i=0;i<n;i++)
     {
       double x;
       scanf("%lf",&x);
       v.push_back(x);
     }
     sort(v.begin(),v.end(),cmp);
     /*for(lli i=0;i<n;i++)
     {
     	printf("%f   ",v[i]);
     }*/
     while(q--)
     {
     	double z;
     	scanf("%lf",&z);
        it=upper_bound(v.begin(),v.end(),z);
        lli ans=n-(it-v.begin());
        printf("%lld\n",ans);
     }
   }  
   return 0;
} 