#include<vector>
#include<stack>
#include<iostream>
using namespace std;
struct TreeNode{
	vector<int> linkto;
	//other information
};
void dfs(vector<TreeNode>& tree,int root){
	stack<int> DFS{};
	DFS.push(root);
	vector<bool> vis(tree.size(),false);
	while(DFS.size()){
		int node=DFS.top();
		DFS.pop();
		vis[node]=true;
		//more operations
		for(auto iter=tree[node].linkto.begin();iter!=tree[node].linkto.end();iter++){
			//more operations
			if(vis[*iter]){
				continue;
			}else{
				DFS.push(*iter);
			}
		}
	}
}
