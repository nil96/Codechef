#include<bits/stdc++.h>
#define lli long long int
#define inf 1000
using namespace std;
vector<lli> v;
vector<lli> ans;
int main()
{
	lli t;
	scanf("%lld",&t);
	while(t--)
	{
		lli n;
 		scanf("%lld",&n);
        v.clear();
        for(lli i=0;i<n;i++)
        {
        	lli temp;
        	scanf("%lld",&temp);
            v.push_back(temp);
        }
        ans.clear();
        ans.push_back(v[0]);
        for(lli i=1;i<n;i++)
        {
          vector<lli>::iterator up;
          if(ans[ans.size()-1]<=v[i])
          	ans.push_back(v[i]);
          else
          {
          	// printf("else\n");
             up=upper_bound(ans.begin(),ans.end(),v[i]);
             lli yak=up-ans.begin();
             //printf("z---%lld\n",yak);
             ans[up-ans.begin()]=v[i];
 
          }
        }
        lli mxx=ans.size();
        printf("%lld ",mxx);
        for(lli i=0;i<ans.size();i++)
        {
        	printf("%lld ",ans[i]);
        }
        printf("\n");
	}
} 