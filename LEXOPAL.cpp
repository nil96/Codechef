#include<bits/stdc++.h>
#define lli long long int
#define gc() getchar()
using namespace std;
char arr[1000000];
char ans[1000000];
lli flag=0;
void fun()
{
    flag=0;
    lli l=strlen(arr);
    lli i,j;
    for( i=0,j=l-1;i<=j;i++,j--)
    {
      if(arr[i]=='.')
        arr[i]=arr[j];
      if(arr[j]=='.')
        arr[j]=arr[i];
      if(arr[i]=='.' && arr[j]=='.')
      {
          arr[i]='a';
          arr[j]='a';
          continue;
      }
      if(arr[i]!=arr[j])
      {
          flag=-1;
          break;
      }
 
    }
}
int main()
{
    lli t;
    scanf("%lld",&t);
    gc();
    while(t--)
    {
        scanf("%s",&arr);gc();
        fun();
        if(flag==-1)
            printf("-1\n");
        else
            printf("%s\n",arr);
 
    }
    return 0;
}
 