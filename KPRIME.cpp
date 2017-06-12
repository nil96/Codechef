#include<stdio.h>
#include<stdlib.h>
#define lli long long int
#define range 100000
#define range_sqrt 320
int a[range+5]={-1};
int b[6][range];
void prime()
{
  lli i,j;
  for(i=2;i<=range_sqrt;i++)
  {
     j=i*i;
     while(j<=range)
     {
        a[j]=0;
        j=j+i;
     }
  }
}
void intilize(int *a)
{
  lli i;
  for(i=2;i<=range;i++)
   a[i]=-1;
}
void operation()
{
  lli i,j,k;
  for(i=2;i<=range;i++)
  {
    if(a[i]!=-1)
     continue;
    else if(a[i]==-1)
    {
       j=1;
       a[i]=0;
       while(1)
       {
         k=i*j;
         if(k>range)
           break;
         a[k]++;
         j++;
       }
    }
  }
}
/*void print1()
{
  lli i;
  for(i=2;i<=range;i++)
   printf("%lld ",i);
   printf("\n");
  for(i=2;i<=range;i++)
   printf("%d ",a[i]);
   printf("\n");
  for(i=2;i<=range;i++)
   printf("%d ",b[1][i]);
}*/
/*void print(int *a)
{
  lli i,count=0,l;
  for(i=2;i<=range;i++)
  {
     if(a[i]==1)
     {
      l=i;
      // printf("%lld======%d\n",i,a[i]);
       count++;
     }
  }
}*/
void optimising()
{
  int count[5];
  lli i;
  count[1]=0;count[2]=0;count[3]=0;count[4]=0;count[5]=0;
  for(i=2;i<=range;i++)
  {
    switch(a[i])
    {
       case 1:
            {
              count[1]++;
              break;
            }
      case 2:
            {
              count[2]++;
              break;
            }
     case 3:
            {
              count[3]++;
              break;
            }
     case 4:
            {
              count[4]++;
              break;
            }
    case 5:
            {
              count[5]++;
              break;
            }
 
    default:
           {
             break;
           }
 
    }
    b[1][i]=count[1];
    b[2][i]=count[2];
    b[3][i]=count[3];
    b[4][i]=count[4];
    b[5][i]=count[5];
  }
 // printf("b[1][99991]===%d\n",b[1][99991]);
}
lli answer(lli l,lli z,lli k)
{
  lli ans=b[k][z]-b[k][l];
 // printf("b[%lld][%lld]====%d   b[%lld][%lld]====%d ans=%lld\n",k,z,b[k][z],k,l,b[k][l],ans);
  if(a[l]==k)
   ans++;
 // printf("%lld\n",ans);
  return ans;
}
int main()
{
  lli t,A,B,K;
  intilize(a);
  prime();
  operation();
  //print(a);
  optimising();
  scanf("%lld",&t);
  while(t--)
  {
      scanf("%lld%lld%lld",&A,&B,&K);
      A=answer(A,B,K);
      printf("%lld\n",A);
  }
}
 