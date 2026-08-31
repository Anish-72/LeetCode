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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == nullptr){
            return {-1,-1};
        }

        vector<int>ans;
        ListNode* temp = head;
        int idx = 1;
        int minIdx = INT_MAX, maxIdx = -1;
        int minDist = INT_MAX;
        int maxDist = INT_MIN;
        int preIdx = 0;
        int currIdx = 0;

        while (temp->next->next != nullptr) {
            idx++;
            int pre = temp->val;
            int curr = temp->next->val;
            int futr = temp->next->next->val;
            
            if (pre < curr && curr > futr || pre > curr && curr < futr) {

                currIdx = idx;
               if (preIdx != 0) {
                    int dist = currIdx - preIdx;
                    minDist = min(minDist, dist);
                }
                preIdx = currIdx;

                minIdx = min(minIdx, idx);
                maxIdx = max(maxIdx, idx);
                maxDist = maxIdx - minIdx;

            }
            temp = temp->next;
        }
        if (minDist == INT_MAX) {
            return {-1, -1};
        }
        ans.push_back(minDist);
        ans.push_back(maxDist);

        return ans;
    }
};