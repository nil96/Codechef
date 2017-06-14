#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#define lli long long int
using namespace std;
map<lli,lli> m;
map<lli ,lli> :: iterator p;
int main()
{
   lli t;
   cin>>t;
   while(t--)
   {
     m.clear();
     lli n,x=1,temp,ans=1;
     cin>>n;
     for(lli i=0;i<n;i++)
     {
        cin>>temp;
        p=m.find(temp);
        if(p==m.end())
        {
         // printf("%lld inserting %lld %lld\n",i,temp,x);
          m.insert(pair<lli,lli>(temp,x));
        }
        else
        {
          lli z=p->second+1;
          m.erase(temp);
         // printf("--%lld inserting %lld %lld\n",i,temp,z);
          m.insert(pair<lli,lli>(temp,z));
          if(ans< z)
          {
            ans=z;
          //  printf("ans %lld\n",ans);
          }
        }
     }
     printf("%lld\n",n-ans);
   }
   return 0;
}
 