//Hello Hello
#include<stdio.h>
#include<stdlib.h>
struct call
{
 float plan_valid;
 float call_rate;
 float cost_of_plan;
};
int main()
{
  int t,no;
  float default_rate=0.0f,talk_last_month,temp1,temp2,temp3;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%f%f%d",&default_rate,&talk_last_month,&no);
    //printf("%f %f %d\n",default_rate,talk_last_month,no);
    struct call *c=(struct call*)malloc((no+2)*sizeof(struct call));
    int i=1;
    while(i<=no)
    {
        fflush(stdin);
        scanf("%f",&c[i].plan_valid);
        scanf("%f",&c[i].call_rate);
        scanf("%f",&c[i].cost_of_plan);
        i++;
    }
    int ans=0;
    float low1=default_rate*talk_last_month,low=0.0f;
    for(i=1;i<=no;i++)
    {
        low=(talk_last_month*c[i].call_rate)+(c[i].cost_of_plan/c[i].plan_valid);
        //printf("low1====%f\n",low1);
       // printf("low======%f\n",low);
       if(low1<=low)
         continue;
       else if(low1>low)
       {
          low1=low;
          ans=i;
       }
    }
     printf("%d\n",ans);
  }
  return 0;
}
 