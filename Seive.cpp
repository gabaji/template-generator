#include<bits/stdc++.h>
#define ll long long

const int N = 1e6 + 1;
vector<bool> soe(N , true);
using namespace std;
// saving primes upto n 
int main(){
	for(int i = 2 ; i * i <= N ; ++i){
		if(soe[i])
		for(int j = i + i ; j <= N; j += i){
			soe[j] = false;
		}
	}
	vector<int> primes;
	for(int i = 2 ; i <= N ; ++i){
		if(soe[i]) 
			primes.push_back(i);
	}
}
