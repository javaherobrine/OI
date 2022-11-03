#include<bits/stdc++.h>
using namespace std;
int a[114514]{1};
int q;
unsigned long long result=0;
void search(int n,int p){
	int i;
	for(i=a[p-1];i<=n;i++){
		if(i<q){
			a[p]=i;
			n-=i;
			if(n==0){
				result++;
			}else{
				search(n,p+1);
			}
			n+=i;
		}
	}
}
int main(){
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	ios::sync_with_stdio(false);
	int p;
	cin>>p;
	q=p;
	for(int i=p;i>1;i--){
		memset(a,0,sizeof(a));
		a[0]=1;
		search(i,1);
		result%=998244353;
		result+=1;
	}
	cout<<result;
}
