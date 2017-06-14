#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    lli a,b;
    scanf("%lld%lld",&a,&b);
    lli m=a*b-1;
    if(m%2==0)
      printf("No\n");
    else
      printf("Yes\n");
  }
}
 