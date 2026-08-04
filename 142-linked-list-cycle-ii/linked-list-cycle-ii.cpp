/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *nodeDetection(ListNode*head, ListNode *slow, ListNode *fast){

        while(fast != slow){

            slow = slow->next;
            fast = fast->next;
            
        }
        return fast;
      
    }

    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;
       

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                slow = head;
                return nodeDetection(head,slow,fast);
            }
        }
        return nullptr;
    }
}; 