#include<stdio.h>
#include<stdlib.h>
#define lli long long int
lli arr[100];
lli oprtn(lli n,lli sum)
{
  lli dp[sum+1][n+1];
  lli i,j;
  for(i=0;i<=n;i++)
  {
    dp[0][i]=1;
  }
  for(i=1;i<=sum;i++)
  {
    dp[i][0]=0;
  }
  for(i=1;i<=sum;i++)
  {
    for(j=1;j<=n;j++)
    {
      dp[i][j]=dp[i][j-1];
      if(i>=arr[j-1])
      {
        dp[i][j]=dp[i][j] || dp[i-arr[j-1]][j-1];
      }
    }
  }
  return dp[sum][n];
}
int main()
{
  lli t,i;
  scanf("%lld",&t);
  while(t--)
  {
    lli n,m;
    scanf("%lld%lld",&n,&m);
    for(i=0;i<n;i++)
       scanf("%lld",&arr[i]);
    lli flag=oprtn(n,m);
    if(flag==1)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
 
Comments 
