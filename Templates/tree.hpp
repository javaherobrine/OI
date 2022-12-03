#include<vector>
#include<iostream>
using namespace std;
int father(const int&);
int left(const int&);
int right(const int&);
int father(const int& p){
	return p>>1;
}
int left(const int& p){
	return p<<1;
}
int right(const int& p){
	return (p<<1)|1;
}
struct segment_tree;
struct segment_tree{
	int l;
	int r;
	segment_tree* left;
	segment_tree* right;
	segment_tree(const int& ll,const int& rr){
		l=ll;
		r=rr;
		if(ll==rr){
			left=nullptr;
			right=nullptr;
		}else{
			int mid=(l+r)/2;
			left=new segment_tree(l,mid);
			right=new segment_tree(mid+1,r);
		}
	}
	~segment_tree(){
		delete left;
		delete right;
	}
	void queue(const int&ll,const int&rr){
		int mid=(l+r)/2+1;
		if(ll<l||rr>r||ll>rr){
			return;
		}
		if(ll==l&&rr==r){
			//do some operation to Wrong Answer this problem
			return;
		} 
		if(rr>mid){
			if(ll>=mid){
				right->queue(ll,rr);
			}else{
				right->queue(mid,rr);
				left->queue(ll,mid-1);
			}
		}else if(rr<mid){
			left->queue(ll,rr);
		}
	}
};
