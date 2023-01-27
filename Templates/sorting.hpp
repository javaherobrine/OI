#include<bits/stdc++.h>
using namespace std;
void counting(vector<int>& sequence){
	int maxx=*max_element(sequence.begin(),sequence.end());
	vector<int> count(maxx+1);
	for(int i:sequence){
		count[i]++;
	}
	int current_index=0;
	for(int i=0;i<=maxx;i++){
		for(int j=0;j<count[i];j++){
			sequence[current_index]=i;
			current_index++;
		}
	}
}
