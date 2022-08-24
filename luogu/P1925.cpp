#include<iostream>
#include<cmath>
#include<numeric>
using namespace std;
const long double E=exp(1);
/*
 * URL:https://www.luogu.com.cn/problem/P1925
 * The maximum of P?We know N is a constant,P is only related to k, we want to know the analytical formula of the function.
 * Suppose m=N/k(k is an integer),and P=f(k)=m^k=(N/k)^k.
 * Make its derivative 0 to gets its maximum.
 * Just take its derivative.
 * f(k)=(N/k)^k
 * ln(f(k))=k*ln(N/k)
 * (ln(f(k)))'=(k*ln*(N/k))'
 * f'(k)/f(k)=k'*ln(N/k)+k*(ln(N/k))'=ln(N/k)+k*(lnN-lnk)'=ln(N/k)+k*ln'N-k*ln'k=ln(N/k)+k*ln'N-k*1/k=ln(N/k)+k*ln'N-1
 * Because N is a constant,lnN is a constant.
 * So f'(k)/f(k)=ln(N/k)+k*0-1=ln(N/k)-1
 * f'(k)=f(k)*[ln(N/k)-1]=(N/k)^k*[ln(N/k)-1]
 * f'(k)=0
 * (N/k)^k*[ln(N/k)-1]=0
 * ln(N/k)-1=0 or (N/k)^k=0(That's impossible)
 * ln(N/k)=1
 * N/k=e
 * k=N/e
 * Because k is an integer,
 * the maximum value of P is obtained at k=ceil(N/e) or k=floor(N/e)
 * Is it hard?No,it's easy!
 */
inline int D(int a){
    int x0=a/E;
    int x1=x0+1;
    long double d1=log((((double)a)/x0))*x0;
    long double d2=log((((double)a)/x1))*x1;
    if(d1>d2){//Choose the greater maximum value
        int g=x0/gcd(a,x0);
        /*
         * Suppose a rational number p/q(p and q are coprime),If and only if prime factors of q only contains 2 and 5,
         * p/q is a finite decimal
         */
        while(g%2==0)g/=2;
        while(g%5==0)g/=5;
        if(g==1){//if the value is a finite decimal
            return -a;
        }else{
            return a;
        }
    }else{
        int g=x1/gcd(a,x1);
        while(g%2==0)g/=2;
        while(g%5==0)g/=5;
        if(g==1){
            return -a;
        }else{
            return a;
        }
    }
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a;
    int r{};
    cin>>a;
    for(int i=5;i<=a;i++){//compute D(5)+D(6)+...+D(a)
        r+=D(i);
    }
    cout<<r<<endl;
}
