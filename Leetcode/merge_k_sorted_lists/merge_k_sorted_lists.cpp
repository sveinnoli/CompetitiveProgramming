#include <vector>
#include <algorithm>
using namespace std;
/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> allNodes;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* current = lists[i];
            while (current) {
                allNodes.push_back(current);
                current = current->next;
            }
        }
        sort(allNodes.begin(), allNodes.end(), 
        [](ListNode* a, ListNode* b) {
           return a->val > b->val;
        });

        ListNode* current = allNodes[0];
        for (int i = 0; i < allNodes.size()-1; i++) {
            current->next = allNodes[i+1];
            current = current->next;
        }
        current->next = nullptr;
        return allNodes[0];
    }
};