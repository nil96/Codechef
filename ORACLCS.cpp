#include<bits/stdc++.h>
#define lli long long int
#define sc(a) scanf("%lld",&a)
#define sc_(a,b) scanf("%lld%lld",&a,&b)
#define sc__(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define FOR(i,a,b) for(lli i=a;i<b;i++)
#define FORE(i,a,b) for(lli i=a;i<=b;i++)
#define gc() getchar_unlocked()
#define MAX(a,b) a>b ? a:b
#define MIN(a,b) a<b ? a:b
#define inf INT_MAX
#include<math.h>
using namespace std;
char buff[5000];
lli counter(lli *a,lli *b)
{
  lli n=strlen(buff);
  FOR(i,0,n)
  {
    if(buff[i]=='a')
     *a=*a+1;
     else
      *b=*b+1;
  }
  return 0;
}
int main()
{
   lli t;
   sc(t);gc();
   while(t--)
   {
     lli n,a_c=inf,b_c=inf;
     sc(n);gc();
     FOR(i,0,n)
     {
        scanf("%s",buff);gc();
        lli a=0,b=0;
        counter(&a,&b);
        a_c=MIN(a_c,a);
        b_c=MIN(b_c,b);
     }
     printf("%lld\n",MIN(a_c,b_c));
   }
   return 0;
}