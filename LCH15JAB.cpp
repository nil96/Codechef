#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define lli long long int
using namespace std;
char arr[1000];
lli buffer[103];
lli oprtn(char *arr)
{
  for(lli i=0;i<='z'-'a';i++)
  {
    buffer[i]=0;
  }
 
  lli n=strlen(arr);
  for(lli i=0;i<n;i++)
  {
    buffer[arr[i]-'a']++;
  }
 
  lli max1=-10;
  lli sum=0;
  for(lli i=0;i<='z'-'a';i++)
  {
    sum=sum+buffer[i];
    if(buffer[i]>max1)
    {
       max1=buffer[i];
    }
  }
 
  if(2*max1==sum)
   return 1;
  else
  return 0;
}
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    scanf("%s",arr);
    getchar_unlocked();
    lli ans=oprtn(arr);
    if(ans==1)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
 