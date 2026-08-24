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
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *pre = nullptr;
        ListNode *curr = slow;

        while(curr != nullptr){
            ListNode *futr = curr->next;
            curr->next = pre;
            pre =  curr;
            curr = futr;
        }

        ListNode *first = head;
        ListNode *last = pre;

        while(first != nullptr && last != nullptr){
            if(first->val != last->val){
                return false;
            }
            first = first->next;
            last = last->next;
        }
        return true;
    }
};