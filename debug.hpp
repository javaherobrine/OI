#include<bits/stdc++.h>
using namespace std;
#ifndef ECLIPSE
#define cout cerr
#endif
template<typename T>
void output(const T& val){
	cerr<<val;
}
template<typename T>
void output(const vector<T>& val){
	for(T& v:val){
		output(v);
		cerr<<" ";
	}
	cerr<<endl;
}
template<typename T>
void output(const deque<T>& val){
	for(T& v:val){
		output(v);
		cerr<<" ";
	}
	cerr<<endl;
}
template<typename K,typename V>
void output(const pair<K,V>& val){
	cerr<<"[";
	output(val.first);
	cerr<<",";
	output(val.second);
	cerr<<"]";
}
template<typename K,typename V>
void output(const unordered_map<K,V>& val){
	for(pair<K,V>& v:val){
		output(v);
		cerr<<" ";
	}
	cerr<<endl;
}
template<typename K,typename V>
void output(const map<K,V>& val){
	for(pair<K,V>& v:val){
		output(v);
		cerr<<" ";
	}
	cerr<<endl;
}
template<typename T,typename... Args>
void multi_output(const T& value,const Args&... args){
	if constexpr(sizeof...(args)){
		output(value);
		cerr<<" ";
		multi_output(args...);
	}else{
		output(value);
		cerr<<endl;
	}
}
