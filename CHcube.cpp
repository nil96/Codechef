#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define lli long long int
#define gc() getchar_unlocked();
using namespace std;
char arr[][100]={"black", "blue", "red", "green", "yellow", "orange"};
char buffer[100];
lli get_color(char *buff)
{
  for(lli i=0;i<6;i++)
  {
    if(strcmp(arr[i],buff)==0)
      return i;
  }
  return -1;
}
int main()
{
  lli t;
  lli p[100];
  scanf("%lld",&t);
  gc();
  while(t--)
  {
    for(lli i=0;i<6;i++)
    {
      scanf("%s",buffer);
      gc();
      p[i]=get_color(buffer);
    }
    lli flag=0;
    if(p[0]==p[4] && p[4]==p[2])
      flag=1;
    else if(p[0]==p[4] && p[4]==p[3])
      flag=1;
    else if(p[0]==p[5] && p[5]==p[2])
      flag=1;
    else if(p[0]==p[5] && p[5]==p[3])
      flag=1;
    else if(p[1]==p[4] && p[4]==p[2])
      flag=1;
    else if(p[1]==p[4] && p[4]==p[3])
      flag=1;
    else if(p[1]==p[5] && p[5]==p[2])
      flag=1;
    else if(p[1]==p[5] && p[5]==p[3])
      flag=1;
    if(flag==1)
     printf("YES\n");
    else
     printf("NO\n");
  }
  return 0;
}