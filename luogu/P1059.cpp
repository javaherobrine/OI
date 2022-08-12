#include<set>
#include<iostream>
using namespace std;
//sorted?avoid duplicate?just use set!
//URL:https://www.luogu.com.cn/problem/P1059
int main(){//It's easy to understand LOL
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	int temp;
	set<int>v{};
	for(int i=0;i<n;i++){
		cin>>temp;
		v.insert(temp);
	}
	cout<<v.size()<<endl;
	auto iter=v.begin();
	while(iter!=v.end()){
		cout<<*iter<<" ";
		iter++;
	}
	return 0;
}
