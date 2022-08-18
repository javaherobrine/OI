#include<vector>
#include<iostream>
using namespace std;
int t=0;
int D=0;
vector<int>numbers{};
void Q(int L){
	int i=numbers.size()-1;
	int max=numbers[i];
	for(int j=0;j<L;j++){
		if(max<numbers[i]){
			max=numbers[i];
		}
		i--;
	}
	t=max;
	cout<<t;
}
void A(int n){
	numbers.push_back((t+n)%D);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M;
	cin>>M>>D;
	int num;
	char command;
	for(int i=0;i<M;i++){
		cin>>command>>num;
		if(command=='A'){
			A(num);
		}else{
			Q(num);
		}
	}
	return 0;
}
