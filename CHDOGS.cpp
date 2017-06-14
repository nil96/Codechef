#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
   lli t;
   scanf("%lld",&t);
   while(t--)
   {
     double a,b;
     scanf("%lf%lf",&a,&b);
     double z=0.666667f;
     a=a*z;
     double ans=(double)(a/b);
     printf("%f\n",ans);
   }
}
 