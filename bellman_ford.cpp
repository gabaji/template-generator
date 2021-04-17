#include<bits/stdc++.h>
using namespace std;



class Solution{
	public:

    const int inf = 1e8;
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        
        vector<int> dp(V , inf);
        dp[S] = 0;
        for(int i = 0 ; i < V - 1 ; ++i){
            bool flag = false;
			for(auto x : adj){
				int a = x[0] , b = x[1] , c = x[2];
				if(dp[b] > dp[a] + c){
				    dp[b] =  dp[a] + c;
				    flag = true;
				}
			}
			if(!flag) break;
		}
		return dp;
    }
    
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.bellman_ford(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
