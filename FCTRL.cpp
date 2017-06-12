#include<stdio.h>
long long int z(long long int);
int main()
{
	long long int i,j,n;
	scanf("%lld",&j);
	for(i=0;i<j;i++)
	{
		scanf("%lld",&n);
		z(n);
	}
	return 0;
}
long long int z(long long int n)
{
	long long int k,x,sum=0;
	for(k=5;k<=n;k=k*5)
	{
		x=n/k;
		sum=sum+x;
	}
	printf("%lld\n",sum);
	return 0;
}
 