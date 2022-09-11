#include<vector>
using namespace std;
void swap(int& a,int& b){
	a^=b;
	b^=a;
	a^=b;
}
void insertion_sort(vector<int>& a){
	for(size_t i=1;i<a.size();i++){
		int& key=a[i];
		for(size_t j=0;j<i;j++){
			if(a[j]>key){
				swap(a[j],key);
			}
		}
	}
}
/*
 * a[from_index..medium_index] and a[medium_index..to_index] are sorted,merge them.
 */
void merge_array(vector<int>&a,int from_index,int medium_index,int to_index){

}
void merge_sort(vector<int>&a){

}
