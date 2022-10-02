#include<bits/stdc++.h>
using namespace std;
streambuf* inbuf;
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	ios::sync_with_stdio(false);
	inbuf=cin.rdbuf();
	int n{},m{};
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}else{
		cout<<2;
		return 0;
	}
}
