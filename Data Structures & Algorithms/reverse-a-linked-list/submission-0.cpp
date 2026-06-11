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

//  Brute force approach

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        ListNode* newHead = nullptr;
        ListNode* newTail = nullptr;
        
        for(int i=arr.size()-1;i>=0;i--)
        {
            ListNode* newNode = new ListNode(arr[i]);
            if(newHead == nullptr)
            {
                newHead = newNode;
                newTail = newNode;
            }
            else{
                newTail->next=newNode;
                newTail = newNode;
            }
        }
        return newHead;
    }
};
