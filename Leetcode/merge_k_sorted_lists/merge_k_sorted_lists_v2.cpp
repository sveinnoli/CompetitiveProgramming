#include <vector>
#include <algorithm>
#include <queue>

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

    struct CompareNodes {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNodes> pq;
        for (ListNode* list : lists) {
            if (list) {
                pq.push(list);
            }
        } 

        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();

            current->next = smallest;
            current = current->next;

            if (smallest->next) {
                pq.push(smallest->next);
            }
        }
        return dummy->next;
    }
};