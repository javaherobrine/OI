#include<iostream>
using namespace std;
streambuf* inbuf;
streambuf* outbuf;
void init(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	inbuf=cin.rdbuf();
	outbuf=cout.rdbuf();
}
int qr(){
	int sgn{1},abs{0};
	char ch{inbuf->sbumpc()};
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			sgn=-1;
		}
		ch=inbuf->sbumpc();
	}
	while(ch>='0'&&ch<='9'){
		abs=(abs<<3)+(abs<<1);
		abs+=ch^48;
		ch=inbuf->sbumpc();
	}
	return sgn*abs;
}
void qw(int num){
	if(num<0){
		outbuf->sputc('-');
		qw(-num);
		return;
	}
	int t=num/10;
	if(t){
		qw(t);
	}
	outbuf->sputc((num%10)|48);
}
