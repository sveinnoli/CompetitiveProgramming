#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        deque<int> removedIndices;
        int removed_elements = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                removedIndices.push_front(i);
                removed_elements++;
            } else {
                if (!removedIndices.empty()) {
                    nums[removedIndices.back()] = nums[i];
                    removedIndices.pop_back();
                    removedIndices.push_front(i);
                }
            }
        }
        return nums.size() - removed_elements;
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