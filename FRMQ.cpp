#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define lli long long int
#define size1 100005
using namespace std;
lli arr[size1+10];
lli tree[10*size1+10];
vector<lli> ans;
vector<lli> cum;
multimap<lli,lli> mp;
multimap<lli,lli> :: iterator it;
struct node
{
  lli x,y;
};
struct node zuck[size1+10];
lli get_mid(lli s,lli e)
{
  return (s+e)/2;
}
lli query(lli qs,lli qe,lli ss,lli se,lli index)
{
  if(se<qs || ss>qe)
    return -1;
  if(qs<=ss && qe>=se)
   return tree[index];
   lli mid=get_mid(ss,se);
   return max(query(qs,qe,ss,mid,2*index+1),query(qs,qe,mid+1,se,2*index+2));
}
lli build_tree(lli index,lli s,lli n)
{
   if(s<=n)
   {
     lli mid=get_mid(s,n);
     if(s==n)
     {
       tree[index]=arr[s];
       return arr[s];
     }
     tree[index]=max(build_tree(2*index+1,s,mid),build_tree(2*index+2,mid+1,n));
     return tree[index];
   }
}
lli min1(lli x,lli y)
{
  if(x<y)
   return x;
  return y;
}
/*void print(lli *cum,lli z)
{
  printf("\n");
  for(lli i=0;i<=z;i++)
  {
    printf("%lld ",cum[i]);
  }
  printf("\n");
}*/
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
lli fun(lli x,lli y,lli m)
{
   lli i=0;
  // printf("x==%lld y==%lld\n",x,y);
   while(1)
   {
     if(zuck[i].x==x && zuck[i].y==y)
     {
        break;
     }
     i++;
   }
   lli terms=i+1;
   lli sum=cum[i+1];
   lli r_terms=m-terms;
   lli xz=cum[ans.size()]-cum[i+1];
   sum=sum+(r_terms/(ans.size()-(i)))*xz;
   terms=terms+(r_terms/(ans.size()-(i)))*(ans.size()-(i));
   for(lli j=i;j<=m-terms;j++)
   {
      sum=sum+ans[j];
   }
   return sum;
}
 
int main()
{
  lli n;
  scanf("%lld",&n);
  for(lli i=0;i<n;i++)
  {
     scanf("%lld",&arr[i]);
  }
  lli m,x,y;
  scanf("%lld%lld%lld",&m,&x,&y);
  build_tree(0,0,n-1);
  lli sum=0;
  mp.clear();
  ans.clear();
  cum.clear();
  cum.push_back(0);
  lli i;
  lli kx,ky;
  for(i=1;i<=m;i++)
  {
    lli a=x,b=y;
    kx=x;ky=y;
    it=mp.find(x);
    zuck[i-1].x=x;  zuck[i-1].y=y;
    if(it!=mp.end())
    {
       lli flag=0;
       while(it->first==x && it!=mp.end())
       {
          if(it->second==y)
          {
             kx=x;ky=y;
            flag=1;
            break;
          }
          it++;
       }
       if(flag==1)
         break;
 
       mp.insert(pair<lli,lli>(x,y));
       //printf("i=%lld insert==%lld %lld\n",i,x,y);
    }
    else
    {
       mp.insert(pair<lli,lli>(x,y));
       //printf("i=%lld insert==%lld %lld\n",i,x,y);
    }
    if(a>b)
    {
      swap(a,b);
    }
    ans.push_back(query(a,b,0,n-1,0) );
    cum.push_back(ans[i-1]+cum[i-1]);
    x=(x+7)%(n-1);
    y=(y+11)%n;
  }
  //printf("i====%lld\n",i);
  lli ans=fun(kx,ky,m);
  printf("%lld\n",ans);
  return 0;
}
 
