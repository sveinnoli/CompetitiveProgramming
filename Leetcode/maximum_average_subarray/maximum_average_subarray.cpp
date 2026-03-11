#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        // Use window to find highest sum, window allows us to remove the last number and add the next and compare it against our current biggest sum.
        int biggest_sum = INT32_MIN;
        int current_sum = 0;

        for (int i = 0; i < k; i++) {
            current_sum += nums[i];
        }
        biggest_sum = max(biggest_sum, current_sum);
        

        for (int i = 1; i <= nums.size()-k; i++) {
            current_sum -= nums[i-1];
            current_sum += nums[i+k-1];
            biggest_sum = max(biggest_sum, current_sum);
        }


        return (double)biggest_sum / k;
    }
};

int main(int argc, char** argv) {

}