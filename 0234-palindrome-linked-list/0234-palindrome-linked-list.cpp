class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;  
        }

        ListNode* fast = head; 
        ListNode* slow = head; 

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next; 
            fast = fast->next->next; 
        }

        ListNode* second_half_prev = nullptr; 
        ListNode* second_half = slow; 
        while (second_half != nullptr) {
            ListNode* temp = second_half->next;  
            second_half->next = second_half_prev; 
            second_half_prev = second_half;       
            second_half = temp;    
        }               

        second_half = second_half_prev;  
        ListNode* first_half = head; 
        while (second_half != nullptr) {
            if (first_half->val != second_half->val) {
                return false;  
            }
            first_half = first_half->next; 
            second_half = second_half->next; 
        }

        return true;  
    }
};
