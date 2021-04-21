#include<bits/stdc++.h>
#define ll long long

const int N = 1e6 + 1;

using namespace std;
// saving primes upto n 
int main(){
	int n; 
	cin>>n;
	vector<bool> soe(N , true);
	
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
	for(int x : primes) 
		cout<<x<<" ";
}
