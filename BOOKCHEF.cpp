#include<bits/stdc++.h>
#define lli long long int
using namespace std;
struct node
{
  lli f,p;
  char arr[105];
};
struct node A[100000];
int a[100000];
int cmp(struct node a1,struct node b1)
{
  if(a[a1.f]==a[b1.f])
    return a1.p>b1.p;
  if(a[a1.f]==1 && a[b1.f]==0)
    return 1;
  return 0;
}
int main()
{
   lli n,m;
   for(lli i=0;i<=100000;i++)
    a[i]=0;
   scanf("%lld%lld",&n,&m);
   for(lli i=0;i<n;i++)
   {
     lli z;
     scanf("%lld",&z);
     a[z]=1;
   }
   for(lli i=0;i<m;i++)
   {
      scanf("%lld%lld%s",&A[i].f,&A[i].p,A[i].arr);
   }
   sort(A,A+m,cmp);
   for(lli i=0;i<m;i++)
   {
     printf("%s\n",A[i].arr);
   }
   return 0;
}
 
Comments 
