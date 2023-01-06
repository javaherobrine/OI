#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int p,w,next=-1;
};
struct Node{
	vector<pair<int,int>> linkto;
};
struct Graph{
	vector<Node> graph;
	Graph(vector<Node> v){
		graph=v;
	}
	Graph(vector<Edge>& edges,vector<size_t>& head){
		graph=vector<Node>(head.size());
		for(size_t i=0;i<head.size();i++){
			size_t current=head[i];
			while(current!=-1){
				graph[i].linkto.push_back({edges[current].p,edges[current].w});
				current=edges[i].next;
			}
		}
	}
	Graph(vector<vector<int>>& matrix,int no_edge){
		graph=vector<Node>(matrix.size());
		for(size_t i=0;i<matrix.size();i++){
			for(size_t j=0;j<matrix.size();j++){
				if(matrix[i][j]!=no_edge){
					graph[i].linkto.push_back({static_cast<int>(j),matrix[i][j]});
				}
			}
		}
	}
};
