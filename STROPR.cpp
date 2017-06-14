#include <bits/stdc++.h>
#define lli long long int
lli fact[1000008],ifact[1000008],arr[1000008];
#define mod 1000000007
#define gc getchar_unlocked
lli denominator=1;
lli numerator=1;
lli read_lli() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  lli ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
lli powr(lli a,lli b)
{
   if(b==0)
   	 return 1;
   lli temp=powr(a,b/2);
   temp=temp%mod;
   if(b%2==0)
   {
   	 return (temp*temp)%mod;
   }
   temp=(temp*temp)%mod;
   return (a*temp)%mod;  
}
lli new_c(lli n,lli r)
{
  denominator=1;
  numerator=1;
  for(lli i=0;i<r;i++)
  {
    numerator=(numerator*(n-i))%mod;
  } 
  for(lli i=1;i<=r;i++)
    denominator=(denominator*i)%mod;
  return 0;
}
int main()
{
	lli t;
	scanf("%llu",&t);
	while(t--)
	{
        lli n,m;
        long long int x;
        numerator=1;
        denominator=1;
        scanf("%lld%lld%lld",&n,&x,&m);
        for(lli i=0;i<n;i++)
        {
          arr[i]=read_lli();
          arr[i]=arr[i]%mod;
        }
        x--;m--;
        lli z=m+x;
        lli sum=0,i=0;
        lli xc=0;
        new_c((m+x),(x))%mod;
        while(x>=0)
        {
        	xc=(numerator*powr(denominator,mod-2))%mod;
          //lli xc1=(numerator*powr(denominator,mod-2));
          //lli xc2=(numerator/denominator);
          //printf("xc===%lld xc1==%lld xc2==%lld z==%lld x==%lld\n",xc,xc1,xc2,z,x);
          sum=(sum%mod+(xc*arr[i])%mod)%mod;
        	sum=sum%mod;
          numerator=(numerator*x)%mod;
          lli z1=z%mod;
          denominator=(denominator*z1)%mod;
          i++;x--;z--;
        }
        sum=sum%mod;
        printf("%lld\n",sum%mod);
	}
} 