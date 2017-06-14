#include<bits/stdc++.h>
#define lli long long int
#define FOR(a,b) for(int i=a;i<b;i++)
#define FORE(a,b) for(int i=a;i<=b;i++)
#define rlli(a) scanf("%lld",&a)
#define sc(a) scanf("%lld",&a)
#define gc() getchar_unlocked()
#define pb() push_back()
using namespace std;
map<string,int> m;
int main()
{
	lli t;
	sc(t);gc();
	while(t--)
	{
      char buff[1000];
      m.clear();
      int c=0;
      FOR(0,4)
      {
          scanf("%s",buff);gc();
          string s(buff);
          m[s]=1;
          c=c+m[s];
      }
      FOR(0,4)
      {
          scanf("%s",buff);gc();
          string s(buff);
          if(m[s]==1)
          	m[s]++;
          else
          	m[s]=1;
          c=c+m[s];
      }
      if(c>=10)
      	printf("similar\n");
      else
      	printf("dissimilar\n");
 
 
	}
} 