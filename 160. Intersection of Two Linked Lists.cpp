/*
Problem Description:
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 �� a2
                   �K
                     c1 �� c2 �� c3
                   �J            
B:     b1 �� b2 �� b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length_A=0,length_B=0;
        ListNode *p=headA,*q=headB;
        while(p)
        {
            length_A++;
            p=p->next;
        }
        while(q)
        {
            length_B++;
            q=q->next;
        }
        p=(length_A>length_B?headA:headB);
        q=(length_A>length_B?headB:headA);
        for(int i=0;i<abs(length_A-length_B);i++)
        {
            p=p->next;
        }
        while(p && q)
        {
            if(p->val==q->val)
            {
                return p;
            }
            p=p->next;
            q=q->next;
        }
        return nullptr;
    }
};