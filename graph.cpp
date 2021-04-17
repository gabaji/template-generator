#include<bits/stdc++.h>
using namespace std;

#define N 1000

vector<int> adj[N];
vector<bool> vis(N);


int main(){
	int n , m;
	cin>>n>>m;
	int a , b , c;
	for(int i = 0 ; i < m ; ++i){
		cin>>a>>b>>c;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
}
