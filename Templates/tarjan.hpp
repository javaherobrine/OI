#include<bits/stdc++.h>
using namespace std;
struct Node{
	int dfn=0,low;
	bool is_in_stack=0;
	vector<int> linkto;
};
stack<int> s;
int current=1;
void tarjan(int source,vector<Node>& graph,vector<vector<int>>& ans){
	Node& n=graph[source];
	n.dfn=current;
	n.low=n.dfn;
	n.is_in_stack=1;
	s.push(source);
	current++;
	for(int i:n.linkto){
		if(graph[i].dfn){
			if(graph[i].is_in_stack){
				n.low=min(n.low,graph[i].dfn);
			}
		}else{
			tarjan(i,graph,ans);
			n.low=min(n.low,graph[i].low);
		}
	}
	if(n.dfn==n.low){
		vector<int> temp;
		while(s.top()!=source){
			temp.push_back(s.top());
			graph[s.top()].is_in_stack=0;
			s.pop();
		}
		temp.push_back(s.top());
		graph[s.top()].is_in_stack=0;
		s.pop();
		ans.push_back(temp);
	}
}
