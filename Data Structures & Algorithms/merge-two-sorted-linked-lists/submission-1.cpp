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

// Initial Approach


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while(temp1!=nullptr && temp2!=nullptr)
        {
            if(temp1->val <= temp2->val)
            {
                if(head == nullptr) 
                {
                    head = temp1;
                    tail = temp1;
                }
                else{
                    tail->next=temp1;
                    tail=temp1;
                }
                temp1=temp1->next;
            }
            else{
                if(head == nullptr) 
                {
                    head = temp2;
                    tail = temp2;
                }
                else{
                    tail->next=temp2;
                    tail=temp2;
                }
                temp2=temp2->next;
            }
        }
        if(temp1)
            tail->next = temp1;

        if(temp2)
            tail->next = temp2;
        return head;
    }
};

// ListNode* head = nullptr;
// ListNode* tail = nullptr;

// if(temp1<=temp2 || temp2==nullptr)
// {
//     if(head == nullptr) 
//     {
//         head = temp1;
//         tail = temp1;
//         temp1=temp1->next;
//     }
//     else{
//         tail=temp1->next;
//         tail=temp1;
//     }
// }
// else{
//     if(head == nullptr) 
//     {
//         head = temp2;
//         tail = temp2;
//         temp2=temp2->next;
//     }
//     else{
//         tail=temp2->next;
//         tail=temp2;
//     }
// }