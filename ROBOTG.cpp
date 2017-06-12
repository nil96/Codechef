#include<bits/stdc++.h>
#define lli long long int
#define gc() getchar_unlocked()
#define sc(t) scanf("%lld",&t) 
using namespace std;
char arr[100000];
int move(lli &n,lli &m,char l)
{
	//up,down,left,right
	lli y[]={-1,1,0,0};
	lli x[]={0,0,-1,1};
    if(l=='U')
    {
    	n=n+y[0],m=m+x[0];
    }
    if(l=='D')
    {
    	n=n+y[1],m=m+x[1];
    }
    if(l=='L')
    {
    	n=n+y[2],m=m+x[2];
    }
    if(l=='R')
    {
//    	printf("Enter r\n");
    	n=n+y[3],m=m+x[3];
    }
}
int isLegal(lli a,lli b,lli n,lli m)
{
	if( (a>=0 &&  a<n) && (b>=0 && b<m) )
		return 1;
	return 0;
}
int main()
{
	lli t;
	sc(t);gc();
	while(t--)
	{
		lli n,m;
		int flag=1;
		sc(n),gc(),sc(m),gc();
		scanf("%s",arr);
		for(lli i=0;i<n;i++)
		{
			for(lli j=0;j<m;j++)
			{
			    flag=1;
			    lli i1=i,j1=j;
				for(lli k=0;k<strlen(arr);k++)
				{
                    move(i1,j1,arr[k]);
                    if(isLegal(i1,j1,n,m)==0)
                    {
                    	flag=0;
                    	break;
                    }
 
				}
				if(flag==1)
					break;
			}
			if(flag==1)
				break;
		}
		 if(flag==1)
		 	printf("safe\n");
		 else
		 	printf("unsafe\n");
    }       
    return 0;
} 
Comments 
