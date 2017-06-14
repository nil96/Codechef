#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
#define lli long long int
using namespace std;
char buffer[1000010];
void strlwr(char *s)
{
  lli n=strlen(s);
  for(lli i=0;i<n;i++)
  {
    if(s[i]>='A'  && s[i]<='Z')
    {
       s[i]=(s[i]-'A')+'a';
    }
  }
}
char oprtn(char *s)
{
  lli n;
  n=strlen(s);
  lli frequency[50];
  for(lli i=0;i<='Z'-'A';i++)
    frequency[i]=0;
 
 
  for(lli i=0;i<n;i++)
  {
    if(s[i]>='a'  && s[i]<='z')
     frequency[s[i]-'a']++;
  }
  lli index=0;
  lli max1=-1;
  for(lli i=0;i<='z'-'a';i++)
  {
    if(frequency[i]>=max1)
    {
      max1=frequency[i];
      index=i;
    }
  }
  return (char)('a'+index);
}
int main()
{
  lli t;
  scanf("%lld",&t);
  getchar_unlocked();
  while(t--)
  {
    scanf("%s",buffer);
    getchar_unlocked();
    strlwr(buffer);
    char ans=oprtn(buffer);
    printf("%c\n",ans);
    fflush(stdin);
    fflush(stdout);
  }
  return 0;
}
 
Comments 
