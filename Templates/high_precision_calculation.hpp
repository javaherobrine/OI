#include<string>
#include<deque>
#include<cstdint>
#include<unordered_map>
using namespace std;
int at(const unsigned int& lhs,const int& rhs){
	return (lhs&(1<<rhs))>>rhs;
}
char decode[]{'0','1','2','3','4','5','6','7','8','9',
'A','B','C','D','E','F','G',
'H','I','J','K','L','M','N',
'O','P','Q','R','S','T',
'U','V','W','X','Y','Z'};
int encode[]{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,
	0,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,
	25,26,27,28,29,30,31,32,33,34,35,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};
class bigint_bit{
	deque<unsigned int> value;
	bool sign;
	void process(string& abs,const bool& sgn,const unsigned int& base){
		sgn=sign;
	}
public:
	bigint_bit(string& input,const unsigned int& base){
		if(input[0]=='+'){
			input=input.substr(1,input.size());
			process(input,true,base);
		}else if(input[0]=='-'){
			input=input.substr(1,input.size());
			process(input,false,base);
		}else{
			process(input,true,base);
		}
	}
	void operator *=(const bigint_bit& rhs){

	}
	void operator <<=(const unsigned int& rhs){
		int put=rhs/32;
		for(int i=0;i<put;i++){
			value.push_front(0);
		}
		int move=rhs%32;
		int add{0};
		int temp{};
		for(auto iter=value.begin();iter!=value.end();iter++){
			temp=*iter;
			*iter<<=move;
			*iter+=add;
			add=temp>>(32-move);
		}
		if(add>0){
			value.push_back(add);
		}
	}
	int operator [](const unsigned int& rhs){
		return at(value[rhs/32],rhs%32);
	}
	void operator >>=(const unsigned int& rhs){
		int remove=rhs/32;
		for(int i=0;i<remove;i++){
			if(value.size()!=0){
				value.pop_front();
			}
		}
		int move=rhs%32;
		int minus=0;
		int temp;
		for(auto iter=value.rbegin();iter!=value.rend();iter++){
			temp=*iter;
			*iter>>=move;
			*iter+=minus;
			minus=temp<<(32-move);
		}
	}
	void operator <<=(const bigint_bit& rhs){

	}
	void operator +=(const bigint_bit& rhs){

	}
	bigint_bit(const unsigned int& value0){
		if(value<0){
			sign=false;
		}else{
			sign=true;
		}
		value.push_back(max(value0,-value0));
	}
};
