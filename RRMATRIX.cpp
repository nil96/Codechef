  #include<stdio.h>
    int t;
    int gcd(int a,int b){while(b!=0){
    t=b;b=a%t;a=t;
    }return a;}
    inline int fast_int(){
    int n=0;
    int ch=getchar_unlocked();
    while(ch<48)
    ch=getchar_unlocked();
    while(ch>47)
    n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
    return n;
    }
    int main(){
    register unsigned int t1;
    t1=fast_int();
    while(t1--){
    printf("%d\n",(gcd(fast_int()-1,fast_int()-1)+1));
    }
    return 0;
    }
