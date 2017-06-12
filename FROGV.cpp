#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define lli long long int
#define FOR(i,a,b) for(lli i=a;i<b;i++)
#define sc(n) scanf("%lld",&n)
#define pf(n) printf("%lld ",n)
 
using namespace std;
struct node
{
	lli data;
	lli index;
};
struct node arr[1000000];
lli learn[1000000];
lli indexing[10000000];
int cmp1(const void *a1,const void*b1)//increasing
{
   lli a=((struct node *)a1)->data;
   lli b=((struct node *)b1)->data;
   if(a>b)
    return 1;
  if(a<b)
    return -1;
  if(a==b)
    return 0;
}
int main()
{
	lli n,k,p;
	sc(n);sc(k);sc(p);
	FOR(i,0,n)
	{
       sc(arr[i].data);
       arr[i].index=i;
	}
	qsort(arr,n,sizeof(struct node),cmp1);
	
 
	FOR(i,0,n)
	{
		indexing[arr[i].index]=i;
	}
 
	learn[0]=0;
	FOR(i,1,n)
	{
      if(arr[i-1].data+k>=arr[i].data)
      	learn[i]=learn[i-1];
      else
       learn[i]=i;
	}
	while(p--)
	{
	   lli x,y;
       sc(x);sc(y);
       lli x1=indexing[x-1];
       lli y1=indexing[y-1];    
       if(learn[y1]==learn[x1])
       {
       	 printf("Yes\n");
       }
       else
       	printf("No\n");
	}
	return 0;
} 