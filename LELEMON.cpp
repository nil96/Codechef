//Little Elephant and Lemonade
#include<stdio.h>
#include<stdlib.h>
#define lli long int
void print(lli *arr,lli n)
{
  int i;
  for(i=0;i<n;i++)
    printf("%ld ",arr[i]);
  printf("\n");
}
void intilize(lli *m_array,lli m)
{
  lli i;
  for(i=0;i<m;i++)
    m_array[i]=0;
}
int cmp(const void *a,const void *b)
{
  if (*(lli*)a < *(lli*)b ) return 1;
  if (*(lli*)a == *(lli*)b ) return 0;
  if (*(lli*)a > *(lli*)b ) return -1;
}
int main()
{
  lli t;
  lli m_array[10010];
  scanf("%ld",&t);
  while(t--)
  {
   // printf("\n===============================\n");
    lli n,m;
    scanf("%ld%ld",&n,&m);
    intilize(m_array,m);
    lli m1=m,temp;
    while(m1--)
    {
       scanf("%ld",&temp);
       m_array[temp]++;
    }
    lli n1=n;
    lli count=-1;
    lli buffer[1000];
    lli sum=0;
    while(n--)
    {
       count++;
       lli size;
       scanf("%ld",&size);
       lli i=0,size1=size;
       intilize(buffer,105);
       while(size--)
       {
         scanf("%ld",&buffer[i]);
         i++;
       }
       qsort(buffer,size1,sizeof(buffer[0]),cmp);
       for(i=0;i<m_array[count];i++)
       {
         sum=sum+buffer[i];
       }
    }
    printf("%ld\n",sum);
  }
}