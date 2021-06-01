#include<bits/stdc++.h>

using namespace std;
const int N = 1e5;
int n , arr[N] , ftree[N];

// For zero based indexing
// to go lower, use (r & (r - 1)) - 1 
// to go up, use (r | (r + 1))

// For 1 based indexing
// use i += (i & (-i)) and i -= (i & (-i))

void add(int index ,int val){		// point update
	for( ; index < n ; index = index | (index + 1))
		ftree[index] += val;
}
int sum(int r){ 					// sum of [0 , r]
	int ans = 0;	
	for( ; r >= 0 ; r = (r & (r + 1)) - 1)
		ans += ftree[r];
	return ans;
}

void build(){					// O(n) build
	for(int i = 0 ; i < n ; ++i){
		ftree[i] += arr[i];
		if((i | (i + 1)) < n){
			ftree[i | (i + 1)] += ftree[i];
		}
	}
}


int main(){
	cin>>n;
	for(int i = 0 ; i < n ; ++i)
		cin>>arr[i];
	
}
