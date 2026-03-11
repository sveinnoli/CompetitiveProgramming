#include <iostream>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode *dummy, *temp;
       dummy = new ListNode();
       temp = dummy;

       while (list1 && list2) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
       }
       if(list1) temp->next = list1;
       if(list2) temp->next = list2;

       return dummy->next;
    }
};


int main(int argc, char** argv) {
    int a_vals[] = {2,4};
    int b_vals[] = {3,4};
    ListNode* a = new ListNode(1);
    ListNode* current = a;
    for (int i = 0; i < 2; i++) {
        current->next = new ListNode(a_vals[i]);
        current = current->next;
    }

    ListNode* b = new ListNode(1);
    current = b;
    for (int i = 0; i < 2; i++) {
        current->next = new ListNode(b_vals[i]);
        current = current->next;
    }

    Solution s;
    s.mergeTwoLists(a, b);
    return 0;
}