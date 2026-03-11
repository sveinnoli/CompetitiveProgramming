using namespace std;
#include <vector>
#include <cmath>
#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
};

int main(int argc, char** argv) {

    Solution s;
    cout << s.climbStairs(5) << "\n";
    
    return 0;
}