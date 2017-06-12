#include<stdio.h>
#include<stdlib.h>
void print(int *a,int n)
{
  int i;
  for(i=0;i<n;i++)
   printf("%d ",a[i]);
  printf("\n");
}
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
     int total,complete,job_com,i;
     scanf("%d",&total);
     scanf("%d",&complete);
     int *a=(int *)calloc((total+1),sizeof(int));
     for(i=1;i<=complete;i++)
     {
        scanf("%d",&job_com);
        a[job_com]=1;
     }
     /*printf("a\n");
     print(a,total+1);*/
     int *buf=(int *)malloc((total+1)*sizeof(int));//record 1st
     int  flag=0,buf_k=0;
     int *buf1=(int *)malloc((total+1)*sizeof(int));//record 2nd
     int buf1_k=0;
     for(i=1;i<=total;i++)
     {
       if(a[i]==0 && flag==0)
       {
          buf[buf_k]=i;
          buf_k++;
          flag=1;
       }
       else if(a[i]==0 && flag==1)
       {
          buf1[buf1_k]=i;
          buf1_k++;
          flag=0;
       }
     }
    /* printf("buf\n");
     print(buf,buf_k);
     printf("buf1\n");
     print(buf1,buf1_k);*/
     for(i=0;i<buf_k;i++)
       printf("%d ",buf[i]);
     printf("\n");
     for(i=0;i<buf1_k;i++)
       printf("%d ",buf1[i]);
     printf("\n");
     free (a);
     a=NULL;
     free (buf);
     buf=NULL;
     free (buf1);
     buf1=NULL;
   }
}