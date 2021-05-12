#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }
#define ll long long

const int N = 10005;
const int LOG = 14;

vector<int> child[N];
int depth[N];

int up[N][LOG];
// 13.2877

void build(int node){
	
	for(int x : child[node]){
		depth[x] = depth[node] + 1;
		up[x][0] = node;
		for(int j = 1 ; j < LOG ; j++){
			up[x][j] = up[up[x][j - 1]][j - 1];
		}
		
		build(x);
	}
}


int jump(int a , int k){
	if(k > depth[a])	
		return -1;
	for(int i = 0 ; i < LOG ; ++i){
		if(k & (1 << i))
			a = up[a][i];
	}
	return a + 1;
}


int query(int a , int b){
	if(depth[a] < depth[b]) return query(b , a);
	
	int dif = depth[a] - depth[b];
	for(int j = LOG - 1; j >= 0 ; --j){
		if(dif & (1 << j)){
			a = up[a][j];
		}
	}
	if(a == b) return a;
	
	for(int j = LOG - 1 ; j >= 0 ; --j){
		if(up[a][j] != up[b][j]){
			a = up[a][j];
			b = up[b][j];
		}
	}
	return up[a][0];
}

int main(){
	int n;
	cin>>n;
	
	for(int i = 0 ; i < n - 1 ; ++i){
		/* edge input */
	}
	build(0);
	int q;
	cin>>q;
	int a , b;
	while(q--){
		cin>>a>>b;
		cout<<query(a , b)<<"\n";
	}
}

