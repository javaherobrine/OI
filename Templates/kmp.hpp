#include<bits/stdc++.h>
using namespace std;
static vector<int> next;//next[i]��ʾpat[0..pat]�������ǰ��׺
static string pat;
void pre(const string& s){
	pat=s;
	int j=0;
	int m=s.size();
	next=vector<int>(m+1);
	next[1]=0;//�߽�����
	for(int i=1;i<m;i++){//�Լ�ƥ���Լ�
		while(j>0&&s[i]!=s[j]){
			j=next[j];//ƥ��ʧ��
		}
		if(s[i]==s[j]){//ƥ��ɹ�
			j++;
		}
		next[i+1]=j;//������ˣ�
	}
}
void match(const string& s){
	int j=0;//��ʼ��λ��
	int m=pat.size();
	for(int i=0;i<s.size();i++){
		while(j>0&&s[i]!=pat[j]){//�������ƥ�䵱ǰ�ַ�����j=next[j]����������
			j=next[j];
		}
		if(s[i]==pat[j]){
			j++;//��ǰƥ��ɹ�
		}
		if(j==m){//ƥ��ɹ�
			cout<<i-m+1<<" ";
			j=next[j];//ƥ����һ��
		}
	}
}
