#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define lli long long int
using namespace std;
char arr[100010];
lli loss(lli x)
{
  if(x%2==0)
    return x/2;
  else
    return x/2+1;
}
lli win(lli x)
{
  return 2*x+11;
}
int main()
{
  lli t;
  scanf("%lld",&t);
  getchar_unlocked();
  scanf("%s",arr);
 
  lli i=0;
  while(arr[i]!='\0')
  {
    if(arr[i]=='L')
    {
      t=loss(t);
    }
    else
    {
      t=win(t);
    }
    i++;
  }
  printf("%lld\n",t);
}
 
Comments 
