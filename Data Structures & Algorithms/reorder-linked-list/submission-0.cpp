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
    void reorderList(ListNode* head) {

        if(head == nullptr || head->next == nullptr)
            return;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;

        while(second)
        {
            ListNode* nextNode = second->next;

            second->next = prev;

            prev = second;
            second = nextNode;
        }

        // Merge
        ListNode* first = head;
        ListNode* secondHalf = prev;

        while(secondHalf)
        {
            ListNode* temp1 = first->next;
            ListNode* temp2 = secondHalf->next;

            first->next = secondHalf;
            secondHalf->next = temp1;

            first = temp1;
            secondHalf = temp2;
        }
    }
};
