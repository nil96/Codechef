#include<stdio.h>
#include<stdlib.h>
#define li long int
#define infinty 1000000008
struct node
{
  li a0;
  li d0;
};
struct node arr[20];
void intilize(li n,li k)
{
  li i;
  for(i=0;i<=k+2;i++)
  {
     arr[i].a0=0;
     arr[i].d0=0;
  }
}
void print(li last)
{
  li i;
  for(i=0;i<=last;i++)
    printf("%ld ",arr[i].a0);
  printf("\n");
  for(i=0;i<=last;i++)
    printf("%ld ",arr[i].d0);
 
}
li push(li temp_a0,li temp_d0)
{
   static li i=0,j;
   if(i==0)
   {
     arr[i].a0=temp_a0;
     arr[i].d0=temp_d0;
     i++;
   }
   else
   {
     for(j=0;j<i;j++)
     {
       if(arr[j].a0==temp_a0 && arr[j].d0==temp_d0)
       {
           return i-1;
       }
     }
     arr[i].a0=temp_a0;
     arr[i].d0=temp_d0;
     i++;
     return i-1;
   }
   return i-1;
}
 
li get(li *temp_a0,li *temp_d0,li last)
{
   li i,j,index=-1;
   li ta0=infinty-1,td0=infinty-1;
   for(j=0;j<=last;j++)
   {
       if(ta0>arr[j].a0)
       {
         ta0=arr[j].a0;
         td0=arr[j].d0;
         index=j;
       }
       if(ta0==arr[j].a0)
       {
         ta0=arr[j].a0;
         td0=arr[j].d0;
         index=j;
       }
   }
   if(index>=0)
   {
      arr[index].a0=infinty+5;
      arr[index].d0=infinty+5;
   }
   *temp_a0=ta0;
   *temp_d0=td0;
   return index;
}
 
 
//
int main()
{
  li n,k,n1;
  scanf("%ld%ld",&n,&k);
  n1=n;
  li *a=(li *)calloc(n+5,sizeof(li));
  li i=0;
  while(n1--)
  {
   scanf("%ld",&a[i]);
   i++;
  }
  li temp_d0,temp_a0,last;
  for(i=1;i<n;i++)
  {
    temp_d0=a[i]-a[i-1];
    temp_a0=a[i]-i*temp_d0;
    last=push(temp_a0,temp_d0);
    //printf("last====%ld\n",last);
 
    /*temp_d0=a[i-1]-a[i];
    temp_a0=a[i]-i*temp_d0;
    last=push(temp_a0,temp_d0);
    printf("last====%ld\n",last);*/
  }
 // printf("------------------------------------------------------------\n");
 // print(last);
 // printf("------------------------------------------------------------\n");
  li j;
  li *buffer=(li *)calloc(n+5,sizeof(li));
  li flag;
  for(j=0;j<=last;j++)
  {
    li l=0;
    flag=get(&temp_a0,&temp_d0,last);
   // printf("------------------------------------------------------------\n");
   // printf("a0===%ld d0===%ld\n",temp_a0,temp_d0);
    //printf("------------------------------------------------------------\n");
    if(flag<0)
    {
         break;
    }
    for(i=0;i<n;i++)
    {
      buffer[i]=temp_a0+i*temp_d0;
      if(buffer[i]!=a[i])
        l++;
      if(l>k)
      {
        break;
      }
    }
    if(i==n)
    {
     //got solution
     break;
    }
  }
  for(i=0;i<n;i++)
    printf("%ld ",buffer[i]);
  return 0;
}