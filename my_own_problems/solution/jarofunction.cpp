/*
 * Jaro's function
 * jaro is an OIer.
 * Because of the cancel of CSP-S2,he feels depressed,so he tried to solve problems to make himself happy
 * His function called itself
 * OH,FUNCTIONS!THAT'S GOOD!!!
 * A function is given,you are required to compute the times of the call of the function
 * There are 1 argument in the function,if the argument is greater than p(an integer),it returns,or it will call
 * itself for q times.
 * The first call of the function is like f(1)(The value of the argument is 1)
 * if you called the function for j times,the argument is a_j*i+b_j(a,b are floating point numbers,use std::floor)
 * Input:
 * p q
 * In the next q lines
 * Each line:a b
 * Output:
 * If it's ¡Þ,output stack overflow
 * Or the times of call
 * std code are shown below
 */
#include<bits/stdc++.h>
#define MOD 114514
using namespace std;
vector<double> a{};
vector<double> b{};
int p,q;
int dp[1919811];
bool visited[1919811];
int f(int i=1){
	if(i>p){
		return 1;
	}
	if(dp[i]!=0){
		return dp[i];
	}
	if(visited[i]){
		cout<<"stack overflow";
		exit(0);
	}
	visited[i]=true;
	int answer=1;
	for(int j=0;j<q;j++){
		answer+=f(int(a[j]*i+b[j]));
		answer%=MOD;
	}
	visited[i]=false;
	dp[i]=answer;
	return answer;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout<<f();
}
