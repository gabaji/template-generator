#include<bits/stdc++.h>
using namespace std;


int slidingwindow(vector<int>& nums, int k) {
	sort(nums.begin() , nums.end());
	int n = nums.size() , sum = 0 , ans = -1e9;
	int j = 0;
	for(int i = 0 ; i < n ; ++i){
		sum += nums[i];
		while(/* invalid condition for a window */){
			sum -= nums[j++];
		}
		// cout<<i<<" "<<j<<"\n";
		ans = max(ans , i - j + 1);
	}
	return ans;
}
