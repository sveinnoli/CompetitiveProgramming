# Definition for singly-linked list.
import heapq

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: list[ListNode]) -> ListNode:
        setattr(ListNode, "__lt__", lambda self, other: self.val <= other.val)
        heapq.heapify(lists)        

        dummy = ListNode()
        current = dummy

        while (lists):
            smallest = heapq.heappop(lists)
            current.next = smallest
            current = current.next

            if (smallest.next):
                heapq.heappush(lists, smallest.next)
        return dummy.next
    
if __name__ == "__main__":
    s = Solution()
    s.mergeKLists([ListNode(2),ListNode(2),ListNode(6),ListNode(2),ListNode(4),ListNode(5)])