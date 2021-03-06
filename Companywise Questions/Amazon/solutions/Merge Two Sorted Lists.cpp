/*
Merge Two Sorted Lists
======================

Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example 1:
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: l1 = [], l2 = []
Output: []

Example 3:
Input: l1 = [], l2 = [0]
Output: [0]

Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    if (l1 == NULL && l2 == NULL)
      return NULL;
    else if (l1 == NULL)
      return l2;
    else if (l2 == NULL)
      return l1;

    ListNode *dummy = new ListNode(-1);
    ListNode *head = dummy, *temp = dummy;

    while (l1 && l2)
    {
      if (l1->val < l2->val)
      {
        temp->next = l1;
        l1 = l1->next;
        temp->next->next = NULL;
        temp = temp->next;
      }
      else
      {
        temp->next = l2;
        l2 = l2->next;
        temp = temp->next;
        temp->next = NULL;
      }
    }

    if (l1)
      temp->next = l1;
    if (l2)
      temp->next = l2;

    return head->next;
  }
};
