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
int gcd(const int& a,const int& b){
	if(b==0){
		return a;
	}else{
		return gcd(b,a%b);
	}
}
int stone=0,scissors=0,paper=0;
int main(){
	freopen("rps.in","r",stdin);
	freopen("rps.out","w",stdout);
	ios::sync_with_stdio(false);
	inbuf=cin.rdbuf();
	int n;
	cin>>n;
	int input;
	for(int i=0;i<n;i++){
		cin>>input;
		stone+=input;
		cin>>input;
		scissors+=input;
		cin>>input;
		paper+=input;
	}
	int g=gcd(stone,gcd(scissors,paper));
	stone/=g;
	scissors/=g;
	paper/=g;
	int sum=stone+scissors+paper;
	double result=0;
	result+=scissors*(scissors*3+stone)/double(sum);
	result+=stone*(stone*3+paper)/double(sum);
	result+=paper*(paper*3+scissors)/double(sum);
	cout<<result;
	return 0;
}
