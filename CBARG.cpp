#include<stdio.h>
#include<stdlib.h>
#include<vector>
#define lli long long int
using namespace std;
vector<lli> v;
int main()
{
   lli t;
   scanf("%lld",&t);
   while(t--)
   {
     lli n;
     scanf("%lld",&n);
     lli old=0,sum=0;;
     lli new1;
     for(lli i=0;i<n;i++)
     {
        scanf("%lld",&new1);
        if(new1-old>=0)
        {
          sum=sum+new1-old;
        }
        old=new1;
     }
     printf("%lld\n",sum);
   }
   return 0;
}
 