#include<bits/stdc++.h>
#define I using
#define AK namespace
#define IOI std
I AK IOI;
struct TreapNode{
	TreapNode *left{nullptr},*right{nullptr};
	int value,priority,size,count;
};
struct Treap{
	TreapNode* NIL=nullptr;
	TreapNode* root=nullptr;
	void insert(int n){
		insert(n,root);
	}
	TreapNode*& find(int n){
		return find(n,root);
	}
	void remove(int n){
		remove(find(n));
	}
private:
	void remove(TreapNode*& node){
		if(node==nullptr){
			return;
		}
		node->count--;
		if(node->count==0){
			if(node->left!=nullptr&&node->right!=nullptr){
				TreapNode*& prev=find_max(node->left);
				node->value=prev->value;
				node->count=prev->count;
				remove(prev);
			}else{
				if(node->left==nullptr&&node->right==nullptr){
					delete node;
					node=nullptr;
					return;
				}
				TreapNode*& ptr=node->left==nullptr?node->right:node->left;
				delete node;
				node=ptr;
			}
		}
	}
	TreapNode*& find_max(TreapNode*& node){
		if(node->right==nullptr){
			return node;
		}
		return find_max(node->right);
	}
	TreapNode*& find_min(TreapNode*& node){
		if(node->left==nullptr){
			return node;
		}
		return find_min(node->left);
	}
	TreapNode*& find(int n,TreapNode*& node){
		if(node==nullptr){
			return NIL;
		}
		if(n==node->value){
			return node;
		}else if(n<node->value){
			return find(n,node->left);
		}else{
			return find(n,node->right);
		}
	}
	void insert(int n,TreapNode*& node){
		if(node==nullptr){
			node=new TreapNode;
			node->value=n;
			node->priority=rand();
			node->count=1;
			return;
		}
		if(node->value>n){
			insert(n,node->left);
		}else if(node->value<n){
			insert(n,node->right);
		}else{
			node->count++;
		}
	}
	void update_size(TreapNode*& n){
		n->size=n->count+n->left->size+n->right->size;
	}
	void left_rotate(TreapNode*& n){
		if(n->right==nullptr){
			return;
		}
		TreapNode* temp=n;
		n=n->right;
		temp->right=n->left;
		n->left=temp;
	}
};
