#include <bits/stdc++.h>
#define lli long long int
#define gc() getchar_unlocked();
#define sc(a) scanf("%lld",&a);
#define sc_(a,b) scanf("%lld%lld",&a,&b);
#define FOR(i,a,b) for(lli i=a;i<b;i++)
#define pb(z)  push_back(z);
using namespace std;
lli arr[100][100];
map<string,lli> m;
map<lli,string> rm;
lli visited[100];
vector<lli> v[100];
 
void init(lli n)
{
  FOR(i,0,n+2)
  {
  	v[i].clear();
    FOR(j,0,n)
      arr[i][j]=0;
  }
   m.clear();
   rm.clear();
}
void v0(lli n)
{
   FOR(i,0,n+2)
    visited[i]=0;
}
int main()
{
   lli n;
   sc(n);
   init(n);
   lli c=0;
   FOR(i,0,n)
   {
   	   string temp;
       cin>>temp;gc();
       if(m.find(temp)==m.end())
       {
       	 m[temp]=c;
       	 rm[c]=temp;
       	 c++;
       }
   }
   lli in;
   sc(in);gc();
   FOR(i,0,in)
   {
   	  string temp,temp1;
   	  lli dist;
   	  cin>>temp;gc();
   	  cin>>temp1;gc();
   	  cin>>dist;gc();
     // cout<<temp<<" "<<temp1<<" "<<dist<<"\n";
   	  arr[m[temp]][m[temp1]]=dist;
   }
   
   lli x;
   sc(x);gc();
   FOR(i,0,x)
   {
   	 lli z;
     v0(n);
   	 sc(z);gc();
   	 string start;
   	 lli dist1=0,flag=1;
   	 cin>>start;gc();
     if(m.find(start)==m.end())
     {
         flag=0;
     }
     else
     {
       visited[m[start]]=1;
     }
   	 FOR(i,0,z-1)
   	 {
       string temp;
       cin>>temp;gc();
       if(flag==0)
       {
       	 continue;
       }
       else if(m.find(temp)==m.end())
       {
            flag=0;
            continue;
       }
       else if(visited[m[temp]]==1)
       {
         flag=0;
         continue;
       }
       else if(arr[m[start]][m[temp]]==0)
       {
          flag=0;
          continue;        
       }
       else
       {
         //cout<<start<<" "<<temp<<" "<<arr[s]<<"\n";
         dist1+=arr[m[start]][m[temp]];
         visited[m[temp]]=1;
         start=temp;
       }
   	 }
     if(flag==0)
       printf("ERROR\n");
     else
       printf("%lld\n",dist1);
   }
   return 0;
} 
Comments 
