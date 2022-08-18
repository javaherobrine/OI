#include<vector>
using namespace std;
vector<int>primes{};
vector<bool>numbers{false,false};
void gen_primes(int max_number){//Euler sieve
    int currentPrime;
    for(int i=2;i<=max_number;i++){
        numbers.push_back(true);
    }
    for(int i=2;i<=max_number;i++){
        if(numbers[i]){
            currentPrime=i;
            primes.push_back(currentPrime);
            int factor=1;
            for(int j=currentPrime;j<=max_number;j=currentPrime*factor){
                numbers[j]=false;
                factor++;
            }
        }
    }
}
