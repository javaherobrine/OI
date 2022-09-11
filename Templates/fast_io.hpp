/*
 * Quick read and quick write based on iostream
 * Faster than getchar() and putchar()
 * Remember to use ios::sync_with_stdio(false) and cin.tie(nullptr)
 */
#include<iostream>
using namespace std;
namespace IO{
	streambuf* inbuf=nullptr;
	streambuf* outbuf=nullptr;
	char getchar(){
		return inbuf->sbumpc();
	}
	void putchar(char c){
		outbuf->sputc(c);
	}
}
long long read(){
	char ch=IO::getchar();
	long long sgn{1},val{};
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			sgn*=-1;
		}
		ch=IO::getchar();
	}
	while(ch>='0'&&ch<='9'){
		val*=10;
		val+=ch-'0';
		ch=IO::getchar();
	}
	return sgn*val;
}
void write(long long val){
	if(val<0){
		IO::putchar('-');
		val=-val;
	}
	if(val==0){
		return;
	}else{
		write(val/10);
		IO::putchar(val%10+'0');
	}
}
