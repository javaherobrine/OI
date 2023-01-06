#include<vector>
using namespace std;
struct SegmentTreeNode{
	int ans,l,r,id,lazy;
};
int father(int x){
	return x>>1;
}
int left(int x){
	return x<<1;
}
int right(int x){
	return (x<<1)|1;
}
struct SegmentTree{
	SegmentTree(vector<int>& seq){
		tree=vector<SegmentTreeNode>(seq.size()<<2);
		build(1,0,tree.size()-1,seq);
	}
	int ask(int l,int r){
		return ask(1,l,r);
	}
	void modify(int l,int r,int add){
		modify(1,l,r,add);
	}
private:
	void pushup(int id){
		tree[id].ans=tree[left(id)].ans+tree[right(id)].ans;
	}
	void pushdown(int id){
		SegmentTreeNode& n=tree[id];
		if(n.l==n.r){
			n.lazy=0;
			return;
		}
		SegmentTreeNode& left=tree[left(id)];
		SegmentTreeNode& right=tree[right(id)];
		left.lazy+=n.lazy;
		right.lazy+=n.lazy;
		left.ans+=n.lazy*(left.r-left.l+1);
		right.ans+=n.lazy*(right.r-right.l+1);
		n.lazy=0;
	}
	void build(int id,int l,int r,vector<int>& seq){
		tree[id].id=id;
		tree[id].l=l;
		tree[id].r=r;
		if(l==r){
			tree[id].ans=seq[l];
			return;
		}
		int mid=(l+r)>>1;
		build(left(id),l,mid,seq);
		build(right(id),mid+1,r,seq);
		pushup(id);
	}
	void modify(int id,int l,int r,int add){
		SegmentTreeNode& n=tree[id];
		if(l<=n.l&&r>=n.r){
			n.lazy+=add;
			n.ans+=(n.r-n.l+1)*add;
			return;
		}
		if(n.lazy){
			pushdown(id);
		}
		int mid=(n.l+n.r)>>1;
		if(l<=mid){
			modify(left(id),l,r,add);
		}
		if(r>mid){
			modify(right(id),l,r,add);
		}
		pushup(id);
	}
	int ask(int id,int l,int r){
		SegmentTreeNode& n=tree[id];
		if(l<=n.l&&r>=n.r){
			return n.ans;
		}
		if(n.lazy){
			pushdown(id);
		}
		int ans=0;
		int mid=(n.l+n.r)>>1;
		if(l<=mid){
			ans+=ask(left(id),l,r);
		}
		if(r>mid){
			ans+=ask(right(id),l,r);
		}
		return ans;
	}
	vector<SegmentTreeNode> tree;
};
