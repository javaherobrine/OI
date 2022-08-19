/*
 * URL:https://www.luogu.com.cn/problem/P1069
 * If the number of cells % the number of test tubes is 0,they can be put into test tubes.
 * If all of prime factors of A is in B,B%A=0
 * So use prime factors.Let me give you some examples to help you solve this problem.
 * Example 1:
 * Input:
 * 1
 * 2 1
 * 3
 * Output:
 * -1
 * 2=2^1,2^1=2^(1*1)=2^1
 * 3=3^1
 * Some of factors of 2(2) isn't in 3,so the time is -1
 * Example 2:
 * Input:
 * 2
 * 24 1
 * 30 12
 * Output:
 * 2
 * 24=2^3*3^1,24^1=2^(3*1)*3^(1^1)=2^3*3^1
 * 30=2^1*3^1*5^1
 * To ensure all of prime factors of 30 is in 24,we should call
 * int time=max(3/1,1/1);
 * The time is 3
 * 12=2^2*3^1
 * We should use rounded up as the result of A/B if A%B isn't 0,the remainder cannot be ignored.
 * The code is
 * int time=max(ceil(3/2),1/1)
 * The time is 2
 * The minimum time is 2,so the output is 2
 * Just process data like this
 * Especially,if the number of test tubes is 1,the time is 0
 */
#include<vector>
#include<unordered_map>
#include<iostream>
#include<cmath>
using namespace std;
int max0=44721;//sqrt(2*10^9)
vector<bool>numbers{false,false};//marks,0 and 1 aren't primes
vector<int>primes{};//primes
void genPrimes(){//use Euler sieve to find primes and put them into vector<int>primes
    int currentPrime;
    for(int i=2;i<=max0;i++){
        numbers.push_back(true);//init
    }
    for(int i=2;i<=max0;i++){
        if(numbers[i]){
            currentPrime=i;
            primes.push_back(currentPrime);
            int factor=1;
            for(int j=currentPrime;j<=max0;j=currentPrime*factor){//p,q¡ÊN+,p,q>1,p*q isn't a prime
                numbers[j]=false;
                factor++;
            }
        }
    }
}
void primeFactors(int& n,unordered_map<int,int>&set){//decomposition prime factors
    int max1=sqrt(n);
    for(int i=0;primes[i]<=max1;i++){
        if(n%primes[i]==0){
        	int j=n/primes[i];
            if(set.count(primes[i])){//change the number of the prime factor
            	set.at(primes[i])++;
            }else{//it can be optimized,the task is yours
            	set.insert({primes[i],1});
            }
            primeFactors(j,set);
            return;
        }
    }
    if(set.count(n)){
    	set.at(n)++;
    }else{
    	set.insert({n,1});
    }
}
int main(){
	genPrimes();
	ios::sync_with_stdio(false);//optimize iostream
	cin.tie(nullptr);
	int n;
	cin>>n;
	int m1,m2;
	cin>>m1>>m2;
	unordered_map<int,int>test_tube{};//prime factors of test tube
	unordered_map<int,int>cells{};//prime factors of cells
	vector<unsigned int>time{};
	primeFactors(m1,test_tube);
	auto iter0=test_tube.begin();
	int temp{};
	while(iter0!=test_tube.end()){
		iter0->second*=m2;//if m=p*q,m^n=p^n*q^n
		iter0++;
	}
	for(int i=0;i<n;i++){
		cin>>temp;
		primeFactors(temp,cells);
		signed int max1=0;
		auto iter=test_tube.begin();
		while(iter!=test_tube.end()){
			if(cells.count(iter->first)){
				int j=cells.at(iter->first);
				int k=iter->second;
				int max2;
				if(k%j!=0){//ceil(k/j)
					max2=k/j+1;
				}else{
					max2=k/j;
				}
				max1=max(max1,max2);
			}else{//if number of test tube has a prime factor the cell doesn't have,the value is -1
				max1=-1;
				break;
			}
			iter++;
		}
		cells.clear();
		time.push_back(max1);
	}
	unsigned int min0=time[0];
	/*
	 * Maybe it's hard to understand why I use unsigned integers
	 * unsigned int a=-1;
	 * unsigned int b=1;
	 * b<a
	 * but if they are signed
	 * signed int a=-1;
	 * signed int b=1;
	 * b>a
	 * The minimum of unsigned integers is the minimum of positive signed integers,or there are only negatives
	 * So using unsigned integers can put -1 into the maximum(other numbers are positives)
	 * The value of -1 is 2^32-1
	 * Then find the minimum and cast into signed integers
	 * Finally,the problem gets solved.
	 */
	for(int i=1;i<time.size();i++){
		if(min0>time[i]){
			min0=time[i];
		}
	}
	if(m1==1){//especially,if the number of test tube is 1,it can be used at once
		cout<<0;
		return 0;
	}
	signed int result=min0;//cast 2^32-1 into -1
	cout<<result;
	return 0;
}
