#include <bits/stdc++.h>
using namespace std;
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

