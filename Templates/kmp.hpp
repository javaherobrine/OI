#include<bits/stdc++.h>
using namespace std;
static vector<int> next;//next[i]表示pat[0..pat]的最长公共前后缀
static string pat;
void pre(const string& s){
	pat=s;
	int j=0;
	int m=s.size();
	next=vector<int>(m+1);
	next[1]=0;//边界条件
	for(int i=1;i<m;i++){//自己匹配自己
		while(j>0&&s[i]!=s[j]){
			j=next[j];//匹配失败
		}
		if(s[i]==s[j]){//匹配成功
			j++;
		}
		next[i+1]=j;//求出来了！
	}
}
void match(const string& s){
	int j=0;//初始的位置
	int m=pat.size();
	for(int i=0;i<s.size();i++){
		while(j>0&&s[i]!=pat[j]){//如果不能匹配当前字符，则j=next[j]（往回跳）
			j=next[j];
		}
		if(s[i]==pat[j]){
			j++;//当前匹配成功
		}
		if(j==m){//匹配成功
			cout<<i-m+1<<" ";
			j=next[j];//匹配下一个
		}
	}
}
