#include<vector>
using namespace std;
class extended_euclidean_algorithm{
private:
	vector<int>qs{};
	vector<int>ss{1,0};
	vector<int>ts{0,1};
	void gen(){
		gen(a,b);
		for(size_t i=1;i<qs.size();i++){
			ss.push_back(ss[i-1]-ss[i]*qs[i-1]);
			ts.push_back(ts[i-1]-ts[i]*qs[i-1]);
		}
		s=ss[ss.size()-1];
		t=ts[ts.size()-1];
		ss.clear();
		ts.clear();
		qs.clear();
		ts.push_back(0);
		ts.push_back(1);
		ss.push_back(1);
		ss.push_back(0);
	}
	void gen(int a,int b){
		int mod=a%b;
		int q=a/b;
		qs.push_back(q);
		if(mod==0){
			gcd=b;
		}else{
			gen(b,mod);
		}
	}
public:
	int a,b;
	int gcd;
	int s,t;//2 values of as+bt=gcd(a,b)
	extended_euclidean_algorithm(int aa,int bb){
		a=aa;
		b=bb;
		s=-1;
		t=-1;
		gcd=-1;
	}
	void change(int aa,int bb){
		a=aa;
		b=bb;
		gen();
	}
};
