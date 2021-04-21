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
const int N = 2e5 + 5;
int seg[4 * N];
int arr[N];


int n;

void build(int index , int tl , int tr){
	if(tl == tr){
		seg[index] = arr[tl];
		return;
	}
	int mid = (tl + tr) / 2;
	
	build(index << 1 , tl , mid);
	build(index << 1 | 1 , mid + 1 , tr);
	
	seg[index] = max(seg[index << 1] , seg[index << 1 | 1]);
}


int findNode(int index , int val , int tl , int tr){
	if(tl == tr){
		seg[index] -= val;
		return tl + 1;
	}
	
	int mid = (tl + tr) / 2;
	int ans;
	if(seg[index << 1] >= val)
		ans = findNode(index << 1 , val , tl , mid);
	else
		ans = findNode(index << 1 | 1 , val ,mid + 1 , tr);
	
	seg[index] = max(seg[index << 1] , seg[index << 1 | 1]);	
	
	return ans;
	
}


int main(){
	int q;
	cin>>n>>q;
	for(int i = 0 ; i < n ; ++i)
		cin>>arr[i];
	
	build(1 , 0 , n - 1);
	
	while(q--){
		int val;
		cin>>val;
		if(val > seg[1])
			cout<<0;
		else
			cout<<findNode(1 , val , 0 , n - 1);
			
		cout<<" ";
	
	}
	cout<<"\n";
	
}

