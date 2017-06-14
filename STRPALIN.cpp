#include<bits/stdc++.h>
#define lli long long int
#define gc() getchar_unlocked()
using namespace std;
char arr[1000000];
char arr1[1000000];
lli map1[1000];
int main()
{
  lli t;
  scanf("%lld",&t);
  gc();
  while(t--)
  {
    scanf("%s",arr);gc();
    scanf("%s",arr1);gc();
    lli flag=0;
    lli l=strlen(arr);
    for(lli i=0;i<50;i++)
    {
      map1[i]=0;
    }
    for(lli i=0;i<l;i++)
    {
       map1[arr[i]-'a']++;
    }
    lli l1=strlen(arr1);
    for(lli i=0;i<l1;i++)
    {
        if(map1[arr1[i]-'a']>0)
        {
          flag=1;
          break;
        }
    }
    if(flag==0)
      printf("No\n");
    else
      printf("Yes\n");
  }
  return 0;
}
 