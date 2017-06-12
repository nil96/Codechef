#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define gc() getchar()
int myfun(lli x)
{
    if(x<0)
      return 0;
    return x;
 
}
int main()
{
    lli t;
    scanf("%lld",&t);
    while(t--)
    {
      lli a;
      char buff[100];
      lli ans=0;
      lli m=0;
      scanf("%lld",&a);gc();
      //printf("a=========%lld \n",a);
      scanf("%s",buff);gc();
      if(strcmp(buff,"INDIAN")==0)
         m=200;
      else
         m=400;
      while(a--)
      {
        scanf("%s",buff);gc();
        if(strcmp(buff,"CONTEST_WON")==0)
        {
            lli temp;
            scanf("%lld",&temp);gc();
            ans=ans+300+myfun(20-temp);
        }
        else if(strcmp(buff,"TOP_CONTRIBUTOR")==0)
          ans+=300;
        else if(strcmp(buff,"BUG_FOUND")==0)
        {
             lli temp;
            scanf("%lld",&temp);gc();
            ans=ans+temp;
        }
        else if(strcmp(buff,"CONTEST_HOSTED")==0)
         ans+=50;
        else
        {
            printf("Eroor\n");
        }
      }
     // printf("ans====%lld\n",ans);
      printf("%lld\n",ans/m);
     // printf("m====%lld\n",m);
      ans=0;
    }
 
 
}
 
Submission Info: