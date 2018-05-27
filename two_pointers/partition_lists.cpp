//https://www.lintcode.com/problem/partition-list/description

// Description
// Given a linked list and a value x,
// partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// Have you met this question in a real interview
// ? Example
// Given 1->4->3->2->5->2->null and x = 3,
// return 1->2->2->4->3->5->null.

/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution
{
  public:
    /**
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode *partition(ListNode *head, int x)
    {
        // write your code here
        ListNode dummy1, dummy2;
        ListNode *small = &dummy1;
        ListNode *big = &dummy2;
        ListNode *cur = head;

        while (cur)
        {
            if (cur->val < x)
            {
                small->next = cur;
                small = small->next;
            }
            else
            {
                big->next = cur;
                big = big->next;
            }
            cur = cur->next;
        }

        big->next = NULL;
        small->next = dummy2.next;
        return dummy1.next;
    }
};