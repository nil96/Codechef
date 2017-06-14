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
    lli n;
    //printf("t====%lld\n",t);
    scanf("%lld",&n);
    v.clear();
    for(lli i=0;i<n;i++)
    {
       lli temp;
       scanf("%lld",&temp);
       v.push_back(temp);
    }
    sort(v.begin(),v.end());
    lli flag=1;
    for(lli i=0;i+1<n;i++)
    {
       if(abs(v[i]-v[i+1])>1)
       {
         flag=0;
         break;
       }
    }
    if(flag==0)
     printf("NO\n");
    else
     printf("YES\n");
  }
}
 