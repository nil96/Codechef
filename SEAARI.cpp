#include<bits/stdc++.h>
#define lli long long int
using namespace std;
lli n,k,d;
lli arr[1000000];
struct node
{
   lli num,ind;
};
struct node arr1[100000];
int cmp(struct node a,struct node b)
{
  return a.num<b.num;
}
int main()
{
   scanf("%lld%lld%lld",&n,&k,&d);
   lli sum=0;
   for(lli i=0;i<n;i++)
   {
      scanf("%lld",&arr[i]);
      sum=sum+arr[i];
   }
   sum=sum/n;
   for(lli i=0;i<n;i++)
   {
      arr1[i].ind=i;
      arr1[i].num=abs(arr[i]-sum);
   }
   sort(arr1,arr1+n,cmp);
   printf("%lld 0\n",sum);
   for(lli i=0,j=n-1;i<d;i++,j--)
   {
       printf("2 %lld\n",arr1[i].ind);
   }
   printf("-1\n");
    return 0;
}
 