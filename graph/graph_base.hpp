#ifndef GRAPH_BASE_HPP
#define GRAPH_BASE_HPP
#include<vector>
struct Edge{
	int to;
};
struct Node{
	std::vector<Edge> linkto;
};
#endif
