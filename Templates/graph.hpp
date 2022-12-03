#include"union_find.hpp"
#include<vector>
#include<algorithm>
using namespace std;
struct Node;
struct Edge;
int kruskal(vector<Edge>&);
struct Edge{
	int p,q,w;
	bool operator <(const Edge& rhs) const{
		return w<rhs.w;
	}
};
#include<bits/stdc++.h>
using namespace std;
struct Node{
	vector<pair<int,int>> linkto;//first:next and second:weight
};
vector<int> dijkstra(vector<Node>& graph,int source){//Index starts from 0 instead of 1
	vector<int> dis(graph.size(),2147483647);
	vector<bool> color(graph.size(),false);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({0,source});
	dis[source]=0;
	while(q.size()){
		pair<int,int> p=q.top();
		q.pop();
		if(color[p.second]){
			continue;
		}
		color[p.second]=true;
		for(auto iter=graph[p.second].linkto.begin();iter!=graph[p.second].linkto.end();iter++){
			if(color[iter->first])
				continue;
			dis[iter->first]=min(iter->second+p.first,dis[iter->first]);
			q.push({dis[iter->first],iter->first});
		}
	}
	return dis;
}
int kruskal(vector<Edge>& node){//compute MST
	union_find uf{114514};
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
