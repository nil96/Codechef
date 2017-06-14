#include<bits/stdc++.h>
#define lli long long int
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define rlli(a) scanf("%lld",&a)
#define sc(a) scanf("%lld",&a)
#define gc() getchar_unlocked()
#define pb(a) push_back(a)
#define pf(a) printf("%lld\n",a);
using namespace std;
struct node
{
   lli waitingTime,travellingTime,deductionTime;
};
struct node arr[100030];
vector<lli> v[100030];
char buff[100030];
lli oprtn()
{
	lli lastWaitingTime=0,travellingTime=-1,deductionTime=0,count1=0;
    for(lli n=strlen(buff),i=n-1;i>=0;i--)
    {
    //	printf("i=================%lld\n",i);
    	arr[i].waitingTime=0;
    	arr[i].travellingTime=0;
    	arr[i].deductionTime=0;
    }
	for(lli n=strlen(buff),i=n-1;i>=0;i--)
	{
	  // printf("i===%lld\n",i);
       if(buff[i]=='1')
       { 
       	   count1++;
           arr[i].travellingTime=(n-1)-i;
        //   printf("eeeee\n");
        //   printf("i====%lld n-1===%lld\n",i,n-1 );
           if(i==n-1)
           {
          // 	 printf("......................\n");
             arr[i].waitingTime=lastWaitingTime;
             lastWaitingTime=arr[i].waitingTime;
           }
           else
           {
          //	  printf("xxxxxxxxxxxxxxxxxxxxxxx");
           	 if(buff[i+1]!='1')
           	 {
           	 	lastWaitingTime=lastWaitingTime+1;
           	 }
          // 	printf("yyyyyyyyyyyyyyyyyyyyyyyyy");
           	 arr[i].waitingTime=lastWaitingTime;
           }
       }
	}
	lli sum=0;
	for(int n=strlen(buff),i=n-1;i>=0;i--)
    {
      sum=sum+arr[i].waitingTime+arr[i].travellingTime;
    }
    sum = sum - ((count1) * (count1-1))/2 ; 
	return sum; 
}
int main()
{
   lli t;	
   sc(t);gc();
   while(t--)
   {
      scanf("%s",buff);gc();
      lli ans=oprtn();
      pf(ans);
   }
   return 0;
}
 