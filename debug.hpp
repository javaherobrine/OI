/*
 * A header file for me to debug
 * use output function to output a single variable
 * use multi_output function to output a number of variables
 * use #define NSTDERR to disable stderr
 * if there is no macro named NSTDERR, your stdout will be replaced with stderr
 * otherwise, your stderr will be replaced with stdout
 * or the output will get mixed
 */
#ifndef DEBUG_HPP
#define DEBUG_HPP
#include<bits/stdc++.h>
using namespace std;
#ifndef NSTDERR
#define cout cerr
#else
#define cerr cout
#endif
template<typename T>
void output(const T& val);
template<typename T>
void output(const vector<T>& val);
template<typename T>
void output(const deque<T>& val);
template<typename K,typename V>
void output(const pair<K,V>& val);
template<typename K,typename V>
void output(const unordered_map<K,V>& val);
template<typename K,typename V>
void output(const map<K,V>& val);
template<typename T>
void output(const T& val){
	cerr<<val;
}
template<typename T>
void output(const vector<T>& val){
	for(auto&& v:val){
		output(v);
		cerr<<" ";
	}
	cerr<<endl;
}
template<typename T>
void output(const deque<T>& val){
	for(auto&& v:val){
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
	for(auto&& v:val){
		output(v);
		cerr<<" ";
	}
	cerr<<endl;
}
template<typename K,typename V>
void output(const map<K,V>& val){
	for(auto&& v:val){
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
#endif
