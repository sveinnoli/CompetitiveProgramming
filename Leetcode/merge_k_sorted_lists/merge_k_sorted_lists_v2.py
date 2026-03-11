# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

import heapq

class Solution:
    def mergeKLists(self, lists: list[ListNode]) -> ListNode:

        # Initialize sorted list head
        head = ListNode()
        curr = head

        # K elements of the curr node of each list will be stored in a min hip, at each traversal an element from list[i] will transfer from minheap to sorted list (Time Complexity = O(log(k))). Next element of list[i] will be added to the sorted list (Time Complexity = O(log(k))).
        heap = []
        heapq.heapify(heap)

        k = len(lists)

        for i in range(k):
            if lists[i]:
                heapq.heappush(heap, (lists[i].val, i))
                lists[i] = lists[i].next
        
        # Till the heap is empty, i.e. all elements of all lists are inserted
        while len(heap)>0:
            val, listid = heapq.heappop(heap)
            # Add min elem of heap to sorted list
            curr.next = ListNode(val)
            curr = curr.next
            if lists[listid]:
                heapq.heappush(heap, (lists[listid].val, listid))
                lists[listid] = lists[listid].next
        
        return head.next