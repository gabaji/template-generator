#include<bits/stdc++.h>

using namespace std;


int slidingwindow(vector<int>& nums, int k) {
	sort(nums.begin() , nums.end());
	int n = nums.size();
	for(ll i = 0 ; i < n ; ++i){
		sum += nums[i];
		while(/* invalid condition for a window */){
			sum -= nums[j++];
		}
		// cout<<i<<" "<<j<<"\n";
		ans = max(ans , i - j + 1);
	}
	return ans;
}
