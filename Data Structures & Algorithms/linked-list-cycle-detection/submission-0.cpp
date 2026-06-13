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

 // Optimal solution: 
 // Think of it like: If the road is straight (i.e Straight Linked list ending at null) , two riders with different speed (constant) never meets.
 //                   But if the road is ciruclar (i.e cyclic , end is connected to somewhere in road), two riders with different speed (constant), will definetely meet.

 // This is called as Tortoise and Hare Algorithm
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                return true;
        }

        return false;
    }
};
