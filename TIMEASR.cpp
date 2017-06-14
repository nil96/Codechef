#include<bits/stdc++.h>
#define lli long long int
#define gc() getchar_unlocked()
using namespace std;
float angle1=0;
float angle2=0;
float abs1(float x)
{
   if(x<0)
     return -x;
   return x;
}
float cal_angle(float h,float m)
{
   float hour_angle=.5*(h*60+m);
   float minute_angle=6.0*m;
   angle1=abs1(hour_angle-minute_angle);
   angle2=abs1(360.0-angle1);
   return 0.0;
}
char arr[][12]={"00","01","02","03","04","05","06","07","08","09","10","11","12"};
int main()
{
   lli t;
   scanf("%lld",&t);
   while(t--)
   {
      float a=0.0;
      float xl=(1.0/120.0);
      scanf("%f",&a);
      for(lli i=0;i<12;i++)
      {
         for(lli j=0;j<60;j++)
         {
            cal_angle(i,j);
            if(abs1(a-angle1)<xl || abs1(a-angle2)<xl)
            {
               /*printf("xl===%f\n",xl);
               printf("angle1====%f\n",angle1);
               printf("angle2====%f\n",angle2);
               printf("abs1(a-angle1)====%f\n",abs1(a-angle1));
               printf("abs1(a-angle1)====%f\n",abs1(a-angle2));*/
               printf("%s:",arr[i]);
               if(j<10)
                printf("%s\n",arr[j]);
               else
                printf("%lld\n",j);
            }
         }
      }
   }
   return 0;
}