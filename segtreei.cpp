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
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int a[2 * N];

int n;

void build(){
	for(int i = n - 1 ; i > 0 ; --i){
		a[i] = a[i << 1] | a[(i << 1) | 1];
	}
}

void modify(int index , int val){
	index += n;
	a[index] = val;
	
	while(index > 1){
		a[index>>1] = a[index] | a[index ^ 1];
		index >>= 1;
	}

}

void solve(){
	int q;
	cin>>n>>q;
	
	for(int i = 0 ; i < n ; ++i)
		cin>>a[n + i];
	
	build();
	cout<<a[1]<<"\n";
	int index , val;
	while(q--){
		cin>>index>>val;
		index--;
		modify(index, val);
		cout<<a[1]<<"\n";
	}
}




int main(){
	int t;
	cin>>t;
	while(t--)
		solve();
}

