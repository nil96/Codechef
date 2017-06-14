#include<bits/stdc++.h>
#define lli long long int
using namespace std;
vector<lli> v;
struct node
{
    pair<lli,lli> start;
    pair<lli,lli> mid;
    pair<lli,lli> end1;
    lli sf;
};
struct node Tree[10000000];
struct node init(lli a,lli x=1)
{
   struct node temp;
   temp.start.first=a;
   temp.start.second=x;
   temp.mid.first=a;
   temp.mid.second=x;
   temp.end1.first=a;
   temp.end1.second=x;
   temp.sf=1;
   return temp;
}
struct node fun1(lli s,lli e,struct node LEFT,struct node RIGHT)
{
    struct node temp;
    temp.start=LEFT.start;
    temp.end1=RIGHT.end1;
    if(LEFT.sf==1)
    {
      if(LEFT.end1.first==RIGHT.start.first)
      {
          temp.start.second = LEFT.end1.second + RIGHT.start.second;
      }
    }
    if(RIGHT.sf==1)
    {
      if(LEFT.end1.first==RIGHT.start.first)
      {
          temp.end1.second = LEFT.end1.second + RIGHT.start.second;
      }
    }
 
 
    if(LEFT.end1.first==RIGHT.start.first)
    {
         temp.mid.first=LEFT.end1.first;
         temp.mid.second=LEFT.end1.second+RIGHT.start.second;
         if(temp.mid.second < LEFT.mid.second)
         {
           temp.mid=LEFT.mid;
         }
         if(temp.mid.second < RIGHT.mid.second)
         {
           temp.mid=RIGHT.mid;
         }
    }
    else
    {
        if(LEFT.mid.second > RIGHT.mid.second)
        {
              temp.mid=LEFT.mid;
        }
        else
        {
              temp.mid=RIGHT.mid;
        }
    }
    if(temp.start.second==e-s+1)
        temp.sf=1;
    else
        temp.sf=0;
    return temp;
}
 
struct node merge1(struct node left,struct node right,lli ss,lli se,lli Left,lli Right)
{
  if(left.start.second==0 && left.mid.second==0 && left.end1.second==0)
  {
     return right;
  }
  if(right.start.second==0 && right.mid.second==0 && right.end1.second==0)
  {
     return left;
  }
  return fun1(ss,se,left,right);
}
struct node _query(lli ss,lli se,lli ind,lli qs,lli qe,lli k)
{
   if(qs<=ss && qe>=se)
   {
     return Tree[ind];
   }
   if(se<qs || ss>qe)
   {
      return init(0,0);
   }
   lli mid=(ss+se)/2;
   struct node left=_query(ss,mid,2*ind+1,qs,qe,k);
   struct node right=_query(mid+1,se,2*ind+2,qs,qe,k);
   return merge1(left,right,ss,se,2*ind+1,2*ind+2);
}
void create(lli s,lli e,lli ind)
{
 
   if(s==e)
   {
      Tree[ind]=init(v[s],1);
      return;
   }
   lli m=(s+e)/2;
   create(s,m,2*ind+1);
   create(m+1,e,2*ind+2);
   Tree[ind]=fun1(s,e,Tree[2*ind+1],Tree[2*ind+2]);
 
}
lli query(lli qs,lli qe,lli k)
{
   struct node x= _query(0,v.size()-1,0,qs,qe,k);
   if(x.start.second>=k)
     return x.start.first;
   if(x.end1.second>=k)
     return x.end1.first;
   if(x.mid.second>=k)
     return x.mid.first;
    return -1;
}
int main()
{
    lli n,m,k;
    scanf("%lld%lld",&n,&m);
    v.clear();
    for(int i=0;i<n;i++)
    {
      lli temp;
      scanf("%lld",&temp);
      v.push_back(temp);
    }
    create(0,v.size()-1,0);
    while(m--)
    {
      lli s,e,k;
      scanf("%lld%lld%lld",&s,&e,&k);
      lli z=query(s-1,e-1,k);
      printf("%lld\n",z);
    }
}
 