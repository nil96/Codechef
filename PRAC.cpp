#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<math.h>
#define lli long long int
using namespace std;
double oprtn(double a,double b,double c)
{
  double z=(a+b+c)*(b+c-a)*(c+a-b)*(a+b-c);
  z=sqrt(z);
  return (a*b*c)/z;
}
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    double a=0.0f,b=0.0f,c=0.0f;
    cin >>a>>b>>c;
    double ans=oprtn(a,b,c);
    cout<< ans<<"\n";
  }
  return 0;
}
 