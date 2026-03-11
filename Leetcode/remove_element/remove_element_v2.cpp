#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;

        for (const int num : nums) {
            if (num != val) {
                nums[i++] = num;
            }
        }
        return i;
    }
};

int main(int argc, char** argv) {

    Solution s;
    vector<int> v({2,2,3});
    int n = s.removeElement(v, 2);
    for (int i = 0; i < n; i++) {
        cout << v[i] <<  " ";
    }
    cout << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] <<  " ";
    }

    return 0;
}