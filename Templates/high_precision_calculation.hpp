#include<string>
#include<deque>
using namespace std;
class BigInteger{//BigDecimal = BigInteger with scale
private:
	deque<int8_t>array{};
	bool isNegate;
	void multi10(){
		if(array[array.size()-1]==0){
			return;
		}else{
			array.push_front(0);
		}
	}
public:
	void operator +=(const BigInteger rhs){

	}
	BigInteger(string s){
		auto iter=s.begin();
		if(*iter=='-'){//<0
			isNegate=true;
			iter++;
		}else if(*iter=='+'){
			isNegate=false;
			iter++;
		}else{
			isNegate=false;
		}
		while(iter!=s.end()){
			array.push_back(sgn()*((*iter)-'0'));//make every bit gets its negate if the number<0
			iter++;
		}
		for(int i=0;i<array.size()/2;i++){
			swap(array[i],array[array.size()-1-i]);//reverse the vector
		}
	}
	inline int& sgn(){
		return isNegate*2-1;
	}
};
