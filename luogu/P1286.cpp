/*
 * URL:https://www.luogu.com.cn/record/86643620
 * n numbers?0.5n(n-1) sum?
 * If we sort them,and suppose the sorted answer is a,b,c,d......
 * The first is a+b,the second is a+c
 * If we know b+c,we can solve a,b,c
 * Then remove them,we can solve d(Because the first sum is a+d now)......
 * If we get d solved,we can remove a+d,b+d and c+d......
 * Then we can solve e
 * Then the first sum is a+e now
 * Just do the circulation and all the numbers will be solved
 * If the computed sum cannot be removed,the a,b,c is wrong,we should solve a,b,c again
 * If all of the a,b,c is wrong,there is no solution and the output is Impossible
 * You can find b+c in n-1 times,it can be proven:
 * Suppose the last element is ¦Á
 * The worst is b+d>b+c(Because d>c)>a+¦Á
 * The index is n
 * Because the first and the second are a+b and a+c
 * The first possible index is 2
 * You will search from 2 to n
 * Searching for n-2+1=n-1 times
 */
#include<iostream>
#include<map>
#include<vector>
#include<sstream>
using namespace std;
/*
 * Sorted elements?The key of the map is sorted LOL
 * The value is the count of the sum
 */
map<int,int>sums{};
streambuf* inbuf;
/*
 * remove an element in std::multiset simulated by std::map(I can't use std::multiset)
 */
bool remove_element(map<int,int>&map,const int& ele){
    if(map.count(ele)){
        map.at(ele)-=1;
        if(map.at(ele)==0){
            map.erase(ele);
        }
        return true;
    }else{
        return false;
    }
}
/*
 * inbuf=cin.rdbuf();
 * int i=qr();
 * Faster than
 * int i;
 * cin>>i;
 */
int qr(){
    char ch=inbuf->sbumpc();
    int val{0},sgn{1};
    while(ch>'9'||ch<'0'){//process invalid characters and sign
        if(ch=='-'){
            sgn*=-1;
        }
        ch=inbuf->sbumpc();
    }
    while(ch<='9'&&ch>='0'){//input the number
        val=(val<<3)+(val<<1);//val*=10,for lower bit
        val+=ch^48;//input the current lowest bit
        ch=inbuf->sbumpc();
    }
    return sgn*val;//the value of the number is its sign * its abs
}
bool process(vector<int>& result,map<int,int>&nums,int n){//compute d,e,f......
    if(n==0){
        return true;
    }
    int d=(nums.begin()->first)-result[0];
    for(auto iter=result.begin();iter!=result.end();iter++){
        if(remove_element(nums,(*iter)+d)){}else{
            return false;
        }
    }
    result.push_back(d);
    return process(result,nums,n-1);
}
int compute(){//find a,b,c
    int n{qr()};
    int nn=n*(n-1)/2;
    int input;
    for(int i=0;i<nn;i++){
        input=qr();
        if(sums.count(input)){
            sums.at(input)++;
        }else{
            sums.insert({input,1});
        }
    }
    vector<int>result{};
    auto iter=sums.begin();
    int ab=iter->first;
    iter++;
    int ac=iter->first;
    n-=2;
    iter++;
    int bc;
    int abc;
    int a,b,c;
    for(int i=0;i<n;i++){
        result.clear();
        bc=iter->first;
        abc=ac+bc+ab;
        if(abc%2!=0){
            if(n==1){
                cout<<"Impossible";
                sums.clear();//REMEMBER IT!!!OR YOU WILL GET ANSWER WRONG!!!!!!!!!!!!!
                return 0;
            }
            iter++;
            continue;
        }
        abc>>=1;
        a=abc-bc;
        b=abc-ac;
        c=abc-ab;
        if(n==1){//If only 3 numbers,no need to compute next
            cout<<a<<" "<<b<<" "<<c;
            sums.clear();
            return 0;
        }
        result.push_back(a);
        result.push_back(b);
        result.push_back(c);
        map<int,int> temp{sums};//A copy of sum
        if(!(remove_element(temp,ab)&&remove_element(temp,bc)&&remove_element(temp,ac))){
            continue;
        }
        if(process(result,temp,n-1)){//If the solution is not illegal
            for(auto iter0=result.begin();iter0!=result.end();iter0++){
                cout<<*iter0<<" ";
            }
            sums.clear();
            return 0;
        }
        iter++;
    }
    //If there is no solution
    cout<<"Impossible";
    sums.clear();
    return 114514;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    stringstream ss;
    string input;
    while(getline(cin,input)){//MORE DATA
        ss.str(input);
        inbuf=ss.rdbuf();
        compute();
        cout<<endl;
    }
}
