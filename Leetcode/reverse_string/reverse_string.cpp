#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        for(int i = 0; i < (int)n/2; i++) {
            // s[i] += s[n-i-1];
            // s[n-i-1] = s[i] - s[n-i-1];
            // s[i] -= s[n-i-1];
            swap(s[i], s[n-i-1]);
        }
    }
};