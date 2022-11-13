#include"union_find.hpp"
#include<vector>
#include<algorithm>
using namespace std;
struct Node;
struct Edge;
int kruskal(vector<Edge>&);
struct Node{
	vector<pair<Node,int>>linkto;
};
struct Edge{
	int p,q,w;
	bool operator <(const Edge& rhs) const{
		return w<rhs.w;
	}
};
vector<Edge> get_edges(vector<Node>& node){

}
int kruskal(vector<Edge>& node){//compute MST
	union_find uf{};
	int sum=0;
	sort(node.begin(),node.end());
	for(auto iter=node.begin();iter!=node.end();iter++){
		if(uf.is_connected(iter->p,iter->q)){
			continue;
		}else{
			sum+=iter->w;
			uf.union_elements(iter->p,iter->q);
		}
	}
	return sum;
}
