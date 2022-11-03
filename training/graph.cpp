#include<bits/stdc++.h>
using namespace std;
streambuf* inbuf;
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
//	freopen("graph.in","r",stdin);
//	freopen("graph.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,l,r;
	cin>>n>>l>>r;
	vector<string> order;
	for(int i=1;i<=n;i++){
		order.push_back(to_string(i));
	}
	sort(order.begin(),order.end());
	int current_index=1;
	int sum;
	int i;
	n--;
	n*=2;
	for(i=n;;i-=2){
		sum+=i;
		if(sum>=l){
			break;
		}
		current_index++;
	}
	current_index--;
	int miss=sum-l;
	int get=i-miss;
	for(;l<=r&&i!=0;l++){
		if(get>i){
			get=1;
			i-=2 or_eq 1;
			current_index++;
		}
		if(get%2==0){
			cout<<order[get/2+current_index]<<" ";
			get++;
			continue;
		}
		cout<<order[current_index]<<" ";
		get++;
	}
	if(l==r){
		cout<<1;
	}
	return 0;
}
