#include<bits/stdc++.h>
#define lli long long int
#define gc() getchar_unlocked()
using namespace std;
char arr[1000000];
char arr1[100000];
lli fun()
{
	lli l=strlen(arr);
   // printf("l===%lld\n",l);
    lli x=-1;
    do
    {
    	x++;
       //printf("infintee x==%lld\n",x);
       if(arr[x]=='?' || arr1[x]=='?' || arr[x]==arr1[x])
       {
       	 continue;
       }
       if(arr1[x]!=arr[x])
       		return 0;
       	
    }while(arr[x]!='\0');
   // printf("done\n");
    return 1;
}
int main()
{
   lli t;
   scanf("%lld",&t);
   gc();
   while(t--)
   {
       scanf("%s",arr);
       gc();
       scanf("%s",arr1);
       gc();
       lli x=fun();
       if(x==0)
       	 printf("No\n");
       else
       	printf("Yes\n");
   }
   return 0;
} 