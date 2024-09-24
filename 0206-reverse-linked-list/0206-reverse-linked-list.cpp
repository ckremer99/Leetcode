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
    ListNode* reverseList(ListNode* head) {
        ListNode* reversed_list = head; 
        ListNode* prev = nullptr; 
        while(reversed_list != nullptr) {
            ListNode* temp = reversed_list->next;  
            reversed_list->next = prev;            
            prev = reversed_list;                  
            reversed_list = temp; 
        }
        return prev; 
    }
};