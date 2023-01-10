/*
 * URL:https://www.luogu.com.cn/problem/P1931
 * gain money?SSSP!
 * if one of distance[i][i] is greater than 0,the answer is true
 * or it's false.
 */
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> hashier;
int current_hash{0};
int hash_string(const string& str){//like std::hash<string> but it's simple
	if(!hashier.count(str)){//if it hasn't been hashed
		hashier[str]=current_hash;//hash it
		current_hash++;
	}
	return hashier[str];
}
void clear(){//or you will Wrong Answer and even Runtime Error this problem
	hashier.clear();
	current_hash=0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	int count=1;
	for(;n!=0;cin>>n){//There are many groups of data~
		cout<<"Case "<<count<<": ";
		vector<vector<double>> graph(n,vector<double>(n,0));//use a matrix to store graph
		for(int i=0;i<n;i++){
			string input;
			cin>>input;
			int n=hash_string(input);
			graph[n][n]=1;//input money
		}
		int m;
		cin>>m;
		for(int i=0;i<m;i++){
			string p,q;
			double m;
			cin>>p>>m>>q;//input rate
			graph[hash_string(p)][hash_string(q)]=m;//edge
		}
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					//Floyd Algorithm
					/*
					 * It's a DP Algorithm
					 * The equation: distance[i][k]=min(distance[i][j],distance[i][k]+distance[k][j])
					 * Each loop will insert a node and try to relax
					 */
					graph[i][j]=max(graph[i][j],graph[i][k]*graph[k][j]);
				}
			}
		}
		bool flag=1;
		for(int i=0;i<n;i++){
			if(graph[i][i]>1){//ans
				flag=0;
				cout<<"Yes\n";
				break;
			}
		}
		if(flag){
			cout<<"No\n";
		}
		count++;
		clear();//or Compile Error,Wrong Answer,Rumtime Error,Time Limit Exceeded,Memory Limit Exceeded
	}
}
