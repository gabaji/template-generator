#include <bits/stdc++.h>

#define inf (int)1e9
#define mod 1000000007
#define vi vector<int>
#define pii pair<ll, ll>
#define ll long long
#define vll vector<ll>
#define nl "\n"
#define f first
#define s second
using namespace std;

vector<pii> points;

bool cw(pii& a , pii& b , pii& c){
	return (c.f - b.f) * (b.s - a.s) - (c.s - b.s) * (b.f - a.f) >= 0;
}

bool acw(pii& a , pii& b , pii& c){
	return (c.f - b.f) * (b.s - a.s) - (c.s - b.s) * (b.f - a.f) <= 0;
}

int main(){
	int n;
	cin>>n;
	
	for(int i = 0 ; i < n ; ++i){
		int a , b;
		cin>>a>>b;
		points.push_back({a , b});
	}
	sort(points.begin() , points.end());
	
	vector<pii> lower, upper;
	
	lower.push_back(points[0]);
	upper.push_back(points[0]);
	
	pii a , b;
	a = points[0] , b = points[n - 1];
	for(int i = 1 ; i < n; ++i){
		if(i == n - 1 || acw(a , points[i] , b)){
			while(lower.size() >= 2 && !acw(lower[lower.size() - 2] , lower[lower.size() - 1] , points[i]))
				lower.pop_back();
			lower.push_back(points[i]);
		}
		if(i == n - 1|| cw(a , points[i] , b)){
			while(upper.size() >= 2 && !cw(upper[upper.size() - 2] , upper[upper.size() - 1] , points[i]))
				upper.pop_back();
			upper.push_back(points[i]);
		}
	}
	vector<pii> ans;
	
	for(auto x : lower) 
		ans.push_back(x);
		
	for(int i = upper.size() - 2 ; i > 0 ; --i)
		ans.push_back(upper[i]);
		
	cout<<ans.size() << "\n";
	for(auto x : ans)	
		cout<<x.f << " " << x.s << "\n";
}
