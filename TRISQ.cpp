#include<stdio.h>
#include<stdlib.h>
#define lli long long int
#include<iostream>
using namespace std;
int main()
{
  lli t;
  cin>>t;
  while(t--)
  {
    lli q;
    cin>>q;
    if(q%2!=0)
     q--;
    lli z=(q*q)/4-(q/2);
    printf("%lld\n",z/2);
  }
  return 0;
}
 