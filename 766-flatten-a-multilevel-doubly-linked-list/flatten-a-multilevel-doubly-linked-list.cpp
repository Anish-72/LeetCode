/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr){
            return nullptr;
        }

        Node* curr = head;

        while(curr != nullptr){
            if(curr->child != nullptr){
                Node* nextNode = curr->next;
                Node* tailNode = curr->child;

                while(tailNode->next != nullptr){
                    tailNode = tailNode->next;
                }
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = nullptr;

                tailNode->next = nextNode;
                if(nextNode != nullptr){
                    nextNode->prev = tailNode;
                }

            }
            curr = curr->next;
        }

        return head;
    }
};