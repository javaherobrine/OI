#include<vector>
struct union_find{
	size_t size;
	std::vector<int>father;
	union_find(const size_t&s){
		size=s;
		father.resize(s);
		clear_set();
	}
	void clear_set(){
		for(int i=0;i<size;i++){
			father[i]=i;
		}
	}
	int find(const int& x){
		if(x==father.at(x)){
			return x;
		}else{
			father.at(x)=find(father.at(x));
			return father.at(x);
		}
	}
	void union_elements(const int&p,const int&q){
		father[find(p)]=find(q);
	}
	void resize(const size_t&new_size){
		father.resize(new_size);
		if(new_size>size){
			for(size_t i=size;i<new_size;i++){
				father[i]=i;
			}
		}
		size=new_size;
	}
	bool is_connected(const int&p,const int&q){
		return find(p)==find(q);
	}
};
//simple one(for OI)
int father[114514];
int find(const int&x){
	if(x!=father[x]){
		father[x]=find(father[x]);
	}
	return father[x];
}
bool judge(const int&p,const int&q){
	return find(p)==find(q);
}
void unionn(const int&p,const int&q){
	father[find(p)]=find(q);
}
