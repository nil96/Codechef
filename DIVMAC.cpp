#include<bits/stdc++.h>
#define lli int
#define size1 1000060
using namespace std;
vector<lli> v;
lli arr[size1];
lli tree[4*size1+4];
lli lazy[4*size1+4];
#define gc getchar_unlocked
int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
void calculate_prime_divisor(lli x)
{
    if(arr[x]!=-1)
        return;
    for(lli i=1,j=x*x;j<size1;i++,j=j+x)
    {
        if(arr[j]==-1)
          arr[j]=x;
    }
    return;
}
void pre_calculate()
{
    arr[0]=1;
    arr[1]=1;
    for(lli i=2;i<size1-3;i++)
        arr[i]=-1;
    lli z=sqrt(size1);
    for(lli i=2;i<z+10;i++)
       calculate_prime_divisor(i);
    for(lli i=0;i<size1-3;i++)
    {
       if(arr[i]==-1)
         arr[i]=i;
    }
 
}
void build(lli node,lli s,lli e)
{
 
    if(s>e)
        return;
    if(s==e)
    {
        tree[node]=arr[v[s]];
    }
    else
    {
        lli m=(s+e)/2;
        build(2*node+1,s,m);
        build(2*node+2,m+1,e);
        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }
}
lli que=0;
lli query(lli node,lli s,lli e,lli l,lli r)
{
     if(s>e)
        return 1;
    if(r<s || e<l)
        return 1;
    if(l<=s && e<=r)
        return tree[node];
    lli m=(s+e)/2;
    lli p1=query(2*node+1,s,m,l,r);
    lli p2=query(2*node+2,m+1,e,l,r);
    return max(p1,p2);
}
void update(lli node,lli s,lli e,lli l,lli r)
{
 
    if(s>e || s>r || e<l)
        return ;
    if(s==e)
    {
      v[s]=v[s]/arr[v[s]];
      tree[node]=arr[v[s]];
      return;
    }
    lli m=(s+e)/2;
    update(node*2+1,s,m,l,r);
    update(node*2+2,m+1,e,l,r);
    tree[node]=max(tree[node*2+1],tree[node*2+2]);
}
vector<lli> ans;
int main()
{
    lli t;
    pre_calculate();
 //   printf("arr[10007]==%d\n",arr[10007]);
    //scanf("%d",&t);
    t=read_int();
    //printf("t=====%d\n",t);
    lli x=0;
    while(t--)
    {
        lli n,m;
        //scanf("%d%d",&n,&m);
        n=read_int();
        m=read_int();
        v.clear();ans.clear();
        for(lli i=0;i<n;i++)
        {
            lli temp;
            temp=read_int();
            //scanf("%d",&temp);
            v.push_back(temp);
        }
        build(0,0,n-1);
        int cnt=0;
        x++;
        while(m--)
        {
            cnt++;
            lli a,b,c;
            //scanf("%d%d%d",&a,&b,&c);
            a=read_int();
            b=read_int();
            c=read_int();
            if(a==0)
            {
               update(0,0,n-1,b-1,c-1);
            }
            if(a==1)
            {
               lli x=query(0,0,n-1,b-1,c-1);
               ans.push_back(x);
            }
        }
        for(lli i=0;i<ans.size();i++)
          printf("%d ",ans[i]);
        printf("\n");
    }
}
 