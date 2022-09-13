/*
 * Quick read and quick write based on iostream
 * Faster than getchar() and putchar()
 * Remember to use ios::sync_with_stdio(false) and cin.tie(nullptr)
 * Just use IO::inbuf=cin.rdbuf() and IO::outbuf=cout.rdbuf()
 * Then use read and write
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
		if(ch=='-'){//get the number's sign
			sgn*=-1;
		}
		ch=IO::getchar();
	}
	while(ch>='0'&&ch<='9'){
		val=val<<3+val<<1;//area for the next digit
		val+=ch^48;//input the next digit
		ch=IO::getchar();
	}
	return sgn*val;//the value of the number is its sign multiplies its absolute value
}
void write(long long val){
	if(val<0){//if it's a negative number
		IO::putchar('-');
		val=-val;
	}
	if(val>9){//print its high bit
		//Why can't I use if(val==0) return;?This is your homework!
		write(val/10);
	}
	IO::putchar(val%10+'0');
}
