#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	int N;
	cin>>N;
	int sum_threads{0};
	vector<vector<unsigned long long>>time{};
	int k;
	int input;
	for(int i=0;i<N;i++){
		time.push_back({0});
		cin>>k;
		sum_threads+=k;
		for(int j=0;j<k;j++){
			cin>>input;
			time[i].push_back(input+time[i][j]);
		}
	}
	int M;
	cin>>M;
	M--;
	int p;
	int index;
	long long sum=0;
	for(vector<unsigned long long> v:time){
		p=sum_threads-v.size()+1;
		index=max(M-p,0);
		sum+=*(v.rbegin())-v[index];
		sum%=int(1e9+7);
	}
	cout<<sum%int(1e9+7);
}
