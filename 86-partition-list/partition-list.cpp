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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    ListNode* small = new ListNode(); 
    ListNode* s = small;
    ListNode* big = new ListNode();
    ListNode* b = big;
    ListNode* p = head;
    while (p) {
        if ( (p->val) < x ) {
            s->next = p;
            s = s->next;
        }
        else {
            b->next = p;
            b = b->next;
        }
        p = p->next;
    }
    b->next = nullptr;
    s->next = big->next; 
    return small->next;   
    }
};