#include<bits/stdc++.h>
#define lli long long int
using namespace std;
vector<lli> v;
int fun(lli a,lli b)
{
    return a<b;
}
lli abx(lli m)
{
    if(m<0)
        return 0;
    return m;
}
lli fun1(lli x)
{
    return abx(x-v[2]);
}
lli fun2(lli x)
{
    lli t=v[x];
    for(lli i=x;i<6;i++)
    {
        v[i]=abx(v[i]-t);
    }
    return t;
}
void print()
{
     printf("\n----------------------------------\n");
    for(lli i=0;i<v.size();i++)
        printf("%lld ",v[i]);
    printf("\n----------------------------------\n");
}
int main()
{
    lli t;
    scanf("%lld",&t);
    for(lli i=0;i<6;i++)
     v.push_back(0);
    while(t--)
    {
        lli p,tie_f=0;
        lli index=0,max1=-1;
        scanf("%lld",&p);
        for(lli i=0;i<p;i++)
        {
            lli n;
            for(lli k=0;k<6;k++)
               v[k]=0;
            scanf("%lld",&n);
            for(lli j=0;j<n;j++)
            {
               lli temp;
               scanf("%lld",&temp);
               v[temp-1]++;
            }
            //print();
            sort(v.begin(),v.end(),fun);
            lli ans=0;
            /*lli m=fun2(0);
         //   print();
            ans=ans+m*10;
            m=fun2(1);
       //     print();
            ans=ans+m*7;
             m=fun2(2);
     //        print();
            ans=ans+m*5;
            ans=ans+v[3]+v[4]+v[5];*/
 
            ans=ans+v[0]*10;//6
            ans=ans+abx((v[1]-v[0])*7);//5
            ans=ans+abx((v[2]-v[1])*5);
            ans=ans+fun1(v[3])+fun1(v[4])+fun1(v[5]);
            //printf("ans====%lld\n",ans);
            if(ans>max1)
            {
                index=i;
                max1=ans;
                tie_f=-1;
            }
            else if(ans==max1)
                tie_f=0;
        }
        if(tie_f==0)
            printf("tie\n");
        else if(index==0)
            printf("chef\n");
         else
            printf("%lld\n",index+1);
    }
}
 