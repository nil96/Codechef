#include<bits/stdc++.h>
#define lli long long int
#define sc(a) scanf("%lld",&a);
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define FORE(i,a,n) for(int i=a;i<=n;i++)
#define gc() getchar_unlocked();
#define pb(a) push_back(a);
using namespace std;
char arr[1000000];
void jud(char a,lli &s,lli &m)
{
	a=='s'?s++:m++;
}
int main()
{
	lli t,n;
	sc(t);gc();
	while(t--)
	{
       scanf("%s",arr);gc();
       //printf("%s\n",arr);
       n=strlen(arr);
       char prev=arr[0];
       lli s=0,m=0;
       jud(prev,s,m);
       FOR(i,1,n)
       {
          jud(arr[i],s,m);
          if(prev=='s' && arr[i]=='m')
          	 s--;
          prev=arr[i];
       }
       if(s>m)
       	printf("snakes\n");
       else if(s<m)
       	printf("mongooses\n");
       else
       	printf("tie\n");
	}
	return 0;
}