#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e5 + 5;
const ll inf = 1e18;
vector<pair<ll , ll>> adj[N];

vector <ll> dijkstra(int V, int S) {
	
	priority_queue<pair<ll , ll> , vector<pair<ll , ll>> , greater<pair<ll, ll>>> pq;
	
	vector<ll> dist(V + 1, inf);
	vector<bool> vis(V + 1);
	pq.push({0 , S});
	dist[S] = 0;
	while(!pq.empty()){
		auto root = pq.top();
		pq.pop();
		if(vis[root.second]) continue;
		vis[root.second] = true;
		for(auto x : adj[root.second]){
			if(dist[x.first] > dist[root.second] + x.second){
				dist[x.first] = dist[root.second] + x.second;
				pq.push({dist[x.first] , x.first});
			}
		}
	}
	return dist;
}



int main(){

        ll V, E;
        cin >> V >> E;
        
        for(int i = 0 ; i < E ; ++i) {
            ll u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v , w});
        }
        
        
    	auto res = dijkstra(V, 1);
    	
    	for(int i=1; i<=V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    

    return 0;
}
