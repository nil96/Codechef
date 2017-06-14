#include <cstdio>
#define MOD 1000000007
 
long long arr[100005];
int main()
{
	long long ans=0,freq,lfreq;
	int t,n;
	scanf("%d",&t);
	while(t-->0)
	{
		ans=0;freq=2,lfreq=2;
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
			scanf("%lld",&arr[i]);
			
			
		if(n==1)
		{
			ans=(ans + (((arr[1]*arr[0])%MOD) * freq%MOD)%MOD)%MOD;
			printf("%lld\n",ans);
			continue;
		}
		
		for(int i=n;i>1;i--)
		{		
			freq=lfreq;
			ans=(ans + (((arr[i]*arr[0])%MOD) * freq%MOD)%MOD)%MOD;
			ans=(ans + (((arr[i]*arr[1])%MOD) * freq%MOD)%MOD)%MOD;			
			for(int j=2;j<i;j++)
			{
				freq=(freq*2)%MOD;
				ans=(ans + (((arr[i]*arr[j])%MOD) * freq%MOD)%MOD)%MOD;	
			}
			lfreq=(lfreq*2)%MOD;
		}	
		freq=(freq*2)%MOD;
		ans=(ans + (((arr[1]*arr[0])%MOD) * freq%MOD)%MOD)%MOD;
		
		printf("%lld\n",ans);
	}
}
 