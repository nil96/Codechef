//https://discuss.codechef.com/questions/1584/csumd-editorial
#include<bits/stdc++.h>
#define lli long long int 
#define mod 1000000007
using namespace std;
lli omat[2][2]={{2,1},{2,0}};
void multiply(lli mul1[][2],lli r1,lli c1,lli mul2[][2],lli r2,lli c2)
{
	lli mul[3][3];
	for(size_t i=0;i<r1;i++)
	{
		for(size_t j=0;j<c2;j++)
		{
           mul[i][j]=0;
           for(size_t k=0;k<c1;k++)
           {
              mul[i][j]+=(mul1[i][k]*mul2[k][j])%mod;
              mul[i][j]=mul[i][j]%mod;
           }
		}
	}
	for(size_t i=0;i<r1;i++)
	{ 
		for(size_t j=0;j<c2;j++)
		{
			mul1[i][j]=mul[i][j];
		}
	}
}
int c1=0;
void power(lli mat[][2],lli n)
{
	if(n==1)
       return;
    if(n%2==1)
    {
    	power(mat,n-1);
    	multiply(mat,2,2,omat,2,2);
    }
    else
    {
    	power(mat,n/2);
    	multiply(mat,2,2,mat,2,2);
    }
}
int main()
{
   lli t,n;
   scanf("%lld",&t);  
   while(t--)
   {
   	 lli mat[2][2]={{2,1},{2,0}};
     lli imat[][2]={{3,1}};
   	 /*power(mat,2);
   	 multiply(imat,1,2,mat,2,2);
   	 for(int i=0;i<2;i++)
   	 {
   		for(int j=0;j<2;j++)
   			printf("%lld ",imat[i][j]);
   		printf("\n");
   	 }*/
     scanf("%lld",&n);
     if(n>2)
     {
        power(mat,n-2);
        multiply(imat,1,2,mat,2,2);
       // multiply(mat,2,2,imat,1,2);
        printf("%lld\n",imat[0][0]%mod);
     }
     else
     {
     	if(n==1)
     	  printf("1\n");
     	if(n==2)
     	  printf("3\n");
     }
   }
 
 
} 