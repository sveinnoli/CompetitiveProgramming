// https://leetcode.com/problems/subarray-sum-equals-k/
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix_sum = {nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            prefix_sum.push_back(prefix_sum[i-1] + nums[i]);
        }

        unordered_map<int, int> mp;

        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (prefix_sum[i] == k) {
                ans++;
            }

            if (mp.find(prefix_sum[i] - k) != mp.end()) {
                ans+=mp[prefix_sum[i] - k];
            }
            mp[prefix_sum[i]]++;
        }
        return ans;
    }
};


int main(int argc, char** argv) {
    Solution s;    
    vector<int> v = {1,2,3};
    cout << s.subarraySum(v, 3);
    return 0;
}