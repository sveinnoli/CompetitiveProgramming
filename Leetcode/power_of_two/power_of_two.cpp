#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return __builtin_popcount(n) == 1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    s.isPowerOfTwo(-0.0625);
    return 0;
}