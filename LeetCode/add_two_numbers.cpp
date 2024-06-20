#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* curr = dummyHead;
        int carry = 0;

        while (p != NULL || q != NULL) {
            int x = (p != NULL) ? p->val : 0;
            int y = (q != NULL) ? q->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if (p != NULL) p = p->next;
            if (q != NULL) q = q->next;
        }

        if (carry > 0) {
            curr->next = new ListNode(carry);
        }

        ListNode* result = dummyHead->next;
        delete dummyHead; 
        return result;
    }
};

void printList(ListNode* node) {
    while (node != NULL) {
        std::cout << node->val;
        if (node->next != NULL) std::cout << " -> ";
        node = node->next;
    }
    std::cout << std::endl;
}
