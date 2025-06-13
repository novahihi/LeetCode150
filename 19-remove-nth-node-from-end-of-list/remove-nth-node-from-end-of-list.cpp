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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* p = head;
    int cnt = 0;
    while (p!=nullptr) {
        cnt++;
        p = p->next;
    }
    ListNode*temp;
    if (cnt==1) {
        head = nullptr;
        return head;
    }
    if (n==cnt) {
        temp = head;
        head = head->next;
        delete(temp);
        return head;
    }
    p = head;
    for (int i = 1; i<cnt-n;i++) {
        p = p->next;
    }
    temp = p->next;
    p->next = p->next->next;
    delete (temp);
    return head;
    }
};