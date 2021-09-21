#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 4;
#define ll long long
int par[N];
int sz[N];
int findpar(int a){
	if(par[a] == 0) return a;
	return par[a] = findpar(par[a]);
}
void merge(int a , int b){
	if(sz[a] > sz[b]) swap(a , b);
	
	int pa = findpar(a) , pb = findpar(b);
	par[pa] = pb;
	sz[pb] += sz[pa];
}
vector<pair<int, int>> adj[N];
int main(){
	int n , m;
	cin >> n >> m;
	vector<vector<int>> edges;
	
	for(int i = 0 ; i < m ; ++i){
		int a , b , w;
		cin >> a >> b >> w;
		adj[a].push_back({b , w});
		edges.push_back({a , b , w});
	}
	auto comp = [&](vector<int>& a , vector<int>& b){
		return a[2] < b[2];
		// return a[2] > b[2];
	};
	sort(edges.begin() , edges.end() , comp);
	ll ans = 0;
	for(int i = 0 ; i < m ; ++i){
		auto x = edges[i];
		if(findpar(x[0]) == findpar(x[1])) continue;
		else{
			merge(x[0] , x[1]);
		}
		ans += x[2];
	}
	
	
	cout << ans << '\n';
}
