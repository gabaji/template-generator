#include<bits/stdc++.h>

// i will prettify it later
// 1. Idea is similar to that of sparse table, go up in powers of 2
// 2. DFS sounds more useful than this one as this one is made easier by leetcode.

using namespace std;
class TreeAncestor {
public:
	vector<int> depth;
	vector<vector<int>> mem;
    int LOG;
    TreeAncestor(int n, vector<int>& parent) {
		// 1. i need depth of each node
		// 2. i need sparse table
		// lezz goooooooo
		depth = vector<int>(n);
		for(int i = 1 ; i < n ; ++i){
			depth[i] = depth[parent[i]] + 1;
		}
		LOG = log2(n);
		// parent[0] = 0;
		mem = vector<vector<int>>(n , vector<int>(LOG + 1));
		for(int i = 1 ; i < n ; ++i){
			mem[i][0] = parent[i];
		}
		
		for(int i = 1 ; i <= LOG ; ++i){
			for(int j = 1 ; j < n ; ++j){
				mem[j][i] = mem[mem[j][i - 1]][i - 1];
			}
		}
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node] < k){
			return -1;
		}
		for(int b = 0 ; b <= LOG ; ++b){
			if(k & (1 << b)){
				node = mem[node][b];
			}
		}
		return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
 int main(){
	 
 }
