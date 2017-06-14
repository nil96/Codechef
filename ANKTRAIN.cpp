#include<bits/stdc++.h>
#define lli long long int
using namespace std;
char arr[15][4];;
lli num[1000];
lli num1[10000];
void strrev(char *a)
{
  lli i=0,j=strlen(a)-1;
  while(i<j)
  {
    swap(a[i],a[j]);
    i++;j--;
  }
 
}
char *myitoa(lli num,char *str)
{
  lli i=0;
  while (num!=0)
  {
        int rem=num%10;
        str[i++]=(rem > 9)?(rem-10)+'a':rem +'0';
        num=num/10;
  }
  str[i]='\0';
  strrev(str);
  return str;
 
}
int main()
{
  strcpy(arr[1],"LB");
  strcpy(arr[2],"MB");
  strcpy(arr[3],"UB");
  strcpy(arr[4],"LB");
  strcpy(arr[5],"MB");
  strcpy(arr[6],"UB");
  strcpy(arr[7],"SU");
  strcpy(arr[8],"SL");
  num[1]=4;num[2]=5;num[3]=6;
  num[4]=1;num[5]=2;num[6]=3;
  num[7]=8;num[8]=7;num[0]=8;
  for(int i=1;i<=8;i++)
    num1[i]=i;
  for(lli i=9,j=1;i<=500;i++,j++)
  {
    if(j>8)
    {
      j=1;
    }
    num[i]=i+num[j]-j;
    num1[i]=j;
  }
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    lli n;
    scanf("%lld",&n);
    printf("%lld%s\n",num[n],arr[num1[n]]);
  }
  return 0;
}
 