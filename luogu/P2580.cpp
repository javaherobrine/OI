#include<iostream>
#include<unordered_map>
#include<string>
//URL:https://www.luogu.com.cn/problem/P2580
//Repeat?The keys of map and unordered_map is unique.
//Wrong?If the name isn't mapped,exception will be thrown
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m,n,o;
	unordered_map<string,int>map{};
	string temp;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>temp;
		map.insert({temp,0});//init
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		try{
			o=map.at(temp);
			if(o==0){//if it hasn't appeared
				cout<<"OK"<<endl;
				map.at(temp)=1;//it has appeared now
			}else{
				cout<<"REPEAT"<<endl;
			}
		}catch(exception& e){//if there isn't the student
			cout<<"WRONG"<<endl;
		}
	}
	return 0;
}
