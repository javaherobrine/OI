#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
	int heavy,father,depth,size=1,top,DFN;
	vector<int> linkto;
};
void dfs0(vector<TreeNode>& tree,int father,int depth,int root){
	TreeNode& n=tree[root];
	n.depth=depth;
	n.father=father;
	for(int next:n.linkto){
		if(next==father){
			continue;
		}
		dfs0(tree,root,depth+1,next);
		n.size+=tree[next].size;
		if(!n.heavy||tree[n.heavy].size<tree[next].size){
			n.heavy=next;
		}
	}
}
static int time=0;
void dfs1(vector<TreeNode>& tree,int father,int top,int root){
	TreeNode& n=tree[root];
	n.top=top;
	n.DFN=time;
	time++;
	if(n.heavy){
		dfs1(tree,root,root,n.heavy);
	}
	for(int next:n.linkto){
		if(next!=father&&next!=n.heavy){
			dfs1(tree,root,next,next);
		}
	}
}
int LCA(vector<TreeNode>& tree,int x,int y){
	TreeNode& p=tree[x];
	TreeNode& q=tree[y];
	if(p.top==q.top){
		return p.depth<q.depth?x:y;
	}
	if(p.depth>q.depth){
		return LCA(tree,tree[p.top].father,y);
	}else{
		return LCA(tree,x,tree[q.top].father);
	}
}
