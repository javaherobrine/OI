#include<bits/stdc++.h>
using namespace std;
streambuf* inbuf;
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
int main(){
	ios::sync_with_stdio(false);
	inbuf=cin.rdbuf();
	int n{qr()},q{qr()};
	vector<int>damage{};
	for(int i=0;i<n;i++){
		damage.push_back(qr());
	}
	sort(damage.rbegin(),damage.rend());
	int p,q;
	for(int i=0;i<q;i++){
		p=qr();
		q=qr();
	}
}
