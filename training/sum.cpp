#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	unsigned long long OR,XOR,AND;
	for(int i=0;i<T;i++){
		cin>>OR;
		cin>>XOR;
		if((OR|XOR)>OR){
			cout<<-1<<"\n";
		}else{
			AND=OR-XOR;
			cout<<XOR+(AND<<1)<<"\n";
		}
	}
}
