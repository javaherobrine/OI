#include<bits/stdc++.h>
using namespace std;
streambuf* inbuf;
int qr(){
	char ch=inbuf->sbumpc();
	int abs,sgn=1;
	while(ch>'9'||ch<'0'){
		if(ch=='-'){
			sgn*=-1;
		}
		ch=inbuf->sbumpc();
	}
	while(ch<='9'&&ch>='0'){
		abs=(abs<<3)+(abs<<1);
		abs+=ch^48;
		ch=inbuf->sbumpc();
	}
	return sgn*abs;
}
unsigned long long C(unsigned long long m,unsigned long long n){
	if(n==m){
		return 1;
	}
	if(n<m-n){
		return C(m,m-n);
	}
	unsigned long long time=1;
	unsigned long long result=1;
	for(unsigned long long i=n+1;i<=m;i++){
		result*=i;
		result/=time;
		result%=998244353;
		time++;
	}
	return result;
}
int main(){
	ios::sync_with_stdio(false);
	inbuf=cin.rdbuf();
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	unsigned long long n,m,k;
	cin>>n>>m>>k;
	if(m<n||m>n*k){
		cout<<0;
		return 0;
	}
	k+=1;
	cerr<<m<<endl;
	cerr<<n<<endl;
	unsigned long long result=C(m-1,n-1);
	cerr<<result<<endl;
	int p=m-k-1;
	for(;p>=n-2;p--){
		result-=C(p,n-2)*n;
		if(result<0){
			result+=998244353;
		}
	}
	cout<<result;
	return 0;
}
