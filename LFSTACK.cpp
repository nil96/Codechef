#include<bits/stdc++.h>
#define lli long long int
using namespace std;
vector<lli> v[100000];
vector<lli> s;
lli s_ind;
lli index1[100005];
lli m,sum=0;//m=number of stack
void input()
{
   sum=0;
   scanf("%lld",&m);
   for(int i=0;i<m;i++)
   {
      v[i].clear();
      lli n;
      scanf("%lld",&n);
      index1[i]=n-1;
      sum=sum+n;
      for(int j=0;j<n;j++)
      {
         lli temp;
         scanf("%lld",&temp);
         v[i].push_back(temp);
       }
    }
    s.clear();
    s_ind=sum-1;
    for(int i=0;i<sum;i++)
    {
        lli temp;
        scanf("%lld",&temp);
        s.push_back(temp);
    }
    reverse(s.begin(),s.end());
    return;
}
void print()
{
    for(lli i=0;i<m;i++)
    {
        for(lli j=0;j<v[i].size();j++)
        {
            printf("%lld ",v[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(lli i=0;i<sum;i++)
        printf("%lld ",s[i]);
    printf("\n");
 
 
 
}
lli flag=0;
void rec()
{
    if(flag==1)
        return;
    if(s_ind==-1)
     flag=1;
    for(lli i=0;i<m;i++)
    {
       //printf("v[%lld][%lld]==%lld s[%lld]==%lld\n",i,index1[i],v[i][index1[i]],s_ind,s[s_ind]);
       if(index1[i]>=0 && s_ind>=0 && v[i][index1[i]]==s[s_ind])
       {
          // printf("i==%lld index[i]==%lld s[s_ind]==%lld s_ind==%lld\n",i,index1[i],s[s_ind],s_ind);
           index1[i]--;
           s_ind--;
           rec();
           index1[i]++;
           s_ind++;
       }
    }
}
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    input();
    /*printf("\n------------------------\n");
    print();
    printf("\n------------------------\n");*/
    flag=0;
    rec();
    if(flag==1)
      printf("Yes\n");
    else
      printf("No\n");
 
  }
}