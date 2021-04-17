#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends





class Solution{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
		const int inf = 1e8;
		priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int, int>>> pq;
		
		vector<int> dist(V , -1);
		vector<int> vis(V);
		pq.push({0 , S});
		dist[S] = 0;
		while(!pq.empty()){
			auto root = pq.top();
			pq.pop();
			
 			if(vis[root.second]) continue;
			dist[root.second] = root.first;
			vis[root.second] = true;
			//cout<<root.second<<"\n";
			
			for(auto x : adj[root.second]){
			    if(vis[x[0]]) continue;
				dist[x[0]] = dist[root.second] + x[1];
				pq.push({dist[x[0]] , x[0]});
			}
		}
		return dist;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
