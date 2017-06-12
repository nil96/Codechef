#include <bits/stdc++.h>
#define lli long long int
#define gc() getchar_unlocked()
#define FOR(i,a,b) for(lli i=a;i<b;i++)
#define FORR(i,a) for(lli i=b;i>=0;i--)
#define sc(n) scanf("%lld",&n);
#define pf(n) printf("%lld\n",n);
using namespace std;
string string1,string2;
map<string,lli> m;
int main()
{
  lli t;
  sc(t);
  gc();
  while(t--)
  {
  	lli n;
  	sc(n);
  	gc();
  	m.clear();
  	FOR(i,0,n)
  	{
  		cin>>string1;gc();
        cin>>string2;
        if(string2[0]=='+')
          m[string1]=1;
        else
          m[string1]=-1;
  	   
  	}
  	map<string,lli> :: iterator it;
  	lli sum=0;
  	for(it=m.begin();it!=m.end();it++)
       sum=sum+it->second;
  	pf(sum); 
  }
  return 0;
} 
Comments 
