#include <bits/stdc++.h>
#define lli long long int
#define FOR(i,a,b) for(lli i=a;i<b;i++)
#define FORE(i,a,b) for(lli i=1;i<=b;i++)
#define gc() getchar_unlocked()
#define sc(a) scanf("%lld",&a);
#define sc_(a,b) scanf("%lld%lld",&a,&b);
#define sc__(a,b,c) scanf("%lld%lld%lld",&a,&b,&c);
#define up 0
#define dwn 1
#define r8 2
#define left 3
using namespace std;
lli x[]={0,0,1,-1};
lli y[]={1,-1,0,0};
lli arr[420][420];
lli chck(lli x,lli y)
{
	if(x>-1 && x<401 && y>-1 && y<401)
		 return 1;
	return 0;
}
lli get_drct(char d)
{
	if(d=='U')
	  return up;
	if(d=='D')
	  return dwn;
	if(d=='R')
	  return r8;
	if(d=='L')
	  return left;
}
int main()
{
   lli t;
   sc(t);gc();
   while(t--)
   {
   	 lli xe,ye;
   	 char de;
   	 scanf("%lld %lld %c",&xe,&ye,&de);
   	 xe+=100;ye+=100;
   	 xe*=2;ye*=2;
   	 memset(arr,0,sizeof(arr));
   	 lli drct=get_drct(de);
   	 for(lli t=0;chck(xe,ye);t++)
   	 {
   	 	arr[xe][ye]=t;
   	 	xe+=x[drct];
   	 	ye+=y[drct];
   	 }
 
   	 lli ans=1000000;
   	 lli n;
   	 sc(n);gc();
   	 while(n--)
   	 {
   	 	lli xa,ya;
   	 	char da;
   	 	scanf("%lld %lld %c",&xa,&ya,&da);
   	 	xa+=100;ya+=100;
   	    xa*=2;ya*=2;
   	    drct=get_drct(da);
   	    for(lli t=0;chck(xa,ya);t++)
   	    {
   	 	    if(t>0 && t==arr[xa][ya])
   	 	    {
   	 	    	ans=min(ans,arr[xa][ya]);
   	 	    	break;
   	 	    }
   	 	    xa+=x[drct];
   	 	    ya+=y[drct];
   	    }
   	 }
   	 if(ans==1000000)
   	 	printf("SAFE\n");
   	 else if(ans%2==0)
   	 	printf("%lld.0\n",ans/2);
   	 else
   	 	printf("%lld.5\n",ans/2);
   }
   return 0;
} 