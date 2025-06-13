class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        stack<ListNode*> st;
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;

        ListNode* curr = head;

        while (curr) {
            int count = 0;
            ListNode* temp = curr;

            while (temp && count < k) {
                st.push(temp);
                temp = temp->next;
                count++;
            }
            if (count == k) {
                while (!st.empty()) {
                    p->next = st.top();
                    st.pop();
                    p = p->next;
                }
                p->next = temp;
                curr = temp;
            } else {
                p->next = curr;
                break;
            }
        }

        return dummy->next;
    }
};